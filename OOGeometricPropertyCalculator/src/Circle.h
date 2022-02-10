//CSCE 240
#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "./Shape.h"
#include <iostream>
#include <string>
using namespace std;

class Circle: public Shape {
    public:
    Circle();
    double getArea(double a, double b);
    double getPerimeter(double a, double b, double c);
    virtual ~Circle();
    void getErrorMessage();
};
#endif