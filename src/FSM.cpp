#include "StatePattern/FSM.hpp"
#include "StatePattern/State.hpp"

FSM::FSM(std::unique_ptr<State> initialState)
    : currentState(std::move(initialState)) {}

void FSM::setState(std::unique_ptr<State> newState) {
    currentState = std::move(newState);
}

void FSM::update() {
    if (currentState) {
        currentState->handle(*this);
    }
}

void FSM::handleInput(char input) {
    if (currentState) {
        currentState->handleInput(*this, input);
    }
}