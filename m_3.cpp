/*Imagine you are developing a graphics application, and you need to calculate the area and 
circumference of a circle based on its radius. You want to create a utility class, 
CircleCalculator, that can perform these calculations.*/

#include <iostream>
#include <cmath>

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getRadius() const {
        return radius;
    }
};

class CircleCalculator {
public:
    static double calculateArea(const Circle& circle) {
        double radius = circle.getRadius();
        return M_PI * radius * radius; // Area = π * r^2
    }

    static double calculateCircumference(const Circle& circle) {
        double radius = circle.getRadius();
        return 2 * M_PI * radius; // Circumference = 2πr
    }
};

int main() {
    const Circle myCircle(5.0);

    double r = myCircle.getRadius();
    std::cout << "Radius: " << r << std::endl;

    double area = CircleCalculator::calculateArea(myCircle);
    double circumference = CircleCalculator::calculateCircumference(myCircle);

    std::cout << "Area of the circle: " << area << std::endl;
    std::cout << "Circumference of the circle: " << circumference << std::endl;

    return 0;
}
