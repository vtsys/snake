#include "setting.h"
#include <windows.h>
#include <string>
#include <stdio.h>


Setting::Setting(int width, int height, std::string title, std::string color){
    this->setWindowSize(width, height);
    this->setWindowTitle(title);
    this->setWindowColor(color);
    this->showWindow();
}

Setting::Setting(){

}

void Setting::setWindowSize(int width, int height) {
    this->windowWidth = width;
    this->windowHeight = height;
}

void Setting::setWindowTitle(std::string title) {
    this->windowTitle = title;
}

void Setting::setWindowColor(std::string color) {
    /* 0 Ч черный 1 Ч синий 2 Ч зеленый 3 Ч голубой 4 Ч красный 5 Ч лиловый 6 Ч желтый 7 Ч белый 8 Ч серый
        9 Ч свело-синий A Ч светло-зеленый B Ч светло-голубой — Ч светло-красный E Ч светло-желтый F Ч €рко-белый */
    this->windowColor = color;
}

int Setting::getWindowWidth() {
    return this->windowWidth;
}

int Setting::getWindowHeight() {
    return this->windowHeight;
}

void Setting::showWindow() {
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT src = {0, 0, this->getWindowWidth() - 1, this->getWindowHeight() - 1};
    SetConsoleWindowInfo (out_handle, true, &src);
    COORD coord = {this->getWindowWidth(), this->getWindowHeight()};
    SetConsoleScreenBufferSize (out_handle, coord);
    SetConsoleTitle(this->windowTitle.c_str());
    std::string buff;
    buff.append("color");
    buff.append(" ");
    buff.append(this->windowColor);
    system(buff.c_str());
}
