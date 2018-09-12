#include "Includes.h"

int main()
{
	cout << "Meta una cantidad entera n: ";
	int n;
	cin >> n;
	cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\ntres veces n == " << 3 * n
		<< "\ndos veces n == " << n + n
		<< "\nn al cuadrado == " << n * n
		<< "\nmitad de n == " << n / 2
		<< "\nraiz cuadrada de  n == " << sqrt(n) << endl
		<< "n al cubo == " << n * n * n << endl
		<< "7 veces n == " << n * 7 << endl
		<< "n + 42 == " << n * 42 << endl;
	    

	keep_window_open();
	return 0;
		
}