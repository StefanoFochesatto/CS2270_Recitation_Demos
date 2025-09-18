#include "Classes.h" // Include the class declaration
#include <cmath>     // For M_PI, the value of pi
#include <iostream>

// Its just like classes in python
// Defining the 'Circle' constructor
Circle::Circle(double r) {
    radius = r;
}
// member functions are like methods
// Defining the 'setRadius' member function (or method)
void Circle::setRadius(double r) {
    if (r >= 0) {
        radius = r;
    }
}

// Defining the 'calculateArea' member function (or method)
double Circle::calculateArea() {
    // This function can directly access the 'radius' member variable
    // of the object it was called on.
    return M_PI * radius * radius;
}

int main(){
   // We create an instance of the Circle class called 'my_circle'.
    // The value 5.0 is passed to the constructor.
    Circle my_circle(5.0);
    std::cout << "Circle object created with radius 5.0" << std::endl;

    // We use the dot (.) operator to call a function ON the object.

    // Call calculateArea() on my_circle and store the result.
    double area = my_circle.calculateArea();
    std::cout << "The initial area is: " << area << std::endl;
    std::cout << "---" << std::endl;

    // Now, let's modify the object's state.
    std::cout << "Changing the radius to 10.0..." << std::endl;
    
    // Call setRadius() to change the internal 'radius' variable.
    my_circle.setRadius(10.0);

    // Call calculateArea() again to see the new result.
    area = my_circle.calculateArea();
    std::cout << "The new area is: " << area << std::endl;
}