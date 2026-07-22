//compile using this command: g++ rectangle.cpp -o rectangle

#include <iostream>
using namespace std;

//Rectangle class
class Rectangle{
   //default access is private
   int width_, height_;

   public:
	//constructors
	Rectangle();
	Rectangle(int w, int h);
	//destructor
	~Rectangle() {cout << "Destructor is called." << endl;};

	int area() const {return width_*height_;}
	int get_width() const {return width_;}
	int get_height() const {return height_;}
	void set_width(int new_width) {width_ = new_width;}
	void set_height(int new_height) {height_ = new_height;}
};
Rectangle::Rectangle(){//set both width and height to 0
	width_ = 0;
	height_ = 0;
}

Rectangle::Rectangle(int w, int h){
	width_ = w;
	height_ = h;
}

int main(){
	Rectangle rect1(3,4);
	Rectangle rect2;
	Rectangle *rect_ptr = &rect1;
	cout << "rect1's area = " << rect_ptr->area() << endl;
	cout << "rect2's area = " << rect2.area() << endl;
	cout<< "rect1's width = " << rect1.get_width() << endl;
	rect1.set_width(5);
	cout<< "rect1's new width = " << rect1.get_width() << endl;
	
	Rectangle *r_ptr2, *r_ptr3;
	r_ptr2 = new Rectangle(5,6);
	cout << "area of rectangle pointed to by r_ptr2 is: " << r_ptr2->area() << endl;

	r_ptr3 = new Rectangle[2]{Rectangle(),Rectangle(2,4)};
	cout << "area of rectangle [0] in array is: " << r_ptr3[0].area() << endl;
	//cout << "area of rectangle [0] in array is: " << r_ptr3->area() << endl;

	//cout << "area of rectangle [1] in array is: " << r_ptr3[1].area() << endl;
	cout << "area of rectangle [1] in array is: " << (r_ptr3+1)->area() << endl;

	delete  r_ptr2;
	delete  [] r_ptr3;

	cout<<"area of rectangle after delete:"<<r_ptr2->area()<<endl;

	return 0;
}
