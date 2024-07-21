#include "colors.h"

#define HEIGTH 40
#define WIDTH 20

typedef struct
{
    int x, y;
    char direction, playerIcon;
} part;

typedef struct
{
    int length;

    part *parts;
} player;

typedef struct
{
    int heigth, width;
    char block, air;
    char field[HEIGTH][WIDTH];
} board;

#define WIDTH 40
#define HEIGTH 20

board initBoard(int heigth, int width, char block, char air, char field[heigth][width])
{
    board newBoard = {heigth, width, block, air, field};
    for (int i = 0; i != heigth; i++)
    {
        if (i == 0 || i == heigth - 1)
        {
            for (int j = 0; j != width; j++)
                newBoard.field[i][j] = block;
        }
        else
        {
            for (int j = 0; j != width; j++)
            {
                if (j == 0 || j == width - 1)
                {
                    newBoard.field[i][j] = block;
                }
                else
                {
                    newBoard.field[i][j] = air;
                }
            }
        }
    }
    return newBoard;
}

void showBoard(player *pl, board *mainBoard)
{
    for (int i = 0; i != mainBoard->heigth; i++)
    {
        for (int j = 0; j != mainBoard->width; j++){
            if (mainBoard->field[i][j] = mainBoard->air){
                printf("%c", mainBoard->field[i][j]);
            }else if(mainBoard->field[i][j] = mainBoard->block){
                printf("%c", mainBoard->field[i][j]);
            }else if(mainBoard->field[i][j] = pl->parts[0].playerIcon){
                printf("%c", mainBoard->field[i][j]);
            }
        }
        printf("\n");
    }
}