#include <player.c>
#include <time.h>
#include <stdlib.h>

apple createApple()
{
    srand(time(NULL));

    apple newApple = {rand()%WIDTH-1,rand()%HEIGTH-1};

    return newApple;
}