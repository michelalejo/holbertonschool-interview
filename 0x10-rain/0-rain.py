#!/usr/bin/python3
"""Calculate how much water will be retained after it rains."""


def rain(walls):
    """Calculate how much water will be retained after it rains."""
    if(not len(walls)):
        return 0

    size = len(walls) - 1
    prev_wall = walls[0]
    prev_wall_index = 0
    temp = 0
    water = 0
    for i in range(1, size + 1):
        if (walls[i] >= prev_wall):
            prev_wall = walls[i]
            prev_wall_index = i
            temp = 0
        else:
            water += prev_wall - walls[i]
            temp += prev_wall - walls[i]

    if (prev_wall_index < size):
        water -= temp
        prev_wall = walls[i]

        for i in range(size, prev_wall_index - 1, -1):
            if (walls[i] >= prev_wall):
                prev_wall = walls[i]
            else:
                water += prev_wall - walls[i]

    return water
