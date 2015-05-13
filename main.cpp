#include <iostream>
#include "setting.h"
#include "snake.h"

using namespace std;

int main()
{
    Setting setting(60, 30, "Snake", "20");
    Snake snake(setting, ">****");
    return 0;
}
