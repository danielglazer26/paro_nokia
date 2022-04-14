#pragma once

#include "Shape.hpp"

class Rectangle : public Shape {
public:
    Rectangle(Color c) : Shape(c){};
    Rectangle(double x, double y);

    Rectangle(const Rectangle &other) = default;

    double getArea() const override;

    double getPerimeter() const override;

    void print() const override;

    double getX() const; //get X is not virtual
    double getY() const;

private:
    Rectangle() = delete;

    double x_;
    double y_;
};
