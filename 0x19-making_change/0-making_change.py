#!/usr/bin/python3
"""
Coin changer.
"""


def makeChange(coins, total):
    """Fewest number of coins needed to meet a given amount total."""

    if total <= 0:
        return 0

    coins.sort(reverse=True)
    stack = total
    mv = 0
    cnt = 0

    while (mv < len(coins)):
        if stack == 0:
            return cnt

        if coins[mv] > stack:
            mv += 1

        else:
            stack -= coins[mv]
            cnt += 1

    return -1
