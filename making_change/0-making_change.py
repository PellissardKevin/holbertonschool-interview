#!/usr/bin/python3

def makeChange(coins, total):
    if total <= 0:
        return 0

    # Initialize dp array with infinity, since we're looking for minimum coins
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    # Loop over each coin in the list
    for coin in coins:
        for amount in range(coin, total + 1):
            # Update the dp table with the minimum coins needed for the current amount
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    # If dp[total] is still infinity, return -1 (total cannot be met)
    return dp[total] if dp[total] != float('inf') else -1
