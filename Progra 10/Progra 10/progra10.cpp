#include "Includes.h"
#include <time.h>

int main() // ejercicio 9
{
	cout << "nombre del primer archivo a abrir: " << endl; // test1.txt
	string aux;
	cin >> aux;
	ifstream inFile1(aux, ios::in);

	cout << "nombre del segundo archivo a abrir: " << endl; // test2.txt
	string aux2;
	cin >> aux2;
	ifstream inFile2(aux2, ios::in);

	cout << "archivo a escribir ambos archivos: " << endl;
	string outf;
	cin >> outf;
	ofstream outFile;
	outFile.open(outf, ios::out);

	string buffer;
	string oracion;
	getline(inFile1, buffer);

	outFile << buffer;
	for (int i = 2; i < 1000; i++) {
		if (i == 2) {
			getline(inFile1, buffer);
			inFile1 >> oracion;
			outFile << oracion << " ";

		}
		if (i % 2 == 0) {
			while (getline(inFile1, buffer)) {
				inFile1 >> oracion;
				outFile << oracion << " ";
			}
		}
		if (i == 3) {
			getline(inFile2, buffer);
			inFile2 >> oracion;
			outFile << oracion << " ";
		}
		if (i % 2 == 1) {
			while (getline(inFile2, buffer)) {
				inFile2 >> oracion;
				outFile << oracion << " ";

			}
		}
	}
	outFile.close();

	keep_window_open();
	return 0;
}


/*int main() { ejercicio 8
	cout << "nombre del primer archivo a abrir: " << endl; // test1.txt
	string aux;
	cin >> aux;
	ifstream inFile1(aux, ios::in);

	cout << "nombre del segundo archivo a abrir: " << endl; // test2.txt
	string aux2;
	cin >> aux2;
	ifstream inFile2(aux2, ios::in);

	cout << "archivo a escribir ambos archivos: " << endl;
	string outf;
	cin >> outf;
	ofstream outFile;
	outFile.open(outf, ios::out);

	string buffer;
	getline(inFile1, buffer);
	outFile << buffer ;
	while (getline(inFile1, buffer)) {
		outFile << buffer;
	}

	getline(inFile2, buffer);
	outFile << buffer;
	while (getline(inFile2, buffer)) {
		outFile << buffer;
	}
	
	outFile.close();

	keep_window_open();
	return 0;
}*/




/*class Roman_int { // ejercicio 7, falla por que se termina el flujo de todo con ctrl z y enter
public:
	Roman_int();
	vector<char> romans;
	Roman_int(vector<char> romans);
	int as_int(Roman_int & r);
};

istream& operator>>(istream & is, Roman_int & r)
{
	char letras;
	vector<char> romans;

	cout << "escriba el numero romano(minusculas), ctrl+z y enter para salir" << endl;
	while (true) {
		is >> letras;
		romans.push_back(letras);
		if (!cin)
			break;

	}
	r.romans = romans;
	return is;
}

Roman_int::Roman_int()
{
	vector<char>x;
}

Roman_int::Roman_int(vector<char> romans)
{
	vector<char>x;
}

int Roman_int::as_int(Roman_int & r)
{
	int sumatoria = 0;
	for (int i = 0; i < r.romans.size(); i++) {
		if (r.romans[i] == 'm') {
			sumatoria += 1000;
		}
		if (r.romans[i] == 'c' && r.romans[i + 1] == 'm') {
			sumatoria += 900;
			i = i + 2;
		}
		if (r.romans[i] == 'd' || r.romans[i] == 'D') {
			sumatoria += 500;
		}
		if (r.romans[i] == 'c' && r.romans[i + 1] == 'd') {
			sumatoria += 400;
			i = i + 2;
		}
		if (r.romans[i] == 'c') {
			sumatoria += 100;
		}
		if (r.romans[i] == 'x'  && r.romans[i + 1] == 'c') {
			sumatoria += 90;
			i = i + 2;
		}
		if (r.romans[i] == 'l') {
			sumatoria += 50;
		}
		if (r.romans[i] == 'x' && r.romans[i + 1] == 'l') {
			sumatoria += 40;
			i = i + 2;
		}
		if (r.romans[i] == 'x') {
			sumatoria += 10;
		}
		if (r.romans[i] == 'i' && r.romans[i + 1] == 'x') {
			sumatoria += 9;
			i = i + 2;
		}
		if (r.romans[i] == 'v') {
			sumatoria += 5;
		}
		if (r.romans[i] == 'i' && r.romans[i + 1] == 'v') {
			sumatoria += 4;
			i = i + 2;
		}
		if (r.romans[i] == 'i') {
			sumatoria += 1;
		}
	}
	return sumatoria;
}


struct Token { // la clase token pasa a ser estructura, por no usar métodos
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(string nombre, char ch) : name(nombre), kind(ch) { }
	Token() {}
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = 'L'; //  declarar variables
const char quit = 'Q'; // cerrar el programa
const char print = ';'; // imprimir resultados
const char number = '8';
const char name = 'a';
const char funcion = 'f'; //habilita al usuario usar una funcion

Token Token_stream::get() //funcion que devuelve un 
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case 'K':
	case '#':
	case 'a':
	case 'L':
	case 'Q': // const char quit para que se pueda salir del ciclo
	case 'f':

		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}

	case 'x':
	case 'i':
	case 'c':
	case 'd':
	case 'v':
	case 'l':
	case 'm':
	{
		cin.unget();
		Roman_int r;
		operator >>(cin, r);
		return Token(number, r.as_int(r));
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s = ch;
			cin.unget();
			if (s == "#") return Token(let); // ambas keywords no funcionan
			if (s == "exit") return Token(quit);
			return Token(name, ch);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
	Variable() {}
};
vector<Variable> names;


Variable K("k", 1000);



double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s) // funcion que checa si ya hay una variable con ese nombre
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts; // una clase tipo token_stream global llamada rs

double expression(); //declara expression arriba para poder llamarla 

double primary() //primario, numero u operacion en parentesis, la mayor jerarquia
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
	}
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double term() // maneja multiplicacion y division antes de las sumas y restas
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression() // maneja sumas y restas despues de multiplicar o dividir
{
	double left = term();
	while (true) {
		Token  t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration() // si se escribe "L a" va a empezar la declaración de una variable
{

	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	cin >> name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double function()
{
	Token t;
	string sqr = t.name;
	cin >> sqr;
	if (sqr == "raiz") { // f raiz expresion
		cout << "escriba una expresion" << endl;
		double n = expression();
		n = round(n);
		if (n < 0) error("no existen las raices cuadradas negativas");
		return sqrt(n);
	}
	else if (sqr == "elevar") { // f elevar expresion potencia
		cout << "escriba un numero o expresion a elevar:" << endl;
		double x = expression();
		cout << "escriba su potencia: " << endl;
		double pot;
		cin >> pot;
		return pow(x, pot);
	}
	else
		error("funcion desconocida");

}

double statement() //funcion principal, llama a expression - declaration o function 
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	case funcion: // por ahorita solo funciona para sqrt
		return function();
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate() // todo lo que se manejba en el main del chap 6
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	//en el libro viene una forma de declarar pero daba a error.
	names.push_back(K); // empujar k 1000 drill 6 
	calculate();
	return 0;

}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}*/
























/*class Roman_int { // leer numeros hasta el 3999 ejercicio 6
public:
	Roman_int();
	vector<char> romans;
	Roman_int(vector<char> romans);
	int as_int(Roman_int & r);
};

istream& operator>>(istream & is, Roman_int & r)
{
	char letras;
	vector<char> romans;
	
	cout << "escriba el numero romano(minusculas), ctrl+z y enter para salir" << endl;
	while (true) {
		is >> letras;
		romans.push_back(letras); 
		if (!cin)
			break;
		
	}
	r.romans =  romans;
	return is;
}



int main()
{
	Roman_int r;
	operator >>(cin, r);
	cout << "en decimal es: " << r.as_int(r) << endl;

	keep_window_open();
	return 0;
}



Roman_int::Roman_int()
{
	vector<char>x;
}

Roman_int::Roman_int(vector<char> romans)
{
	vector<char>x;
}

int Roman_int::as_int(Roman_int & r)
{
	int sumatoria = 0;
	for (int i = 0; i < r.romans.size(); i++) {
		if (r.romans[i] == 'm') {
			sumatoria += 1000;
		}
		if (r.romans[i] == 'c' && r.romans[i + 1] == 'm') {
			sumatoria += 900;
			i = i + 2;
		}
		if (r.romans[i] == 'd' || r.romans[i] == 'D') {
			sumatoria += 500;
		}
		if (r.romans[i] == 'c' && r.romans[i + 1] == 'd') {
			sumatoria += 400;
			i = i + 2;
		}
		if (r.romans[i] == 'c') {
			sumatoria += 100;
		}
		if (r.romans[i] == 'x'  && r.romans[i + 1] == 'c') {
			sumatoria += 90;
			i = i + 2;
		}
		if (r.romans[i] == 'l') {
			sumatoria += 50;
		}
		if (r.romans[i] == 'x' && r.romans[i + 1] == 'l') {
			sumatoria += 40;
			i = i + 2;
		}
		if (r.romans[i] == 'x') {
			sumatoria += 10;
		}
		if (r.romans[i] == 'i' && r.romans[i + 1] == 'x') {
			sumatoria += 9;
			i = i + 2;
		}
		if (r.romans[i] == 'v') {
			sumatoria += 5;
		}
		if (r.romans[i] == 'i' && r.romans[i + 1] == 'v') {
			sumatoria += 4;
			i = i + 2;
		}
		if (r.romans[i] == 'i') {
			sumatoria += 1;
		}
	}
	return sumatoria;
}*/







/*void end_of_loop(istream& ist, char term, const string& message) ejercicio 5, no terminado
{
	if (ist.fail()) { // use term as terminator and/or separator
		ist.clear();
		char ch;
		if (ist >> ch && ch == term) return; // all is fine
		error(message);
	}
}

istream& operator>>(istream& is, Year& y)
// read a year from is into y
// format: { year 1972 . . . }
{
	char ch;
	is >> ch;
	if (ch != '{') {
		is.unget();
		is.clear(ios::failbit);
		return is;
	}
	string year_marker;
	int yy;
	is >> year_marker >> yy;
	if (!is || year_marker != "year") error("bad start of year");
	y.year = yy;
	while (true) {
		Month m; // get a clean m each time around
		if (!(is >> m)) break;
		y.month[m.month] = m;
	}
	end_of_loop(is, '}', "bad end of year");
	return is;
}

const int not_a_reading = -7777;

const int not_a_month = -1;


struct Day {
	vector<double> hour{ vector<double>(24,not_a_reading) };
};

struct Month { // a month of temperature readings
	int month{ not_a_month }; // [0:11] January is 0
	vector<Day> day{ 32 }; // [1:31] one vector of readings per day
};

struct Year { // a year of temperature readings, organized by month
	int year; // positive == A.D.
	vector<Month> month{ 12 }; // [0:11] January is 0
};

ostream& operator<<(ostream& os, const Day & d)
{
	return os << d.hour[];
}

ostream& operator<<(ostream & os, const Month & m)
{
	return os << m.month << m.day;
}


void print_year(ofstream & ofs, Year & y)
{
	ofs << y.year << " " << y.month
}


int main()
{
	// open an input file:
	cout << "Please enter input file name\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) error("can't open input file", iname);
	ifs.exceptions(ifs.exceptions() | ios_base::badbit); // throw for bad()
	// open an output file:
	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs) error("can't open output file", oname);
	// read an arbitrary number of years:
	vector<Year> ys;
	while (true) {
		Year y; // get a freshly initialized Year each time around
		if (!(ifs >> y)) break;
		ys.push_back(y);
	}
	cout << "read " << ys.size() << " years of readings\n";
	for (Year& y : ys) print_year(ofs, y);
}*/

/*double mean(const vector<double> temperaturas) ejercicio 3
{
	double sumatoria = 0;
	for (int i = 0; i < temperaturas.size(); i++) {
		sumatoria += temperaturas[i];
	}

	sumatoria = sumatoria / temperaturas.size();
	return sumatoria;
}

int main()
{
	int hour;
	double temperature;
	ifstream inFile("raw_temps.txt", ios::in);
	vector<int> hours;
	vector<double> temperatures;
	string buffer;

	inFile >> hour;
	hours.push_back(hour);
	inFile >> temperature;
	temperatures.push_back(temperature);
	
	while (getline(inFile, buffer)) {
		inFile >> hour;
		hours.push_back(hour);
		inFile >> temperature;
		temperatures.push_back(temperature);
	}
	
	temperatures.pop_back();
	hours.pop_back();

	sort(temperatures);
	cout << "promedio de las temperaturas = " << mean(temperatures) << endl;
	cout << "mediana de las temperaturas = " << temperatures[(temperatures.size() +1) / 2] << endl;
	cin.ignore();
	return 0;
}*/

/*struct Reading { // a temperature reading ejercicio 2-4
	int hour; 
	double temperature;
	char scale; // c o f
};

void convertir_c_to_f(double & temperatura)
{
	temperatura = (temperatura * 9 / 5) + 32;
}

void get_vector(vector<Reading> & lecturas)
{
	int hour;
	double temperature;
	char scale;
	Reading aux;
	for (int i = 0; i < 50; i++) {
		cin >> hour >> temperature >> scale;
		aux.hour = hour;
		if (scale == 'c')
			convertir_c_to_f(temperature);
		
		aux.temperature = temperature;
		aux.scale = 'f';
		lecturas.push_back(aux);
	}
}

/*void generar_lecturas(vector<Reading> & lecturas) {
	srand(time(0));
	Reading aux;
	for (int i = 0; i < 50; i++) {
		aux.hour = (rand() % 24);
		aux.temperature = (rand() % 91) - 20;
		lecturas.push_back(aux);
	}
}

void imprimir_lecturas(const vector<Reading> & lecturas, ofstream & temps) {
	for(int i = 0; i < lecturas.size(); i++){
		temps << lecturas[i].hour << " " << lecturas[i].temperature << lecturas[i].scale << endl;
	}
}

int main()
{
	Reading buffer;
	vector<Reading> lecturas;
	get_vector(lecturas);
	//generar_lecturas(lecturas);
	
	ofstream temps;
	temps.open("raw_temps.txt", ios::out);
	imprimir_lecturas(lecturas, temps);
	temps.close();
	
	cin.ignore();
	return 0;
}*/






/*#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

int sumatoria(const vector<int> & nums) ejercicio 1
{
	int sumatoria = 0;
	for (int i = 0;  i <nums.size(); i++)
	{
		sumatoria += nums[i];
	}
	return sumatoria;
}

int main()
{
	vector<int> numeros; // tengo que usar un vector porque  el ciclo siempre agarra el ultimo dos veces
	int buffer = 0; 
	ifstream inFile("numeros.txt", ios::in);

	while (!inFile.eof()) {
		inFile >> buffer;
		numeros.push_back(buffer);
		if (!cin)
			break;
	}

	inFile.close();
	numeros.pop_back();
	cout << "la sumatoria total es: " << sumatoria(numeros) << endl;

	cin.ignore();
	return 0;
}*/

/*class Points // drill completo 
{
public:
	Points();
	~Points();
	int px;
	int py;
	Points(int px, int py);
	void print_Points(const Points & x);
	void get_Points(Points & x);
private:
};

Points::Points()
{
	px = 0;
	py = 0;
}

Points::~Points()
{
}

Points::Points(int px, int py)
{
	px = 0;
	py = 0;
}

void Points::print_Points(const Points & x)
{
	cout << "punto x: " << x.px << "  punto y: " << x.py << endl;
}

void Points::get_Points(Points & x)
{
	int px;
	int py;
	cin >> px >> py;
	x.px = px;
	x.py = py;
}




void print_vector(const vector<Points> & puntos)
{
	for (Points x : puntos)
		x.print_Points(x);
}


int main()
{
	Points p;
	vector<Points> original_points;
	vector<Points> processed_points;
	string buffer;
	string aux1;
	string aux2;
	string aux3;
	string aux4;
	

	for (int i = 0; i < 7; i++) {
		cout << "ingrese punto x y punto y" << endl;
		p.get_Points(p);
		//p.print_Points(p);
		original_points.push_back(p);
	}
	
	//cout << "vector original: " << endl;
	//print_vector(original_points);

	ofstream outfile;
	outfile.open("mydata.txt", ios::out);
	for(Points x : original_points)
		outfile << "punto x: " << x.px << "  punto y: " << x.py << endl;
	outfile.close();

	ifstream infile("mydata.txt", ios::in);
	infile >> aux1;
	infile >> aux2;
	infile >> p.px;
	infile >> aux3;
	infile >> aux4;
	infile >> p.py;
	processed_points.push_back(p);
	while (getline(infile, buffer)) {
		infile >> aux1;
		infile >> aux2;
		infile >> p.px;
		infile >> aux3;
		infile >> aux4;
		infile >> p.py;
		processed_points.push_back(p);
	}
	infile.close();

	processed_points.pop_back();

	cout << "vector original: " << endl;
	print_vector(original_points);
	cout << endl;

	cout << "vector procesado: " << endl;
	print_vector(processed_points);

	if (original_points.size() != processed_points.size())
		cout << "something went wrong" << endl;
	else
		cout << "Everything is fine, please dont kill yourself" << endl;

	cout << "ingrese una tecla para continuar" << endl;
	string kc;
	cin >> kc;
	return 0;
}*/

