#pragma once
#include "Ship.h"
class Hunter : public Ship
{
	public:
		Hunter();
		~Hunter();

		void special(std::shared_ptr<Ship> enemyShip) override;

		void buildShip() override;

	private:
};

