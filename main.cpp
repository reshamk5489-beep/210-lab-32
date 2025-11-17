#include "Car.h"
#include <deque>
#include <array>
using namespace std;

// Comment #1: Define a constant to initialize deque with number of cars.
const int NUMBER_OF_CARS_IN_LINE = 2;
const int NUMBER_OF_LANES = 4;

void printAllCarDetails(deque<Car> &cars);
void printCarDetails(Car &car);
void simulateTollBooth(array<deque<Car>, NUMBER_OF_LANES> &lanes);

int main()
{
    // Comment #2: Create an array of 4 lanes with each lane being a deque of car.
    array<deque<Car>, NUMBER_OF_LANES> lanes;

    cout << "Initial queue:" << endl;

    // Initialize each lane with 2 cars.
    for (int laneNum = 0; laneNum < lanes.size(); laneNum++ )
    {
        cout << "Lane " << laneNum + 1 << ":" << endl;
        // Comment #3: Initialize deque with number of cars in line.
        for (int i = 0; i < NUMBER_OF_CARS_IN_LINE; i++)
        {
            // Comment #4: Create a random car object and add to the deque.
            Car car;
            lanes[laneNum].push_back(car); // Adding cars to each lane
        }

        printAllCarDetails(lanes[laneNum]);
    }

    simulateTollBooth(lanes);

    return 0;
}

void printAllCarDetails(deque<Car> &cars)
{
    if (cars.empty())
    {
        cout << "    Empty";
    }
    else
    {
        // Comment #5: Iterate over cars in the deque and print the cars' details.
        for (auto &car : cars) 
        {
            cout << "        ";    
            printCarDetails(car);
        }
    }

    // cout << endl;
}

void simulateTollBooth(array<deque<Car>, NUMBER_OF_LANES> &lanes)
{
    for (int i = 1; i < 20; ++i)
    {
        cout << endl << "Time: " << i << endl;
        for (int laneNum = 0; laneNum < lanes.size(); laneNum++ )
        {
            deque<Car> cars = lanes[laneNum];
            // Comment #6: Iterate over deque of cars until the deque is empty.
           
            cout << "Lane: " << laneNum + 1;
            int r = rand() % 100 + 1;   // Comment #7: Generate random number between 1 and 100.

            if (r <= 55) // Comment #8: If random number is less than or equal to 55 means 55% 
                         // probability that the car pays toll and leaves.
            {
                // Comment #9: Read car from the head before deleting it.
                Car car = cars.front();
                cars.pop_front();
                cout << " Paid: ";
                printCarDetails(car);

            } 
            else // Comment #10: If random number is less than or equal to 45 means 45% 
                 // probability that the car joins the line for the toll booth.
            {
                Car car;
                cars.push_back(car);
                cout << " Joined: ";
                printCarDetails(car);
            }
        }

        for (int laneNum = 0; laneNum < lanes.size(); laneNum++ )
        {
            deque<Car> cars = lanes[laneNum];
            cout << "Lane " << laneNum + 1 << " Queue:" << endl;
            printAllCarDetails(cars);
        }
    }

    cout << endl;
}

void printCarDetails(Car &car)
{
    // Comment #11: Printing a single car's details.
    cout << "[" << car.getYear() << " " << car.getMake() << " (" 
    << car.getTransponder() << ")]" << endl;
}

// branch from lab 32