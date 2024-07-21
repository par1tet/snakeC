#include "board.c"

int changePosition(part *pl, int newX, int newY, board *mainBoard, apple *newApple)
{
    if (mainBoard->field[newY][newX] == newApple->icon)
    {
    }
    else if (mainBoard->field[newY][newX] != mainBoard->air)
        return 0;

    mainBoard->field[pl->y][pl->x] = mainBoard->air;
    pl->x = newX;
    pl->y = newY;
}

void drawPlayer(player *pr, board *mainBoard)
{
    // printf("%d, %d", (*pl).x, (*pl).y);
    for (int i = 0; i != pr->length; i++)
    {
        part currentPart = pr->parts[i];
        (*mainBoard).field[currentPart.y][currentPart.x] = currentPart.playerIcon;
    }
}

void movePlayer(player *pl, board *mainBoard, apple *newApple)
{
    for (int i = 0; i != pl->length; i++)
    {
        part *currentPart = &(pl->parts[i]);
        switch (currentPart->direction)
        {
        case 'r':
            changePosition(currentPart, currentPart->x + 1, currentPart->y, mainBoard, newApple);
            break;
        case 'l':
            changePosition(currentPart, currentPart->x - 1, currentPart->y, mainBoard, newApple);
            break;
        case 'u':
            changePosition(currentPart, currentPart->x, currentPart->y - 1, mainBoard, newApple);
            break;
        case 'd':
            changePosition(currentPart, currentPart->x, currentPart->y + 1, mainBoard, newApple);
            break;

        default:
            break;
        }
    }
}