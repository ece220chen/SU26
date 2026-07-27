#include "shape.hpp"

//Shape class methods
Shape::Shape(){width_=0;height_=0;}
Shape::Shape(double a, double b) { width_ = a; height_ = b;}
double Shape::area(){return 0;}

//Rectangle class methods
Rectangle::Rectangle():Shape(), color_(0){} //inline initializer 
Rectangle::Rectangle(double a, double b, int c):Shape(a, b), color_(c){}
double Rectangle::area(){return (double)width_*height_;}
void Rectangle::set_color(int c){color_=c;}
int Rectangle::get_color(){return color_;}

//Triangle class methods
Triangle::Triangle():Shape(){}
Triangle::Triangle(double a, double b):Shape(a, b){}
double Triangle::area(){return (double)width_*height_*0.5;}
