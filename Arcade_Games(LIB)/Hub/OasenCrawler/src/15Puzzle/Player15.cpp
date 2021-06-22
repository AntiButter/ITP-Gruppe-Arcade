#include <iostream>
#include "Player15.h"
#include <conio.h>


Player15::Player15() {
	px = 0; 
	py = 0; 
	std::cout << "Spieler erstellt" << std::endl; 
}
Player15::~Player15() {
	std::cout << "Spieler zerstoert" << std::endl;
}

void Player15::SetPx(int px) {
	this->px = px; 
}
int Player15::GetPx() const {
	return this->px; 
}
void Player15::SetPy(int py) {
	this->py = py; 
}
int Player15::GetPy() const {
	return this->py; 
}

int Player15::move(std::vector<std::vector<int>>& puzzle) {
    int valid = 0;
    char direction = ' ';

    while (valid == 0) {
        direction = _getch();
        switch (direction) {
        case 'a':
            if (this->GetPx() == 0) {
                std::cout << "Du kannst nicht weiter nach links gehen" << std::endl;
            }
            else {
                this->SetPx(this->GetPx() - 1);
                valid = 1;
            }
            break;
        case 'd':
            if (this->GetPx() == 3) {
                std::cout << "Du kannst nicht weiter nach rechts gehen" << std::endl;
            }
            else {
                this->SetPx(this->GetPx() + 1);
                valid = 1;
            }
            break;
        case 'w':
            if (this->GetPy() == 0) {
                std::cout << "Du kannst nicht weiter nach oben gehen" << std::endl;
            }
            else {
                this->SetPy(this->GetPy() - 1);
                valid = 1;
            }
            break;
        case 's':
            if (this->GetPy() == 3) {
                std::cout << "Du kannst nicht weiter nach unten gehen" << std::endl;
            }
            else {
                this->SetPy(this->GetPy() + 1);
                valid = 1;
            }
            break;
        case 'x':
            return 5;
            break;
        case 'l':
            /*
            if (puzzle[((this->GetPy() * 4) + this->GetPx()) - 1] == 0 || puzzle[((this->GetPy() * 4) + this->GetPx()) + 1] == 0 || puzzle[((this->GetPy() * 4) + this->GetPx()) - 4] == 0 || puzzle[((this->GetPy() * 4) + this->GetPx()) + 4] == 0) {
                std::cout << "gangad" << std::endl; 
            }
            else {
                std::cout << "gangad ned" << std::endl; 
            }
            */

            if (this->GetPy() + 1 <= 3 && puzzle[this->GetPy() + 1][this->GetPx()] == 0) {
                return 1; 
            }
            else if (this->GetPy() - 1 >= 0 && puzzle[this->GetPy() - 1][this->GetPx()] == 0) {
                return 2; 
            }
            else if (this->GetPx() + 1 <= 3 && puzzle[this->GetPy()][this->GetPx() + 1] == 0) {
                return 3; 
            }
            else if (this->GetPx() - 1 >= 0 && puzzle[this->GetPy()][this->GetPx() - 1] == 0) {
                return 4; 
            }
            else {
                return 0; 
            }

            break;
        default:
            continue;
        }
    }
    return 0; 
}

void Player15::swap(std::vector<std::vector<int>>& puzzle, int swapper) {
    
    if (swapper == 1) {
        puzzle[this->GetPy() + 1][this->GetPx()] = puzzle[this->GetPy()][this->GetPx()];
        puzzle[this->GetPy()][this->GetPx()] = 0;
    } else if (swapper == 2) {
        puzzle[this->GetPy() - 1][this->GetPx()] = puzzle[this->GetPy()][this->GetPx()];
        puzzle[this->GetPy()][this->GetPx()] = 0;
    } else if (swapper == 3) {
        puzzle[this->GetPy()][this->GetPx() + 1] = puzzle[this->GetPy()][this->GetPx()];
        puzzle[this->GetPy()][this->GetPx()] = 0;
    } else if (swapper == 4) {
        puzzle[this->GetPy()][this->GetPx() - 1] = puzzle[this->GetPy()][this->GetPx()];
        puzzle[this->GetPy()][this->GetPx()] = 0;
    }
    else {
        std::cout << "Unknown error" << std::endl; 
    }

}
