#include "Includes.h"

int main()
{
	double val1 = 0.0;
	double val2 = 0.0;

	cout << "escriba dos valores diferentes y operare con ellos" << endl;
	cin >> val1 >> val2;

	if (val1 > val2)
		cout << val1 << " es mayor que " << val2 << endl;
	else
		cout << val2 << " es mayor que " << val1 << endl;

	cout << "la suma es: " << val1 + val2 << endl
		<< "su resta es: " << val1 - val2 << endl
		<< "su producto es: " << val1 * val2 << endl
		<< "su division es: " << val1 / val2 << endl;

	keep_window_open();
	return 0;
}


/*int main()
{
	int val1 = 0;
	int val2 = 0;

	cout << "escriba dos valores diferentes y operare con ellos" << endl;
	cin >> val1 >> val2;

	if (val1 > val2)
		cout << val1 << " es mayor que " << val2 << endl;
	else
		cout << val2 << " es mayor que " << val1 << endl;

	cout << "la suma es: " << val1 + val2 << endl
		<< "su resta es: " << val1 - val2 << endl
		<< "su producto es: " << val1 * val2 << endl
		<< "su division es: " << val1 / val2 << endl;

	keep_window_open();
	return 0;
}

escriba dos valores diferentes y operare con ellos (int)
 8 7
8 es mayor que 7
la suma es: 15
su resta es: 1
su producto es: 56
su division es: 1
Please enter a character to exit

escriba dos valores diferentes y operare con ellos (double)
8 7
8 es mayor que 7
la suma es: 15
su resta es: 1
su producto es: 56
su division es: 1.14286
Please enter a character to exit

*/