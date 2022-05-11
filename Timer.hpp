#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer
{
    typedef std::chrono::high_resolution_clock stdyC;
    typedef stdyC::time_point sPt;
public:
    void start() {
        this->Start = stdyC::now();
        this->isRunning = true;
    }

    void stop() {
        this->End = stdyC::now();
        this->isRunning = false;
    }

    void restart() {
        this->Start = stdyC::now();
    }

    double elapsedns() {
        
        sPt end;

        if (this->isRunning) {
            end = stdyC::now();
        }
        else {
            end = this->End;
        }

        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->Start).count();

    }

    double elapsedus() {

        sPt end;

        if (this->isRunning) {
            end = stdyC::now();
        }
        else {
            end = this->End;
        }

        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->Start).count() * 0.001;
    }

    double elapsedms() {

        sPt end;

        if (this->isRunning) {
            end = stdyC::now();
        }
        else {
            end = this->End;
        }

        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->Start).count() * 0.000001;
    }

    double elapseds() {

        sPt end;

        if (this->isRunning) {
            end = stdyC::now();
        }
        else {
            end = this->End;
        }

        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->Start).count() * 0.000000001;
    }

private:
    sPt Start;
    sPt End;
    bool isRunning = false;
};

#endif
