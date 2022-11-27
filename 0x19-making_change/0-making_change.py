#!/usr/bin/python3
"""
Time complexity: O(Array_size x total_amount_required).
Auxiliary space: O(total_amount_required) for using extra matrix space
"""

INF = 10000
def makeChange(coins, total):
    """
    + coins: List containing the possible coins to use.
    + total: 
    + Return: fewest number of coins needed to meet total
        If total is 0 or less, return 0
        If total cannot be met by any number of coins you have, return -1
    """
    k = len(coins)
    n = total
    d= coins
    if total <= 0:
        return 0
    M = [0]*(n+1)
    S = [0]*(n+1)
#    breakpoint()
    for j in range(1, n+1):
        minimum = INF
        coin = 0

        for i in range(1, k):
            #breakpoint()
            if(j >= d[i]):
                minimum = min(minimum, 1+M[j-d[i]])
                coin = i
        M[j] = minimum
        S[j] = coin
    if M[n] == INF:
        return -1
    return M[n]

