/*
imagine you are developing a program to calculate the total cost of items in a shopping cart. You 
have a global variable called total_cost, and within a function that calculates the cost of a specific 
item, you also have a local variable with the same name total_cost. You want to access the global 
total_cost variable from within the function while taking into account the local variable.
*/
#include <iostream>

int stock = 100;  // Global variable

void track_product_stock(int product_stock) {
    int stock = product_stock;  // Local variable
    // Access global stock using the scope resolution operator ::
    std::cout << "Global stock: " << ::stock << std::endl;
    std::cout << "Local stock: " << stock << std::endl;
}

int main() {
    int product_stock = 20;
    track_product_stock(product_stock);

    return 0;
}
