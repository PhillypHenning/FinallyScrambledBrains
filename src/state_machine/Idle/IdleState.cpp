#include "StatePattern/IdleState.hpp"
#include "StatePattern/FSM.hpp"
#include "StatePattern/WalkState.hpp"
#include <iostream>

void IdleState::handle(FSM& fsm) {
    // Idle state behavior
    std::cout << "Currently in Idle State.\n";
}

void IdleState::handleInput(FSM& fsm, char input) {
    if (input == 'w') {  // Simulate pressing the 'W' key to walk
        std::cout << "Transitioning to Walk State\n";
        fsm.setState(std::make_unique<WalkState>());
    }
}