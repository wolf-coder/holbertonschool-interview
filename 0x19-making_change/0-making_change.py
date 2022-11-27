#!/usr/bin/python3
"""
Time complexity: O(Array_size x total_amount_required).
Auxiliary space: O(total_amount_required) for using extra matrix space
"""
def makeChange(coins, total):
    '''determine the fewest number of coins
    needed to meet a given amount total'''
    if total <= 0:
        return 0
    nCoins = 0
    coins = sorted(coins, reverse=True)
    for coin in coins:
        quotient, total = divmod(total, coin)
        nCoins += quotient
        if total == 0:
            return nCoins
    return -1
