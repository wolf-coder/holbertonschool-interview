#!/usr/bin/python3
"""
Pascal’s triangle
"""


def pascal_triangle(n):
    """
    Function that returns a list of lists of integers representing
 the Pascal’s triangle of n:
      + Returns an empty list if n <= 0
      + You can assume n will be always an integer
    """

    Array = []
    edges = [0]
    top = [1]

    if n <= 0:
        return Array
    for _ in range(n):
        Array.append(top)
        top = [x + y for x, y in zip(top + edges, edges + top)]

    return Array
