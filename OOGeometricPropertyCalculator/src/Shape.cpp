//CSCE 240
#include "./Shape.h"
#include <iostream>
#include <string>
using namespace std;

Shape::~Shape(){}

Shape::Shape(){
shape = "No Shape to work with.";
}

Shape::Shape(string line){
    shape = line;
}

void Shape::setShape(string line){
shape = line;
}

string Shape::getShape(){
return shape;
}

double Shape::getArea(double a, double b){
    if (getShape() == "rectangle"){
        area = a*b;
    }
    else if (getShape() == "circle"){
        area = 3.14*(a*a);
    }
    else if (getShape() == "triangle"){
        area = 0;
        getErrorMessage();
    }
    else{
    getErrorMessage();
    }
    return area;
}

double Shape::getPerimeter(double a, double b, double c){
    if (getShape() == "rectangle"){
        perimeter = 2* (a+b);
    }
    else if (getShape() == "circle"){
        perimeter = 2*3.14*a;
    }
    else if (getShape() == "triangle"){
        perimeter = a + b + c;  
    }
    else{
    getErrorMessage();
    }
    return perimeter;
}

void Shape::getErrorMessage(){
    if (getShape() == "triangle"){
        cout << "Cannot get area of this triangle." << endl;
    }
    else {
        cout << "There is an error in your work. Check your file." << endl;
    }
}
