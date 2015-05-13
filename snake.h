#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include "setting.h"
#include <string>
#include <vector>
class Snake {
private:
    Setting setting; // ����� ��������
    std::vector<char> snakeView; // ��� ������ (<**, >**, ^**, v**)
    int snakeCoord[][2]; // ���������� ������ (������ �� ���, x, y);
    void setSetting(Setting setting); // ����������� ��������
    void setSnakeView(std::string snakeView); // ������� ��������� ����� ������
    void setSnakeView(char snakeView); // ������� ��������� ����� ������
    void editSnakeView(int snakeElement, char *snakeView); //
    Setting getSetting(); // ������ � ����������
    char processingKey(); // ��������� ������� ������
    void moveSnake(char processingKey); // �������� ������
public:
    Snake(Setting setting, std::string snakeView); // �����������
    void setSnakeCoord(int snakeView, int x, int y); // ������� ��������� ������� ��������, �� ������, ����� ����� ���������
    int getSnakeCoordX(int snakeView); // ������� �������� X �� ���� �������� ������(������ �� ������ �� ���)
    int getSnakeCoordY(int snakeView); // ������� �������� Y �� ���� �������� ������(������ �� ������ �� ���)
    void positionCursor(int x, int y); // ��������� ������� �������
    bool startSnake(); // ������ ������
};
#endif // SNAKE_H_INCLUDED
