#!/usr/bin/python3
"""
    Prototype:
    def isWinner(x, nums):
    
    Parameters:
    x: int: the number of rounds
    nums: List[int]: an array of n
    
    Return: 
    Name of the player that won the most rounds.
    If the winner cannot be determined, return None"""


def isWinner(x, nums):
    if x >= 10000 or max(nums) >= 10000:
        return None

    maria_wins = 0
    ben_wins = 0
    round_num = 1
    current_player = "Maria"

    for n in nums:
        if n <= 1:
            ben_wins += 1
            round_num += 1
            continue
        integers = set(range(2, n + 1))
        while integers:
            primes = set(
                i for i in integers if all(
                    i %
                    j != 0 for j in range(
                        2, int(
                            i ** 0.5) + 1)))
            if primes:
                if current_player == "Maria":
                    integers -= set(range(min(primes), n + 1, min(primes)))
                    maria_wins += 1
                    current_player = "Ben"
                else:
                    integers -= set(range(min(primes), n + 1, min(primes)))
                    ben_wins += 1
                    current_player = "Maria"
            else:
                break

    if maria_wins > ben_wins:
        return "Maria"
    elif maria_wins < ben_wins:
        return "Ben"
    else:
        return None
