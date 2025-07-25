#!/usr/bin/python3
"""
    A script that calculates how many square units of water (representing
    the heights between two walls, as if viewing the cross-section of a
    relief map) will be retained after it rains.
"""


def rain(walls):
    """
        Calculates how many square units of water will be retained after it
        rains.

        Args:
            walls (list): a list of non-negative integers.

        Returns:
            An integer indicating total amount of rainwater retained and
            0 if the list is empty.
    """
    rainwater = 0

    for index in range(1, len(walls) - 1):
        left_wall = walls[index]
        for i in range(index):
            left_wall = max(left_wall, walls[i])

        right_wall = walls[index]
        for j in range(i + 1, len(walls)):
            right_wall = max(right_wall, walls[j])

        rainwater += (min(left_wall, right_wall) - walls[index])

    return rainwater
