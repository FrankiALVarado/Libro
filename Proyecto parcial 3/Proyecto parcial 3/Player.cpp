#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

Player::Player(string nombre, int vida,int nivel, double exp, int ataque, int defensa, int velocidad)
{
    nombre = "";
	nivel = 1;
	exp = 0;
	vida = 200;
    ataque = 10;
	defensa = 10;
	velocidad = 100;
	
}

void Player::player_GetName(Player & r)
{
	string name;
	cin >> name;
	r.nombre = name;
}

void Player::print_name(const Player & r)
{
	cout << r.nombre;
}

void Player::initialize_stats(Player & r)
{
	r.nivel = 1;
	r.exp = 0;
    r.vida = 200;
	r.ataque = 10;
	r.defensa = 1;
	r.velocidad = 100;
}

void Player::check_level_up(Player & r)
{
	if (r.exp >= (r.nivel * 10)) {
		r.nivel++;
		r.vida += 10;
		r.ataque += 2;
		r.defensa++;
		r.velocidad++;
		cout << "felicidades has subido de nivel al nivel " << r.nivel << endl;
	}
}