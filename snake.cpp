#include "snake.h"
#include "setting.h"
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <time.h>

Snake::Snake(Setting setting, std::string snakeView) {
    this->setSetting(setting);
    this->setSnakeView(snakeView);
    if(this->startSnake()) {
        system("cls");
        this->positionCursor((this->getSetting().getWindowWidth()/2) - 3, this->getSetting().getWindowHeight()/2);
        std::cout << "END.";
        Sleep(4000);
        exit(1);
    }
}

void Snake::setSetting(Setting setting) {
    this->setting = setting;
}

void Snake::setSnakeView(std::string snakeView) {
    for(int i = 0; snakeView[i]; i++) {
        this->snakeView.push_back(snakeView[i]);
    }
}

void Snake::setSnakeView(char snakeView) {
    this->snakeView.push_back(snakeView);
}

void Snake::editSnakeView(int snakeElement, char *snakeView) {
    this->snakeView[snakeElement] = *snakeView;
}

Setting Snake::getSetting() {
    return this->setting;
}

void Snake::setSnakeCoord(int snakeView, int x, int y) {
    this->snakeCoord[snakeView][0] = x;
    this->snakeCoord[snakeView][1] = y;
}

void Snake::positionCursor(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Snake::getSnakeCoordX(int snakeView) {
    return this->snakeCoord[snakeView][0];
}

int Snake::getSnakeCoordY(int snakeView) {
    return this->snakeCoord[snakeView][1];
}

char Snake::processingKey() {
    if(GetKeyState(VK_UP) & 0x80) {
        return 'U';
    }

    if(GetKeyState(VK_DOWN) & 0x80) {
        return 'D';
    }

    if(GetKeyState(VK_LEFT) & 0x80) {
        return 'L';
    }

    if(GetKeyState(VK_RIGHT) & 0x80) {
        return 'R';
    }
}

void Snake::moveSnake(char processingKey) {
    int sizeSnake[64555][2] = {{0,0}, {0,0}};

    switch(processingKey) {
        case 'U':
            this->editSnakeView(0, "^");
            for(int i = 0; i < this->snakeView.size(); i++) {
                sizeSnake[i][0] = this->getSnakeCoordX(i);
                sizeSnake[i][1] = this->getSnakeCoordY(i);
                if(i == 0) {

                    if(this->getSnakeCoordY(i) <= 0) {
                        this->setSnakeCoord(i, this->getSnakeCoordX(i), this->getSetting().getWindowHeight() - 1);
                    } else {
                        this->setSnakeCoord(i, this->getSnakeCoordX(i), this->getSnakeCoordY(i) - 1);
                    }
                }

                if(i > 0) {
                    this->setSnakeCoord(i, sizeSnake[i - 1][0], sizeSnake[i - 1][1]);
                }
            }
        break;
        case 'D':
            this->editSnakeView(0, "V");
            for(int i = 0; i < this->snakeView.size(); i++) {
                sizeSnake[i][0] = this->getSnakeCoordX(i);
                sizeSnake[i][1] = this->getSnakeCoordY(i);
                if(i == 0) {
                    if(this->getSnakeCoordY(i) >= this->getSetting().getWindowHeight() - 1) {
                        this->setSnakeCoord(i, this->getSnakeCoordX(i), 0);
                    } else {
                        this->setSnakeCoord(i, this->getSnakeCoordX(i), this->getSnakeCoordY(i) + 1);
                    }
                }

                if(i > 0) {
                    this->setSnakeCoord(i, sizeSnake[i-1][0], sizeSnake[i-1][1]);
                }
            }
        break;
        case 'L':
            this->editSnakeView(0, "<");
            for(int i = 0; i < this->snakeView.size(); i++) {
                sizeSnake[i][0] = this->getSnakeCoordX(i);
                sizeSnake[i][1] = this->getSnakeCoordY(i);
                if(i == 0) {
                        if(this->getSnakeCoordX(i) <= 0) {
                            this->setSnakeCoord(i, this->getSetting().getWindowWidth() - 1, this->getSnakeCoordY(i));
                        } else {
                            this->setSnakeCoord(i, this->getSnakeCoordX(i) - 1, this->getSnakeCoordY(i));
                        }
                }

                if(i > 0) {
                    this->setSnakeCoord(i, sizeSnake[i - 1][0], sizeSnake[i - 1][1]);
                }
            }
        break;
        case 'R':
            this->editSnakeView(0, ">");
            for(int i = 0; i < this->snakeView.size(); i++) {
                sizeSnake[i][0] = this->getSnakeCoordX(i);
                sizeSnake[i][1] = this->getSnakeCoordY(i);
                if(i == 0) {

                    if(this->getSnakeCoordX(i) >= this->getSetting().getWindowWidth() - 1) {
                        this->setSnakeCoord(i, 0, this->getSnakeCoordY(i));
                    } else {
                        this->setSnakeCoord(i, this->getSnakeCoordX(i) + 1, this->getSnakeCoordY(i));
                    }
                }

                if(i > 0) {
                    this->setSnakeCoord(i, sizeSnake[i - 1][0], sizeSnake[i - 1][1]);
                }
            }
        break;
        default:
        break;
    }
}

bool Snake::startSnake() {
    this->setSnakeCoord(0, 15, 12);
    this->setSnakeCoord(1, 14, 12);
    this->setSnakeCoord(2, 13, 12);
    this->setSnakeCoord(3, 12, 12);
    this->setSnakeCoord(4, 11, 12);
    std::vector<char> key;
    int snakeHealth = 100;
    key.push_back('R');
    int snakeFood[2] = {0, 0};
    int snakeSpeed = 1;

    while(1) {
        system("cls"); // Чистем консоль

        if (snakeFood[0] == 0 && snakeFood[1] == 0) {
                srand(time(NULL));
                snakeFood[0] = rand() % this->getSetting().getWindowWidth();
                snakeFood[1] = rand() % this->getSetting().getWindowHeight();
                if(snakeFood[1] < 4) {
                    snakeFood[1] = snakeFood[1] + 4;
                }
        }

        this->positionCursor(snakeFood[0], snakeFood[1]);
        std::cout << "@";

        if(processingKey()) {
            key.push_back(processingKey());
            this->moveSnake(processingKey());
        } else {
            this->moveSnake(key[key.size()-1]);
        }

        for(int i = 0; i < this->snakeView.size(); i++) {
            this->positionCursor(this->snakeCoord[i][0], this->snakeCoord[i][1]);
            std::cout << this->snakeView[i];
            if(this->getSnakeCoordX(0) == this->getSnakeCoordX(i+1) &&
               this->getSnakeCoordY(0) == this->getSnakeCoordY(i+1)) {
                snakeHealth = snakeHealth - 15;
            }
        }


        if(this->getSnakeCoordX(1) == this->getSetting().getWindowWidth() - 1 &&
            this->getSnakeCoordX(0) == 0 ||
            this->getSnakeCoordX(0) == this->getSetting().getWindowWidth() - 1 &&
            this->getSnakeCoordX(1) == 0 ||
            this->getSnakeCoordY(1) == this->getSetting().getWindowHeight() - 1 &&
            this->getSnakeCoordY(0) == 0 ||
            this->getSnakeCoordY(0) == this->getSetting().getWindowHeight() - 1 &&
            this->getSnakeCoordY(1) == 0) {
            snakeHealth = snakeHealth - 5;
        }

        if(this->getSnakeCoordX(0) == snakeFood[0] && this->getSnakeCoordY(0) == snakeFood[1]) {
            this->setSnakeView('*');
            snakeHealth += 3;
            snakeFood[0] = 0;
            snakeFood[1] = 0;
        }

        this->positionCursor(this->getSetting().getWindowWidth() - 20, 0);
        std::cout << "Length:" << this->snakeView.size() - 1;
        this->positionCursor(this->getSetting().getWindowWidth() - 20, 1);
        std::cout << "Speed:" << snakeSpeed << "lvl";
        this->positionCursor(this->getSetting().getWindowWidth() - 20, 2);
        std::cout << "Health:" << snakeHealth << '%';

        if(this->snakeView.size() >= 0 && this->snakeView.size() <= 10) {
            Sleep(210);
            snakeSpeed  = 1;
        } else if(this->snakeView.size() - 1 >= 10 && this->snakeView.size() - 1 <= 20) {
            Sleep(190);
            snakeSpeed = 2;
        } else if(this->snakeView.size() - 1 >= 20 && this->snakeView.size() - 1 <= 30) {
            Sleep(170);
            snakeSpeed = 3;
        } else if(this->snakeView.size() - 1 >= 30 && this->snakeView.size() - 1 <= 100) {
            Sleep(150);
            snakeSpeed = 4;
        } else {
            Sleep(130);
            snakeSpeed = 5;
        }

        if(snakeHealth < 0) {
            return 1;
        }
    }
}
