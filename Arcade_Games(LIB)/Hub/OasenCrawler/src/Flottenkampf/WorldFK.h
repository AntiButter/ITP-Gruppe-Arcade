#pragma once
#include <iostream>

#include "Ship.h"
#include "playerFK.h"
class PlayerFK;


class WorldFK
{
	public:
		WorldFK();
		~WorldFK();

		void printWorld(int cursorX, int cursorY);

		void scanWorld(std::shared_ptr<PlayerFK> newPlayer, std::shared_ptr<PlayerFK> bot);

		void setWorld(int x, int y, int value);

		int checkPos(int x, int y);

	private:
		int world[10][15];
};

