//CSCE 240
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "./Shape.h"
#include <iostream>
#include <string>
using namespace std;

class Triangle: public Shape {
    public:
    Triangle();
    double getArea(double a, double b);
    double getPerimeter(double a, double b, double c);
    ~Triangle();
    void getErrorMessage();
};
#endif