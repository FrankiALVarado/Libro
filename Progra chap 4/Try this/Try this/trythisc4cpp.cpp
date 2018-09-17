#include "Includes.h"
#include "cuadrado.h"

int main() // ejercicio 19
{
	string nombre;
	int valor;
	vector<string> lista_nombres;
	vector<int> puntuaciones;

	while (nombre != "noname" && valor != 0) {
		cout << "escriba un nombre y puntuaciones" << endl;
		cin >> nombre >> valor;
		lista_nombres.push_back(nombre);
		puntuaciones.push_back(valor);
	}

	for (int i = 0; i < puntuaciones.size(); ++i)
		cout << lista_nombres[i] << "\t" << puntuaciones[i];

	keep_window_open();
	return 0;

	
}

/*int main() // ejercicio 18
{
	int a = 0;
	int b = 0;
	int c = 0;
	double x1 = 0.0;
	double x2 = 0.0;

	cout << "escriba a, b y c de una ecuacion cuadratica" << endl;
	cin >> a >> b >> c;

	x1 = (-b + sqrt(cuadrado(b) - (4 * a * c))) / 2;
	x2 = (-b - sqrt(cuadrado(b) - (4 * a * c))) / 2;

	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;

	keep_window_open();
	return 0;
}*/

/*int main()  // ejercicio 17, tanto en este como en el pasado me falta la media, es por falta de tiempo
{
	string menor = "zzzz";
	string mayor = "aaaa";
	vector <string> lista;
	for (string palabras; cin >> palabras;) {
		cin >> palabras;
		lista.push_back(palabras);
		if (palabras <= menor)
			menor = palabras;
		if (palabras > mayor)
			mayor = palabras;
		cout << "tu palabra fue: " << palabras << endl;
		cout << "la menor alfabeticamente hasta ahorita es: " << menor << endl;
		cout << "la mayor alfabeticamente hasta ahorita es: " << mayor << endl;
	}
	for (int i = 0; i < lista.size(); ++i) {
		cout << lista[i] << endl;
	}
}*/

/*int main() //ejercicio 16
{
	unsigned int repeticion = 0;
	unsigned int num_repetido = 0;
	vector <unsigned int> serie_de_numeros;

	for (int numeros; cin >> numeros; ) {
		serie_de_numeros.push_back(numeros);
	}

	sort(serie_de_numeros);
	for (int i = 0; i < serie_de_numeros.size(); ++i) {
		if (serie_de_numeros[i] == serie_de_numeros[i + 1])
			repeticion = repeticion + 1;
		num_repetido = serie_de_numeros[i];
	}

	cout << "modo es: " << num_repetido << endl;
	cout << "numero de repeticiones: " << repeticion << endl;

	keep_window_open();
	return 0;
}*/


/*int main() // ejercicio 15
{
	vector<int> primos{ 2 };
	int n = 0;
	
	cout << "le dire los primeros n numeros primos" << endl;
	cin >> n;

	while (primos.size() <= n) {
		for (int i = 3; i <= 100000; ++i) {
			
			for(int x = 0; x < primos.size(); ++x)
				if (i % primos[x] == 0) {
				}
				else {
					primos.push_back(i);
				}
		}
	}

	for (int y = 0; y < primos.size(); ++y)
		cout << primos[y] << endl;

	keep_window_open();
	return 0;
}*/


/*int main() // ejercicio 13-14
{
	vector<int> primos{2};
	int max = 0;
	cout << "hasta que valor quiere saber los numeros primos" << endl;
	cin >> max;
	

	for(int i = 2; i <= max; ++i) { // no se si algun día compile esto, pero esto debería de ser

		for (int x = 0; x < primos.size(); ++x) {
			while (cuadrado(primos[x]) <= max) {
			    if (i != primos[x] && i % primos[x] == 0) {

			    }
			    else if (i != primos[x] && i % primos[x] != 0) {
				        primos.push_back(i);
			    }
		    }
			
		
		}
		
		
				
	}
		
	for (int y = 0; y < primos.size(); ++y)
		cout << primos[y] << endl;
			  
	keep_window_open();
	return 0;
}*/



/*int main() // ejercicio 13
{
	vector<int> primos;
	for (int i = 2; i <= 100; ++i) {
		if (i != 2 && i % 2 == 0) {
		}
		else if (i != 3 && i % 3 == 0) {
		}
		else if (i != 5 && i % 5 == 0) {
		}
		else if (i != 7 && i % 7 == 0) {
		}
		else
			primos.push_back(i);
	}
	for (int x = 0; x < primos.size(); ++x)
		cout << primos[x] << endl;
	
	keep_window_open();
	return 0;	
}*/

/*int main()
{
	int limite = 0;
	vector <int> primos;
	int ultimo = 3;
	cout << "escribe de 1 a x y te dire cuales son todos los numeros primos en medio de ellos" << endl;
	cin >> limite;
	
	for (int i = 1;  i <= limite; ++i) // para este ejercicio 11-12 en especial el doce intente crear un loop dentro del for que checara hasta el ultimo primo ingresado dentro del vector
	{                                  // pero no imprimía nada y empezzaba a acabarme la ram.
		if (i == 1 || i == 4 || i == 6)
		{

		}
		if (i == 2)
			primos.push_back(i);
		else if (i == 3)
			primos.push_back(i);
		else if (i == 5)
			primos.push_back(i);
		else if (i == 7)
			primos.push_back(i);
		else if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0 || i % 11 == 0) {

		}
		else
			primos.push_back(i);
		
	}

	cout << "todos los primos del 1 al 100 son:" << endl;
	for (int y = 0; y < primos.size(); ++y) {
		cout << primos[y] << endl;
	}
	keep_window_open();
	return 0;
}*/


/*int main()
{
	vector<string> ia{ "piedra", "tijeras", "piedra", "papel", "papel", "tijeras" };
	string respuesta;


	for (int i = 0; i < ia.size(); i++)
	{
	 cout << "vamos a jugar piedra papel y tijeras, elige" << endl;
 	 cin >> respuesta;
     cout << "la maquina escoge: " << ia[i] << endl;
	 
	 if (respuesta == ia[i])
		 cout << "empate" << endl;
     else if (respuesta == "papel" && ia[i] == "piedra")
		 cout << "felicidades, has ganado" << endl;
	 else if (respuesta == "papel" && ia[i] == "tijeras")
		 cout << "has perdido" << endl;
	 else if (respuesta == "piedra" && ia[i] == "tijeras")
		 cout << "felicidades, has ganado" << endl;
	 else if (respuesta == "piedra" && ia[i] == "papel")
		 cout << "has perdido" << endl;
	 else if (respuesta == "tijera" && ia[i] == "papel")
		 cout << "felicidades, has ganado" << endl;
	 else if (respuesta == "tijera" && ia[i] == "piedra")
		 cout << "has perdido" << endl;


	}
	keep_window_open();
	return 0;	
}*/

/*int main() ejercicios 8-9
{
	double arroz = 1;
	int cuadrados = 0;
	int i = 1;
	//int num = 0;
	double sumatoria_arroz = 0;
	//cout << "cuantos cuadrados ocupan para darle x num de arroz" << endl;
	//cin >> num;
	while (i <= 1000) //sumatoria_arroz <= num
	{
		cuadrados++;
		cout << "cuadrado " << cuadrados << endl;
		cout << "arroz ganado = " << arroz << endl;
		sumatoria_arroz = sumatoria_arroz + arroz;
		arroz = arroz * 2;
		cout << "arroz total = " << sumatoria_arroz << endl;
		i++;
	
	}
	cout << cuadrados << endl;
	keep_window_open();
	return 0;
}*//*cuadrado 20
arroz ganado = 524288
arroz total = 1.04858e+06
cuadrado 21
arroz ganado = 1.04858e+06
arroz total = 2.09715e+06
cuadrado 22
arroz ganado = 2.09715e+06
arroz total = 4.1943e+06*/

/*int main() //ejercicio 7
{
	double numero1 = 0.0;
	double numero2 = 0.0;
	char operacion = ' ';
	string digit_o_palabra;
	string digito1 = " ";
	string digito2 = " ";
	
	cout << "vas a escribir los numeros en digitos o en palabras?" << endl;
	cin >> digit_o_palabra;
	if (digit_o_palabra == "digitos")
	{
	 cout << "escribe dos numeros, luego una operacion:" << endl;
	 cin >> numero1 >> numero2 >> operacion;

	}
	else if (digit_o_palabra == "palabras")
	{
		cout << "escribe dos digitos luego la operacion" << endl;
		cin >> digito1 >> digito2 >> operacion;

		if (digito1 == "uno")
			numero1 = 1;
		else if (digito1 == "dos")
			numero1 = 2;
		else if (digito1 == "tres")
			numero1 = 3;
		else if (digito1 == "cuatro")
			numero1 = 4;
		else if (digito1 == "cinco")
			numero1 = 5;
		else if (digito1 == "seis")
			numero1 = 6;
		else if (digito1 == "siete")
			numero1 = 7;
		else if (digito1 == "ocho")
			numero1 = 8;
		else if (digito1 == "nueve")
			numero1 = 9;
		else {
			simple_error("no se cual es ese numero");
		}

		if (digito2 == "uno")
			numero2 = 1;
		else if (digito2 == "dos")
			numero2 = 2;
		else if (digito2 == "tres")
			numero2 = 3;
		else if (digito2 == "cuatro")
			numero2 = 4;
		else if (digito2 == "cinco")
			numero2 = 5;
		else if (digito2 == "seis")
			numero2 = 6;
		else if (digito2 == "siete")
			numero2 = 7;
		else if (digito2 == "ocho")
			numero2 = 8;
		else if (digito2 == "nueve")
			numero2 = 9;
		else {
			simple_error("no se cual es ese numero");
		}

	}

	if (operacion == '+')
		cout << numero1 << " + " << numero2 << " = " << numero1 + numero2 << endl;
	else if (operacion == '-')
		cout << numero1 << " - " << numero2 << " = " << numero1 - numero2 << endl;
	else if (operacion == '*')
		cout << numero1 << " * " << numero2 << " * " << numero1 * numero2 << endl;
	else if (operacion == '/')
		cout << numero1 << " / " << numero2 << " = " << numero1 / numero2 << endl;
	else {
		simple_error("no se a que te refieres");

	}
	
	keep_window_open();
	return 0;
}*/

/*int main() //ejercicio 6
{
	vector<string> numeros_escritos = { "cero", "uno", "dos","tres", "cuatro", "cinco","seis", "siete","ocho", "nueve",};
	for (int i = 0; i < numeros_escritos.size(); ++i)
	{
		if (numeros_escritos[i] == "cero")
			cout << '0' << endl;
		else if (numeros_escritos[i] == "uno")
			cout << '1' << endl;
		else if (numeros_escritos[i] == "dos")
			cout << '2' << endl;
		else if (numeros_escritos[i] == "tres")
			cout << '3' << endl;
		else if (numeros_escritos[i] == "cuatro")
			cout << '4' << endl;
		else if (numeros_escritos[i] == "cinco")
			cout << '5' << endl;
		else if (numeros_escritos[i] == "seis")
			cout << '6' << endl;
		else if (numeros_escritos[i] == "siete")
			cout << '7' << endl;
		else if (numeros_escritos[i] == "ocho")
			cout << '8' << endl;
		else if (numeros_escritos[i] == "nueve")
			cout << '9' << endl;
	}
	keep_window_open();
	return 0;
}*/


/*int main() ejercicio 5
{
	double numero1 = 0.0;
	double numero2 = 0.0;
	char operacion = ' ';

	cout << "escribe dos numeros, luego una operacion:" << endl;
	cin >> numero1 >> numero2 >> operacion;

	if (operacion == '+')
		cout << numero1 << " + " << numero2 << " = " << numero1 + numero2 << endl;
	else if (operacion == '-')
		cout << numero1 << " - " << numero2 << " = " << numero1 - numero2 << endl;
	else if (operacion == '*')
		cout << numero1 << " * " << numero2 << " * " << numero1 * numero2 << endl;
	else if (operacion == '/')
		cout << numero1 << " / " << numero2 << " = " << numero1 / numero2 << endl;
	else {
		simple_error("no se a que te refieres");
	}

	keep_window_open();
	return 0;
}*/

/*int main() ejercicio 4
{
	char par_o_impar = ' ';
	char yesno = ' ';
	int adivinar = 0;
	int intento_de_adivinar = 50;
	cout << "piensa de un numero del 1 al 100 y lo adivinare" << endl;
	cin >> adivinar;
	cout << "tu numero es par(p) o impar (i)" << endl;
	cin >> par_o_impar;
	if (par_o_impar = 'p') {
		if (intento_de_adivinar == adivinar)
			cout << "tu numero es " << adivinar;
		else if(adivinar)
	}
	    
		
}*/

/*int main() //ejercicio 3
{
	double menor = 1.0 / 0.000001;
	double mayor = -1.0 / 0.000001;
	vector<double> distancias;
	double sumatoria = 0.0;
	double promedio = 0.0;

	cout << "ingrese distancias, ctrl+z para terminar el ciclo" << endl;
	for (double distancia; cin >> distancia;)
	{
		distancias.push_back(distancia);
		sumatoria += distancia;

		if (distancia <= menor)
			menor = distancia;
		if (distancia > mayor)
			mayor = distancia;
		
	}
	
	promedio = sumatoria /distancias.size();
	cout << "la suma total de las distancias fue: " << sumatoria << endl;
	cout << "el promedio de las distancias fue: " << promedio << endl;
	cout << "la menor distancia fue: " << menor << endl;
	cout << "la mayor distancia fue: " << mayor << endl;

	keep_window_open();
	return 0;

}*/

/*int main() //ejercicio 2
{
	double media = 0.0;
	cout << "ingrese temperaturas para dolverle la media, presiona ctl+z y enter para salir del ciclo" << endl;
		vector<double> temperaturas;
		for (double temperatura; cin >> temperatura;)
		{
			temperaturas.push_back(temperatura);
		}
		
		sort(temperaturas);
		if (temperaturas.size() % 2 == 0) //si la cantidad de numeros es par se debe de hacer operaciones extra
			media = (((temperaturas[temperaturas.size() / 2]) + (temperaturas[(temperaturas.size()/2) -1])) / 2 );
		else { 
			media = temperaturas[temperaturas.size()/2];
		}

		cout << "la media fue: " << media << endl;

		keep_window_open();
		return 0;
}*/


/* int main() drill 6-11
{
	vector<double> entradas_en_metros;
	double sumatoria = 0.0;
	double menor = 1.0 / 0.001;
	double mayor = -1.0 / 0.001;
	double numero_entrada = 0.0;
	string unidad = "";
	constexpr double cm_a_metro = 0.01;
	constexpr double pulgadas_a_metro = 0.0254;
	constexpr double pie_a_metro = 0.3048;
	double unidad_a_metros = 0.0; //numero de entrada convertido a metros
	
	cout << "empieza el ciclo" << endl;
	cout << "escribe un numero y una unidad (cm,in,ft,m)" << endl;
	for (double numero_entrada; cin >> numero_entrada;)
	{
		cout << "\n" << endl;
		cin >> unidad;
		
		if (unidad == "cm")
		unidad_a_metros = numero_entrada * cm_a_metro;
		else if (unidad == "in")
			unidad_a_metros = numero_entrada * pulgadas_a_metro;
		else if (unidad == "ft")
			unidad_a_metros = numero_entrada * pie_a_metro;
		else if (unidad == "m")
			unidad_a_metros = numero_entrada;
		else
		{
			cout << "no se a que unidad te refieres, se contaran como metros" << endl;
		}
		
		if (unidad_a_metros <= menor)
			menor = unidad_a_metros;
		if (unidad_a_metros > mayor)
			mayor = unidad_a_metros;
		
		sumatoria += unidad_a_metros;

		cout << "tu numero fue: " << unidad_a_metros  << " metros"<< endl;
		cout << "el menor hasta ahorita es: " << menor << " metros" << endl;
		cout << "el mayor hasta ahorita es: " << mayor << " metros" << endl;
		
		cout << "ingrese un numero o ctrl+z y enter para terminar el ciclo" << endl;
		
		entradas_en_metros.push_back(unidad_a_metros);

	}
	cout << "la sumatoria en metros fue: " << sumatoria << endl;
	cout << "tus entradas en orden numerico fueron:" << endl;
	
	sort(entradas_en_metros);
	
	for (int i = 0; i < entradas_en_metros.size(); ++i)
		cout << entradas_en_metros[i] << "metros" << endl;
	
	keep_window_open();
	return 0;
}*/

/*int main() // drill 1-5
{
	double n1 = 0; 
	double n2 = 1;
	char c1 = '|';
	int cancel = c1;

	while(n1 || n2 != c1 ) // el libro nos pide que usemos | como input para terminarlo pero hace que explote la consola y se repita 
		//el ciclo infinitamente casi me hace leña la ram profe wtf
	{
		cout << "escriba dos numeros o | para terminar el loop" << endl;
		cin >> n1 >> n2;

		cout << "tus numeros son: " << n1 << ", " << n2 << endl;
		
		if (n1 < n2)
			cout << "el menor numero es: " << n1 << " y el mayor es: " << n2 << endl;
		else if (n2 < n1)
			cout << "el menor numero es: " << n2 << "y el mayor es: " << n1 << endl;
		else {
			cout << "los numeros son iguales" << endl;
		}

		 if ((n1 + 1.0 / 100.0) >= n2)
		cout << n1 << " y " << n2 << " casi son iguales" << endl;
		else if ((n2 + 1.0 / 100) >= n1)
		cout << n2 << " y " << n1 << "casi son iguales" << endl;
 

		

	}
	
	keep_window_open();
	return 0;
}*/

/*int main() // try this 6
{
	string bleep1 = "boda";
	string bleep2 = "matrimonio";
	string bleep3 = "suegra";
	vector<string> palabras;
	cout << "escriba palabras hasta que se canse, ctrl+z y enter para dejar de escribir" << endl;
	for (string temp; cin >> temp;) 
		palabras.push_back(temp); 
	
	for (int i = 0; i < palabras.size(); ++i)
	{
		if (palabras[i] == bleep1 || palabras[i] == bleep2 || palabras[i] == bleep3)
			cout << "BLEEP" << endl;
		else {
			cout << palabras[i] << "\n";
		}
			
			
		
	}
	keep_window_open();
	return 0;
}*/
	

/*int main() //try this 5
{
	cout << cuadrado(50) << endl;
	keep_window_open();
	return 0;
}*/



/*int main() // try this 4
{
	char a = 'A';
	int s = a;

	for (int i = 65; i < 123; ++i) {
		cout << a << "\t" << s << endl;
		a++;
		s = a;
	}
	keep_window_open();
	return 0;
}*/



/*int main() // try this 3
{
	char a = 'a';
	int s = a;
	int i = 0;

	while (i < 26) {
		cout << a << "\t" << s << endl;
		++a;
		s = a;
		++i;
	}

	keep_window_open();
	return 0;
}*/

/*int main() // try this 2
{
	constexpr double yen_a_dolares = 0.0089;
	constexpr double libras_a_dolares = 1.31;
	constexpr double kroner_a_dolares = 0.12;
	constexpr double yuan_a_dolares = 0.15;
	
	constexpr double dolares_a_yuan = 6.86;
	constexpr double yen_a_yuan = 0.061;
	constexpr double libras_a_yuan = 8.98;
	constexpr double kroner_a_yuan = 0.83;
	
	constexpr double yen_a_kroner = 0.074;
	constexpr double libras_a_kroner = 10.81;
	constexpr double dolares_a_kroner = 8.27;
	constexpr double yuan_a_kroner = 1.20;

	double cantidad_currency = 0.0;
	char unidad_adquirida = ' ';
	char unidad_a_convertir = ' '; // en este caso no podemos usar string por el switch case

	cout << "que unidad de moneda manejas, yen (y), libras(l), kronen (k), dolares (d), yuan(c)" << endl; // c por china
	cin >> unidad_adquirida;
	
	cout << "cuantas(os) unidades tienes?" << endl;
	cin >> cantidad_currency;

	switch (unidad_adquirida) {

	case 'y':
		cout << "a que unidad lo quieres convertir, dolares(d), yuan(c) o kroner(k)" << endl;
		cin >> unidad_a_convertir;
		switch (unidad_a_convertir) {
		case 'd':
			cout << cantidad_currency << " yen son: " << cantidad_currency * yen_a_dolares << " dolares" << endl;
			break;
		
		case 'c':
			cout << cantidad_currency << " yen son: " << cantidad_currency * yen_a_yuan << " yuan" << endl;
			break;

		case 'k':
			cout << cantidad_currency << " yen son: " << cantidad_currency * yen_a_kroner << " yuan" << endl;
			break;

		default:
			cout << "no se a que unidad te refieres" << endl;
			break;
		}
	    break;

	case 'l':
		 cout << "a que unidad lo quieres convertir, dolares(d), yuan(c) o kroner(k)" << endl;
		 cin >> unidad_a_convertir;
		 switch (unidad_a_convertir) {
		 case 'd':
			 cout << cantidad_currency << " libras son:" << cantidad_currency * libras_a_dolares << " dolares" << endl;
			 break;

		 case 'c':
			 cout << cantidad_currency << " libras son:" << cantidad_currency * libras_a_yuan << " yuan" << endl;
			 break;

		 case 'k':
			 cout << cantidad_currency << " libras son:" << cantidad_currency * libras_a_kroner << " kroner" << endl;
			 break;
		 
		 default:
			 cout << "no se a que unidad te refieres" << endl;
			 break;
		 }
		 break;

	case'k':
		 cout << "a que unidad lo quieres convertir, dolares(d) o yuan(C)" << endl;
		 cin >> unidad_a_convertir;
		 switch (unidad_a_convertir) {
		 case 'd':
			 cout << cantidad_currency << " kroner son: " << cantidad_currency * kroner_a_dolares << " dolares" << endl;
			 break;
		 
		 case 'c':
			 cout << cantidad_currency << " kroner son: " << cantidad_currency * kroner_a_yuan << " yuan" << endl;
			 break;

		 default:
			 cout << "no se a que unidad te refieres" << endl;
			 break;
		 }
		 break;
    
	case'd':
		cout << "a que unidad lo quieres convertir, yuan(c) o kroner (k)" << endl;
		cin >> unidad_a_convertir;
		switch (unidad_a_convertir) {
		case'c':
			cout << cantidad_currency << " dolares son:" << cantidad_currency * dolares_a_yuan << " yuan" << endl;
			break;
		case'k':
			cout << cantidad_currency << " dolares son:" << cantidad_currency * dolares_a_kroner << " kroner" << endl;
			break;
		default:
			cout << "no se a que unidad te refieres" << endl;
			break;
		}
		break;

	case'c':
		cout << "a que unidad lo quieres convertir, dolares(d) o kroner(k)" << endl;
		cin >> unidad_a_convertir;
		switch (unidad_a_convertir) {
		case'd':
			cout << cantidad_currency << " yuan son: " << cantidad_currency * yuan_a_dolares << " dolares" << endl;
			break;

		case'k':
			cout << cantidad_currency << " yuan son: " << cantidad_currency * yuan_a_kroner << " kroner" << endl;
			break;

		default:
			cout << "no se a que unidad te refieres" << endl;
			break;
		}
		break;

	default:
		cout << "no se a que unidad te refieres" << endl;
		break;
	}
	
	keep_window_open();
	return 0;
}*/

/*int main()
{
	constexpr double yen_a_dolares = 0.0089;
	constexpr double libras_a_dolares = 1.31;
	constexpr double kronen_a_dolares = 0.12;

	string unidad_a_convertir = " ";
	double unidades_de_moneda = 0.0;

	cout << "que moneda te gustaria convertir a dolares, yen, libra o kroner" << endl;
	cin >> unidad_a_convertir;

	cout << "cuantas(os) " << unidad_a_convertir << " tienes?" << endl;
	cin >> unidades_de_moneda;

	if (unidad_a_convertir == "yen")
		cout << unidades_de_moneda << " yens son: " << yen_a_dolares * unidades_de_moneda << " dolares" << endl;
	else if (unidad_a_convertir == "libra")
		cout << unidades_de_moneda << " libras son: " << libras_a_dolares * unidades_de_moneda << " dolares" << endl;
	else if (unidad_a_convertir == "kroner")
		cout << unidades_de_moneda << " kronen son: " << kroner_a_dolares * unidades_de_moneda << " dolares" << endl;
	else
		cout << "moneda desconocida" << endl;

	keep_window_open();
	return 0;

}*/