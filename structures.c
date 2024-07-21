#define HEIGTH 20
#define WIDTH 40

typedef struct
{
    int x, y;
    char direction, playerIcon;
} part;

typedef struct
{
    int length;

    part *parts;
} player;

typedef struct
{
    int heigth, width;
    char block, air;
    char field[HEIGTH][WIDTH];
} board;

typedef struct
{
    int x, y;
    char icon;
} apple;