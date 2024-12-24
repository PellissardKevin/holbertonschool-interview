#!/usr/bin/python3
"""
PrimeGame Definition
"""


def isWinner(x, nums):
    """
    Determines the winner of a game played over x rounds where Maria and Ben choose prime numbers optimally.
    :param x: Number of rounds.
    :param nums: Array of integers where each element represents the upper limit n for the round.
    :return: Name of the player who won the most rounds or None if it's a tie.
    """
    if x < 1 or not nums:
        return None

    # Helper function to determine all primes up to the maximum number in nums
    def sieve_of_eratosthenes(max_n):
        is_prime = [True] * (max_n + 1)
        is_prime[0] = is_prime[1] = False
        for i in range(2, int(max_n**0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, max_n + 1, i):
                    is_prime[j] = False
        return is_prime

    max_num = max(nums)
    primes = sieve_of_eratosthenes(max_num)

    # Precompute the number of primes up to each number
    prime_count = [0] * (max_num + 1)
    for i in range(1, max_num + 1):
        prime_count[i] = prime_count[i - 1] + (1 if primes[i] else 0)

    maria_wins = 0
    ben_wins = 0

    # Simulate each round
    for n in nums:
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
