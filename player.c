#include "board.c"

void addPart(part **parts, int length, part elem)
{
    part* newParts = malloc(24);

    for (int i = 0; i != length; i++)
    {
        newParts[i] = (*parts[i]);
    }

    *parts = newParts;
}
int changePosition(part *pt, int newX, int newY, board *mainBoard, apple *newApple, player *pl)
{
    printf("%p", pl->parts);
    if (mainBoard->field[newY][newX] == newApple->icon && mainBoard->field[pt->y][pt->x] == pl->headIcon)
    {
        part newPart = {1, 7, 'r'};
        addPart(&(pl->parts), pl->length, newPart);
        pl->length++;
    }
    else if (mainBoard->field[newY][newX] != mainBoard->air)
        return 0;

    mainBoard->field[pt->y][pt->x] = mainBoard->air;
    pt->x = newX;
    pt->y = newY;
    for (int i = 0; i != pl->length; i++)
    {
        printf("%d,%d,%c\n", pl->parts[i].x, pl->parts[i].y, pl->parts[i].direction);
    }
    printf("%d\n", pl->length);
    printf("%ld\n", (pl->length) * sizeof(part));
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