#ifndef BotRandom_HEADER
#define BotRandom_HEADER


#include "Bots.h"
#include <vector>

class BotRandom : public Bots {

public:
	BotRandom();

	~BotRandom();

	std::vector<std::vector<std::vector<int>>> mine(std::vector<std::vector<std::vector<int>>> world);
};

#endif
