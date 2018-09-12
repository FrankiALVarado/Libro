#include "Includes.h"

int main()
{
	int n1 = 0; int n2 = 0; int n3 = 0;
	
	cout << "escriba 3 numeros y los acomodare de menor a mayor" << endl;
	cin >> n1 >> n2 >> n3;

		if (n1 <= n2)
			if (n2 <= n3)
				cout << n1 << ", " << n2 << ", " << n3 << endl;
			else if (n3 < n1)
				cout << n3 << ", " << n1 << ", " << n2 << endl;
	
		if (n2 <= n3)
			if (n3 < n1)
				cout << n2 << ", " << n3 << ", " << n1 << endl;
			
		if (n1 <= n3)
			if (n3 < n2)
				cout << n1 << ", " << n3 << ", " << n2 << endl;
			else if (n2 < n1)
				cout << n2 << ", " << n1 << ", " << n3 << endl;
			
		if (n1 > n2)
			if (n2 > n3)
				cout << n3 << ", " << n2 << ", " << n1 << endl;			
	
	keep_window_open();
	return 0;
}