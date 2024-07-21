#include <stdio.h>
#include <math.h>
#include "player.c"

#define width 40
#define heigth 10

void showBoard(char field[heigth][width]);
void initBoard(char field[heigth][width], char, char);

int main()
{
    system("clear");

    char field[heigth][width] = {};
    player pl1 = {(int)round(width / 2), (int)round(heigth / 2)};

    initBoard(field, '.', '#');
    drawPlayer(&pl1, width, heigth, field);
    showBoard(field);

    return 0;
}

void showBoard(char field[heigth][width])
{
    for (int i = 0; i != heigth; i++)
    {
        for (int j = 0; j != width; j++)
            printf("%c", field[i][j]);
        printf("\n");
    }
}

void initBoard(char field[heigth][width], char air, char blocks)
{
    for (int i = 0; i != heigth; i++)
    {
        if (i == 0 || i == heigth - 1)
        {
            for (int j = 0; j != width; j++)
                field[i][j] = blocks;
        }
        else
        {
            for (int j = 0; j != width; j++)
            {
                if (j == 0 || j == width - 1)
                {
                    field[i][j] = blocks;
                }
                else
                {
                    field[i][j] = air;
                }
            }
        }
    }
}