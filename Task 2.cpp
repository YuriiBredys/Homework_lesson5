#include<iostream>
using namespace std;

class Shape
{
public:
	Shape() {}
	virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
	double R;
public:
	Circle(double r): R(r) {}
	double area()
	{
		return 3.141 * R * R;
	}
};

class Rectangle : public Shape
{
private:
	double A, B;
public:
	Rectangle(double a, double b) : A(a), B(b) {}
	double area() 
	{
		return A * B;
	}
};

class Square : public Rectangle
{
public:
	Square(double A) : Rectangle(A, A) {}

};

int main()
{
	Shape** array = new Shape * [3];
	array[0] = new Circle(3.5);
	array[1] = new Rectangle(6, 8);
	array[2] = new Square(12);

	for (int i = 0; i < 3; i++)
	{
		cout << array[i]->area() << "\n";
	}

	delete array[0];
	delete array[1];
	delete array[2];
	delete[] array;

	return 0;
}
