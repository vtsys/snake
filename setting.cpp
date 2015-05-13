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
    /* 0 � ������ 1 � ����� 2 � ������� 3 � ������� 4 � ������� 5 � ������� 6 � ������ 7 � ����� 8 � �����
        9 � �����-����� A � ������-������� B � ������-������� � � ������-������� E � ������-������ F � ����-����� */
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
