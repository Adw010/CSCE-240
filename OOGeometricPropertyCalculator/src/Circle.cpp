//CSCE 240
#include "./Circle.h"
#include <iostream>
#include <string>
using namespace std;

Circle::~Circle(){}

Circle::Circle(){
    shape = "circle";
}

double Circle::getArea(double a, double b){
    Shape::getArea(a, b);
    return area;
}

double Circle::getPerimeter(double a, double b, double c){
    Shape::getPerimeter(a, b, c);
    return perimeter;
}

void Circle::getErrorMessage(){
    Shape::getErrorMessage();
    return;
}