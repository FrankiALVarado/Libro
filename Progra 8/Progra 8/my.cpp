#include "my.h"
#include "Includes.h"
int foo = 0;

void print_foo()
{
	cout << foo << endl;
}

void print(int i)
{
	cout << i << endl;
}

void swap_v(int a, int b)
{
	 int temp; 
	 temp = a, 
	 a = b; 
	 b = temp; 
}

void swap_r(int & a, int & b)
{
	int temp;
	temp = a,
	a = b;
	b = temp;
}



	/*void swap_cr(const int & a, const int & b)
{ esto no va a dejar compilar
	int temp;
	temp = a,
	a = b;
	b = temp;
}*/
