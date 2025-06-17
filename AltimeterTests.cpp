#include "AltimeterTests.h"

using Catch::Approx;

TEST_CASE( "Altimeter GetAverage returns correct average", "[GetAverage]" ) {


    SECTION("Average with the first 5 additions to the buffer"){

        FilterSubmarineAltimeter altimeter(1000.0, 10);

        altimeter.AddReading(100);
        altimeter.AddReading(200);
        altimeter.AddReading(300);
        altimeter.AddReading(400);
        altimeter.AddReading(500);
        
        double avg = altimeter.GetAverage();

        cout<<avg<<endl;

        REQUIRE(avg == Approx(174));
    }
    SECTION("Average of 7 values when SMA history is less than (5)"){

        FilterSubmarineAltimeter altimeter(1000.0, 10);

        altimeter.AddReading(100);
        altimeter.AddReading(200);
        altimeter.AddReading(300);
        altimeter.AddReading(400);
        altimeter.AddReading(500);
        altimeter.AddReading(100);
        altimeter.AddReading(100);
        
        double avg = altimeter.GetAverage();

        cout<<avg<<endl;

        REQUIRE(avg == Approx(175).margin(0.5));
    }
    SECTION("Correct average after full buffer and wrapping"){

        FilterSubmarineAltimeter altimeter(1000.0, 10);

        altimeter.AddReading(100);
        altimeter.AddReading(100);
        altimeter.AddReading(100);
        altimeter.AddReading(100);
        altimeter.AddReading(100);
        altimeter.AddReading(100);
        altimeter.AddReading(100);
        altimeter.AddReading(100);
        altimeter.AddReading(100);
        altimeter.AddReading(100); //  fills the buffer up full with 100s
        altimeter.AddReading(200); // differing values to check it has worked makes idx 0 = 120
        
        double avg = altimeter.GetAverage(); // avg of buffer with 120 idx 0 and 100 everywhere else

        cout<<avg<<endl;

        REQUIRE(avg == Approx(102));
    }

}