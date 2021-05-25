#pragma once
#include <string>

#include "WorldFK.h"

class WorldFK;

class Ship
{
	public:
		Ship();
		virtual ~Ship();

		void setHull(int value);

		int getHull();

		void setSize(int value);

		int getSize();

		void setDmg(int value);

		int getDmg();

		void setPosition(int x, int y);

		int rollDice();

		void queryPosition(WorldFK* ocean);

		std::string getShipType();

		void setShipType(std::string signation);

		int getDistance(Ship* target);

		virtual void special(Ship* enemyShip) = 0;

		virtual void buildShip() = 0;

		//void setPosition(int x, int y);

		int posX;
		int posY;

	private:

		int hull;
		int size;
		int dmg;
		std::string shipType;
};