#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int n1, n2;

  n1 = sysclcnt();
  printf("sysclcnt first: %d\n", n1);

  // یک system call معمولی، مثل write/printf
  printf("hello from test\n");

  n2 = sysclcnt();
  printf("sysclcnt second: %d\n", n2);

  printf("difference = %d\n", n2 - n1);

  exit(0);
}
