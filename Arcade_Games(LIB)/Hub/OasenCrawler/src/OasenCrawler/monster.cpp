#include "monster.h"
#include <iostream>

monster::monster(int x, int y)
{
    this->SetHp(1);
    this->SetMx(x);
    this->SetMy(y);
}

monster::~monster()
{

}


void monster::SetHp(int hp) {
    this->hp = hp;
}

int monster::GetHp() {
    return this->hp;
}

void monster::SetMx(int mx) {
    this->mx = mx;
}

int monster::GetMx() {
    return this->mx;
}

void monster::SetMy(int my) {
    this->my = my;
}

int monster::GetMy() {
    return this->my;
}

void monster::MoveMonster(int px, int py) {
    std::cout << "Monster X:" << this->mx << "Monster Y: " << this->my << std::endl;
    std::cout << "Player X:" << px << "Player Y: " << py << std::endl;
    int rnum = 0;

    //testet ob sich das Monster links/rechts/über/unter dem Spieler befindet und
    //führt je nach dem verschiedene Movement-Aktionen aus
    if (px < this->GetMx() && py < this->GetMy()) {
        //hoch oder links
        rnum = rand() % 2;
        if (rnum == 0) {
            this->SetMy(this->GetMy() - 1);
        }
        else {
            this->SetMx(this->GetMx() - 1);
        }
    }
    else if (px > this->GetMx() && py < this->GetMy()) {
        //hoch oder rechts
        rnum = rand() % 2;
        if (rnum == 0) {
            this->SetMy(this->GetMy() - 1);
        }
        else {
            this->SetMx(this->GetMx() + 1);
        }
    }
    else if (px < this->GetMx() && py > this->GetMy()) {
        //runter oder links
        rnum = rand() % 2;
        if (rnum == 0) {
            this->SetMy(this->GetMy() + 1);
        }
        else {
            this->SetMx(this->GetMx() - 1);
        }
    }
    else if (px > this->GetMx() && py > this->GetMy()) {
        //runter oder rechts
        rnum = rand() % 2;
        if (rnum == 0) {
            this->SetMy(this->GetMy() + 1);
        }
        else {
            this->SetMx(this->GetMx() + 1);
        }
    }
    else if (px == this->GetMx() && py < this->GetMy()) {
        //hoch
        std::cout << "hoch" << std::endl;
        this->SetMy(this->GetMy() - 1);
    }
    else if (px == this->GetMx() && py > this->GetMy()) {
        //runter
        std::cout << "runter" << std::endl;
        this->SetMy(this->GetMy() + 1);
    }
    else if (px < this->GetMx() && py == this->GetMy()) {
        //links
        std::cout << "links" << std::endl;
        this->SetMx(this->GetMx() - 1);
    }
    else if (px > this->GetMx() && py == this->GetMy()) {
        //rechts
        std::cout << "rechts" << std::endl;
        this->SetMx(this->GetMx() + 1);
    }
    else {
        std::cout << "error" << std::endl;
    }

    //Spieler verliert das Spiel wenn ihn das Monster fängt
    if (px == this->GetMx() && py == this->GetMy()) {
        this->SetHp(0);
    }
}
