#!/usr/bin/python3
"""
    A script that determines the fewest number of coins needed to meet a given
    amount "total", given a pile of coins of different values.
"""


def division(dividende, diviseur):
    """
        Performs a division between two numbers.

        Args:
            dividende (int): the number to be divided.
            divisor (int): the number to divide by.

        Returns:
            The rest and the quotient of the division.
    """
    reste = dividende % diviseur
    quotient = dividende // diviseur

    return reste, quotient


def makeChange(coins, total):
    """
        Determines the fewest number of coins needed to meet a given amount
        total.

        Args:
            coins (list): a list of coins of different values.
            total (int): the target amount.

        Returns:
            fewest number of coins needed to meet total.
            If total is 0 or less, return 0.
            If total cannot be met by any number of coins you have, return -1.
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    sorted_coins = coins
    result = 0
    for coin in sorted_coins:
        total, quotient = division(total, coin)
        result += quotient
        if total == 0:
            return result

    return -1
