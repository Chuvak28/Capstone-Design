#include <thread>
#include <wiringPi.h>

#include "state.cpp"
#include "../models/motor.cpp"
#include "../models/tracers/tracerLeft.cpp"
#include "../models/tracers/tracerRight.cpp"

class Bootstrap
{
public:
    static void init()
    {
        State *state = State::getInstance();

        Motor *motor = Motor::getInstance();
        TracerLeft *tracerLeft = TracerLeft::getInstance();
        TracerRight *tracerRight = TracerRight::getInstance();

        wiringPiSetup();
        motor->init();
        tracerLeft->init();
        tracerRight->init();

        std::thread tracerLeftThread = TracerLeft::getInstance()->initThread(state);
        std::thread tracerRightThread = TracerRight::getInstance()->initThread(state);
        
        state->init();

        tracerLeftThread.join();
        tracerRightThread.join();
    }
};