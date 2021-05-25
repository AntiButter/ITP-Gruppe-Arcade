#pragma once
#include "Ship.h"
class Hunter : public Ship
{
	public:
		Hunter();
		~Hunter();

		void special(Ship* enemyShip) override;

		void buildShip() override;

	private:
};

