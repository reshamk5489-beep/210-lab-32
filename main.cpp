#include "Car.h"
#include <deque>
using namespace std;

// Comment #1: Define a constant to initialize deque with number of cars.
const int NUMBER_OF_CARS_IN_LINE = 2;

void printCarDetails(deque<Car> &cars);

int main()
{
    // Comment #2: Create a deque of cars.
    deque<Car> cars;

    // Comment #3: Initialize deque with number of cars in line.
    for (int i = 0; i < NUMBER_OF_CARS_IN_LINE; i++)
    {
        // Comment #4: Create a random car object and add to the deque.
        Car car;
        cars.push_back(car);
    }

    printCarDetails(cars);

    return 0;
}

void printCarDetails(deque<Car> &cars)
{
    // Comment #5: Iterate over cars in the deque and print the cars' details.
    for (auto &car : cars) 
    {
        cout << "[" << car.getYear() << " " << car.getMake() << " (" 
            << car.getTransponder() << ")]" << endl;
    }
}