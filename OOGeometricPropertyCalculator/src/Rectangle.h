//CSCE 240
#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "./Shape.h"
#include <iostream>
#include <string>
using namespace std;

class Rectangle: public Shape {
    public:
    Rectangle();
    double getArea(double a, double b);
    double getPerimeter(double a, double b, double c);
    virtual ~Rectangle();
    void getErrorMessage(); 
};
#endif