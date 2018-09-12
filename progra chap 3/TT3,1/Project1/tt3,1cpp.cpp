#include "Includes.h"

int main()
{
	string nombre;
	double edad;
	
	cout << "Escribe tu primer nombre y tu edad separados por un espacio" << endl;
	cin >> nombre >> edad;

	cout << "tu nombre es: " << nombre << ", tienes " << edad << " a" << char(164) << "os" << endl;
	cout << "tu edad en meses es: " << edad * 12 << endl;
	
	keep_window_open();
	return 0;


}