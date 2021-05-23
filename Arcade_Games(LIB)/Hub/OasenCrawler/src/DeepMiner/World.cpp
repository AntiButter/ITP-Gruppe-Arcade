#include "World.h"
#include <iostream>
#include <time.h>
#include <random>
#include <Windows.h>

World::World(int yLength, int xLength) {
    this->world = std::vector<std::vector<std::vector<int>>>(yLength, std::vector<std::vector<int>>(xLength, std::vector<int>(10, 1)));
    this->yLength = yLength;
    this->xLength = xLength;
}

World::~World() {
    delete player;
    delete ai1Miner;
}

void World::createRandomWorld() {
    srand(time(NULL));
    int xCounter = 0;
    int yCounter = 0;
    int zCounter = 0;
    int randomNumber;

    for (yCounter; yCounter < yLength; yCounter++) {
        for (xCounter; xCounter < xLength; xCounter++) {
            for (zCounter; zCounter < 10; zCounter++) {
                randomNumber = rand() % 9 + 1;
                world[yCounter][xCounter][zCounter] = randomNumber;
                totalSumStart += randomNumber;
            }
            zCounter = 0;
        }
        xCounter = 0;
    }
}

void World::changeWorld() {
    srand(time(NULL));
    int xCounter = 0;
    int yCounter = 0;
    int zCounter = 0;
    int randomNumber;

    for (yCounter; yCounter < yLength; yCounter++) {
        for (xCounter; xCounter < xLength; xCounter++) {
            randomNumber = rand() % 3 + 1;
            if (randomNumber == 1) {
                std::sort(world[yCounter][xCounter].begin(), world[yCounter][xCounter].end());
            }
            else if (randomNumber == 2) {
                std::sort(world[yCounter][xCounter].begin(), world[yCounter][xCounter].end(), std::greater<int>());
            }
            else if (randomNumber == 3) {
                auto rng = std::default_random_engine{};
                std::shuffle(std::begin(world[yCounter][xCounter]), std::end(world[yCounter][xCounter]), rng);
            }
        }
        xCounter = 0;
    }
    std::cout << "Ein Erdrutsch hat die Mine durchgemischt!" << std::endl;
}

void World::calcTotalSum() {
    int xCounter = 0;
    int yCounter = 0;
    int zCounter = 0;
    totalSum = 0;

    for (yCounter; yCounter < yLength; yCounter++) {
        for (xCounter; xCounter < xLength; xCounter++) {
            for (zCounter; zCounter < 10; zCounter++) {
                totalSum += world[yCounter][xCounter][zCounter];
            }
            zCounter = 0;
        }
        xCounter = 0;
    }
}

void World::chooseBotsPlayer() {
    bool loopDone;
    int botSelector;
    do {
        loopDone = false;
        std::cout << "Waehle deinen Roboter!" << std::endl;
        std::cout << "Highest-Bot(1), Triple-Bot(2), Random-Bot(3)" << std::endl;
        std::cin >> botSelector;
        if (botSelector == 1) {
            Bots* highest = new BotHighest();
            player->SetMiner(highest);
            loopDone = true;
        }
        else if (botSelector == 2) {
            Bots* triple = new BotTriple();
            player->SetMiner(triple);
            loopDone = true;
        }
        else if (botSelector == 3) {
            Bots* random = new BotRandom();
            player->SetMiner(random);
            loopDone = true;
        }
        else {
            std::cout << "Ungueltige Eingabe!" << std::endl;
        }
    } while (loopDone != true);
    do {
        loopDone = false;
        std::cout << "Waehle den gegnerischen Roboter!" << std::endl;
        std::cout << "Highest-Bot(1), Triple-Bot(2), Random-Bot(3)" << std::endl;
        std::cin >> botSelector;
        if (botSelector == 1) {
            Bots* highest2 = new BotHighest();
            ai1Miner->SetMiner(highest2);
            loopDone = true;
        }
        else if (botSelector == 2) {
            Bots* triple2 = new BotTriple();
            ai1Miner->SetMiner(triple2);
            loopDone = true;
        }
        else if (botSelector == 3) {
            Bots* random2 = new BotRandom();
            ai1Miner->SetMiner(random2);
            loopDone = true;
        }
        else {
            std::cout << "Ungueltige Eingabe!" << std::endl;
        }
    } while (loopDone != true);
}

void World::gamePlayer() {
    system("CLS");
    do {
        this->calcTotalSum();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 95);
        std::cout << "Verbleibendes Gold in der Mine:" << money << totalSum << std::endl;
        std::cout << "Spieler: " << money << player->GetMiner()->getTotalPoints() << std::endl;
        std::cout << "AI: " << money << ai1Miner->GetMiner()->getTotalPoints() << std::endl;

        if (totalSum <= 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            break;
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 48);
        std::cout << "Du bist dran!" << std::endl;
        std::cout << "Dein Miner steht momentan auf Feld x: [" << player->GetMiner()->getPosX() << "] y: [" << player->GetMiner()->getPosY() << "]" << std::endl;
        player->GetMiner()->move(yLength, xLength);
        std::cout << "Dein Miner sucht hier nach Gold-> x: [" << player->GetMiner()->getPosX() << "] y: [" << player->GetMiner()->getPosY() << "]" << std::endl;
        world = player->GetMiner()->mine(world);
        std::cout << "Deine Runde ist vorbei." << std::endl;
        if (player->GetMiner()->getTotalPoints() % 50 == 0) {
            this->changeWorld();
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
        std::cout << "Der Computer ist dran!" << std::endl;
        std::cout << "Der gegnerische Miner steht momentan auf Feld x: [" << ai1Miner->GetMiner()->getPosX() << "] y: [" << ai1Miner->GetMiner()->getPosY() << "]" << std::endl;
        ai1Miner->GetMiner()->randMove(yLength, xLength);
        std::cout << "Der gegnerische Miner sucht hier nach Gold-> x: [" << ai1Miner->GetMiner()->getPosX() << "] y: [" << ai1Miner->GetMiner()->getPosY() << "]" << std::endl;
        world = ai1Miner->GetMiner()->mine(world);
        std::cout << "Die gegnerische Runde ist vorbei." << std::endl;
        if (ai1Miner->GetMiner()->getTotalPoints() % 50 == 0) {
            this->changeWorld();
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("pause");
        system("CLS");
    } while (true);
}

void World::endScreen() {
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 111);
    std::cout << "Die Mine ist leergeraeumt! Such dein Gold wo anders du gieriger Kobold!" << std::endl << "Results:" << std::endl;

    std::cout << "Spieler: " << money << player->GetMiner()->getTotalPoints() << std::endl;
    std::cout << "AI: " << money << ai1Miner->GetMiner()->getTotalPoints() << std::endl;

}

int World::getPlayerTotalPoints() {
    return player->GetMiner()->getTotalPoints();
}

int World::getTotalSumStart()
{
    return totalSumStart;
}

std::vector<std::vector<std::vector<int>>> World::getWorld() const {
    return world;
}
