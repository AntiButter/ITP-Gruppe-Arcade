#include "BotHighest.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h> 

BotHighest::BotHighest() {
	posX = 0;
	posY = 0;
	totalPoints = 0;
}

BotHighest::~BotHighest() {

}

std::vector<std::vector<std::vector<int>>> BotHighest::mine(std::vector<std::vector<std::vector<int>>> world) {
	int minedValue = 0;
	int tempValueA = 0;
	int tempValueB = 0;

	std::sort(world[posY][posX].begin(), world[posY][posX].end());

	minedValue = world[posY][posX][9];
	for (int i = 0; i < 10; i++) {
		tempValueA = world[posY][posX][i];
		world[posY][posX][i] = tempValueB;
		tempValueB = tempValueA;
	}
	totalPoints += minedValue;
	std::cout << "Der Miner hat " << minedValue << " Gold abgebaut, dadurch besitzt er nun " << totalPoints << " Gold!" << std::endl;
	return world;
}
