#ifndef TIMER_H
#define TIMER_H
#include <chrono>

class Timer
{
public:
    void start() {
        this->Start = std::chrono::high_resolution_clock::now();
        this->isRunning = true;
    }

    void stop() {
        this->End = std::chrono::high_resolution_clock::now();
        this->isRunning = false;
    }

    void restart() {
        this->Start = std::chrono::high_resolution_clock::now();
    }

    double elapsedns() {
        
        std::chrono::steady_clock::time_point end;

        if (this->isRunning) {
            end = std::chrono::high_resolution_clock::now();
        }
        else {
            end = this->End;
        }

        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->Start).count();

    }

    double elapsedus() {

        std::chrono::steady_clock::time_point end;

        if (this->isRunning) {
            end = std::chrono::high_resolution_clock::now();
        }
        else {
            end = this->End;
        }

        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->Start).count() / 1000.0;
    }

    double elapsedms() {

        std::chrono::steady_clock::time_point end;

        if (this->isRunning) {
            end = std::chrono::high_resolution_clock::now();
        }
        else {
            end = this->End;
        }

        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->Start).count() / 1000000.0;
    }

    double elapseds() {

        std::chrono::steady_clock::time_point end;

        if (this->isRunning) {
            end = std::chrono::high_resolution_clock::now();
        }
        else {
            end = this->End;
        }

        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->Start).count() / 1000000000.0;
    }

private:
    std::chrono::steady_clock::time_point Start;
    std::chrono::steady_clock::time_point End;
    bool isRunning = false;
};

#endif
