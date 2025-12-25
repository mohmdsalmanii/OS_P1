#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  int cpu, io;

  cpu = fork();
  if(cpu == 0){
    chpnice(getpid(), 10);
    volatile uint64 x = 0;
    int start = uptime();
    while(uptime() - start < 50){
      x++;
      if((x % 2000000) == 0){
        printf("cpu pid=%d tick=%d\n", getpid(), uptime());
      }
    }
    exit(0);
  }

  io = fork();
  if(io == 0){
    chpnice(getpid(), 0);
    for(int i = 0; i < 15; i++){
      printf("io  pid=%d tick=%d\n", getpid(), uptime());
      sleep(2);
    }
    exit(0);
  }

  wait(0);
  wait(0);
  exit(0);
}
