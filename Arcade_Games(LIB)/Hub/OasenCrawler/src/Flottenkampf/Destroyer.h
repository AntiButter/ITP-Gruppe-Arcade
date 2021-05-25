#pragma once
#include "Ship.h"
class Destroyer : public Ship
{
	public:
		Destroyer();
		~Destroyer();

		void special(Ship* enemyShip) override;

		void buildShip() override;

	private:
};

