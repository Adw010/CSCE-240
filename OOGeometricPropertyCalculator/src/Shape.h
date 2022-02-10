//CSCE 240
#ifndef SHAPE_H_
#define SHAPE_H_
#include <iostream>
#include <string>
using namespace std;

class Shape {

    public:
    Shape();
    Shape(string line);
    string getShape();
    void setShape(string line);
    void getErrorMessage();
    double getArea(double a, double b);
    double getPerimeter(double a, double b, double c);
    virtual ~Shape();

    protected:
    string shape;
    double area = 0;
    double perimeter = 0; 
};

#endif