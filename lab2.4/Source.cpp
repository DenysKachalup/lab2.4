#include <iostream>
#include "Matr.h"

using namespace std;

int main()
{ 
	int Row, Col;

	cout << "Row = "; cin >> Row;
	cout << "Col = "; cin >> Col;
	Matr mas(Row, Col);
	cin >> mas;
	cout << mas << endl;

	int scal;
	cout << "Scal = "; cin >> scal;
	mas = mas * scal;
	cout << mas << endl;

	//cout << "Row = "; cin >> Row;
	//cout << "Col = "; cin >> Col;
	Matr mas1(Row, Col);
	cin >> mas1;
	cout << mas1 << endl;

	bool a = mas == mas1;
	cout << "Rivnist matr: " << a << endl;

	cout <<" Normal: "<< mas.Norm(mas) << endl;;

	return 0;
}