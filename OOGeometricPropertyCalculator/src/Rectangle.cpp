//CSCE 240
#include "./Rectangle.h"
#include <iostream>
#include <string>
using namespace std;

Rectangle::~Rectangle(){}

Rectangle::Rectangle(){
    shape = "rectangle";
}

double Rectangle::getArea(double a, double b){
    Shape::getArea(a, b);
    return area;
}

double Rectangle::getPerimeter(double a, double b, double c){
    Shape::getPerimeter(a, b, c);
    return perimeter;
}

void Rectangle::getErrorMessage(){
    Shape::getErrorMessage();
    return;
}
