#include <iostream>
#include <unistd.h>
#include <termios.h>
#include "StatePattern/FSM.hpp"
#include "StatePattern/IdleState.hpp"

// Function to set terminal in raw mode
void set_raw_mode(bool enable) {
    static struct termios oldt, newt;
    if (enable) {
        // Get current terminal attributes
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        // Modify terminal attributes for raw input
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        // Restore original terminal attributes
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

// Function to read a single character from stdin
char getch() {
    char buf = 0;
    if (read(STDIN_FILENO, &buf, 1) < 0) {
        perror("read");
    }
    return buf;
}

int main() {
    auto initialState = std::make_unique<IdleState>();
    FSM fsm(std::move(initialState));

    std::cout << "Press 'w' to transition to Walk State and 'i' to transition to Idle State.\n";
    std::cout << "Press 'q' to quit.\n";

    set_raw_mode(true);  // Enable raw mode
    char input;
    while (true) {
        fsm.update();
        input = getch();  // Capture key press without waiting for enter
        if (input == 'q') {
            break;  // Exit the loop when 'q' is pressed
        }
        fsm.handleInput(input);
    }
    set_raw_mode(false);  // Disable raw mode

    return 0;
}