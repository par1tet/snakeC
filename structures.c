#define HEIGTH 30
#define WIDTH 50

typedef struct part_stc
{
    int x;
    int y;
    char direction;
} part;

typedef struct
{
    int length;
    part *parts;
    char headIcon, partIcon;

} player;

typedef struct board_stc
{
    int heigth;
    int width;
    char block;
    char air;
    char field[HEIGTH][WIDTH];
} board;

typedef struct
{
    int x, y;
    char icon;
} apple;