#include "Car.h"
#include <deque>
using namespace std;

const int NUMBER_OF_CARS_IN_LINE = 2;

void print(deque<Car> cars);

int main()
{
    deque<Car> cars;
    Car car1;
    Car car2;

    cars.push_back(car1);
    cars.push_back(car2);

    print(cars);

    return 0;
}

void print(deque<Car> cars)
{
    for (auto &car : cars) 
    {
        cout << "[" << car.getYear() << " " << car.getMake() << " (" 
            << car.getTransponder() << ")]" << endl;
    }
}