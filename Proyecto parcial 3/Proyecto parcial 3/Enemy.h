#pragma once
#include <string>
using std::string;
using std::getline;
class Enemy
{
public:
	Enemy();
	string nombre;
	int nivel;
	double experiencia;
	int vida;
	int ataque;
	int defensa;
	int velocidad;
	Enemy(string nombre, int nivel, double experiencia, int vida, int ataque, int defensa, int velocidad);
	void initialize_Goblin(Enemy & x);
	void initialize_KingGob(Enemy & x);

	~Enemy();
};