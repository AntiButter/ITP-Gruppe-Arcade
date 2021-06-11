#pragma once
#include <vector>
#include <string>
#include "Ship.h"
#include "WorldFK.h"
class WorldFK;
class Ship;

class PlayerFK : public std::enable_shared_from_this<PlayerFK>
{
	public:
		PlayerFK(std::shared_ptr<WorldFK> ocean);
		PlayerFK(std::shared_ptr<WorldFK> ocean, int fleetSize);
		~PlayerFK();

		void createBotFleet(int fleetSize, std::shared_ptr<WorldFK> ocean);

		void createFleet(int fleetSize, std::shared_ptr<WorldFK> ocean);

		void queryName();

		void setName(std::string name);

		int getStarterFleetSize();

		int queryFleetSize();

		void queryNewShip(std::shared_ptr<WorldFK> ocean);

		void addShip(int type);

		std::string nameGenerator();
		
		std::string getName();

		std::vector<std::shared_ptr<Ship>> fleet;

		void playerTurn(std::shared_ptr<WorldFK> ocean, std::shared_ptr<PlayerFK> enemy);

		void moveShip(std::shared_ptr<Ship> target, std::shared_ptr<WorldFK> ocean);

		int queryAttackShip(std::shared_ptr<PlayerFK> target, std::shared_ptr<WorldFK> ocean);

		void printFleet(std::shared_ptr<PlayerFK> target, int x, int y);

		void moveCursor(char direction);

		void botTurn(std::shared_ptr<WorldFK> ocean, std::shared_ptr<PlayerFK> newPlayer);

		void moveBot(int index, std::shared_ptr<WorldFK> ocean);

		//void checkSelection(int x, int y);

	private:
		std::string name;

		int cursor[2];
		int fleetSize;
};

