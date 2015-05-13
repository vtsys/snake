#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include "setting.h"
#include <string>
#include <vector>
class Snake {
private:
    Setting setting; // Копия настроек
    std::vector<char> snakeView; // Вид змейки (<**, >**, ^**, v**)
    int snakeCoord[][2]; // Координаты змейки (ссылка на вид, x, y);
    void setSetting(Setting setting); // Копирования настроек
    void setSnakeView(std::string snakeView); // Вставка элементов ввида змейки
    void setSnakeView(char snakeView); // Вставка элементов ввида змейки
    void editSnakeView(int snakeElement, char *snakeView); //
    Setting getSetting(); // Доступ к настройкам
    char processingKey(); // Обработка нажатия кнопок
    void moveSnake(char processingKey); // Движение змейки
public:
    Snake(Setting setting, std::string snakeView); // Конструктор
    void setSnakeCoord(int snakeView, int x, int y); // Вставка координат каждого элемента, по одному, нужно будет перебрать
    int getSnakeCoordX(int snakeView); // Возврат значения X по виду элемента змейки(тоесть по ссылке на вид)
    int getSnakeCoordY(int snakeView); // Возврат значения Y по виду элемента змейки(тоесть по ссылке на вид)
    void positionCursor(int x, int y); // Установка позиции курсора
    bool startSnake(); // Запуск змейки
};
#endif // SNAKE_H_INCLUDED
