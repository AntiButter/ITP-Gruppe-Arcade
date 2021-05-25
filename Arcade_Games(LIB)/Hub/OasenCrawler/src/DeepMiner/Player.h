#ifndef Player_HEADER
#define Player_HEADER

#include "Bots.h"
#include "BotHighest.h"
#include "BotRandom.h"
#include "BotTriple.h"

class PlayerDM {
public:
	PlayerDM();
	~PlayerDM();

	void SetMiner(Bots* choice);
	Bots* GetMiner() const;

private:
	Bots* Miner;
};

#endif