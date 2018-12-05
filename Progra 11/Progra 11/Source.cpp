#include "Includes.h" 

void disemvowel(string & palabra) {
	for (char & x : palabra) {
		if (x == 'a' || x == 'o' || x == 'e' || x == 'i' || x == 'u')
			x = ' ';
	}
}

int main()
{
	ifstream inFile("exe3.txt", ios::in);
	ofstream outFile;
	outFile.open("sin_vocales.txt", ios::out);
	string buffer;
	string palabra;

	while (getline(inFile, buffer)) {
		stringstream ss{ buffer };
		for (palabra; ss >> palabra;) {
			disemvowel(palabra);
			outFile << palabra << " ";
		}
		outFile << endl;
	}


	inFile.close();
	outFile.close();
}





/*bool in_Vector(const vector<int> & lineas, const int & linea) ejercicio 2
{
	for (int i = 0; i < lineas.size(); i++) {
		if (linea == lineas[i])
			return true;
	}

	return false;
}

int main()
{
	ifstream inFile("exe2.txt", ios::in);
	string buffer;
	string palabra;
	int linea = 1;
	vector<int> lineas;
	string buscando;

	cout << "que palabra busca?" << endl;
	cin >> buscando;

	
	while (getline(inFile, buffer)) {
		stringstream ss{ buffer };
		for (palabra; ss >> palabra;) {
			if (palabra == buscando && !in_Vector(lineas, linea))
				lineas.push_back(linea);
		}
		cout << buffer << endl;
		linea++;
	}

	cout << "la palabra " << buscando << " se encuentra en las lineas:" << endl;

	for (int i = 0; i < lineas.size(); i++)
	{
		cout << lineas[i] << endl;
	}

	inFile.close();
	keep_window_open();
	return 0;
}*/

/*void to_Lower(string & palabra) ejercicio 1
{
	for (char & x : palabra)
		if (isupper(x)) {
			x = tolower(x);
		}
	
}

int main()
{
	ifstream inFile("exe1.txt", ios::in);
	ofstream outFile;
	outFile.open("minusculas.txt", ios::out);
	string buffer;
	string palabra;

	while (true) {

		inFile >> palabra;
		to_Lower(palabra);
		outFile << palabra << " ";
		if (inFile.eof())
			break;
	}

	inFile.close();
	outFile.close();
}*/





/*int main() drill
{
	//float x = 1234567.89;
	//int a, b, c, d;
	int age = 23;
	int birth_year = 1995;
	cout << "decimal " << '\t' << birth_year << endl
		<< "octal " << '\t' << oct << birth_year << endl
		<< "hexadecimal " << '\t' << hex << birth_year << endl;
	
	cout << "edad: " << dec << age << endl;

	//cin >> a >> oct >> b >> hex >> c >> d;
	//cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

	//cout << defaultfloat << x << '\t' << fixed << x << '\t' << scientific << x << endl; // el mejor para manejar con exactitud es scientific

	cout << "Alvarado" << setw(12) << "Francisco" << setw(13) << "6624154694" << setw(22) << "frankigps@gmail.com" << endl;

	keep_window_open();
	return 0;
}*/