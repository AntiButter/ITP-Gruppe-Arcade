#pragma once
#include <vector>
#include <string>
#include "Ship.h"
#include "WorldFK.h"
class WorldFK;

class Ship;

class PlayerFK
{
	public:
		PlayerFK(WorldFK* ocean);
		PlayerFK(WorldFK* ocean, int fleetSize);
		~PlayerFK();

		void createBotFleet(int fleetSize, WorldFK* ocean);

		void createFleet(int fleetSize, WorldFK* ocean);

		void queryName();

		void setName(std::string name);

		int queryFleetSize();

		void queryNewShip(WorldFK* ocean);

		void addShip(int type);

		std::string nameGenerator();
		
		std::string getName();

		std::vector<Ship*> fleet;

		void playerTurn(WorldFK* ocean, PlayerFK* enemy);

		void moveShip(Ship* target, WorldFK* ocean);

		int queryAttackShip(PlayerFK* target, WorldFK* ocean);

		void printFleet(PlayerFK* target, int x, int y);

		void moveCursor(char direction);

		void botTurn(WorldFK* ocean, PlayerFK* newPlayer);

		void moveBot(int index, WorldFK* ocean);

		//void checkSelection(int x, int y);

	private:
		std::string name;

		int cursor[2];
};

