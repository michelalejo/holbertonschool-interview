#include "sandpiles.h"

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i = 0, j = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
}