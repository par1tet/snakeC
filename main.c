#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include "colors.h"
#include "apple.c"

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
    char esc = 1;
    board mainBoard = initBoard(HEIGTH, WIDTH, '#', ' ');
    part head = {(int)round(WIDTH / 2), (int)round(HEIGTH / 2), 'r'};
    part *parts = malloc(sizeof(part));
    *parts = head;

    player pl1 = {1, parts, '@', '+'};

    disable_canonical_mode();

    pthread_t control_thread;
    pthread_create(&control_thread, NULL, control_thread_func, NULL);

    // main loop

    do
    {
        system("clear");
        apple newApple = createApple('*');

        movePlayer(&pl1, &mainBoard, &newApple);
        drawPlayer(&pl1, &mainBoard);
        if (hasApple(&newApple, &mainBoard))
        {
            showApple(&newApple, &mainBoard);
        }
        showBoard(&pl1, &mainBoard, &newApple);

        for (int i = 0; i != pl1.length; i++)
        {
            printf("%d,%d,%c", parts[i].x, parts[i].y, parts[i].direction);
        }
        usleep(150000);
        switch (pressedKey)
        {
        case 'q':
            esc = 0;
            break;
        case 'w':
            pl1.parts[0].direction = 'u';
            break;
        case 'a':
            pl1.parts[0].direction = 'l';
            break;
        case 's':
            pl1.parts[0].direction = 'd';
            break;
        case 'd':
            pl1.parts[0].direction = 'r';
            break;

        default:
            continue;
            break;
        }
    } while (esc);

    free(pl1.parts);
    free(parts);

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
