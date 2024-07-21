typedef struct
{
    int heigth, width;
    char block, air;
    char** field;
} board;

board initBoard(int heigth, int width, char block, char air, char field[heigth][width]){
    board newBoard = {heigth, width, block, air, .field = field};
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
