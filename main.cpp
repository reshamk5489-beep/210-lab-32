#include "Car.h"
#include <deque>
#include <array>
using namespace std;

// Comment #1: Define a constant to initialize deque with number of cars.
const int NUMBER_OF_CARS_IN_LINE = 2;
const int NUMBER_OF_LANES = 4;
const int NUMBER_OF_TIME_PERIODS = 20;
const int PROBABILITY_OF_CAR_PAYING_AND_LEAVING = 46;
const int PROBABILITY_OF_CAR_JOINING = 39;

void printAllCarDetails(deque<Car> &cars);
void printCarDetails(Car &car);
void simulateTollBooth(array<deque<Car>, NUMBER_OF_LANES> &lanes);

int main()
{
    // Comment #2: Create an array of 4 lanes with each lane being a deque of car.
    array<deque<Car>, NUMBER_OF_LANES> lanes;

    cout << "Initial queue:" << endl;

    // Comment #3: Initialize each lane with 2 cars.
    for (int laneNum = 0; laneNum < lanes.size(); laneNum++ )
    {
        cout << "Lane " << laneNum + 1 << ":" << endl;
        // Comment #4: Initialize deque with number of cars in line.
        for (int i = 0; i < NUMBER_OF_CARS_IN_LINE; i++)
        {
            // Comment #5: Create a random car object and add to the deque.
            Car car;

            // Comment #6: Adding cars to each lane.
            lanes[laneNum].push_back(car); 
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
        // Comment #7: Iterate over cars in the deque and print the cars' details.
        for (auto &car : cars) 
        {
            cout << "        ";    
            printCarDetails(car);
        }
    }
}

void simulateTollBooth(array<deque<Car>, NUMBER_OF_LANES> &lanes)
{
    // Comment #8: Run the simulation for 20 time periods.
    for (int i = 1; i <= NUMBER_OF_TIME_PERIODS; ++i)
    {
        cout << endl << "Time: " << i << endl;

        // Comment #9: Iterate over each lane.
        for (int laneNum = 0; laneNum < lanes.size(); laneNum++ )
        {
            deque<Car> cars = lanes[laneNum];
           
            cout << "Lane: " << laneNum + 1;
            int r = rand() % 100 + 1;   // Comment #10: Generate random number between 1 and 100.

            if (r <= PROBABILITY_OF_CAR_PAYING_AND_LEAVING) // Comment #11: If random number is less than or equal to 46 means 46% 
                                                            // probability that the car pays toll and leaves.
            {
                // Comment #12: Read car from the head before deleting it.
                Car car = cars.front();
                cars.pop_front();
                cout << " Paid: ";
                printCarDetails(car);

            } 
            else if (r <= PROBABILITY_OF_CAR_PAYING_AND_LEAVING + PROBABILITY_OF_CAR_JOINING)
                // Comment #13: If random number is less than or equal to 39 means 39% 
                // probability that the car joins the line for the toll booth.
            {
                Car car;
                cars.push_back(car);
                cout << " Joined: ";
                printCarDetails(car);
            }
            else
            {
                // Comment #14: 15% probabillity switching lanes.
                int randomLaneNum = rand() % 4; // Comment #15: Random number between 0 to 3.
                if (laneNum == randomLaneNum)
                {
                    if (laneNum == 0)
                    {
                        randomLaneNum++;
                    }
                    else
                    {
                        randomLaneNum--;
                    }
                }

                Car car = cars.back();
                // Comment #16: Switching a car from laneNum to randomLaneNum.
                lanes[randomLaneNum].push_back(car); 
                cars.pop_front();

                cout << " Switched: ";
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
    // Comment #17: Printing a single car's details.
    cout << "[" << car.getYear() << " " << car.getMake() << " (" 
    << car.getTransponder() << ")]" << endl;
}