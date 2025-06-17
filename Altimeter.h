// class for a submarine altimeter
#ifndef ALTIMETER_H
#define ALTIMETER_H

#include <iostream>
#include "ringbuffer.h"
#include <string>

using namespace std;

class FilterSubmarineAltimeter {

private:

    double MaxAltitude;

    bool CheckNegative(double Reading);
    
    double ClipAltitudeFilter(double Reading);

    double SMAFilter(double Reading, int SMAHistory);

    int SMAHistory = 5;

    RingBuffer readings;

    int DumpCount = 0;

protected:


public:

    FilterSubmarineAltimeter(double MaxAltitude, int BufferSize);

    void AddReading(double altitude);

    double GetAverage();

    void PrintReadings();  

    void LogBuffer();
};

#endif // ALTIMETER_H