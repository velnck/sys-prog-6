#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    pid_t newPid = fork();
    if (newPid == 0)
    {
        // child process
        char *args[]={"./main",NULL};
        execv("main", args);
        return EXIT_SUCCESS;
    }
    else if (newPid == -1)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        // initial process
        printf("Main program started. PID: %d\n", newPid);
        sleep(5);
        kill(newPid, SIGTERM);
    }
    return EXIT_SUCCESS;
}
