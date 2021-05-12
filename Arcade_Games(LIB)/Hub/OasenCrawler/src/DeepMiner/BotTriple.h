#ifndef BotTriple_HEADER
#define BotTriple_HEADER


#include "Bots.h"
#include <vector>

class BotTriple : public Bots {

public:
	BotTriple();

	~BotTriple();

	std::vector<std::vector<std::vector<int>>> mine(std::vector<std::vector<std::vector<int>>> world);
};

#endif
