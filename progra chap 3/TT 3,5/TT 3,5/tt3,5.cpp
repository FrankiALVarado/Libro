#include "Includes.h"

int main()
{
	double d = 0;
	while (cin >> d) { // repeat the statements below
	
		int i = d; // trata de meter un double a un entero
		char c = i; //trata de meter un int a un char
		int i2 = c; // valor entero del cáracter
		cout << "d==" << d // original
			<< " i==" << i // convertido a entero
			<< " i2==" << i2 // valor entero del cáracter
			<< " char(" << c << ")\n"; // cáracter
	}
}

/* Resultados:
5
d==5 i==5 i2==5 char()
1337
d==1337 i==1337 i2==57 char(9)
-52
d==-52 i==-52 i2==-52 char(╠)
89
d==89 i==89 i2==89 char(Y)
128
d==128 i==128 i2==-128 char(Ç)
56.9
d==56.9 i==56 i2==56 char(8)
*/