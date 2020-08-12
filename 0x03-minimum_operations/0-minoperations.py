#!/usr/bin/python3


def minOperations(n):
    """Minimum Operations"""
    if n <= 1:
        return 0

    for i in range(n - 1, 0, -1):
        if n % i == 0:
            number = n // i
            return number + minOperations(i)
