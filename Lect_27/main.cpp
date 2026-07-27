//compile cmd: g++ shape.cpp main.cpp
#include "shape.hpp"
#include <iostream> //use for I/O
using std::cout; //import cout to globle scope
using std::endl; //import endl to globle scope

//What does this program print?
//How can we invoke the derived class implementation of area() via a base class pointer?
int main(){
	Shape shape(1,2);
	Rectangle rec(3,5,1);
	rec.set_color(255);
	cout<<"Rectangle object's color is: " <<rec.get_color()<<endl;
	Triangle tri(3.5,5.5);

	cout<<"Shape object's area = "<<shape.area()<<endl;
	cout<<"Rectangle object's area = "<<rec.area()<<endl;
	cout<<"Triangle object's area = "<<tri.area()<<endl;

	Shape *ptr;
	ptr = &shape;
	cout<<"Shape object's area = "<<ptr->area()<<endl;

	//use ptr to point to rec
	ptr = &rec;
	cout<<"Rectangle object's area = "<<ptr->area()<<endl;

	//use ptr to point to tri
	ptr = &tri;
	cout<<"Triangle object's area = "<<ptr->area()<<endl;

	return 0;
}
