#include <thread>
#include "tracer.cpp"
#include "../../core/state.cpp"

#ifndef TRACER_RIGHT_CPP
#define TRACER_RIGHT_CPP

class TracerRight : public Tracer
{
private:
    const short pin = RIGHT_TRACER_PIN;

    static TracerRight *instance;
    TracerRight() {}

public:
    static TracerRight *getInstance()
    {
        if (instance == nullptr)
            instance = new TracerRight();

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
            state->setTracerRight(this->read());
        }
    }

    std::thread initThread(State *state) {
        return std::thread(&TracerRight::listen, this, state);
    }
};

TracerRight *TracerRight::instance = nullptr;

#endif