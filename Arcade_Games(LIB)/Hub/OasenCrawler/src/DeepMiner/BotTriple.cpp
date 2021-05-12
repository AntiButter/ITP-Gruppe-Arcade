#include "BotTriple.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h> 

BotTriple::BotTriple() {
	posX = 0;
	posY = 0;
	totalPoints = 0;
}

BotTriple::~BotTriple() {

}

std::vector<std::vector<std::vector<int>>> BotTriple::mine(std::vector<std::vector<std::vector<int>>> world) {
	int minedValue = 0;
	int tempValueA = 0;
	int tempValueB = 0;

	minedValue = world[posY][posX][9];
	minedValue += world[posY][posX][8];
	minedValue += world[posY][posX][7];
	for (int x = 0; x < 3; x++) {
		tempValueB = 0;
		for (int i = 0; i < 10; i++) {
			tempValueA = world[posY][posX][i];
			world[posY][posX][i] = tempValueB;
			tempValueB = tempValueA;
		}
	}

	totalPoints += minedValue;
	std::cout << "Der Miner hat " << minedValue << " Gold abgebaut, dadurch besitzt er nun " << totalPoints << " Gold!" << std::endl;
	return world;
}

