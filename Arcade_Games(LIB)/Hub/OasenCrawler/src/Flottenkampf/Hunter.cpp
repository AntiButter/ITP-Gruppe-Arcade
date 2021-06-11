#include <Windows.h>
#include <conio.h>

#include "Hunter.h"

Hunter::Hunter()
{
	setShipType("Jaeger");
	buildShip();
}

Hunter::~Hunter()
{
}

void Hunter::special(std::shared_ptr<Ship> enemyShip)
{
	int dice = rollDice();
	if (dice >= 9)
	{
		std::cout << "\n\nTREFFER!";
		std::cout << "\nSchaden: -" << (getDmg() / getDistance(enemyShip)) * 2;
		enemyShip->setHull(enemyShip->getHull() - (getDmg() / getDistance(enemyShip)) * 2);
	}
	else if (dice >= 10 - enemyShip->getSize())
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

void Hunter::buildShip()
{
	setHull(75);
	setSize(4);
	setDmg(30);
}
