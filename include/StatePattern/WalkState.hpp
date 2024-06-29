#ifndef WALK_STATE_HPP
#define WALK_STATE_HPP

#include "State.hpp"

class WalkState : public State {
public:
    void handle(FSM& fsm) override;
    void handleInput(FSM& fsm, char input) override;
};

#endif // WALK_STATE_HPP