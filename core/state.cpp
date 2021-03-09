#include <stdio.h>
#include "../helpers/constants.h"
#include "../models/motor.cpp"

#ifndef STATE_CPP
#define STATE_CPP

class State
{
private:
    static State *instance;
    State() {}

    short tracerLeft = TRACER_RESTRICTED;
    short tracerRight = TRACER_RESTRICTED;

public:
    static State *getInstance()
    {
        if (instance == nullptr)
            instance = new State();

        return instance;
    }

    void setTracerLeft(short value)
    {
        this->tracerLeft = value;
    }
    
    void setTracerRight(short value)
    {
        this->tracerRight = value;
    }

    void init()
    {
        Motor *motor = Motor::getInstance();

        while(true){
            if(this->tracerLeft == TRACER_RESTRICTED && this->tracerRight == TRACER_RESTRICTED)
                motor->stop();
            else if(this->tracerLeft == TRACER_RESTRICTED)
                motor->left(0.6);
            else if(this->tracerRight == TRACER_RESTRICTED)
                motor->right(0.6);
            else
                motor->forward(0.6);
        }
    }
};

State *State::instance = nullptr;

#endif