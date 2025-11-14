#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int pid1 = fork();
    if(pid1 == 0){
        // Child 1
        int pid2 = fork();
        if(pid2 == 0){
            // Child 2
            sleep(50);  // صبر کن تا پدر بمیرد
            printf("Child2 alive after reparenting. My PID = %d\n", getpid());
            exit(0);
        }

        // Parent1 exits → Child2 orphan می‌شود
        exit(0);
    }

    // Grandparent
    wait(0); // منتظر Parent1

    sleep(100); // فرصت برای reparenting
    printf("Grandparent (%d): waiting for child2...\n", getpid());

    wait(0); // منتظر child2 که حالا reparent شده
    printf("Reparent test completed.\n");
    exit(0);
}
