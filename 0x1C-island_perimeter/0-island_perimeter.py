#!/usr/bin/python3
"""
Returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    Returns the perimeter of the island described in grid
    """
    cnt = 0
    perim = 0

    while cnt < len(grid):
        mv = 0
        while mv < len(grid[0]):
            if grid[cnt][mv] == 1:
                perim += 4

                if cnt - 1 >= 0 and grid[cnt - 1][mv] == 1:
                    perim -= 1

                if cnt + 1 < len(grid) and grid[cnt + 1][mv] == 1:
                    perim -= 1

                if mv - 1 >= 0 and grid[cnt][mv - 1] == 1:
                    perim -= 1

                if mv + 1 < len(grid[0]) and grid[cnt][mv + 1] == 1:
                    perim -= 1

            mv += 1
        cnt += 1
    return perim
