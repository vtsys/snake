#ifndef SETTING_H_INCLUDED
#define SETTING_H_INCLUDED
#include <string>
class Setting {
private:
    int windowWidth; // ������ ����
    int windowHeight; // ������ ����
    std::string windowColor; // ���� ���� ������ ����
    std::string windowTitle; // �������� ����
    void setWindowSize(int, int); // ��������� �������� ����, �������� ������ �� ������������
    void setWindowTitle(std::string); // ��������� �������� ����, �������� ������ �� ������������
    void setWindowColor(std::string); // ��������� ����� ������ ����, �������� ������ �� ������������
    void showWindow(); // ����������� ����, �������� ������ �� ������������ ???
public:
    Setting(int width, int height, std::string title, std::string color); // �����������
    Setting();
    int getWindowWidth(); // ������� ��� ��������� ������ ����
    int getWindowHeight(); // ������� ��� ��������� ������ ����
};
#endif // SETTING_H_INCLUDED
