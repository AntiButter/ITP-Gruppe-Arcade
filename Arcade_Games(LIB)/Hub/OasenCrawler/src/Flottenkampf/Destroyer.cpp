#include <Windows.h>
#include <conio.h>

#include "Destroyer.h"

Destroyer::Destroyer()
{
	setShipType("Zerstorer");
	buildShip();
}

Destroyer::~Destroyer()
{
}

void Destroyer::special(Ship* enemyShip)
{
	if (rollDice() + 2 >= 10 - enemyShip->getSize())
	{
		std::cout << "\n\nTREFFER!";
		std::cout << "\nSchaden: -" << getDmg() / getDistance(enemyShip);
		enemyShip->setHull(enemyShip->getHull() - (getDmg() / getDistance(enemyShip)));
		_getch();
	}
	if (enemyShip->getHull() == 0)
	{
		std::cout << "\n\nFeindlicher " << enemyShip->getShipType() << " wurde zerstort.";
		_getch();
	}
}

void Destroyer::buildShip()
{
	setHull(150);
	setSize(6);
	setDmg(60);
}
