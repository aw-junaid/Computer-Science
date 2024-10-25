#include <iostream>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signal) {
    std::cout << "Received SIGINT signal." << std::endl;
    std::cout << "Blocking SIGTERM signal." << std::endl;
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGTERM);
    sigprocmask(SIG_BLOCK, &mask, NULL);
    sleep(5);
    std::cout << "Unblocking SIGTERM signal." << std::endl;
    sigprocmask(SIG_UNBLOCK, &mask, NULL);
}

int main() {
    signal(SIGINT, sigint_handler);
    while (1) {
        std::cout << "Waiting for signals..." << std::endl;
        sleep(1);
    }
    return 0;
}
