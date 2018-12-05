#pragma once
#include "Enemy.h"
#include <fstream>
#include "Player.h"
using std::ifstream;
using std::ios;
using std::endl;
class Zone
{
public:
	Zone(); 
	Player jugador;
	Enemy guardian;
	bool already_Through;
	bool in;
	bool l; //                  {  izquierda
	bool r; // caminos posibles {  derecha
	bool m; //       {  en medio
	bool bl;//       ( atras-izquierda
	bool bm;//       { atras-medio
	bool br;//       { atras-derecha
	bool already_in;
	Zone * izq;
	Zone * med;
	Zone * der;
	Zone * backl;
	Zone * back;
	Zone * backr;
	void print_Zone();
	void print_Adjacent(const Zone & x);  
	void start_Player(Player &p, Zone & z); 
	Zone(Enemy x, bool in, bool already, bool l, bool r, bool m ,bool bl, bool bm, bool br, Player p, Zone * izq, Zone * med, Zone * der, Zone * back, Zone * backl, Zone * backr);
	void delete_pointers(Zone * izq, Zone * med, Zone * der, Zone * back, Zone * backl, Zone * backr);
	~Zone();
};

class Nivel
{
public:
	Nivel();
	Zone uno;
	Zone uno_l;
	Zone uno_r;
	Zone dos;
	Zone dos_l;
	Zone dos_r;
	Zone tres;
	Nivel(Zone uno, Zone uno_l, Zone uno_r, Zone dos, Zone dos_l, Zone dos_r, Zone tres);
	void Initialize_lvl(Nivel & n);
	void print_Adjacent(const Nivel & x);
	~Nivel();
};
