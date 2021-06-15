#include "Table.h"
#include <iostream>
#include <random>
#include <Windows.h>
#include <conio.h>
//#include <stdlib.h> 
//#include <algorithm>

Table::Table(int difficulty) {
	this->difficulty = difficulty;
	shuffleCards();
	curserPos = 0;
	open1 = -1;
	open2 = -1;
	solved = 0;
}

Table::~Table() {

}

void Table::shuffleCards() {
	int z = 0;

	if (difficulty == 1) {
		cards.clear();
		for (int i = 1; i <= 10; i++) {
			cards.push_back(symbols[z]);
			if (i % 2 == 0) {
				z++;
			}
		}
		auto rng = std::default_random_engine{ std::random_device{}() };
		std::shuffle(std::begin(cards), std::end(cards), rng);
	}
	else if (difficulty == 2) {
		cards.clear();
		for (int i = 1; i <= 20; i++) {
			cards.push_back(symbols[z]);
			if (i % 2 == 0) {
				z++;
			}
		}
		auto rng = std::default_random_engine{ std::random_device{}() };
		std::shuffle(std::begin(cards), std::end(cards), rng);
	}
	else if (difficulty == 3) {

	}
}

void Table::printTable() {
	if (difficulty == 1) {
		for (int i = 0; i < 10; i++) {
			std::cout << cards[i];
			std::cout << " ";
			if ((i + 1) % 5 == 0) {
				std::cout << std::endl;
			}
		}
	}
	else if (difficulty == 2) {

	}
	else if (difficulty == 3) {

	}
}

void Table::printHidden() {
	bool reset = false;
	if (difficulty == 1) {
		while (solved < 5) {
			for (int i = 0; i < 10; i++) {
				if (cards[i] == ' ') {
					std::cout << ' ';
				}
				else if (open1 == i) {
					std::cout << cards[i];
				}
				else if (open2 == i) {
					std::cout << cards[i];
					reset = true;
				}
				else {
					if (i == curserPos) {
						std::cout << 'X';
					}
					else {
						std::cout << hidden;
					}
				}

				std::cout << " ";
				if ((i + 1) % 5 == 0) {
					std::cout << std::endl;
				}
			}
			if (reset == true) {
				if (cards[open1] == cards[open2]) {
					cards[open1] = ' ';
					cards[open2] = ' ';
					solved++;
				}
				open1 = -1;
				open2 = -1;
				reset = false;
				Sleep(1500);
				system("CLS");
			}
			else {
				std::cout << "Mit 'F' bestaetigen, Cursor mit 'WASD' bewegen" << std::endl;
				movement = _getch();
				switch (movement) {
				case 's':
					if (curserPos < 5) {
						curserPos += 5;

					}
					break;
				case 'w':
					if (curserPos > 4) {
						curserPos -= 5;
					}
					break;
				case 'a':
					if (curserPos > 0) {
						curserPos--;

					}
					break;
				case 'd':
					if (curserPos < 9) {
						curserPos++;
					}
					break;
				case 'f':
					//open
					break;
				}

				system("CLS");
				if (movement == 'f') {
					if (open1 != -1) {
						if (open1 != curserPos) {
							open2 = curserPos;
						}
					}
					else {
						open1 = curserPos;
					}
				}
				if (open1 != -1 && open2 != -1) {
					//??
				}
			}

		}
		
	}


	else if (difficulty == 2) {

	}
	else if (difficulty == 3) {

	}
}