#include "sandpiles.h"

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles.
 * @grid1: First sandpile.
 * @grid2: Second sandpile.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0, is_stable = 1;
	int new[3][3];

	sum_sandpiles(grid1, grid2);
	while (is_stable == 1)
	{
		is_stable = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				new[i][j] = 0;
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					printf("=\n");
					printgrid(grid1);
					balance_sandpile(new, j, i);
					is_stable = 1;
				}
			}
		}
		sum_sandpiles(grid1, new);
	}
}

/**
 * sum_sandpiles - Function that sums two sandpiles.
 * @grid1: First sandpile.
 * @grid2: Second sandpile.
 */
void sum_sandpiles(int grid1[3][3], int grid2[3][3])
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

/**
 * balance_sandpile - Function that makes stable a Sandpile.
 * @grid: Sandpile to be balanced.
 * @i: Posiion of the Sandpile to be balanced.
 * @j: Posiion of the Sandpile to be balanced.
 */
void balance_sandpile(int grid[3][3], int i, int j)
{
	grid[j][i] = grid[j][i] - 4;
	if (i + 1 < 3)
		grid[j][i + 1]++;

	if (i - 1 > -1)
		grid[j][i - 1]++;

	if (j + 1 < 3)
		grid[j + 1][i]++;

	if (j - 1 > -1)
		grid[j - 1][i]++;
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
