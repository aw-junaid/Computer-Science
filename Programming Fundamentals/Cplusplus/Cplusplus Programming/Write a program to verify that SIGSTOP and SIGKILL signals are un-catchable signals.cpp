#include <iostream>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    std::cout << "Caught signal: " << signum << std::endl;
}

int main() {
    // Catch SIGSTOP and SIGKILL signals
    if (signal(SIGSTOP, signal_handler) == SIG_ERR) {
        std::cout << "Unable to catch SIGSTOP signal" << std::endl;
    }
    if (signal(SIGKILL, signal_handler) == SIG_ERR) {
        std::cout << "Unable to catch SIGKILL signal" << std::endl;
    }

    // Wait for signals
    while (true) {
        std::cout << "Waiting for signals..." << std::endl;
        sleep(1);
    }

    return 0;
}
