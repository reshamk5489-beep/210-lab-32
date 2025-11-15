#include "Car.h"
#include <deque>
using namespace std;

// Comment #1: Define a constant to initialize deque with number of cars.
const int NUMBER_OF_CARS_IN_LINE = 2;

void printAllCarDetails(deque<Car> &cars);
void printCarDetails(Car &car);
void simulateTollBooth(deque<Car> &cars);

int main()
{
    // Comment #2: Create a deque of cars.
    deque<Car> cars;

    cout << "Initial queue:" << endl;

    // Comment #3: Initialize deque with number of cars in line.
    for (int i = 0; i < NUMBER_OF_CARS_IN_LINE; i++)
    {
        // Comment #4: Create a random car object and add to the deque.
        Car car;
        cars.push_back(car);
    }

    printAllCarDetails(cars);
    simulateTollBooth(cars);

    return 0;
}

void printAllCarDetails(deque<Car> &cars)
{
    // Comment #6: Iterate over cars in the deque and print the cars' details.
    for (auto &car : cars) 
    {
        cout << "\t";    
        printCarDetails(car);
    }

    cout << endl;
}

void simulateTollBooth(deque<Car> &cars)
{
    int i = 1;

    while (!cars.empty())
    {
        cout << "Time: " << i << " Operation: ";
        int r = rand() % 100 + 1;   // gives 1–100

        if (r <= 55) 
        {
            Car car = cars.front();
            cars.pop_front();
            cout << "Car paid: ";
            printCarDetails(car);

        } 
        else 
        {
            Car car;
            cars.push_back(car);
            cout << "Joined lane: ";
            printCarDetails(car);
        }

        printAllCarDetails(cars);
        ++i;
    }
}

void printCarDetails(Car &car)
{
    cout << "[" << car.getYear() << " " << car.getMake() << " (" 
    << car.getTransponder() << ")]" << endl;
}
