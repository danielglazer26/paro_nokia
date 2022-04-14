#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(Color c): Shape(c){};
    Circle(const Circle & other) = default;
    Circle(double r);

    double getArea() const override;
    [[deprecated]] double getPi() const;
    void print() const override;
    double getPerimeter() const noexcept override;
    double getRadius()  const noexcept;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_;
};
