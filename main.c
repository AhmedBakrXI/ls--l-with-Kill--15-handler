#include "list_utils.h"
#include <signal.h>

void stopKill_15();
void kill_handler();

// uncomment the commented lines if you want to test kill -15

int main(int argc, char **argv) {
    // stopKill_15();

    char **directories;
    setDirectoriesPaths(&directories, argv, argc);
    list(&directories, argc);
    free(directories);

    // while (1);
    return 0;
}

void stopKill_15() {
    struct sigaction sa;
    sa.sa_handler = kill_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGTERM, &sa, NULL) == -1) {
        printf("Hahahahaha");
        exit(EXIT_FAILURE); // exit program if setting handler failed
    }
}

void kill_handler() {
    printf("بس ياض");
    fflush(stdout);
}
