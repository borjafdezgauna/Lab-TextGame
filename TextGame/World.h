#pragma once
#include "Timer.h"

class World
{
	//un caracter por cada casilla. Se inicializa en el constructor
	char* m_pContent;
	//el valor con el que inicializaremos cada casilla
	char m_defaultValue;
	//tama�o del mapa en x e y
	int m_sizeX, m_sizeY;
	

	int getPosInArray(int x, int y) const;

	Timer m_timer;

public:
	World(int sizeX, int sizeY, char defaultValue = ' ');
	//liberar la memoria reservada en el constructor
	~World();

	int getSizeX() const;
	int getSizeY() const;

	//se asegura de que x e y est�n en rango
	void clamp(int& x, int& y) const;

	char get(int x, int y) const;
	void set(int x, int y, char value);
	char move(int originX, int originY, int destX, int destY);
	//dibujar el mapa
	void draw();
};