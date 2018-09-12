#include "Includes.h"


int main() //ejercicio 11
{
	int pen; int nick; int dime;
	int quart; int half; int dol;
	double total;

	cout << "cuantos pennies tienes?" << endl;
	cin >> pen;

	cout << "cuantos nickels tienes?" << endl;
	cin >> nick;

	cout << "cuantos dimes tienes?" << endl;
	cin >> dime;

	cout << "cuantos quarters tienes?" << endl;
	cin >> quart;

	cout << "cuantos halfs tienes?" << endl;
	cin >> half;

	cout << "cuantos golden dollars tienes?" << endl;
	cin >> dol;

	if (pen == 1)
		cout << "tienes 1 dime" << endl;
	else if (pen > 1)
		cout << "tienes " << pen << " pennies" << endl;
	else {
	}

	if (nick == 1)
		cout << "tienes 1  nickel" << endl;
	else if (nick > 1)
		cout << "tienes " << nick << " nickels" << endl;
	else {
	}

	if (dime == 1)
		cout << "tienes 1 dime" << endl;
	else if (dime > 1)
		cout << "tienes " << dime << " dimes" << endl;
	else {
	}

	if (quart == 1)
		cout << "tienes 1 quarter" << endl;
	else if (quart > 1)
		cout << "tienes " << dime << " dimes" << endl;
	else {
	}

	if (half == 1)
		cout << "tienes 1 half" << endl;
	else if (half > 1)
		cout << "tienes " << half << " halfs" << endl;
	else {
	}

	if (dol == 1)
		cout << "tienes un golden dollar" << endl;
	else if (dol > 1)
		cout << "tienes " << dol << " golden dollars" << endl;
	else {
	}

	total = pen + (nick * 5) + (dime * 10) + (quart * 25) + (half * 50) + (dol * 100);
	cout << "en total tienes " << total / 100 << "dolares" << endl;

	keep_window_open();
	return 0;


}


 /*int main() ejercicio 10
{
	string operador;
	double n1; double n2;
	cout << "ingrese un operador, luego dos numeros" << endl;
	cin >> operador >> n1 >> n2;
	if (operador == "+")
		cout << "suma de " << n1 << " + " << n2 << " = " << n1 + n2 << endl;
	
	if (operador == "-")
		cout << "la resta de " << n1 << " - " << n2 << " = " << n1 - n2 << endl;

	if (operador == "*")
		cout << "el producto de " << n1 << " * " << n2 << " = " << n1 * n2 << endl;

	if (operador == "/")
		cout << "la division de " << n1 << " - " << n2 << " = " << n1 / n2 << endl;

	keep_window_open();
	return 0;

}

/*int main() ejercicio 9
{
	string num;
	cout << "escriba un numero en letras y se lo devuelvo en digito" << endl;
	cin >> num;
	
	if (num == "cero")
		cout << "0" << endl;
	else if (num == "uno")
		cout << "1" << endl;
	else if (num == "dos")
		cout << "2" << endl;
	else if (num == "tres")
		cout << "3" << endl;
	else if (num == "cuatro")
		cout << "4" << endl;
	else {
		simple_error("payaso");
	}
	
	keep_window_open();
	return 0;
}

/* int main() // ejercicio 8
{
	int num = 0;
	cout << "escriba un numero, le dire si es par" << endl;
	cin >> num;
	
	if (num % 2 == 0)
		cout << num << " es par." << endl;
	else
		cout << num << " es impar" << endl;

	keep_window_open();
	return 0;
}






/*int main() ejercicio 7
{
	string p1; string p2; string p3;

	cout << "escriba 3 palabras y se las ordenare alfabeticamente" << endl;
	cin >> p1 >> p2 >> p3;

	if (p1 <= p2)
		if (p2 <= p3)
			cout << p1 << ", " << p2 << ", " << p3 << endl;
		else if (p3 < p1)
			cout << p3 << ", " << p1 << ", " << p2 << endl;

	if (p2 <= p3)
		if (p3 < p1)
			cout << p2 << ", " << p3 << ", " << p1 << endl;

	if (p1 <= p3)
		if (p3 < p2)
			cout << p1 << ", " << p3 << ", " << p2 << endl;
		else if (p2 < p1)
			cout << p2 << ", " << p1 << ", " << p3 << endl;

	if (p1 > p2)
		if (p2 > p3)
			cout << p3 << ", " << p2 << ", " << p1 << endl;

	keep_window_open();
	return 0;
}*/