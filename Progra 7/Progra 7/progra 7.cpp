
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "Includes.h"
// drill completo, no se en que momento dejaron de funcionar las keywords y la declaracion de variables
struct Token { // la clase token pasa a ser estructura, por no usar m�todos
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(string nombre, char ch) : name(nombre), kind(ch) { }
	Token()  {}
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
	case 'f': // funcion lo reconozca como token
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
	Variable () {}
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

double declaration() // si se escribe "L a" va a empezar la declaraci�n de una variable
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
}