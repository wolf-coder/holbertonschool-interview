#!/usr/bin/python3
"""
Time complexity: O(Array_size x total_amount_required).
Auxiliary space: O(total_amount_required) for using extra matrix space
"""
INF = 400000  # Avoiding `sys.maxsize` for runtime evaluation


def makeChange(coins, total):
    """
    + coins: List containing the possible coins to use.
    + total: amount to satisfy
    + Return: fewest number of coins needed to meet total
        If total is 0 or less, return 0
        If total cannot be met by any number of coins you have, return -1
    """
    if total <= 0:
        return 0
    coins = sorted(coins, reverse=False)

    matrix = [INF for i in range(total + 1)]

    matrix[0] = 0

    for i in range(1, total + 1):
        for j in range(len(coins)):
            if (coins[j] <= i):
                sub_res = matrix[i - coins[j]]
                if (sub_res != INF and sub_res + 1 < matrix[i]):
                    matrix[i] = sub_res + 1

    if matrix[total] == INF:
        return -1
    return matrix[total]
