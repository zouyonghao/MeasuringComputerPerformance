gcc profile.c -lunwind -lunwind-x86_64 -lunwind-ptrace -lc -o profile
gcc -g test.c -o test