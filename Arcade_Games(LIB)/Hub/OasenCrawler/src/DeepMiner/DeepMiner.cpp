#include <iostream>
#include <vector>
#include <stdlib.h>  
#include <time.h>
#include <Windows.h>
#include <algorithm>
#include <numeric>
#include <random>
#include "Bots.h"
#include "BotHighest.h"
#include "BotTriple.h"
#include "BotRandom.h"
#include "Player.h"
#include "World.h"
#include "DeepMiner.h"

namespace deepMiner {
    std::vector<int> PlayDeepMiner()
    {
        bool loopDone;
        int yLength, xLength;
        char input;
        int totalPointsMine;
        int newScore;

        do {
            loopDone = false;
            std::cout << "Waehle die y-Laenge deiner Mine:" << std::endl;
            std::cin >> yLength;
            std::cout << "Waehle die x-Laenge deiner Mine:" << std::endl;
            std::cin >> xLength;
            if (yLength > 1 && xLength > 1) {
                loopDone = true;
            }
            else {
                std::cout << "Bitte gib deiner Minenlaenge nur Werte ueber 1!" << std::endl;
            }
        } while (loopDone == false);

        World* world = new World(yLength, xLength);
        world->createRandomWorld();

        //Points calc
        totalPointsMine = world->getTotalSumStart();

        world->chooseBotsPlayer();
        world->gamePlayer();


        world->endScreen();
       
        //setzt score für unten
        newScore = world->getPlayerTotalPoints();

        delete world;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        std::vector<int> vector;
        int percentage = (newScore * 100 / totalPointsMine) ;
        std::cout << "Your Score: " << percentage << "%"<<std::endl;
        int gamblePoints = percentage * 1.34;  // = 100 points at 75% clear
        vector.push_back(percentage);
        vector.push_back(gamblePoints);
        if (vector[1] > 100)
            vector[1] = 100;

        return vector;
    }
}

