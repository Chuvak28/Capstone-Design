#include <thread>
#include "tracer.cpp"
#include "../../core/state.cpp"

#ifndef TRACER_LEFT_CPP
#define TRACER_LEFT_CPP

class TracerLeft : public Tracer
{
private:
    const int pin = LEFT_TRACER_PIN;

    static TracerLeft *instance;
    TracerLeft() {}

public:
    static TracerLeft *getInstance()
    {
        if (instance == nullptr)
            instance = new TracerLeft();

        return instance;
    }

    void init()
    {
        Tracer::init(this->pin);
    }

    short read()
    {
        return Tracer::read(pin);
    }

    void listen(State *state)
    {
        while (true)
        {
            state->setTracerLeft(this->read());
        }
    }

    std::thread initThread(State *state) {
        return std::thread(&TracerLeft::listen, this, state);
    }
};

TracerLeft *TracerLeft::instance = nullptr;

#endif