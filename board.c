#define WIDTH 40
#define HEIGTH 20

typedef struct
{
    int heigth, width;
    char block, air;
    char field[HEIGTH][WIDTH];
} board;

board initBoard(int heigth, int width, char block, char air, char field[heigth][width])
{
    board newBoard = {heigth, width, block, air, field};
    for (int i = 0; i != heigth; i++)
    {
        if (i == 0 || i == heigth - 1)
        {
            for (int j = 0; j != width; j++)
                newBoard.field[i][j] = block;
        }
        else
        {
            for (int j = 0; j != width; j++)
            {
                if (j == 0 || j == width - 1)
                {
                    newBoard.field[i][j] = block;
                }
                else
                {
                    newBoard.field[i][j] = air;
                }
            }
        }
    }
    return newBoard;
}

void showBoard(board *mainBoard)
{
    for (int i = 0; i != mainBoard->heigth; i++)
    {
        for (int j = 0; j != mainBoard->width; j++)
            printf("%c", mainBoard->field[i][j]);
        printf("\n");
    }
}