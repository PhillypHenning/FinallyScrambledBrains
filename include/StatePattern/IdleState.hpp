#ifndef IDLE_STATE_HPP
#define IDLE_STATE_HPP

#include "State.hpp"

class IdleState : public State {
public:
    void handle(FSM& fsm) override;
    void handleInput(FSM& fsm, char input) override;
};

#endif // IDLE_STATE_HPP