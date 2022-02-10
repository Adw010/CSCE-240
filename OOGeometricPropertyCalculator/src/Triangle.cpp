//CSCE 240

#include "./Triangle.h"
#include <iostream>
#include <string>
using namespace std;


Triangle::~Triangle(){}

Triangle::Triangle(){
    shape = "triangle";
}

double Triangle::getArea(double a, double b){
    Shape::getArea(a, b);
    return area;
}

double Triangle::getPerimeter(double a, double b, double c){
    Shape::getPerimeter(a, b, c);
    return perimeter;
}

void Triangle::getErrorMessage(){
    Shape::getErrorMessage();
    return;
}

