#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <cmath>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) -> bool {
    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) -> bool {
    if (s)
        return (s->getPerimeter() > 20);
    return false;
};

auto areaLessThanX = [x = 10](shared_ptr<Shape> s) -> bool {
    if (s)
        return (s->getArea() < x);
    return false;
};

void printCollectionElements(const Collection &collection) {
    for (const auto &it: collection)
        if (it)
            it->print();
}

void printAreas(const Collection &collection) {
    for (const auto &it: collection)
        if (it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection &collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info) {
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

// too fast
constexpr double fibonacciNumber(int numberOfSequence) {
    return pow(((1 + sqrt(5)) / 2), numberOfSequence) / sqrt(5);
}

constexpr double fibonacciNumberSlower(int numberOfSequence) {
    std::pair<double, double> fib(0, 1);
    for (int i = 2; i < numberOfSequence; i++) {
        swap(fib.first, fib.second);
        fib.second = fib.first + fib.second;
    }
    return fib.first + fib.second;
}


int main() {
    auto val1 = fibonacciNumber(45);
    auto val2 = fibonacciNumberSlower(45);
    cout.precision(15);
    cout << "Fibonacci: " << val1 << endl;
    cout << "Fibonacci: " << val2 << endl;
    Collection shapes{make_shared<Circle>(2.0),
                      make_shared<Circle>(3.0),
                      nullptr,
                      make_shared<Circle>(4.0),
                      make_shared<Rectangle>(10.0, 5.0),
                      make_shared<Square>(3.0),
                      make_shared<Circle>(4.0),
                      make_shared<Square>(1.0),
                      make_shared<Square>(Color::Crimson),
                      make_shared<Circle>(Color::Turquoise),
                      make_shared<Rectangle>(Color::Beige)};
    printCollectionElements(shapes);

    cout.precision(2);
    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    return 0;
}

