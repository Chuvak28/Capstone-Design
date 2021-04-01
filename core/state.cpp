#include <stdio.h>
#include "../helpers/constants.h"
#include "../models/motor.cpp"

#ifndef STATE_CPP
#define STATE_CPP

class State
{
private:
    short tracerLeft = TRACER_RESTRICTED;
    short tracerRight = TRACER_RESTRICTED;

    short irSensorLeft = TRACER_RESTRICTED;
    short irSensorRight = TRACER_RESTRICTED;

    int ultraSonic = 40;

public:
    void setTracerLeft(short value)
    {
        this->tracerLeft = value;
    }

    void setTracerRight(short value)
    {
        this->tracerRight = value;
    }

    void setIRSensorLeft(short value)
    {
        this->irSensorLeft = value;
    }

    void setIRSensorRight(short value)
    {
        this->irSensorRight = value;
    }

    void setUltraSonic(int value)
    {
        this->ultraSonic = value;
    }

    void init()
    {
        while (true)
        {
            if (this->ultraSonic < 30 || (this->irSensorLeft == TRACER_RESTRICTED && this->irSensorRight == TRACER_RESTRICTED))
                motor->stop();
            else if (this->tracerLeft == TRACER_RESTRICTED)
                motor->left(0.7);
            else if (this->tracerRight == TRACER_RESTRICTED)
                motor->right(0.7);
            else
                motor->forward(0.7);
        }
    }
};

State *state = new State();

#endif