#include "Circle.hpp"
#include <cmath>
#include <iostream>


Circle::Circle(double r) : r_(r) {}

double Circle::getArea() const {
    return M_PI * r_ * r_;
}

double Circle::getPi() const {
    return M_PI;
}

double Circle::getPerimeter() const noexcept {
    return 2 * M_PI * r_;
}

double Circle::getRadius() const noexcept {
    return r_;
}

void Circle::print() const {
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
