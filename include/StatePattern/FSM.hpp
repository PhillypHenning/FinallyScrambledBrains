#ifndef FSM_HPP
#define FSM_HPP

#include <memory>

class State;

class FSM {
public:
    FSM(std::unique_ptr<State> initialState);
    void setState(std::unique_ptr<State> newState);
    void update();
    void handleInput(char input);

private:
    std::unique_ptr<State> currentState;
};

#endif // FSM_HPP