//base class
class Shape{
	public:
	Shape();
	Shape(double a, double b);
	virtual double area();
	protected:
	double width_, height_;
};

//derived class
class Rectangle : public Shape{
	public:
	Rectangle();
	Rectangle(double a, double b, int c);
	double area();
	void set_color(int c);
	int get_color();
	private:
	int color_;
};

//derived class
class Triangle : public Shape{
	public:
	Triangle();
	Triangle(double a, double b);
	double area(); 
};
