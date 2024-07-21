typedef struct
{
    int x, y;

} player;

void changePosition(player *pl, int newX, int newY)
{
    (*pl).x = newX;
    (*pl).y = newY;
}

void drawPlayer(player *pl, int width, int heigth, char field[heigth][width])
{
    // printf("%d, %d", (*pl).x, (*pl).y);

    field[(*pl).y][(*pl).x] = '@';
}