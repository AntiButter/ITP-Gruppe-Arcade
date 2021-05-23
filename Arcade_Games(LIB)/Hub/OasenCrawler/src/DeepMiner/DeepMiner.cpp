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
        int highscore = 0;
        char input;
        int totalPointsMine;
        int newScore;

        do {
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
            //diese Ausgabe weglassen, weil wir dass eigentlich schon in der Main machen ?
            if (world->getPlayerTotalPoints() > highscore) {
                std::cout << "Du hast den alten Highscore von " << highscore << " Punkten geschlagen. Der neue Highscore liegt nun bei " << world->getPlayerTotalPoints() << " Punkten! Gratulation!" << std::endl;
                highscore = world->getPlayerTotalPoints();
            }

            //setzt score für unten
            newScore = world->getPlayerTotalPoints();

            delete world;
            std::cout << "Der Highscore liegt bei: " << highscore << std::endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            //Das eventuell weglassen sonst werden die Punkte für die Runde verloren gehen
            //Oder die Gmable/Highscore objekte mitgeben und hier nach jeder Runde die Funktionen aufrufen
            do {
                std::cout << "Noch ein Spiel? (j)ja, (n)nein" << std::endl;
                std::cin >> input;
            } while (input != 'j' && input != 'n');

        } while (input != 'n');

        std::vector<int> vector;
        int percentage = (newScore * 100 / totalPointsMine) ;
        int gamblePoints = percentage * 1.34;  // = 100 points at 75% clear
        vector.push_back(percentage);
        vector.push_back(gamblePoints);
        if (vector[1] > 100)
            vector[1] = 100;

        return vector;
    }
}

