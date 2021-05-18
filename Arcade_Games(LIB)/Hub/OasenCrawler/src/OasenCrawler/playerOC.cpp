#include "playerOC.h"
#include <iostream>
#include <windows.h>

player::player(int hp)
{
    this->SetHp(hp);
    this->SetRelics(0);
    this->SetPx(0);
    this->SetPy(0);
    this->SetStrength(rand() % 10);
    this->SetDefense(rand() % 10);
    this->SetAgility(rand() % 10);

    std::cout << "player created" << std::endl;

#if DEBUG
    std::cout << "Created player" << std::endl;
#endif // DEBUG
}

player::~player()
{

}


void player::SetHp(int hp) {

    if (hp >= 0) {
        this->hp = hp;
    }
    else {
        this->hp = 0;
    }

}

int player::GetHp() {
    return this->hp;
}

void player::SetRelics(int relics) {
    this->relics = relics;
}

int player::GetRelics() {
    return this->relics = relics;
}

void player::SetPx(int px) {
    this->px = px;
}

int player::GetPx() {
    return this->px;
}

void player::SetPy(int py) {
    this->py = py;
}

int player::GetPy() {
    return this->py;
}

void player::SetStrength(int strength) {
    this->strength = strength;
}

int player::GetStrength() {
    return this->strength;
}

void player::SetDefense(int defense) {
    this->defense = defense;
}

int player::GetDefense() {
    return this->defense;
}

void player::SetAgility(int agility) {
    this->agility = agility;
}

int player::GetAgility() {
    return this->agility;
}

void player::printStats() {

    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 10);
    std::cout << "[HP:  " << this->GetHp() << "] ";
    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "[ATK: " << this->GetStrength() << "]" << std::endl;
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << "[DEF: " << this->GetDefense() << "] ";
    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "[SPD: " << this->GetAgility() << "]" << std::endl;
    SetConsoleTextAttribute(hConsole, 7);
}

