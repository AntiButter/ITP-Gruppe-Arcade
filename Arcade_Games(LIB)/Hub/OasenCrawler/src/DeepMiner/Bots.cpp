#include "Bots.h"
#include <iostream>

Bots::~Bots() {

}
int Bots::getPosX() const {
	return posX;
}
int Bots::getPosY() const {
	return posY;
}
int Bots::getTotalPoints() const {
	return totalPoints;
}
void Bots::move(int yLength, int xLength) {
	bool moved = false;
	char input;

	do {
		std::cout << "Bewege deinen Miner mit WASD oder bleibe mit F stehen!" << std::endl;
		std::cin >> input;
		switch (input) {
		case 'w':
			if (posY > 0) {
				posY--;
				moved = true;
			}
			else {
				std::cout << "Du kannst nicht weiter nach oben!" << std::endl;
			}
			break;
		case 'W':
			if (posY > 0) {
				posY--;
				moved = true;
			}
			else {
				std::cout << "Du kannst nicht weiter nach oben!" << std::endl;
			}
			break;
		case 's':
			if (posY < (yLength - 1)) {
				posY++;
				moved = true;
			}
			else {
				std::cout << "Du kannst nicht weiter nach unten!" << std::endl;
			}
			break;
		case 'S':
			if (posY < (yLength - 1)) {
				posY++;
				moved = true;
			}
			else {
				std::cout << "Du kannst nicht weiter nach unten!" << std::endl;
			}
			break;
		case 'a':
			if (posX > 0) {
				posX--;
				moved = true;
			}
			else {
				std::cout << "Du kannst nicht weiter nach links!" << std::endl;
			}
			break;
		case 'A':
			if (posX > 0) {
				posX--;
				moved = true;
			}
			else {
				std::cout << "Du kannst nicht weiter nach links!" << std::endl;
			}
			break;
		case 'd':
			if (posX < (xLength - 1)) {
				posX++;
				moved = true;
			}
			else {
				std::cout << "Du kannst nicht weiter nach rechts!" << std::endl;
			}
			break;
		case 'D':
			if (posX < (xLength - 1)) {
				posX++;
				moved = true;
			}
			else {
				std::cout << "Du kannst nicht weiter nach rechts!" << std::endl;
			}
			break;
		case 'f':
			moved = true;
			break;
		case 'F':
			moved = true;
			break;
		default:
			std::cout << "Ungueltige Eingabe!" << std::endl;
		}
	} while (moved != true);
}

void Bots::randMove(int yLength, int xLength) {
	bool moved = false;
	char input;
	int randValue;
	do {
		randValue = rand() % 5;
		if (randValue == 0) {
			input = 'f';
		}
		else if (randValue == 1) {
			input = 'w';
		}
		else if (randValue == 2) {
			input = 'a';
		}
		else if (randValue == 3) {
			input = 's';
		}
		else if (randValue == 4) {
			input = 'd';
		}
		else {
			input = 'f';
		}

		switch (input) {
		case 'w':
			if (posY > 0) {
				posY--;
				moved = true;
			}
			break;
		case 'W':
			if (posY > 0) {
				posY--;
				moved = true;
			}
			break;
		case 's':
			if (posY < (yLength - 1)) {
				posY++;
				moved = true;
			}
			break;
		case 'S':
			if (posY < (yLength - 1)) {
				posY++;
				moved = true;
			}
			break;
		case 'a':
			if (posX > 0) {
				posX--;
				moved = true;
			}
			break;
		case 'A':
			if (posX > 0) {
				posX--;
				moved = true;
			}
			break;
		case 'd':
			if (posX < (xLength - 1)) {
				posX++;
				moved = true;
			}
			break;
		case 'D':
			if (posX < (xLength - 1)) {
				posX++;
				moved = true;
			}
			break;
		case 'f':
			moved = true;
			break;
		case 'F':
			moved = true;
			break;
		}
	} while (moved != true);
}