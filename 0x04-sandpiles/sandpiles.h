#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void sum_sandpiles(int grid1[3][3], int grid2[3][3]);
void printgrid(int grid[3][3]);
void balance_sandpile(int grid[3][3], int i, int j);

#endif
