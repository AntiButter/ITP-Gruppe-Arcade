#include <time.h>
#include <stdio.h>
#include <iostream>
#include <memory>
#include "Hangman.h"
int main()
{
	int points;
	srand(time(NULL));
	std::unique_ptr<hangman>game(new hangman());
	points = game->gameLoop();
	return points;
}
