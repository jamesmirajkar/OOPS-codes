/*Create a C++ program that defines a "Car" class with attributes for brand, model, and year. The 
program should create two car objects, one for a Toyota Camry (2029) and the other for a Honda 
Civic (2019). Implement methods to start and stop the car's engine and display messages indicating 
the actions performed and the car's details.*/

#include <iostream>


class Car {
public:

    std::string brand;
    std::string model;
    int year;


    void startEngine() {
        std::cout << "Engine started for " << brand << " " << model << std::endl;
    }

    void stopEngine() {
        std::cout << "Engine stopped for " << brand << " " << model << std::endl;
    }
};

int main() {

    Car myCar;
    myCar.brand = "Toyota";
    myCar.model = "Camry";
    myCar.year = 2020;

    Car yourCar;
    yourCar.brand = "Honda";
    yourCar.model = "Civic";
    yourCar.year = 2019;


    myCar.startEngine();
    yourCar.startEngine();

    myCar.stopEngine();
    yourCar.stopEngine();

    return 0;
}
