#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Player
{
public:
	Player();
	string nombre;
	int nivel;
	double exp;
	int vida;
	int ataque;
	int defensa;
	int velocidad;
	Player(string nombre,int nivel, int vida, double exp, int ataque, int defensa, int velocidad);
	void player_GetName(Player & r);
	void print_name(const Player & r);
	void initialize_stats(Player & r);
	void check_level_up(Player & r);
	~Player();
};