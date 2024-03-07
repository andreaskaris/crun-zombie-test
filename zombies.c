#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_ZOMBIES 10
#define CHILD_SLEEP_TIME 10
#define PARENT_SLEEP_TIME 60

int main(void)
{
    int num_zombies = NUM_ZOMBIES;
    if (getenv("NUM_ZOMBIES")) {
        num_zombies = atoi(getenv("NUM_ZOMBIES"));
    }
    int child_sleep_time = CHILD_SLEEP_TIME;
    if (getenv("CHILD_SLEEP_TIME")) {
        child_sleep_time = atoi(getenv("CHILD_SLEEP_TIME"));
    }
    int parent_sleep_time = PARENT_SLEEP_TIME;getenv("PARENT_SLEEP_TIME");
    if (getenv("PARENT_SLEEP_TIME")) {
        parent_sleep_time = atoi(getenv("PARENT_SLEEP_TIME"));
    }


    pid_t pids[num_zombies];
    int i;

    for (i = 0; i < num_zombies; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            printf("Child%d\n", i);
            sleep(child_sleep_time);
            _exit(0);
        }
    }

    sleep(parent_sleep_time);

    return 0;
}
