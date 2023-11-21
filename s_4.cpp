/*Suppose you are building a software system to model different types of vehicles. You have two 
base classes: Car and Bicycle, each of which contains a member variable called speed. Now, you want
 to create a class HybridVehicle that inherits from both Car and Bicycle and you need to access the
  speed variables of both base classes and differentiate between them.*/

  #include <iostream>

// Base class Car
class Car {
public:
    int speed; // Speed for cars

    Car(int s) : speed(s) {}

    void displaySpeed() {
        std::cout << "Car Speed: " << speed << " km/h" << std::endl;
    }
};

// Base class Bicycle
class Bicycle {
public:
    int speed; // Speed for bicycles

    Bicycle(int s) : speed(s) {}

    void displaySpeed() {
        std::cout << "Bicycle Speed: " << speed << " km/h" << std::endl;
    }
};

// Derived class HybridVehicle inheriting from both Car and Bicycle
class HybridVehicle : public Car, public Bicycle {
public:
    HybridVehicle(int carSpeed, int bicycleSpeed)
        : Car(carSpeed), Bicycle(bicycleSpeed) {}

    void displayBothSpeeds() {
        // Accessing the speed variables from both base classes using scope resolution operator
        std::cout << "Car Speed: " << Car::speed << " km/h" << std::endl;
        std::cout << "Bicycle Speed: " << Bicycle::speed << " km/h" << std::endl;
    }
};

int main() {
    // Create a HybridVehicle object with car and bicycle speeds
    HybridVehicle hybrid(65, 20);

    // Display the speed of each base class
    hybrid.Car::displaySpeed();
    hybrid.Bicycle::displaySpeed();

    // Display the speed of both base classes in the HybridVehicle
    hybrid.displayBothSpeeds();

    return 0;
}
