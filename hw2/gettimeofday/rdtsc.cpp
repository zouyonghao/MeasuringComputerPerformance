//
// Created by zyh on 2020/3/9.
//
#include <boost/process.hpp>
#include <linux/types.h>

namespace bp = ::boost::process;

__u64 rdtsc() {
  __u32 lo, hi;

  __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
  return (__u64)hi << 32u | lo;
}

int main(int argc, char *argv[]) {
  __u64 begin;
  __u64 end;

  begin = rdtsc();

  bp::child c(bp::search_path("bash"), "-c", argv[1]);
  c.wait();

  end = rdtsc();
  printf("Process running CPU cycle is %llu\n", end - begin);
  return 0;
}