#include<iostream>
#include<string>
using namespace std;

class Fraction
{
private:
	int n;
	int d;

public:

	Fraction() {}

	Fraction(int n, int d)
	{
		if (d == 0)
		{
			throw "Exeption";
		}
		this->n = n;
		this->d = d;
	}

	Fraction& operator ++()
	{
		this->n += this->d;
		return *this;
	}

	Fraction& operator ++(int value)
	{
		Fraction temp(*this);
		this->n += this->d;
		return temp;
	}

	Fraction operator *(const Fraction& other)
	{
		Fraction temp;
		temp.n = this->n * other.n;
		temp.d = this->d * other.d;
		return temp;
	}

	Fraction operator -(const Fraction& other)
	{
		Fraction temp;
		temp.n = (this->n * other.d) - (other.n * this->d);
		temp.d = this->d * other.d;
		return temp;
	}

	int getN() const
	{
		return n;
	}

	int getD() const
	{
		return d;
	}

	void setN(int n)
	{
		this->n = n;
	}

	void setD(int d)
	{
		if (d == 0)
		{
			throw "Exeption";
		}
		this->d = d;
	}

};

string toString(Fraction x)
{
	string temp, n, d, s;
	int _n, _d;
	_n = x.getN();
	_d = x.getD();
	n = to_string(_n);
	s = " / ";
	d = to_string(_d);
	temp = n + s + d;
	return temp;
}

int main()
{
	try {
		pow(1, 2);
		Fraction a(1, 3);
		Fraction b(3, 4);
		Fraction c = a * b;
		Fraction d = b - a;
		cout << toString(c)<< endl;
		cout << d.getN() << " / " << d.getD() << endl;
		++a;
		b++;
		cout << a.getN() << " / " << a.getD() << endl;
		cout << b.getN() << " / " << b.getD() << endl;
		return 0;
	}
	catch (...) 
	{
		cerr << "Exeption\n";
	}

}
