#include "ringbuffer.h"

// constructor, initialises private member variables
RingBuffer::RingBuffer(int size): BufferSize(size), BufferIdx(0), Full(false), ReadingsDate("Readings.csv"){
    RingArray = new TimedReading[size];
    ReadingsDate << "Altitude,Timestamp\n"; // headings for csv
}

// deconstructor frees up memory and closes csv file
RingBuffer::~RingBuffer(){
    delete[] RingArray;
    ReadingsDate.close();
}

void RingBuffer::Add(double value){


    TimedReading reading;

    // gets current time and adds to timestamp of struct. adds value too
    const auto TimeNow = system_clock::now();
    time_t test= system_clock::to_time_t(TimeNow);
    string timestamp = ctime(&test);
    timestamp.pop_back(); // strip out the newline character here
    
    
    reading.timestamp = timestamp;
    reading.altitude = value;

    // adds struct to the buffer and the csv file
    RingArray[BufferIdx] = reading;
    ReadingsDate << reading.altitude<< ",\"" << reading.timestamp<< "\"\n";

    cout<<"added: "<<RingArray[BufferIdx].altitude<<" at buffer idx: "<<BufferIdx<<endl;
    
    // wrap around for when buffer reaches max capacity
    if (BufferIdx == (BufferMaxIdx)){
        BufferIdx = 0;
        Full = true;
    }
    else
    {
        BufferIdx++;
    }

}

int RingBuffer::CurrentSize(){

    if(Full)
    {
        return (BufferSize);
    }
    else
    {
        return (BufferIdx);
    }
}


double RingBuffer::Get(int idx)
{   
    // If recieving negative readings, wrap around to the other end of the buffer
    if(idx < 0)
    {
        idx = (idx % BufferSize + BufferSize) % BufferSize; //  ensures that negative values from the outer SMA get wrapped around to the other end of the buffer.
        
    }
    return RingArray[idx].altitude;
}

string RingBuffer::GetTimedReading(int idx)
{
    // used to get the timestamp of a particular index in the buffer
    if(idx < 0)
    {
        idx = (idx % BufferSize + BufferSize) % BufferSize; //  ensures that negative values from the outer SMA get circled back around to the other end of the buffer.
        
    }
    return RingArray[idx].timestamp;
}

void RingBuffer::PrintBuffer()
{
    
    cout<<"the current size is: "<<CurrentSize()<<endl;
    for(int idx = 0; idx < CurrentSize(); idx++)
    {
        cout<<"Buffer Idx: "<<idx<<" Contains: "<<RingArray[idx].altitude<<" at time: "<<RingArray[idx].timestamp<<endl;
    }
}

int RingBuffer::GetCurrentIdx()
{
    return BufferIdx;
}
