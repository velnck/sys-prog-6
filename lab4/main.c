#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

void signalHandler(int n_signal)
{
    printf("Received SIGTERM signal. Creating a copy of the current process.\n");
    pid_t newPid = fork();
    if (newPid == 0)
    {
        return;
    }
    else if (newPid == -1)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Child process created with PID: %d\n", newPid);
        exit(EXIT_SUCCESS);
    }

}

int main(int argc, char *argv[])
{
    signal(SIGTERM, signalHandler);
    int counter = 0;
    while (counter < 15)
    {
        counter++;
        printf("Counter: %d.\n", counter);
        sleep(1);
    }
    return EXIT_SUCCESS;
}
