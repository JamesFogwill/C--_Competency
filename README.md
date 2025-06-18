# Altimeter Compitancy test

This project simulates an altimeter with a ring buffer for storing readings and calculating a Simple Moving Average (SMA).

## Features

- Ring buffer for efficient storage
- SMA calculation over recent altitude readings
- Unit tests written with Catch2

## Getting Started

### Building the Project
1. Ensure you have a C++ compiler and Catch2 set up.
2. Build using tasks.json with MVSC

### Running Tests
Run the test executable instead of `main.cpp`.
Make sure `#define CATCH_CONFIG_MAIN` at the top of `AltimeterTests.cpp`
Make sure to add `AltimeterTests.cpp`, `catch_amalgamated.cpp` to the tasks.json file in the args section.
Make sure to remove `main.cpp` from the tasks.json file in the args section.
Without completing these steps you will not be able to run the unit tests.

Reverse all of these steps to get main.cpp to work again.

## Comment on possible improvements

Different Average could of been used instead of SMA. Exponential moving average weight recent data more
so if the altimeter is for live reading this could be more efficient and give more meaningful results.
SMA is also sensitive to outliers, especially when using a smaller SMA history to calculate the SMA.

Implementation makes use of OOP and defensive coding with good unit testing of individual functions
with differing test cases.
Buffer has its own class and it configurable in size.
