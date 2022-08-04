#!/usr/bin/python3
"""
Minimum Operations with:
- Paste
- Copy all
"""


def minOperations(n):
    """
    > Returns an integer
    > If n is impossible to achieve, return 0
    """

    if not isinstance(n, int):
        return 0

    cp = final = 0
    paste = 1
    while paste < n:
        rest = n - paste
        if rest % paste == 0:
            final = paste
            cp += 2
            paste += final
        else:
            cp += 1
            paste += final

    return cp
