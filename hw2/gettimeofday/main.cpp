//
// Created by zyh on 2020/3/9.
//
#include <boost/process.hpp>
#include <sys/time.h>

namespace bp = ::boost::process;

int main(int argc, char *argv[]) {
  struct timeval start {};
  struct timeval end {};
  unsigned long diff;
  gettimeofday(&start, nullptr);

  bp::child c(bp::search_path("bash"), "-c", argv[1]);
  c.wait();

  gettimeofday(&end, nullptr);
  diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
  printf("Process running time is %ld\n", diff);
  return 0;
}