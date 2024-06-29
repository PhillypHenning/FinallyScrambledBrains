#ifndef STATE_HPP
#define STATE_HPP

class FSM;

class State {
public:
    virtual ~State() = default;
    virtual void handle(FSM& fsm) = 0;
    virtual void handleInput(FSM& fsm, char input) = 0;
};

#endif // STATE_HPP