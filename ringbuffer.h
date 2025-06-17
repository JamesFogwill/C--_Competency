#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <iostream>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

class RingBuffer {

private:
    int BufferSize;
    int BufferMaxIdx = BufferSize -1;
    int BufferIdx;

    struct TimedReading
    {
        double altitude;
        string timestamp;
    };

    TimedReading *RingArray; // values buffer

    ofstream ReadingsDate;
    

public:

    bool BufferStartFlag = false;

    RingBuffer(int size);

    ~RingBuffer();

    bool Full;

    double Get(int idx);

    void Add(double value);

    void PrintBuffer();

    int CurrentSize();

    int GetCurrentIdx();

    string GetTimedReading(int idx);
    

};
#endif // RINGBUFFER_H