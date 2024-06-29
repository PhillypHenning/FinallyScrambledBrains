#include <Godot.hpp>
#include <Node.hpp>
#include "StatePattern/FSM.hpp"
#include "StatePattern/IdleState.hpp"
#include "StatePattern/WalkState.hpp"

using namespace godot;

class FSMController : public Node {
    GODOT_CLASS(FSMController, Node)

private:
    std::unique_ptr<FSM> fsm;

public:
    static void _register_methods() {
        register_method("_init", &FSMController::_init);
        register_method("on_idle_button_pressed", &FSMController::on_idle_button_pressed);
        register_method("on_walk_button_pressed", &FSMController::on_walk_button_pressed);
    }

    void _init() {
        // Initialize FSM with IdleState
        fsm = std::make_unique<FSM>(std::make_unique<IdleState>());
    }

    void on_idle_button_pressed() {
        fsm->handleInput('i');
    }

    void on_walk_button_pressed() {
        fsm->handleInput('w');
    }
};

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    Godot::nativescript_init(handle);

    register_class<FSMController>();
}