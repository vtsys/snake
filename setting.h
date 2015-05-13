#ifndef SETTING_H_INCLUDED
#define SETTING_H_INCLUDED
#include <string>
class Setting {
private:
    int windowWidth; // Ширена окна
    int windowHeight; // Высота окна
    std::string windowColor; // Цвет фона внутри окна
    std::string windowTitle; // Название окна
    void setWindowSize(int, int); // Установка размеров окна, доступно только из конструктора
    void setWindowTitle(std::string); // Установка названия окна, доступно только из конструктора
    void setWindowColor(std::string); // Установка цвета внутри окна, доступно только из конструктора
    void showWindow(); // Отображение окна, доступно только из конструктора ???
public:
    Setting(int width, int height, std::string title, std::string color); // Конструктор
    Setting();
    int getWindowWidth(); // Функция для получения ширины окна
    int getWindowHeight(); // Функция для получения высоты окна
};
#endif // SETTING_H_INCLUDED
