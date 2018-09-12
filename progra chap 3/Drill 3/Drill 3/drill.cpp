#include "Includes.h"

int main()
{
	cout << "A quien le quieres escribir una carta" << endl;
	string nombre; 
	cin >> nombre; 
	cout << "Querido " << nombre << ", " << "espero que te la vida no te agarre a golpes." << endl		 <<"no olvides hidratarte correctamente." << endl;		string nombre_amigo;	cout << "preguntale en la carta por un amigo" << endl;	cin >> nombre_amigo;	cout << "has visto a " << nombre_amigo << " recientemente?" << endl;	char sexamigo = 0;	cout << "escriba m si su amigo es hombre o f en caso de ser mujer" << endl;	cin >> sexamigo;	if (sexamigo == 'm')		cout << "dile a nuestro amigo " << nombre_amigo << " que me marque cuando pueda" << endl;	if (sexamigo == 'f')		cout << "dile a nuestra amiga " << nombre_amigo << " que me marque cuando pueda" << endl;	int edad;	cout << "cuantos a" << char(164) << "os tiene el destinatario de la carta" << endl;	cin >> edad;	if (edad < 0 || edad > 110)		simple_error("no seas payasito");	else		cout << "supe de tu cumplea" << char(164) << "os, ahora tienes " << edad << " a" << char(164) << "os de edad" << endl;	if (edad < 12)		cout << "el proximo a" << char(164) << "o cumpliras " << edad + 1 << endl;	if (edad == 17)		cout << "podras votar el proximo a" << char(164) << 'o' << endl;	if (edad >= 70)		cout << "esperos disfrutes de tu retiro/asilo" << endl;	cout << "Atentamente , Francisco Alvarado" << endl;		keep_window_open();	return 0; 
}