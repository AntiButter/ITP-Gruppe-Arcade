#include <windows.h>
#include "Battleship.h"
#include <conio.h>

Battleship::Battleship()
{
	setShipType("Kreuzer");
	buildShip();
}

Battleship::~Battleship()
{
}

void Battleship::special(std::shared_ptr<Ship> enemyShip)
{
	int newDMG = 0;
	while (rollDice() >= 10 - enemyShip->getSize() && enemyShip->getHull() > 0)
	{
		std::cout << "\nTREFFER! " << getDmg() / getDistance(enemyShip) << " - Spezial aktiviert.";
		newDMG += getDmg();
		enemyShip->setHull(enemyShip->getHull() - (getDmg() / getDistance(enemyShip)));
		_getch();
	}
	std::cout << "\nSchaden gesamt: -" << newDMG / getDistance(enemyShip);
	_getch();
	if (enemyShip->getHull() == 0)
	{
		std::cout << "\n\nFeindlicher " << enemyShip->getShipType() << " wurde zerstort.";
		_getch();
	}
}

void Battleship::buildShip()
{
	setHull(250);
	setSize(8);
	setDmg(50);
}