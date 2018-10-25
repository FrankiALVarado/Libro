#include <vector>
#include <iostream>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;


int mode(const vector<int> nums) { // ejercicio 11
	int repeticiones = 0;
	int auxiliar = 0;
	int num = 0;
	int moda = 0;
	for (int i = 0; i < nums.size(); i++) {
		for (int x = 0; x < nums.size(); x++) {
			if (i != x) {
				if (nums[i] == nums[x]){
					auxiliar++;
					num = nums[i];
			    }
			}
		}
		if (auxiliar > repeticiones) {
			repeticiones = auxiliar;
			moda = num;
		}
		auxiliar = 0;
	}
	return moda;
}

int median(const vector<int> nums) {
	int mediana = nums[(nums.size() + 1) / 2];
	return mediana;
}

/*int minv(const vector<int> & nums) {
	int menor = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (i == 0) {
			menor = nums[i];
		}

		if (nums[i] < menor)
			menor = nums[i];
	}
	return menor;
}                          // estas funciones estan comentadas porque no las ocupo despues de sortear el vector

int maxv(const vector<int> & nums) { 
	int mayor = 0;
	int menor = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (i == 0) {
			mayor = nums[i];
			menor = nums[i];
		}
		
		if (nums[i] > mayor)
			mayor = nums[i];
		
		if (nums[i] < menor)
			menor = nums[i];
	}
	return mayor;
}*/

void sort_vector(vector<int> & vint) {
	for (int i = 0; i < vint.size(); i++) {
		for (int x = 0; x < vint.size(); x++) { 
			if (x != i) { 
				if (vint[i] < vint[x]) {
					int k = vint[i];
					vint[i] = vint[x];
					vint[x] = k;
				}
			}
		}
	}
}

void print_vector(const vector<int> & v) { // ejercicio 6
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i + 1 < v.size())
			cout << ", ";
		else
			cout << " .";

	}
	cout << endl;
}


int main()
{
	vector<int> numeros;
	while (true) {
		cout << "ingrese un vector de numeros, ctrl+z y enter para terminar la entrada de datos" << endl;
		int num;
		cin >> num;
		if (!cin)
			break;
		numeros.push_back(num);
	}
	cout << endl;
	sort_vector(numeros);

	cout << "vector ordenado : " << endl;
	print_vector(numeros);
	cout << "numero mayor = " << numeros[numeros.size() - 1] << endl;
	cout << "numero menor = " << numeros[0] << endl;
	cout << "mediana = " << median(numeros) << endl;
	cout << "moda = " << mode(numeros) << endl;

	cin.clear();
	cin.ignore();
	return 0;
}


/*double maxv(const vector<double> & nums) { // ejercicio 10
	double mayor = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (i == 0)
			mayor = nums[i];
		
		if (nums[i] > mayor)
			mayor = nums[i];
	}
	return mayor;
}

int main()
{
	vector<double> numeros;
	while (true) {
		cout << "ingrese un numero, le devolvere el mas grande, ctrl+z y enter para terminar la entrada de datos" << endl;
		double num;
		cin >> num;
		if (!cin)
			break;
		numeros.push_back(num);
	}
	cout << "numero mayor = " << maxv(numeros) << endl;

	cin.clear();
	cin.ignore();
}*/


/*double index(const vector<double> & weight, const vector<double> & price) { // ejercicio  9
	double sum = 0;
	for (int i = 0; i < weight.size(); i++) {
		sum += weight[i] * price[i];
	}
	return sum;
}


int main()
{
	double weight = 0;
	double price = 0;
	vector<double> peso;
	vector<double> costo;
	while (true) {
		cout << "ingrese peso y costo, ctrl+z y enter para terminar la entrada de datos" << endl;
		cin >> weight >> price;
		if (!cin)
			break;

		peso.push_back(weight);
		costo.push_back(price);
	}

	cout << "valor total =  " << index(peso, costo) << "." << endl;

	cin.clear();
	cin.ignore();
}*/

/*void print_vector(const vector<string> & v, const vector<int> & e) { // ejercicios 7-8
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ",  " << e[i] << " anos de edad." << endl;
	}
	cout << endl;
}

void sort_vector(vector<string> & vstring, vector<int> & vint) {
	for (int i = 0; i < vstring.size(); i++) {
		for (int x = 0;  x < vstring.size(); x++) { // uso dos ciclos para checar cada cada palabra, con todas las de dif
			if (x != i) { // indice, menos la misma
				if (vstring[i] < vstring[x]) {
		            string k = vstring[i]; 
					vstring[i] = vstring[x];
					vstring[x] = k;
					int aux = vint[i];// hace los mismos cambios en el vector de edades que en el de strings
					vint[i] = vint[x]; // para que sigan estando emparejados con el mismo nombre
					vint[x] = aux;
				}
			}
		}
	}

}
int main()
{
	string nombre;
	vector<string> nombres;
	int edad;
	vector<int> edades;
	while (true) {
		cout << "escribe un nombre y su edad separados por un espacio, ctrl+z y enter para terminar la entrada de datos" << endl;
		cin >> nombre >> edad;
		if (!cin)
			break;
		nombres.push_back(nombre);
		edades.push_back(edad);
	}
	sort_vector(nombres, edades);
	print_vector(nombres, edades);
	
	
	cin.clear();
	cin.ignore();
	return 0;
}*/

/*void print_vector(const vector<string> & v, const string label) { // ejercicio 6
	cout << label << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i + 1 < v.size())
			cout << ", ";

	}
	cout << endl;
}

void reverse_vector(const vector<string> & a, vector<string> & b) {
	int tamano = a.size() - 1;
	for (int i = 0; i <= tamano; tamano--) {
		b.push_back(a[tamano]);
	}
}

void invertir_vector(vector<string> & x) {
	int tamano = x.size() - 1;
	for (int i = 0; i < (tamano + 1) / 2; i++) {
		string aux = x[i];
		x[i] = x[tamano - i];
		x[tamano - i] = aux;
	}
}

int main() {
	string x;
	vector<string> reverse;
	vector<string> cadenas;
	while (true) {
		cin >> x;
		if (!cin)
			break;
		cadenas.push_back(x);

	}

	reverse_vector(cadenas, reverse);
	print_vector(reverse, "vector invertido");
	invertir_vector(cadenas);
	print_vector(cadenas, "mismo vector pero modificado");
	cin.clear();
	cin.ignore();
	return 0;
}*/




/*void print_vector(const vector<int> & v, const string label) { // ejercicio 5 
	cout << label << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i + 1 < v.size())
			cout << ", ";
		
	}
	cout << endl;
}

void reverse_vector(const vector<int> & a, vector<int> & b) {
	int tamano = a.size() - 1;
	for (int i = 0; i <= tamano; tamano--) {
		b.push_back(a[tamano]);
	}
}

void invertir_vector(vector<int> & x) {
	int tamano = x.size() - 1;
	for (int i = 0; i < (tamano + 1) / 2; i++) {
		int aux = x[i];
		x[i] = x[tamano - i];
		x[tamano - i] = aux;
	}
}

int main() {
	int x;
	vector<int> reverse;
	vector<int> nums;
	while (true) {
		cin >> x;
		if (!cin)
			break;
		nums.push_back(x);

	}

	reverse_vector(nums, reverse);
	print_vector(reverse, "vector invertido");
	invertir_vector(nums);
	print_vector(nums, "mismo vector pero modificado");
	cin.clear();
	cin.ignore();
	return 0;
}*/


/*void print_vector(const vector<int> & v, const string label) { // ejercicio 2-3-4
	cout << label << endl;

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", ";
	}
}

void fibonacci(int x, int y, vector<int> & v, int n) { // agarra la referencia del vector para sobreescribirlo
	v.push_back(x);
	v.push_back(y);

	for (int i = 2; i < n; i++) {
		int sum = v[i - 2] + v[i - 1];
		v.push_back(sum);
	}
}

int main() // el ultimo numero que se puede albergar en int desde la secuencia normal es el 47, el 48 sale negativo
{
	int x;
	int y;
	int n;

	cout << "escriba los dos primeros numeros de la sucesion de fibonacci" << endl;
	cin >> x >> y;

	cout << "escriba cuantos numeros quiere en la sucesion" << endl;
	cin >> n;

	vector<int> v;
	fibonacci(x, y, v, n);

	print_vector(v, "valores de fibonacci");
	
	cin.get();
	cin.ignore();
	return 0;
}
*/




/*#include "my.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

namespace X { //drill 3
	int var = 0;
	void print() {
		cout << "var X = " << var << endl;
	}
}

namespace Y {
	int var = 0;
	void print() {
		cout << "var Y = " << var << endl;
	}
}

namespace Z {
	int var = 0;
	void print() {
		cout << "var Z = " << var << endl;
	}
}

int main() {
	X::var = 7;
	X::print(); // print X’s var
	using namespace Y;
	var = 9;
	print(); // print Y’s var
	{  using Z::var;
	 using Z::print;
	 var = 11;
	 print(); // print Z’s var
	}
	print(); // print Y’s var
	X::print(); // print X’s var

	cin.ignore();
	return 0;
}*/





/*int main() { drill 1-2
	foo = 7;
	print_foo();
	print(99);

	int x = 7;
	int y = 9;
	swap_r (x, y);
	cout << "cambio de ref " << x << " " << y << endl; // este es el unico que si logra hacer el cambio
	swap_v(x, y);// replace ? by v, r, or cr
	cout << "cambio de enteros " << x << " " << y << endl;
	swap_v (7, 9);
	cout << "cambio de enteros " << x << " " << y << endl;
	const int cx = 7;
	const int cy = 9;
	swap_v (cx, cy);
	cout << "cambio de enteros " << cx << " " << cy << endl;
	swap_v (7.7, 9.9);
	cout << "cambio de enteros " << x << " " << y << endl;
	double dx = 7.7;
	double dy = 9.9;
	swap_v (dx, dy);
	cout << "cambio de enteros " << dx << " " << dy << endl;
	
	
	cin.ignore();
	return 0;
}*/