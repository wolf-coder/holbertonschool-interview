#!/usr/bin/python3
"""
Time complexity: O(Array_size x total_amount_required).
Auxiliary space: O(total_amount_required) for using extra matrix space
"""
import sys
def makeChange(coins, total):
    """
    determine the fewest number of coins needed
    to meet a given amount total
    """
    number_coins = 0
    cents = 0
    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)

    for coin in coins:
        while cents + coin <= total:
            cents += coin
            number_coins += 1
        if cents == total:
            return number_coins
    return -1
