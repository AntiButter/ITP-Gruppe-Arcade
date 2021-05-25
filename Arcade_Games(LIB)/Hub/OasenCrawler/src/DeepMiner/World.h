#ifndef World_HEADER
#define World_HEADER

#include "Player.h"
#include <vector>

class World {
public:
	World(int yLength, int xLength);
	~World();

	void createRandomWorld();
	void changeWorld();
	void calcTotalSum();
	void chooseBotsPlayer();
	void gamePlayer();
	void endScreen();

	std::vector<std::vector<std::vector<int>>> getWorld() const;
	int getPlayerTotalPoints();
	int getTotalSumStart();
private:
	std::vector<std::vector<std::vector<int>>> world;
	int totalSum, yLength, xLength, totalSumStart;
	PlayerDM* player = new PlayerDM();
	PlayerDM* ai1Miner = new PlayerDM();
	char money = 36;
};
#endif
