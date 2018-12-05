#include "Zona.h" 



Zone::Zone()
{
	Player jugador;
	Enemy guardian;
	bool already_Through = false;
	bool l = false; 
	bool r = false; 
	bool m = false; 
	bool already_in = false;	
	Zone * izq = nullptr;
	Zone * med = nullptr;
	Zone * der = nullptr;
	Zone * backl = nullptr;
	Zone * back = nullptr;
	Zone * backr = nullptr;
}

void Zone::print_Zone()
{
	ifstream * inFile = new ifstream("Zone.txt", ios::in);
	string *buffer = new string;
	while (getline(*inFile, *buffer)) {
		cout << "                                                        " << *buffer << endl;
	}
	inFile->close();
	delete inFile;
	delete buffer;
}

void Zone::print_Adjacent(const Zone & x)
{
	if (x.l && x.r) {
		ifstream *inFile = new ifstream("adjacent_zones.txt", ios::in);
		string *buffer = new string;
		while (getline(*inFile, *buffer)) {
			cout << "                   " << *buffer << "                                                 " << *buffer << endl;
		}
		inFile->close();
		delete inFile;
		delete buffer;
	}
	else if (x.m) {
		ifstream *inFile = new ifstream("adjacent_zones.txt", ios::in);
		string *buffer = new string;
		while (getline(*inFile, *buffer)) {
			cout << "                                                        " << *buffer << endl;
		}
		inFile->close();
		delete inFile;
		delete buffer;
	}
}

void Zone::start_Player(Player & p, Zone & z)
{
	z.jugador = p;
	z.in = true;
}

Zone::Zone(Enemy x, bool in, bool already, bool l, bool r, bool m,bool bl, bool bm, bool br, Player p, Zone * izq, Zone * med, Zone * der, Zone * back, Zone * backl, Zone * backr)
{
	x;
	already = false;
	l = false;
	r = false;
	m = false;
	bl = false;
	bm = false;
	br = false;
	p;
	izq = nullptr;
	med = nullptr;
	der = nullptr;
	back = nullptr;
	backl = nullptr;
	backr = nullptr;
}

Zone::~Zone()
{
}

Nivel::Nivel()
{
}

Nivel::Nivel(Zone uno, Zone uno_l, Zone uno_r, Zone dos, Zone dos_l, Zone dos_r, Zone tres)
{
	uno;
	uno_l;
	uno_r;
	dos;
	dos_l;
	dos_r;
	tres;
}

void Nivel::Initialize_lvl(Nivel & n)
{
	n.uno.in = true;
	n.uno.guardian.initialize_Goblin(n.uno.guardian);
	n.uno.l = true;
	n.uno.m = false;
	n.uno.r = true;
	n.uno.bl = false;
	n.uno.bm = false;
	n.uno.br = false;
	n.uno.already_in = true;
	

	n.uno.izq = &n.uno_l;
	n.uno.med = nullptr;
	n.uno.der = &n.uno_r;
	n.uno.backl = nullptr;
	n.uno.back = nullptr;
	n.uno.backr = nullptr;
//-----------------------------------------------------------------------------	

	n.uno_l.in = false;
	n.uno_l.guardian.initialize_Goblin(n.uno_l.guardian);
	n.uno_l.l = false;
	n.uno_l.m = true;
	n.uno_l.r = false;
	n.uno_l.bl = false;
	n.uno_l.bm = true;
	n.uno_l.br = false;
	n.uno_l.already_in = false;
	
	n.uno_l.izq = nullptr;
	n.uno_l.med = &n.dos;
	n.uno_l.der = nullptr;
	n.uno_l.back = &n.uno;
	n.uno_l.backl = nullptr;
	n.uno_l.backr = nullptr;
//-----------------------------------------------------------------------------------

	n.uno_r.in = false;
	n.uno_r.guardian.initialize_Goblin(n.uno_r.guardian);
	n.uno_r.l = false;
	n.uno_r.m = true;
	n.uno_r.r = false;
	n.uno_r.bl = false;
	n.uno_r.bm = true;
	n.uno_r.br = false;
	n.uno_r.already_in = false;


	n.uno_r.izq = nullptr;
	n.uno_r.med = &n.dos;
 	n.uno_r.der = nullptr;
	n.uno_r.back = &n.uno;
	n.uno_l.backl = nullptr;
	n.uno_l.backr = nullptr;
//--------------------------------------------------------------------------------------------

	n.dos.in = false;
	n.dos.guardian.initialize_Goblin(n.dos.guardian);
	n.dos.l = true;
	n.dos.m = false;
	n.dos.r = true;
	n.dos.bl = true;
	n.dos.bm = false;
	n.dos.br = true;
	n.dos.already_in = false;


	n.dos.izq = &n.dos_l;
	n.dos.med = nullptr;
	n.dos.der = &n.dos_r;
	n.dos.back = nullptr;
	n.dos.backl = &n.uno_l;
	n.dos.backr = &n.uno_r;
//----------------------------------------------------------------------------------------------

	n.dos_l.in = false;
	n.dos_l.guardian.initialize_Goblin(n.dos_l.guardian);
	n.dos_l.l = false;
	n.dos_l.m = true;
	n.dos_l.r = false;
	n.dos_l.bl = false;
	n.dos_l.br = false;
	n.dos_l.bm = true;
	n.dos_l.already_in = false;

	n.dos_l.izq = nullptr;
	n.dos_l.med = &n.tres;
	n.dos_l.der = nullptr;
	n.dos_l.back = &n.dos;
	n.dos_l.backl = nullptr;
	n.dos_l.backr = nullptr;
//-----------------------------------------------------------------------------------------------
	n.dos_r.in = false;
	n.dos_r.guardian.initialize_Goblin(n.dos_r.guardian);
	n.dos_r.l = false;
	n.dos_r.m = true;
	n.dos_r.r = false;
	n.dos_r.bl = false;
	n.dos_r.br = false;
	n.dos_r.bm = true;
	n.dos_r.already_in = false;

	n.dos_r.izq = nullptr;
	n.dos_r.med = &n.tres;
	n.dos_r.der = nullptr;
	n.dos_r.back = &n.dos;
	n.dos_r.backl = nullptr;
	n.dos_r.backr = nullptr;
//------------------------------------------------------------------------------------------------

	n.tres.in = false;
	n.tres.guardian.initialize_KingGob(n.tres.guardian);
	n.tres.l = false;
	n.tres.m = false;
	n.tres.r = false;
	n.tres.bl = true;
	n.tres.br = true;
	n.tres.bm = false;
	n.tres.already_in = false;

	n.tres.izq = nullptr;
	n.tres.der = nullptr;
	n.tres.med = nullptr;
	n.tres.back = nullptr;
	n.tres.backl = &n.dos_l;
	n.tres.backr = &n.dos_r;
}

void Nivel::print_Adjacent(const Nivel & x)
{ 
	
}

Nivel::~Nivel()
{
 
}
