#!/usr/bin/python3
"""
Calculating the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    Function that returns the perimeter of the island described in grid:
      + grid is a list of list of integers:
      + 0 represents water
      + 1 represents land
      + Each cell is square, with a side length of 1
      + Cells are connected horizontally/vertically (not diagonally).
      + grid is rectangular, with its width and height not exceeding 100
      + The grid is completely surrounded by water
      + There is only one island (or nothing).
      + The island doesn’t have “lakes” (water inside that
isn’t connected to the water surrounding the island).
    """
    def Two_cell(i, j):
        """
        Function that calculate the side to substract
        i,j: cell coordinates
        """
        subs = 0
        # check right
        if j < C - 1 and grid[i][j + 1] == 1:
            subs += 2
        # check right
        if i < R - 1 and grid[i+1][j] == 1:
            subs += 2
        return -subs

    R = len(grid)  # numer of rows
    C = len(grid[0])  # numer of columns
    count = 0
    for i in range(R):
        for j in range(C):
            if grid[i][j] == 1:
                count += (4 + Two_cell(i, j))

    return count
