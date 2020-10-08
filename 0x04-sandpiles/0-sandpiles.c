#include "sandpiles.h"

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles.
 * @grid1: First sandpile.
 * @grid2: Second sandpile.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, toppling = 0;
	int toppling_check[3][3];

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	do {
		toppling = 0;
		for (i = 0; i < SIZE; i++)
			for (j = 0; j < SIZE; j++)
			{
				if (grid1[i][j] > 3)
				{
					toppling_check[i][j] = 1;
					toppling = 1;
				}
				else
					toppling_check[i][j] = 0;
			}
		if (toppling)
		{
			printgrid(grid1);
			for (i = 0; i < SIZE; i++)
				for (j = 0; j < SIZE; j++)
				{
					if (toppling_check[i][j] == 1)
						balance_sandpile(grid1, i, j);
				}
		}
	} while (toppling);
}

/**
 * balance_sandpile - Function that makes stable a Sandpile.
 * @grid1: Sandpile to be balanced.
 * @i: Posiion of the Sandpile to be balanced.
 * @j: Posiion of the Sandpile to be balanced.
 */
void balance_sandpile(int grid1[3][3], int i, int j)
{
	int l_i = 0, l_j = -1;
	int r_i = 0, r_j = 1;
	int u_i = -1, u_j = 0;
	int d_i = 1, d_j = 0;

	grid1[i][j] -= 4;

	if (IN_RANGE(l_i + i, l_j + j))
		grid1[l_i + i][l_j + j] += 1;
	if (IN_RANGE(r_i + i, r_j + j))
		grid1[r_i + i][r_j + j] += 1;
	if (IN_RANGE(u_i + i, u_j + j))
		grid1[u_i + i][u_j + j] += 1;
	if (IN_RANGE(d_i + i, d_j + j))
		grid1[d_i + i][d_j + j] += 1;
}

/**
 * printgrid - Function that prints a Sandpile.
 * @grid: Sandpile to be printed
 */
void printgrid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
