#include "player.c"

apple createApple(char icon)
{
    srand(time(NULL));

    apple newApple = {rand() % WIDTH, rand() % HEIGTH, icon};

    return newApple;
}