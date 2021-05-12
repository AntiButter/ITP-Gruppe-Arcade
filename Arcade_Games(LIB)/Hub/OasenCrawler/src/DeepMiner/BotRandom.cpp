#include "BotRandom.h"
#include <iostream>
#include <algorithm>
#include <stdlib.h> 
#include <random>

BotRandom::BotRandom() {
	posX = 0;
	posY = 0;
	totalPoints = 0;
}

BotRandom::~BotRandom() {

}

std::vector<std::vector<std::vector<int>>> BotRandom::mine(std::vector<std::vector<std::vector<int>>> world) {
	int minedValue = 0;
	int tempValueA = 0;
	int tempValueB = 0;

	//auto rd = std::random_device{};
	auto rng = std::default_random_engine{ std::random_device{}() };
	std::shuffle(std::begin(world[posY][posX]), std::end(world[posY][posX]), rng);

	minedValue = world[posY][posX][9];
	minedValue += world[posY][posX][8];
	minedValue += world[posY][posX][7];
	minedValue += world[posY][posX][6];
	for (int x = 0; x < 4; x++) {
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
