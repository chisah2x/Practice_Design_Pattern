#include <iostream>
#include <functional>

/*
Understanding std::function: A Simple Explanation
std::function is a part of the C++ Standard Library that allows you to store and manage functions, 
including regular functions, lambda expressions, and even function objects.
Think of it as a versatile container that can hold any callable entity, 
making it easier to pass functions around in your code.
*/

void add(int a, int b) {
    std::cout << "Sum: " << a + b << std::endl;
}

void multiply(int a, int b) {
    std::cout << "Product: " << a * b << std::endl;
}

//int main() {
//    std::function<void(int, int)> operation;
//
//    operation = add; // Store the add function
//    operation(5, 3); // Calls add: Sum: 8
//
//    operation = multiply; // Store the multiply function
//    operation(5, 3); // Calls multiply: Product: 15
//
//    return 0;
//}