typedef struct
{
    int x, y;
    char direction;

} player;

int changePosition(player *pl, int newX, int newY, int width, int heigth, char field[heigth][width])
{
    if (field[newY][newX] == '#')
        return 0;

    (*pl).x = newX;
    (*pl).y = newY;
}

void drawPlayer(player *pl, int width, int heigth, char field[heigth][width])
{
    // printf("%d, %d", (*pl).x, (*pl).y);
    field[(*pl).y][(*pl).x] = '@';
}

void movePlayer(player *pl, int width, int heigth, char field[heigth][width])
{
    switch ((*pl).direction)
    {
    case 'r':
        changePosition(pl, (*pl).x + 1, (*pl).y, width, heigth, field);
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