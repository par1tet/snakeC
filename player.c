#include "board.c"

typedef struct
{
    int x, y;
    char direction;
    char playerIcon;

} player;

int changePosition(player *pl, int newX, int newY, board *mainBoard)
{
    if (mainBoard->field[newY][newX] == '#')
        return 0;

    mainBoard->field[pl->y][pl->x] = mainBoard->air;
    pl->x = newX;
    pl->y = newY;
}

void drawPlayer(player *pl, board *mainBoard)
{
    // printf("%d, %d", (*pl).x, (*pl).y);
    (*mainBoard).field[(*pl).y][(*pl).x] = (*pl).playerIcon;
}

void movePlayer(player *pl, board *mainBoard)
{
    switch ((*pl).direction)
    {
    case 'r':
        changePosition(pl, (*pl).x + 1, (*pl).y, mainBoard);
        break;
    case 'l':

        break;

    case 'u':

        break;

    case 'd':

        break;

    default:
        break;
    }
}