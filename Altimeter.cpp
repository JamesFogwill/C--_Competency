#include "Altimeter.h"

// constructor, initialises private memebr variables of the class
FilterSubmarineAltimeter::FilterSubmarineAltimeter(double MaxAltitude, int BufferSize)
    : MaxAltitude(MaxAltitude), readings(BufferSize){}

void FilterSubmarineAltimeter::AddReading(double Reading){

    // filters results before adding them
    if (CheckNegative(Reading))
    {
        Reading = ClipAltitudeFilter(Reading);
        Reading = SMAFilter(Reading, SMAHistory);
        readings.Add(Reading);
    }
}

bool FilterSubmarineAltimeter::CheckNegative(double Reading){
    // negative altitudes are not allowed
    if(Reading < 0){
        cout<<"Negative Altitudes are not allowed"<<endl;
        return false;
    }
    else{
        return true;
    }
}

double FilterSubmarineAltimeter::ClipAltitudeFilter(double Altitude)
{
    // values above 1000 (variable) not allowed
    if(Altitude > MaxAltitude)
    {
        return Altitude = MaxAltitude; // clips values over max to the max
    } 
    else
    {
        return Altitude;
    }
}

double FilterSubmarineAltimeter::SMAFilter(double Altitude, int SMASize)
{
    // take the last n number of readings in the buffer
    // get the SMA of the n number of readings
    // this is dynamic - gets SMA of buffer even when not full. SMA will always be buffer size.

    double SMA = Altitude; // first value in the SMA calculation will always be the new value
    int ArraySize = readings.CurrentSize(); 

    if (ArraySize >SMASize) 
    {
        ArraySize = SMASize; // caps the ArraySize variable to the maximum SMA history
    }
    else if (readings.BufferStartFlag == false)
    {
        readings.BufferStartFlag = true; // runs for the first buffer reading added
        return SMA;
    }
    

    int CurrentIdx = readings.GetCurrentIdx(); 
    int BufferUsed = min(readings.CurrentSize(), SMASize - 1); // gets whichever is smaller , buffer size of SMA history

    // for loop designed to be able to calculate SMA
    // works for when buffer contains less values than the history requires too.
    for (int i = 1; i <= BufferUsed; ++i) {
        SMA += readings.Get(CurrentIdx - i);  // wraparound handled in Get()
    }

    SMA /= (BufferUsed + 1); // calculate the SMA
    
    cout<<"sma is: "<<SMA<<endl;

    return SMA;
}

double FilterSubmarineAltimeter::GetAverage()
{
    double Average = 0;

    for(int idx = 0; idx < readings.CurrentSize(); ++idx)
    {
        Average += readings.Get(idx);
    }
    Average = Average/(readings.CurrentSize());
    return Average;
}

void FilterSubmarineAltimeter::PrintReadings()
{
    readings.PrintBuffer(); // prints all values in the buffer to the terminal
}

void FilterSubmarineAltimeter::LogBuffer()
{
    // creates file every time buffer is dumped
    // increments file name by 1 every time
    string filename = "DumpBuffer" + to_string(DumpCount) + ".csv";
    ofstream DumpBuffer(filename);

    // loops through whole buffer

    DumpBuffer << "Altitude,Timestamp\n"; // headings for csv

    for(int idx = 0; idx < readings.CurrentSize(); ++idx)
    {
        double Data = readings.Get(idx);
        string Time = readings.GetTimedReading(idx);

        DumpBuffer <<  Data <<",\""<<Time<<"\"\n"; //  adds date and reading to the csv
    }
    DumpCount++; // increments for the file name
    
}