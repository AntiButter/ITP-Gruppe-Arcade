#pragma once
#include "Ship.h"
class Battleship : public Ship
{
	public:
		Battleship();
		~Battleship();

		void special(std::shared_ptr<Ship> enemyShip) override;

		void buildShip() override;

	private:
};

