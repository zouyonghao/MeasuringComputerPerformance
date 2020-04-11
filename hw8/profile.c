#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/ptrace.h>

#include <libunwind.h>
#include <libunwind-ptrace.h>

#define MAX_COUNT 1000

struct function_info
{
	char *function_name;
	int function_count;
};

int compare_function(const void *elem1, const void *elem2)
{
	struct function_info *f1 = (struct function_info *)elem1;
	struct function_info *f2 = (struct function_info *)elem2;
	if (f1->function_count > f2->function_count)
	{
		return -1;
	}
	if (f1->function_count < f2->function_count)
	{
		return 1;
	}
	return 0;
}

unsigned long total_profile_count = 0;
unsigned int total_count = 0;
struct function_info functions[MAX_COUNT];

void print_result()
{
	qsort(functions, total_count, sizeof(struct function_info), compare_function);
	printf("%20s\ttimes\tpercentage\n", "name");
	for (int i = 0; i < total_count; i++)
	{
		printf("%20s\t%d\t%.2f\n", functions[i].function_name, functions[i].function_count, (double)functions[i].function_count / total_profile_count);
	}
	printf("total count is %ld\n", total_profile_count);
	exit(0);
}

int main(int argc, char **argv)
{
	signal(SIGINT, print_result);
	unw_cursor_t c;
	unw_word_t ip;
	unw_addr_space_t as;
	struct UPT_info *ui;
	char buf[512];
	int ret;
	pid_t pid;

	for (int i = 0; i < MAX_COUNT; i++)
	{
		functions[i].function_count = 0;
	}

	pid = atol(argv[1]);

	while (1)
	{
		ret = ptrace(PTRACE_ATTACH, pid);
		// printf("attach = %d\n", ret);
		// if (ret == -1) {
		// 	continue;
		// }
		as = unw_create_addr_space(&_UPT_accessors, 0);
		ui = _UPT_create(pid);
		unw_init_remote(&c, as, ui);
		do
		{
			unw_get_proc_name(&c, buf, sizeof(buf), NULL);
			int func_exist = 0;
			for (int i = 0; i < total_count; i++)
			{
				if (strcmp(functions[i].function_name, buf) == 0)
				{
					func_exist = 1;
					functions[i].function_count++;
					break;
				}
			}
			if (!func_exist)
			{
				char *name = malloc(sizeof(buf));
				strcpy(name, buf);
				functions[total_count].function_name = name;
				functions[total_count].function_count++;
				total_count++;
			}
			// printf("%s\n", buf);
		} while ((ret = unw_step(&c)) > 0);
		total_profile_count++;
		_UPT_destroy(ui);
		ptrace(PTRACE_DETACH, pid, 0, 0);

		sleep(0.1);

		// printf("total_count is %d\n", total_count);
		// printf("total_profile_count is %ld\n", total_profile_count);

		struct stat sts;
		char s[100];
		sprintf(s, "/proc/%d", pid);
		// printf("%s\n", s);
		if (stat(s, &sts) == -1)
		{
			break;
		}
	}
	print_result();
	return 0;
}