#include "Includes.h"
#include "area.h"

int main()
{
		vector<string> dia_de_la_semana;
		vector<int> valor;
		vector<int> incorrecto;
		vector<string> dia_incorrecto;
		int dia = 0;
		string nombre_dia = 0;
		int sumatoria = 0;
		string nombre_dia = "";

		for (int i = 0; i < 7; ++i) {

			cout << "ingrese un dia y su numero" << endl;
			cin >> nombre_dia >> dia;

			if (dia < 1 || dia > 31)// input del valor del dia correcto
				incorrecto.push_back(dia);
			else {
				valor.push_back(dia);
			}

			if (nombre_dia == "lunes" || nombre_dia == "martes" || nombre_dia == "miercoles" || nombre_dia == "jueves" || nombre_dia == "viernes")
				dia_de_la_semana.push_back(nombre_dia);
			else if (nombre_dia == "sabado" || nombre_dia == "domingo")
				dia_de_la_semana.push_back(nombre_dia);
			else {
				dia_incorrecto.push_back(nombre_dia);
			}
		}

			for (int x = 0; x < valor.size(); ++x) {
				sumatoria += valor[x];
			}	

			for (int y = 0; y < dia_de_la_semana.size(); ++y) {
			
				cout << dia_de_la_semana[y] << ", " << endl;
			}
		
			cout << "sumatoria de los dias = " << sumatoria << endl;
			cout << "inputs incorrectos: " << incorrecto.size() + dia_incorrecto.size() << endl;

			keep_window_open();
			return 0;
}

/*int main() // ejercicio 12-13
{
	while (true) {
	 //vector<int> adivinar{ 4, 6, 7, 2 };
	 vector<int> adivinar;
	 vector<int> intento;
	 int bull = 0;
	 int cow = 0;
	 int num = 0;
	 int iterador = 1;
	 //int semilla = 0;
	 int rando = 0;
	 cout << "ingrese una semilla para generar numeros random, diferente cada vez" << endl;
	  // la funcion que pide el libro seed_randint ya no está en includes.h
	 for (int y = 0; y < 4; ++y) {
		 rando = randint(10);
		 adivinar.push_back(rando);
	 }

	 for (int p = 0; p < adivinar.size(); ++p) {
		 cout << adivinar[p] << ", ";
	 }
	 cout << "ingrese 4 nums diferentes para jugar bull and cows, ctrl+z y enter para salir" << endl;

		while (intento != adivinar) {
			for (int n = 0; n < adivinar.size(); ++n) { //llenar el vector de intento
				cout << "num " << iterador << "= ";
				cin >> num;
				cout << endl;
				intento.push_back(num);
				iterador++;
			}
			
			for (int i = 0; i < adivinar.size(); i++) { //chequeo de bulls
				if (intento[i] == adivinar[i]) {
					bull++;
				}
			}
			// primero chequea que no sean bulls
			if (intento[0] != adivinar[0]) {// chequeo de cows, pudiera ser más rápido con un for y que chequee las otras opciones menos la posicion del iterador
				if (intento[0] == adivinar[1] || intento[0] == adivinar[2] || intento[0] == adivinar[3]) //pero no se como se representa en la sintaxis si es que se puede :D
					cow++;
			}

			if (intento[1] != adivinar[1]) {
				if (intento[1] == adivinar[0] || intento[1] == adivinar[2] || intento[1] == adivinar[3])
					cow++;
			}

			if (intento[2] != adivinar[2]) {
				if (intento[2] == adivinar[0] || intento[2] == adivinar[1] || intento[2] == adivinar[3])
					cow++;
			}

			if (intento[3] != adivinar[3]) {
				if (intento[3] == adivinar[0] || intento[3] == adivinar[1] || intento[3] == adivinar[2])
					cow++;
			}

			cout << "bulls: " << bull << endl;
			cout << "cows: " << cow << endl;

			iterador = 1;
			intento.clear();
		}
		cout << "felicidades, atinaste" << endl;

	}
	keep_window_open();
	return 0;
}*/

/*int main() // ejercicio 11 los int sirven hasta el numero 47 de la secuencia
{
	int v1 = 0;
	int v2 = 1;
	int limite = 0;
	int aux = 0;
	vector<int> fibonacci;
	cout << "serie de fibonacci hasta un numero" << endl;
	cin >> limite;

	for (int i = 0; i < limite; ++i) {
		if (i <= 1)
			fibonacci.push_back(i);
		else {

			aux = v1 + v2;
			v1 = v2;
			v2 = aux;
			fibonacci.push_back(aux);
		}
	}
	for (int x = 0; x < fibonacci.size(); ++x) {
			cout << fibonacci[x] << endl;
	}
	
	keep_window_open();
	return 0;
}*/

/*int main() // ejercicios 8-9-10, no supe hacer la comparacion de si sumatoria es un int
{
	try {
		double valor = 0;
		double sumatoria = 0;
		int n = 0;
		double restatoria = 0;
		vector<double> restas;
		vector<double> valores;
		cout << "cuantos valores quieres sumar?" << endl;
		cin >> n;
		cout << "empezare a almacenar valores, ctrl z + enter para terminar" << endl;

		for (double valor; cin >> valor;)
		{
			valores.push_back(valor);

		}

		if (n > valores.size())
			error("no tienes tantos valores en el vector");

			for (int i = 0; i < n; ++i)
				sumatoria += valores[i];

		restatoria = valores[0];
		for (int i = 1; i < n - 1; ++i)
			restatoria -= valores[i];


		cout << "sumatoria = " << sumatoria << endl;
		cout << "resta de los nums = " << restatoria << endl;

		keep_window_open();
		return 0;
	}

	catch (out_of_range &e) {
		cerr << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (runtime_error &e) {
		cerr << e.what() << endl;
		keep_window_open();
		return 2;
	}
}*/

/*int main() // ejercicio 7 
{
	double a; double b; double c;
	double x1; double x2;
	cout << "escribe a, b, c de una ecuacion cuadratica" << endl;
	cin >> a >> b >> c;

	try {
		if ((cuadrado(b) - (4 * a*c) < 0))
			error("raices imaginarias");

		x1 = (-b + sqrt(cuadrado(b) - (4 * a*c))) / 2 * a;
		x2 = (-b - sqrt(cuadrado(b) - (4 * a*c))) / 2 * a;

		cout << "x1 = " << x1 << " , x2 = " << x2 << endl;
		keep_window_open();
		return 0;
	} 
	catch (runtime_error & e)
	{
		cerr << e.what() << endl;
		keep_window_open();
		return 1;
	}
}*/

/*int main() // ejercicio 6
{
	try {
		double c = 0;
		char conversion = ' ';

		cout << "quieres convertir de celcius a Farenehit (f) o de Farenheit a celsius(c)" << endl;
		cin >> conversion;

		if (conversion == 'f')
		{
			cout << "cuantos grados celcius vas a convertir? " << endl;
			cin >> c; // retrieve temperature to input variable d no estaba declarada
			double f = ctof(c); // convert temperature error string c
			cout << c << "celcius a farenheit = " << f << endl; // print out temperature error cout con C
		}

		if (conversion == 'c')
		{
			cout << "cuantos grados farenheit vas a convertir? " << endl;
			double f = 0;
			cin >> f;
			c = ftoc(f);
			cout << f << " farenheit a grados celsius = " << c << endl;
		}
		else
			error("no se que conversion quieres");
		keep_window_open();
		return 0;
	}

	catch (runtime_error &e) {
		cerr << "runtime_error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
}*/

/*int main() // ejercicio 2-3-4-5
{
	try {
		double c = 0;
		char conversion = ' ';

		cout << "quieres convertir de celcius a kelvin (k) o de kelvin a celsius(c)" << endl;
		cin >> conversion;

		if (conversion == 'k')
		{
			cout << "cuantos grados celcius vas a convertir? " << endl;
			cin >> c; // retrieve temperature to input variable d no estaba declarada
			double k = ctok(c); // convert temperature error string c
			cout << k << endl; // print out temperature error cout con C
		}
		
		if (conversion == 'c')
		{
			cout << "cuantos grados kelvin vas a convertir? " << endl;
			double k = 0;
			cin >> k;
			c = ktoc(k);
			cout << k << " kelvin a grados celsius = " << c << endl;
		}
		else
		    error("no se a que conversion te refieres");
		keep_window_open();
		return 0;
	}

	catch (runtime_error &e){
		cerr << "runtime_error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
}*/

/*int main() // try this 8 no hay valor que no se cumpla a la postcondicion.
{
	int v1 = 0;
	int v2 = 0;

	while (cin >> v1 >> v2)
	{
		cout << area(v1, v2) << endl;
	}
	keep_window_open();
	return 0;
}*/

/*int main() // try this 7
{
	double constexpr distancia = 1778.4;
	double constexpr velocidad_promedio_carro = 73.33333;
	double constexpr velocidad_promedio_avion = 872.5;
	cout << "distancia promedio nueva york a denver en carro = " << distancia * velocidad_promedio_carro << endl;
	cout << "distancia promedio de nueva york a denver en avion = " << distancia * velocidad_promedio_avion;

	keep_window_open();
	return 0;
} */

/*int main() try this 6
{
	cout << "programa para calcular el area del try this" << endl; //try this 6
	double lado = 2;
	double apotema = cuadrado(lado) - (cuadrado(0.5));
	apotema = sqrt(apotema);

	cout << "area = " << lado * apotema << endl;

	keep_window_open();
	return 0;


}*/

/*int main() //try this 4-5
{
  vector<double> temps; 
  for (double temp; cin >> temp; ) 
  {
	  cout << "ingrese temperaturas de Guadalajara, ctrl+z y enter para acabar el ciclo" << endl;
      temps.push_back(temp);
  }
  double sum = 0;
  double  high_temp = -7.0; // más baja historica
  double  low_temp = 38.7; // más alta historica
 
 
  for (double x : temps)
  {
  if(x > high_temp) high_temp = x; 
  if(x < low_temp) low_temp = x; 
  sum += x; 
  }
 
  cout << "temperatura mas alta: " << high_temp << '\n';
  cout << "temperatura mas baja: " << low_temp << '\n';
  cout << "promedio de las temperaturas: " << sum/temps.size() << '\n';

  keep_window_open();
  return 0;
}*/

/* int main() drill
try {
	int x = 4; double d = 5 / (x-2); if (d = 2 * x + 0.5) cout << "Success!\n";
	keep_window_open();
	return 0;
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
}*/
/*
 1. Cout << "Success!\n"; arreglado:  arreglado: cout << "Success!\n";
 2. cout << "Success!\n;  arreglado: arreglado: cout << "Success!\n";
 3. cout << "Success" << !\n"   arreglado: cout << "Success" << "!\n";
 4. cout << success << '\n';   cout << "success" << '\n';
 5. string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n"; arreglado: int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
 6. vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";   arreglado : vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "Success!\n";
 7. if (cond) cout << "Success!\n"; else cout << "Fail!\n"; arreglado: if (true) cout << "Success!\n"; else cout << "Fail!\n";
 8. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";  arreglado: bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";
 9. string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n"; arreglado: string s = "ape"; bool c = "fool" > s; if (c) cout << "Success!\n";
 10. string s = "ape"; if (s=="fool") cout << "Success!\n"; arreglado: string s = "ape"; if (s!="fool") cout << "Success!\n";
 11. string s = "ape"; if (s=="fool") cout < "Success!\n"; arreglado: string s = "ape"; if (s!="fool") cout << "Success!\n";
 12. string s = "ape"; if (s+"fool") cout < "Success!\n"; arreglado: string s = "ape"; if (s!="fool") cout << "Success!\n";
 13. vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n"; arreglado: vector<char> v(5); for (int i = 0; i < v.size(); ++i) cout << "Success!\n";
 14. vector <char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n"; arreglado: vector <char> v(5); for (int i = 0; i <= v.size(); ++i) cout << "Success!\n";
 15. string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i]; arreglado string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s;
 16. if (true) then cout << "Success!\n"; else cout << "Fail!\n"; arreglado: if (true) cout << "Success!\n"; else cout << "Fail!\n";
 17. int x = 2000; char c = x; if (c==2000) cout << "Success!\n"; arreglado: int x = 20; char c = x; if (c == 20) cout << "Success!\n";
 18. string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i]; nada que corregir
 19. vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n"; arreglado: vector<int> v(5); for (int i = 0; i <= v.size(); ++i) cout << "Success!\n";
 20. int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n"; arreglado: int i = 0; int j = 9; while (i < 10) { if (i < j) { ++i; cout << "Success!\n"; } }
 21. int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n"; arreglado: int x = 2; double d = 5 / (x-1); if (d == 2 *( x + 0.5)) cout << "Success!\n";
 22. string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i]; arreglado: string s = "Success!\n"; for (int i = 0; i < 9; ++i) cout << s[i];
 23. int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n"; arreglado: int i = 0; while (i < 10) { ++i;  cout << "Success!\n"; }
 24. int x = 4; double d = 5/(x–2); if (d=2*x+0.5) cout << "Success!\n"; arreglado: int x = 4; double d = 5 / (x-2); if (d = 2 * x + 0.5) cout << "Success!\n";
 25. cin << "Success!\n"; arreglado:  cout << "Success!\n"; */ 




/*int main()  //try this 3  if (x - frame_width <= 0 || y - frame_width <= 0)
{
		        error("non-positive area() argument called by framed_area()");
	                     if (length <= 0 || width <= 0) error("valor no positivo");
	try {
		int x = -1;
		int y = 2;
		int z = 4;

		int area1 = area(x, y);
		if (area1 <= 0) error("non-positive area");
		int area2 = framed_area(1, z);
		int area3 = framed_area(y, z);
		double ratio = double(area1) / area3;
	}

	catch (...) {
		cerr << "payaso" << endl;
		keep_window_open();
		return 1;
	}
}*/


/*int main()  try this 2
{
	int x0 = arena(7); // identificador arena no esta definido
	int x1 = area(7); // no hay suficientes argumentos en la llamada a funcion
	int x2 = area("seven", 2); // const char [6] "seven" un argumento tipo const char no es compatible con un parametro int
}*/

/*int main() //try this 1
{
	int s1 = area(7; 
	int s2 = area(7) 
	Int s3 = area(7);
	int s4 = area('7); 
}*/
/*
1>c:\users\frank\onedrive\escritorio\progra chap 5\chap 5\chap 5\chap 5cpp.cpp(7): error C2065: 's3': identificador no declarado
*/

/*
1>c:\users\frank\onedrive\escritorio\progra chap 5\chap 5\chap 5\chap 5cpp.cpp(7): error C2065: 'Int': identificador no declarado1
*/

/*
1>c:\users\frank\onedrive\escritorio\progra chap 5\chap 5\chap 5\chap 5cpp.cpp(6): error C2660: 'area': la función no acepta 1 argumentos
*/

/*
1>c:\users\frank\onedrive\escritorio\progra chap 5\chap 5\chap 5\chap 5cpp.cpp(7): error C2146: error de sintaxis: falta ';' delante del identificador 's3'
*/

/*
1>c:\users\frank\onedrive\escritorio\progra chap 5\chap 5\chap 5\chap 5cpp.cpp(5): error C2143: error de sintaxis: falta ')' delante de ';'
*/
