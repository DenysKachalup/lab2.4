#include "Matr.h"
#include <iomanip>

Matr::Matr(int Rowa, int Col)
{
	if (Rowa < 1)
		this->Rowa = 1;
	else
		this->Rowa = Rowa;
	if (Col < 1)
		this->Col = 1;
	else
		this->Col = Col;

	r = new Row[this->Rowa];
	for (int i = 0; i < this->Rowa; i++)
	{
		r[i] = Row(this->Col);
	}
}
Matr:: ~Matr()
{
	for (int i = 0; i < Rowa; i++)
	{
		if (r[i].v != nullptr)
			delete[] r[i].v; 
	}
	
	if (r != nullptr)
		delete[] r;
}
Matr::Matr(const Matr& a)
{
	Rowa = a.Rowa;
	Col = a.Col;

	r = new Row[this->Rowa];
	for (int i = 0; i < this->Rowa; i++)
	{
		r[i] = Row(this->Col);
	}
	for (int i = 0; i < Rowa; i++)
		for (int j = 0; j < Col; j++)
			r[i][j] = a.r[i][j];
}
Matr::Row::Row(int Col)
{
	v = new int[Col];
	for (int j = 0; j < Col; j++)
		v[j] = 0;
}
int& Matr::Row:: operator [] (int j)
{
	return v[j];
}
//Row& Matr::operator [] (int i)
//{
//	return r[i];
//}
istream& operator >> (istream& in, Matr& w)
{
	for (int i = 0; i < w.getR(); i++)
	{
		for (int j = 0; j < w.getC(); j++)
		{
			cout << "Mas[" << i << "][" << j << "] = "; in >> w[i][j];
		}
		cout << endl;
	}
	return in;
}
ostream& operator << (ostream& out, Matr& mas)
{
	for (int i = 0; i < mas.getR(); i++)
	{
		for (int k = 0; k < mas.getC(); k++)
		{
			mas.x = mas[i][k];
			out << setw(4) << string(mas) ;
		}
		cout << endl;
	}
	return out;
}
Matr operator *(Matr& mas, int y)
{ 
	Matr tmp(mas.getR(),mas.getC());
	for (int i = 0; i < mas.getR(); i++)
	{
		for (int k = 0; k < mas.getC(); k++)
		{
			
			tmp[i][k] = mas[i][k] * y;
		}
	}
	return tmp;
}
Matr& Matr::operator = (const Matr& a)
{
	for (int i = 0; i < Rowa; i++)
		if ( r[i].v != nullptr)
		{
		
			delete[] r[i].v;
		}
	if ( r != nullptr)
	{
		delete[] r;
	}

	Rowa = a.Rowa;
	Col = a.Col;

	r = new Row[this->Rowa];
	for (int i = 0; i < this->Rowa; i++)
	{
		r[i] = Row(this->Col);
	}
	for(int i = 0; i< Rowa;i++)
		for (int j = 0; j < Col; j++)
			r[i][j] = a.r[i][j];

	return *this;
}
bool operator ==(Matr& a, Matr& b)
{
	if (a.Col != b.Col || a.Rowa != b.Rowa)
		return false;

	for (int i = 0; i < a.getR(); i++)
	{
		for (int k = 0; k < a.getC(); k++)
		{
			if (a[i][k] != b[i][k])
				return false;
		}
		cout << endl;
	}
	return true;
}
Matr :: operator string() const
{
	stringstream sout;
	sout << x;
	return sout.str();
}
double Matr::Norm(Matr& a)
{
	int b = 0;
	for (int i = 0; i < a.getR(); i++)
	{
		for (int k = 0; k < a.getC(); k++)
		{
			b += (a[i][k] * a[i][k]);
		}
		cout << endl;
	}
	return sqrt(b);
}