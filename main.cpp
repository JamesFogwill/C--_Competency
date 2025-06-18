#include <iostream>
#include "Altimeter.h"
#include "ringbuffer.h"

using namespace std;

double MaxAltitude = 1000;
int BufferSize = 10;

FilterSubmarineAltimeter AltimeterFilterClassInst(MaxAltitude, BufferSize); // create altimeter object

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

    AltimeterFilterClassInst.LogBuffer(); // empties buffer into csv file 

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