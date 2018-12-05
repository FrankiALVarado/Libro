#include "Enemy.h"
#include <iostream>
using std::cout;
Enemy::Enemy()
{
}


Enemy::Enemy(string nombre, int nivel, double experiencia, int vida, int ataque, int defensa, int velocidad)
{
	nombre = "";
	nivel = 1;
	experiencia = 10;
	vida = 10;
	ataque = 5;
	defensa = 3;
	velocidad = 70;
}

void Enemy::initialize_Goblin(Enemy & x)
{
	x.nombre = "Goblin";
	x.nivel = 1;
	x.experiencia = 10;
	x.vida = 10;
	x.ataque = 5;
	x.defensa = 0;
	x.velocidad = 80;
}

void Enemy::initialize_KingGob(Enemy & x)
{
	x.nombre = "King Goblin";
	x.nivel = 10;
	x.experiencia = 300;
	x.vida = 300;
	x.ataque = 20;
	x.defensa = 5;
	x.velocidad = 95;
}


Enemy::~Enemy()
{
}

