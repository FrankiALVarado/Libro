#include  "Includes.h"
#include "Player.h"
#include "Enemy.h"
#include "Zona.h"
void travel(Player & p);
int travel_Menu(Player & p, Zone & n);
void Move_Menu(Player & p, Zone & n);
void load_game()
{
	Player p;
	cout << "archivo para cargar al personaje" << endl;
	string eleccion;
	cin >> eleccion;
	if (!cin)
		load_game();
	
	ifstream * inFile = new ifstream(eleccion, ios::in);
	string nombre;
	int nivel;
	double exp;
	int vida;
	int ataque;
	int defensa;
	int velocidad;

	*inFile >> nombre >> nivel >> exp >> vida >> ataque >> defensa >> velocidad;
	p.nombre = nombre;
	p.nivel = nivel;
	p.exp = exp;
	p.ataque = ataque;
	p.defensa = defensa;
	p.velocidad = velocidad;

	delete inFile;
	travel(p);

}
void save_Game(Player & p, Zone & n)
{ 
	cout << "nombre para guardar su personaje" << endl;
	ofstream * outFile = new ofstream;
	string nombre;
	cin >> nombre;
	if (!cin)
		save_Game(p, n);
	
	nombre += "-personaje";
	outFile->open(nombre, ios::out);
	*outFile << p.nombre << " " << p.nivel << " " << p.exp << " " << p.vida << " " << p.ataque << " " << p.defensa << " " << p.velocidad;

	delete outFile;
}
void battle(Player & p, Enemy & x);
void Move(Player p, Zone & n, const string & eleccion)
{
	if (eleccion == "izquierda") {
		n.in = false;
		n.already_in = true;
		n.izq->jugador = p;
		n.jugador;
		n.izq->in = true;
		n.izq->already_in = true;
		travel_Menu(p, *n.izq);
	}
	if (eleccion == "derecha") {
		n.in = false;
		n.already_in = true;
		n.der->jugador = p;
		n.jugador;
		n.der->in = true;
		n.der->already_in = true;
		travel_Menu(p, *n.der);
	}
	if (eleccion == "medio") {
		n.in = false;
		n.already_in = true;
		n.med->jugador = p;
		n.jugador;
		n.med->in = true;
		n.med->already_in = true;
		travel_Menu(p, *n.med);
	}
	if (eleccion == "atras-izquierda") {
		n.in = false;
		n.already_in = true;
		n.backl->jugador = p;
		n.jugador;
		n.backl->in = true;
		n.backl->already_in = true;
		travel_Menu(p, *n.backl);
	}
	if (eleccion == "atras-derecha") {
		n.in = false;
		n.already_in = true;
		n.backr->jugador = p;
		n.jugador;
		n.backr->in = true;
		n.backr->already_in = true;
		travel_Menu(p, *n.backr);
	}
	if (eleccion == "atras-medio") {
		n.in = false;
		n.already_in = true;
		n.back->jugador = p;
		n.jugador;
		n.back->in = true;
		n.back->already_in = true;
		travel_Menu(p, *n.back);
	}

	
}

void Move_Menu(Player & p, Zone & n)
{
	cout << "A donde te quieres mover?" << endl;
	if ((n.l && n.r) && !(n.bl && n.br && n.bm && n.m) ) {
		cout << "Izquierda o derecha" << endl;
		string eleccion;
		cin >> eleccion;
		if (eleccion == "izquierda" || eleccion == "derecha")
			Move(p, n, eleccion);
		else
			Move_Menu(p, n);
	}
	else if ((n.bm && n.m) && !(n.l)) {
		cout << "atras-medio o medio" << endl;
		string eleccion;
		cin >> eleccion;
		if (eleccion == "atras-medio" || eleccion == "medio")
			Move(p, n, eleccion);
		else
			Move_Menu(p, n);
	}
	else if (n.bl && n.br && n.r && n.l) {
		cout << "izquierda o derecha o atras-izquierda o atras-derecha" << endl;
		string eleccion;
		cin >> eleccion;
		if (eleccion == "atras-derecha" || eleccion == "atras-izquierda" || eleccion == "izquierda" || eleccion == "derecha")
			Move(p, n, eleccion);
		else
			Move_Menu(p, n);
	}
	else if ((n.bl && n.br) && !(n.l)) {
		cout << "atras-izquierda o atras-derecha" << endl;
		string eleccion;
		cin >> eleccion;
		if (eleccion == "atras-derecha" || eleccion == "atras-izquierda")
			Move(p, n, eleccion);
		else
			Move_Menu(p, n);
	}
}
int travel_Menu(Player & p, Zone & n)
{
	battle(p, n.guardian);
	n.print_Adjacent(n);

	cout << "Que deseas hacer: " << endl;
	cout << "a) Moverte" << endl;
	cout << "b) Guardar" << endl;
	cout << "c) Salir" << endl;
	char eleccion;
	cin >> eleccion;

	switch (eleccion)
	{
	case 'a':
		Move_Menu(p,n);
		break;
	case 'b':
		save_Game(p, n);
		cout << "Continuar jugando s/n?" << endl;
		char eleccion2;
		cin >> eleccion2;
		if (eleccion2 == 's')
			travel_Menu(p, n);
		else
			return 0;
		break;
	case 'c':
		cout << "de verdad quieres salir sin guardar s\n?" << endl;
		cin >> eleccion2;
		if (eleccion2 == 's')
			return 0;
		else
			travel_Menu(p, n);
		break;
	default:
		travel_Menu(p,n);
		break;
	}
}
void travel(Player & p)
{
	Nivel * nivel = new Nivel;
	nivel->Initialize_lvl(*nivel);
	nivel->uno.start_Player(p, nivel->uno);
	nivel->uno.print_Zone();
	travel_Menu(p, nivel->uno);
	delete nivel;
	
}

void new_Game();
void parse(const string & palabra, Player & p)
{
	if (palabra == "battle") {
		Enemy * goblin = new Enemy;
		goblin->initialize_Goblin(*goblin);
		battle(p, *goblin);
		delete goblin;
	}
	else if (palabra == "name")
		p.print_name(p);
	else if (palabra == "name,"){ 
		p.print_name(p);
		cout << ", ";
	}
	else if (palabra == "travel") {
		travel(p);
	}
	else{
		cout << palabra << " ";
	}
	
}
void show_Menu()
{
	char eleccion;
	cout << " Bienvenido a Amnesiac Knight" << endl
		<< "a) Nuevo juego" << endl
		<< "b) Cargar juego" << endl
		<< "c) Salir" << endl; 
	cin >> eleccion;
	system("CLS");
	switch (eleccion)
	{
	case 'a':
	   new_Game();
	   break;

	case 'c':
		load_game();
		break;
	default:
		show_Menu();
		break;
	}
}

void new_Game()
{
	ifstream *inFile = new ifstream("amnesiacknight.txt", ios::in);
	string buffer;
	Player * jugador = new Player;
	string nombre;
	cout << "como quieres llamar a tu personaje?" << endl;
	jugador->player_GetName(*jugador);
	jugador->initialize_stats(*jugador);
	while (getline(*inFile, buffer)) {
		stringstream ss{ buffer };
		for (string evento; ss >> evento;) {
			parse(evento, *jugador);
		}
		cout << endl;
	}
	delete jugador;
	delete inFile;
}

int main()
{
	show_Menu();

	keep_window_open();
	return 0;
}
void battle(Player & p, Enemy & x)
{

	cout << endl;
	cout << endl;
	cout << "ha iniciado una batalla contra " << x.nombre << " nivel " << x.nivel << endl;
	cout << "presione una tecla para continuar" << endl;
	string wait;
	cin >> wait;
	if (p.velocidad < x.velocidad) { // golpe de oportunidad
		p.vida -= p.defensa - x.ataque;
		cout << "El golpe de oportunidad lo gana " << x.nombre << " inflige " << p.defensa - x.ataque << "hits" << endl;
	}
	else if (x.velocidad < p.velocidad) {
		x.vida = x.vida - (p.ataque - x.defensa);
		cout << "El golpe de oportunidad lo gana " << p.nombre << " inflige " << p.ataque - x.defensa << "hits" << endl;
	}
	while (p.vida < 0 || x.vida > 0) {

	}

	if (x.vida <= 0){
		cout << "Has matado a " << x.nombre << endl;
	    cout << "Has ganado " << x.experiencia << " puntos de experiencia" << endl;
		p.exp += x.experiencia;
		p.check_level_up(p);
    }
	else if (p.vida <= 0) {
		cout << "Has sido derrotado" << endl;
		cout << "Presiona una tecla para continuar" << endl;
		cin >> wait;
		delete &p;
		delete &x;
		show_Menu();
	}
	
	cout << "presione una tecla para continuar" << endl;
	cin >> wait;
}