#pragma once

#include "Color.h"

class Shape{
private:
    Color color;
public:
    Shape(){};
    Shape(Color c): color(c) {};
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};



