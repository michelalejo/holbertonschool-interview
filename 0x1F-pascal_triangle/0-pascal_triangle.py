#!/usr/bin/python3
"""
Returns a list of lists of integers
representing the Pascal’s triangle of n
"""


def pascal_triangle(n):
    """
    Returns an empty list if n <= 0
    n will be always an integer
    """
    if n <= 0:
        return []

    trgl = [[1]]

    for cnt in range(1, n):
        trgl.append([])

        for mv in range(cnt + 1):

            if mv == 0 or mv == cnt:
                trgl[cnt].append(1)

            else:
                trgl[cnt].append(trgl[cnt - 1][mv - 1] + trgl[cnt - 1][mv])
    return trgl
