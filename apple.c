#include "player.c"

apple createApple(char icon)
{
    srand(time(NULL));

    apple newApple = {rand() % WIDTH, rand() % HEIGTH, icon};

    return newApple;
}

char hasApple(apple* currentApple, board* mainBoard){
    for (int i = 0;i != mainBoard->heigth;i++){
        for (int j = 0;j != mainBoard->width;j++){
            if (mainBoard->field[i][j] == currentApple->icon){
                return 0;
            }
        }
    }
    return 1;
}