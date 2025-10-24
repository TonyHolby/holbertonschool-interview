#!/usr/bin/python3
"""
    A function that returns the perimeter of the island described in grid.
"""


def island_perimeter(grid):
    """
        Returns the perimeter of the island described in grid.

        Args:
            grid (list of list): a list of list of integers.

        Returns:
            The perimeter of the island.
    """
    if not grid:
        return 0

    rows, cols = len(grid), len(grid[0])
    perimeter_count = 0

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                if row == 0 or grid[row - 1][col] == 0:
                    perimeter_count += 1
                if row == rows - 1 or grid[row + 1][col] == 0:
                    perimeter_count += 1
                if col == 0 or grid[row][col - 1] == 0:
                    perimeter_count += 1
                if col == cols - 1 or grid[row][col + 1] == 0:
                    perimeter_count += 1

    return perimeter_count
