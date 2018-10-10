#include "Includes.h" 
#include <time.h>
/*vector<string> noun{ "birds", "fish", "c++" }; // ejercicio 5-6 
vector<string> verb{ "rules", "fly", "swim" };
vector<string> enlazador{ "and", "or" "but" }; // conjunciones, marcaba error de ambiguedad si usaba el nombre conjunction en el vector
vector<string> article{ "The", "the" };

bool sustantivo(string palabra) {
	for (int i = 0; i < noun.size(); i++)
	{
		if (palabra == noun[i])
			return true;
	}
	return false;
}

bool verbo(string palabra) {
	for (int i = 0; i < verb.size(); i++)
	{
		if (palabra == verb[i])
			return true;
	}
	return false;
}

bool conjuncion(string palabra) {
	for (int i = 0; i < enlazador.size(); i++)
	{
		if (palabra == enlazador[i])
			return true;
	}
	return false;
}

bool articulo(string palabra){ // funcion que checa si empieza con articulo o lo usa despues de una conjuncion
	for (int i = 0; i < article.size(); i++)
	{
		if (palabra == article[i])
			return true;
	}
	return false;
}


bool oracion_correcta() {
	string article_o_sustantivo; // dos formas de iniciar una oracion
	cin >> article_o_sustantivo;
	if(!articulo(article_o_sustantivo) && !sustantivo(article_o_sustantivo )) //si no es articulo o sustantivo 
		return false;
	
	string sustantivo_o_verbo;
	cin >> sustantivo_o_verbo;
	if (articulo(article_o_sustantivo)) { //si empieza con articulo, tiene que seguir un sustantivo
		if(!sustantivo(sustantivo_o_verbo))
			return false;
	}
	else if (sustantivo(article_o_sustantivo)) { //si empezó con sustantivo, tiene que seguir un verbo
		if (!verbo(sustantivo_o_verbo))
			return false;
	}


	string verbo_o_conjuncion;
	cin >> verbo_o_conjuncion;
	if (sustantivo(sustantivo_o_verbo)) { // si inicia con The y un sutantivo, sigue un verbo
		if (!verbo(verbo_o_conjuncion))
			return false;
	}
	else if (verbo(sustantivo_o_verbo)) { // si inicia con sustantivo y siguio verbo, sigue una conjuncion
		if (verbo_o_conjuncion == " .") {
			return true; // no funciona no se por qué
		}                  // caso de que sea enunciado simple sustantivo y verbo, lo detecte como tal
		else if (!conjuncion(verbo_o_conjuncion)) // caso de que continue
			return false;
	}

	
	string conjunction_o_final;
	cin >> conjunction_o_final;
	if (verbo(verbo_o_conjuncion)) { //despues del verbo puede acabar la oracion
		if (conjunction_o_final == " .") // espacio y punto es la forma de terminar la oracion
			return true;
	}
	else if (conjuncion(conjunction_o_final)) // despues de la conjuncion sigue un articulo o un sustantivo
	{
		oracion_correcta(); // si vuelve a pedir un articulo o un sustantivo, va a volver a ser lo mismo así que desde este punto se hace recursiva
	}
	
	
}

int main()
{
	bool correcto;
	while (cin) {
		correcto = oracion_correcta();
		if (correcto)
			cout << "OK" << endl;
		else
			cout << "Not ok" << endl;
	}
	

	keep_window_open();
	return 0;
}



/*class Name_value {      //ejercicio 4
public:
	Name_value();
	string m_nombre;
	int m_valor;
	Name_value(string nombre, int valor) // namevalue tiene nombre y un valor
		:m_nombre(nombre), m_valor(valor) {}

	Name_value Get_name(); 
	void Print_name(); 

};

Name_value::Name_value()
{
}

Name_value Name_value::Get_name() //funcion para agarrar nombre y valor
{
	string m_nombre;
	int m_valor;
	cin >> m_nombre >> m_valor;
	return Name_value(m_nombre, m_valor);
}

void Name_value::Print_name() // funcion para imprimir nombre y valor
{
	cout << "Nombre = " << m_nombre << " Valor = " << m_valor << endl;
}

int main()
	try {
	Name_value buffer;
		vector<Name_value> Entradas;
		
		cout << "ingrese nombre y valor, escribe NoName y 0 para terminar con el ingreso de datos" << endl;
		while (cin) {
			buffer = buffer.Get_name();
			if (buffer.m_nombre == "NoName" && buffer.m_valor == 0) // condiciones para terminar de ingresar datos
				break;

			for (Name_value y : Entradas) { // checa que no se repita el nombre antes de meterlo en el vector
				if (y.m_nombre == buffer.m_nombre)
					error("nombre repetido");
			}

			Entradas.push_back(buffer);
		}

		for (Name_value x : Entradas) { // ciclo para imprimir cada namevalue x guardada
			x.Print_name();
		}

		keep_window_open();
		return 0;
	}
	catch (runtime_error & e) {
		cerr << "error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}*/



	//------------------------------------------------------------------------------
//drill, ejercicio 2 y 3
class Token { // crea la clase token, puede ser un char solo o un char y un double
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream { //clase creada para manejar el flujo del token, leer un token
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t) // si no está lleno el buffer, cambia full a verdadero y buffer ahora alberga un token
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
		// remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case '=':    // for "print"
	case 'x':    // for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/': case '{': case '}': case '!':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token('8', val);  // let '8' represent "a number"
	}
	default:
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

Token_stream ts; // tipo token_stream para ser usado en funciones        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '{':
	{
		double x = expression();
		t = ts.get();
		if (t.kind != '}') error("se esperaba '}'");
		return x;
	}
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '8':            // we use '8' to represent a number
		return t.value;  // return the number's value
	default:
		error("primary expected");
	}
}
//------------------------------------------------------------------------------
double factorial(double x) // funcion para llamarla en alta jerarquia
{
	double multiplicacion = 1;
	double caso0 = 1;
	x = round(x); // redondear el double

	if (x < 0)
		error("no existe el factorial de un numero negativo");
	if (x == 0)
		return caso0;

	for (double i = 1.0; i <= x; i++)
	{
		multiplicacion *= i;
	}
	return multiplicacion;
}
//------------------------------------------------------------------------------

double Alta_Jerarquia()
{
	double left = primary();
	Token t = ts.get();

	switch (t.kind) {
	case '!':
	{
		left = factorial(left);
		return left;
	}
	default:
		ts.putback(t);
		return left;

	}
}
//------------------------------------------------------------------------------
// deal with *, /, and %
double term()
{
	double left = Alta_Jerarquia();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
		{
			left *= Alta_Jerarquia();
			t = ts.get();
			break;
		}
		case '/':
		{
			double d = Alta_Jerarquia();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = Alta_Jerarquia();
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

int main()
try
{

	cout << "Calculadora simple, los operadores son: {}, (), *, /, -, +, %. Presiona x para salir e = para imprimir el calculo" << endl;
	double val = 0;
	while (cin) {
		Token t = ts.get();

		if (t.kind == 'x') break; // 'q' for quit
		if (t.kind == '=')        // ';' for "print now"
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		val = expression();
	}
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}
