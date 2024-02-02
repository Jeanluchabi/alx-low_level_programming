#!/usr/bin/python3
"""This function  returns the perimeter of the island"""


def island_perimeter(grid):
    """
    Calculates the perimeter of the island in the grid.

    Args:
        grid(lists): A list of list of integers representing the grid.

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    width = len(grid[0])
    height = len(grid)

    for i in range(width):
        for j in range(height):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
