#include "Player.h"

PlayerDM::PlayerDM() {
	Miner = new BotHighest();
}

PlayerDM::~PlayerDM() {

}

void PlayerDM::SetMiner(Bots* choice) {
	Miner = choice;
}

Bots* PlayerDM::GetMiner()const {
	return Miner;
}
