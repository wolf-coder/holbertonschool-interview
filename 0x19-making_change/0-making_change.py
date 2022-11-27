#!/usr/bin/python3
"""
Time complexity: O(Array_size x total_amount_required).
Auxiliary space: O(total_amount_required) for using extra matrix space
"""
import sys
def makeChange(coins, total):
    """
    + coins: List containing the possible coins to use.
    + total: 
    + Return: fewest number of coins needed to meet total
        If total is 0 or less, return 0
        If total cannot be met by any number of coins you have, return -1
    """
    amount = total
    if amount <= 0 :
        return 0
    if min(coins) > amount:
        return -1
    dp = [-1 for i in range(0, amount + 1)]
    for i in coins:
        if i > len(dp) - 1:
            continue
        dp[i] = 1
        for j in range(i + 1, amount + 1):
            if dp[j - i] == -1:
                continue
            elif dp[j] == -1:
                dp[j] = dp[j - i] + 1
            else:
                dp[j] = min(dp[j], dp[j - i] + 1)
        #print(dp)
    return dp[amount]
