#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "player.c"

#define width 40
#define heigth 20

void showBoard(char field[heigth][width]);
void initBoard(char field[heigth][width], char, char);
void disable_canonical_mode();

int main()
{
    char field[heigth][width] = {};
    player pl1 = {(int)round(width / 2), (int)round(heigth / 2), 'r'};
    char pressedKey;
    char esc = 1;

    disable_canonical_mode();

    // main loop

    do
    {
        system("clear");

        initBoard(field, '.', '#');
        drawPlayer(&pl1, width, heigth, field);
        showBoard(field);

        movePlayer(&pl1, width, heigth, field);

        usleep(500000);

        pressedKey = getchar();

        switch (pressedKey)
        {
        case 'q':
            esc = 0;
            break;
        case 'w':
            changePosition(&pl1, pl1.x, pl1.y - 1, width, heigth, field);
            break;
        case 'a':
            changePosition(&pl1, pl1.x - 1, pl1.y, width, heigth, field);
            break;
        case 's':
            changePosition(&pl1, pl1.x, pl1.y + 1, width, heigth, field);
            break;
        case 'd':
            pl1.direction = 'r';
            break;

        default:
            continue;
            break;
        }
    } while (esc);

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

// Функция для отключения режима канонического ввода
void disable_canonical_mode()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Отключаем канонический режим и отображение вводимых символов
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
