typedef struct
{
    int x, y;

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