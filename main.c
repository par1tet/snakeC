#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "player.c"

char pressedKey;
void disable_canonical_mode();

void *control_thread_func()
{
    while (1)
    {
        pressedKey = getchar();
    }
}

int main()
{

    char field[HEIGTH][WIDTH] = {};
    board mainBoard = initBoard(HEIGTH, WIDTH, '#', '.', field);
    player pl1 = {(int)round(WIDTH / 2), (int)round(HEIGTH / 2), 'r', '@'};
    char esc = 1;

    disable_canonical_mode();

    pthread_t control_thread;
    pthread_create(&control_thread, NULL, control_thread_func, NULL);

    // main loop

    do
    {
        system("clear");
        drawPlayer(&pl1, &mainBoard);
        showBoard(&mainBoard);

        // movePlayer(&pl1, &mainBoard);

        usleep(500000);
        switch (pressedKey)
        {
        case 'q':
            esc = 0;
            break;
        case 'w':
            changePosition(&pl1, pl1.x, pl1.y - 1, &mainBoard);
            break;
        case 'a':
            changePosition(&pl1, pl1.x - 1, pl1.y, &mainBoard);
            break;
        case 's':
            changePosition(&pl1, pl1.x, pl1.y + 1, &mainBoard);
            break;
        case 'd':
            changePosition(&pl1, pl1.x + 1, pl1.y, &mainBoard);
            break;

        default:
            continue;
            break;
        }
    } while (esc);

    return 0;
}

// Функция для отключения режима канонического ввода
void disable_canonical_mode()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Отключаем канонический режим и отображение вводимых символов
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
