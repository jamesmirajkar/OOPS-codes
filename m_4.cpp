/*Imagine you are building a simple inventory management system for a store. Each product in the 
store has a unique identifier, a name, a price, and a quantity in stock. You need to create a 
Product class with inline member functions for calculating the total cost of a product 
(price * quantity) and for restocking the product (increasing the quantity in stock).*/

#include <iostream>
#include <string>

class Product {
private:
    int id;
    std::string name;
    double price;
    int quantity;

public:
    Product(int productId, const std::string& productName, double productPrice, int productQuantity)
        : id(productId), name(productName), price(productPrice), quantity(productQuantity) {}

    // Inline function to calculate the total cost of the product
    inline double calculateTotalCost() {
        return price * quantity;
    }

    // Inline function to restock the product
    inline void restock(int additionalQuantity) {
        if (additionalQuantity > 0) {
            quantity += additionalQuantity;
        }
    }

    void displayProductInfo() {
        std::cout << "Product ID: " << id << std::endl;
        std::cout << "Product Name: " << name << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Quantity in Stock: " << quantity << std::endl;
        std::cout << "Total Cost: $" << calculateTotalCost() << std::endl;
    }
};

int main() {
    Product laptop(1, "Laptop", 999.99, 10);
    Product smartphone(2, "Smartphone", 499.99, 15);

    laptop.displayProductInfo();
    smartphone.displayProductInfo();

    laptop.restock(5);
    smartphone.restock(10);

    std::cout << "After restocking:" << std::endl;
    laptop.displayProductInfo();
    smartphone.displayProductInfo();

    return 0;
}
