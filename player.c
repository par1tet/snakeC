#include "board.c"

struct part_stc *addPart(struct part_stc *parts, int *length, part elem)
{
    struct part_stc *temp = realloc(parts, ((*length) + 1) * sizeof(struct part_stc));

    temp[(*length)] = elem;
    *length += 1;

    return temp;
}
int changePosition(part *pt, int newX, int newY, board *mainBoard, apple *newApple, player *pl)
{
    // printf("%p", pl->parts);
    if (mainBoard->field[newY][newX] == newApple->icon)
    {
        part newPart = {1, 7, 'r'};
        pl->parts = addPart(pl->parts, &(pl->length), newPart);
    }
    else if (mainBoard->field[newY][newX] != mainBoard->air)
        return 0;

    mainBoard->field[pt->y][pt->x] = mainBoard->air;
    pt->x = newX;
    pt->y = newY;
}

int drawPlayer(player *pr, board *mainBoard)
{
    // printf("%d, %d", (*pl).x, (*pl).y);
    for (int i = 0; i != pr->length; i++)
    {
        part currentPart = pr->parts[i];
        if (i == 0)
        {
            (*mainBoard).field[currentPart.y][currentPart.x] = pr->headIcon;
            continue;
        }
        (*mainBoard).field[currentPart.y][currentPart.x] = pr->partIcon;
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
            changePosition(currentPart, currentPart->x + 1, currentPart->y, mainBoard, newApple, pl);
            break;
        case 'l':
            changePosition(currentPart, currentPart->x - 1, currentPart->y, mainBoard, newApple, pl);
            break;
        case 'u':
            changePosition(currentPart, currentPart->x, currentPart->y - 1, mainBoard, newApple, pl);
            break;
        case 'd':
            changePosition(currentPart, currentPart->x, currentPart->y + 1, mainBoard, newApple, pl);
            break;

        default:
            break;
        }
    }
}