#!/usr/bin/python3
"""

"""


def Per_line(line):
    """
    line is a vector to calculate its retained rainwater.
    """
    sum = 0
    add = 0
    count = False
    for el in line:
        if el == 0 and count:
            add += 1
        if el == 1:
            sum += add
            add = 0
            count = True
    return sum


def rain(walls):
    """
    - walls is a list of non-negative integers.
    - Return: Integer indicating total amount of rainwater retained.
    - Assume that the ends of the list (before index 0 and after index
        walls[-1]) are not walls, meaning they will not retain water.
    - If the list is empty return 0.
    """

    # Transform walls into a matrix
    matrix = []
    Max_wall = max(walls)
    for base in walls:
        line = [0] * Max_wall
        for i in range(base):
            if base != 0:
                line[0:base] = [1] * base
        matrix.append(line)
    matrix = [list(el) for el in zip(*matrix)]

    sum = 0
    for line in matrix:
        sum += Per_line(line)

    return sum
