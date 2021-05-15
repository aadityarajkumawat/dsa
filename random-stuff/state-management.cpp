#include <iostream>
using namespace std;

template <typename T>
struct StateData {
    T current_state;
    T previous_state;
    T initial_state;
};

template <typename T>
class State {
private:
    StateData<T> state_data;
public:
    State(T state) {
        this->state_data.initial_state = state;
        this->state_data.current_state = state;
        this->state_data.previous_state = state;
    }

    void setState(T newState) {
        this->state_data.previous_state = this->state_data.current_state;
        this->state_data.current_state = newState;
        return;
    }

    T getState() {
        return this->state_data.current_state;
    }

};

int main() {
    State<string>* nameState = new State<string>("Aditya Raj");

    cout << nameState->getState() << endl;

    nameState->setState("Dan Abarnov");

    cout << nameState->getState() << endl;

    return 0;
}
