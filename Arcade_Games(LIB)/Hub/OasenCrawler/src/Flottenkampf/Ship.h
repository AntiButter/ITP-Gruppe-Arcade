#pragma once
#include <string>
#include <memory>

#include "WorldFK.h"
#include "PlayerFK.h"

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

		void queryPosition(std::shared_ptr<WorldFK> ocean, std::shared_ptr<PlayerFK> newPlayer);

		std::string getShipType();

		void setShipType(std::string signation);

		int getDistance(std::shared_ptr<Ship> target);

		virtual void special(std::shared_ptr<Ship> enemyShip) = 0;

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