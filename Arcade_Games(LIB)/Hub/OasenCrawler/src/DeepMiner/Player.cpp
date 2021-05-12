#include "Player.h"

Player::Player() {
	Miner = new BotHighest();
}

Player::~Player() {

}

void Player::SetMiner(Bots* choice) {
	Miner = choice;
}

Bots* Player::GetMiner()const {
	return Miner;
}
