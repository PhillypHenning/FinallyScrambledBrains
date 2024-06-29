#include "StatePattern/WalkState.hpp"
#include "StatePattern/FSM.hpp"
#include "StatePattern/IdleState.hpp"
#include <iostream>

void WalkState::handle(FSM& fsm) {
    // Walk state behavior
    std::cout << "Currently in Walk State.\n";
}

void WalkState::handleInput(FSM& fsm, char input) {
    if (input == 'i') {  // Simulate pressing the 'I' key to go idle
        std::cout << "Transitioning to Idle State\n";
        fsm.setState(std::make_unique<IdleState>());
    }
}