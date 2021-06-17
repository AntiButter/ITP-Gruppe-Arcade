#include <time.h>
#include <stdio.h> 
#include <iostream>
#include <memory>
#include "Hangman.h"
int main()
{
	srand(time(NULL));
	std::unique_ptr<hangman>game(new hangman());
}