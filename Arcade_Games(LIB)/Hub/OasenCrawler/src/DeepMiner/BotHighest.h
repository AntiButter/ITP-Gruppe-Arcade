#ifndef BotHighest_HEADER
#define BotHighest_HEADER


#include "Bots.h"
#include <vector>

class BotHighest : public Bots {
public:
	BotHighest();

	~BotHighest();

	std::vector<std::vector<std::vector<int>>> mine(std::vector<std::vector<std::vector<int>>> world);
};

#endif
