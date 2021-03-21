#pragma once
#include <iostream>	
#include <string>
#include <sstream>	

using namespace std;

class Matr
{
	class Row;
	int Rowa, Col,x;
	Row* r;

	class Row
	{
	public :
		int* v;
		Row(int Col = 1);
		int& operator [] (int j);
	};

public:
	Row& operator [] (int i)
	{
		return r[i];
	}
	int getC() const { return Col; }
	int getR() const { return Rowa; }

	Matr(int Rowa, int Col);
	~Matr();
	Matr(const Matr& a);

	friend istream& operator >> (istream& in, Matr& w);
	friend ostream& operator << (ostream& out, Matr& w);

	friend Matr operator * (Matr& x, int y);
	Matr& operator = (const Matr& a);
	operator string () const;

	double Norm(Matr& a);

	friend bool operator ==(Matr& a, Matr& b);
	friend bool operator !=(Matr& a, Matr& b);
};

