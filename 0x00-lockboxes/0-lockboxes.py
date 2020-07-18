#!/usr/bin/python3


def canUnlockAll(boxes):
    if (type(boxes) is not list):
        return False

    if (len(boxes) == 0):
        return False

    keys = [0]
    for i in keys:
        for j in boxes[i]:
            if j not in keys:
                keys.append(j)
    if len(keys) == len(boxes):
        return True
    return False
