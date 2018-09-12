#include "Includes.h"

int main()
{
	double miles = 0.0;
	cout << "ingrese millas y se le regresare el valor en km" << endl;
	cin >> miles;
	cout << miles << " millas son: " << miles * 1.609 << " km" << endl;

	keep_window_open();
	return 0;

}