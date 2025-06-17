#include <iostream>
#include "Altimeter.h"
#include "ringbuffer.h"

using namespace std;

double MaxAlt = 1000;
int BufSize = 10;

FilterSubmarineAltimeter AltimeterFilterClassInst(MaxAlt, BufSize);

int main() {

	AltimeterFilterClassInst.AddReading(345);
    AltimeterFilterClassInst.AddReading(-500);
    AltimeterFilterClassInst.AddReading(1233);
    AltimeterFilterClassInst.AddReading(343);
    
    float Avergae = AltimeterFilterClassInst.GetAverage();
    
    AltimeterFilterClassInst.AddReading(345);
    AltimeterFilterClassInst.AddReading(500);
    AltimeterFilterClassInst.AddReading(1233);
    AltimeterFilterClassInst.AddReading(743);
    AltimeterFilterClassInst.AddReading(756);
    AltimeterFilterClassInst.AddReading(8936);
    AltimeterFilterClassInst.AddReading(134);
    AltimeterFilterClassInst.AddReading(445);

    Avergae = AltimeterFilterClassInst.GetAverage();
    AltimeterFilterClassInst.PrintReadings();

    AltimeterFilterClassInst.LogBuffer();

    AltimeterFilterClassInst.AddReading(1);
    AltimeterFilterClassInst.AddReading(22);
    AltimeterFilterClassInst.AddReading(333);
    AltimeterFilterClassInst.AddReading(4444);
    AltimeterFilterClassInst.AddReading(55);
    AltimeterFilterClassInst.AddReading(6);
    AltimeterFilterClassInst.AddReading(77);
    AltimeterFilterClassInst.AddReading(888);

    AltimeterFilterClassInst.LogBuffer();

    
	return 0;
}