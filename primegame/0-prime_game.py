#!/usr/bin/python3
"""
    Given a set of consecutive integers starting with 1 up to and including n,
    two players take turns choosing a prime number from the set and removing
    that number and its multiples from the set. The player that cannot make a
    move loses the game.
"""


def isWinner(x, nums):
    """
        Determines the overall winner of multiple rounds of the Prime Game.

        Args:
            x (int): The number of rounds played.
            nums (int): A list of integers representing n for each round.

        Returns:
            The name of the player that won the most rounds
    """

    def eratosthenes_sieve(n):
        """
            Generates a list indicating prime numbers up to n using the
            sieve of Eratosthenes algorithm.

            Args:
                n (int): the upper bound of numbers to check for primality.

            Returns:
                A list indicating if each number <= n is a prime number.
        """
        if n < 2:
            return [False] * (n + 1)
        is_prime = [False, False] + [True] * (n - 1)
        for i in range(2, int(n ** 0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, n + 1, i):
                    is_prime[j] = False

        return is_prime

    def count_primes_numbers(n):
        """
            Counts the number of prime numbers from 1 to n.

            Args:
                n (int): the pper bound to count primes.

            Returns:
                The total number of prime numbers <= n.
        """
        primes = eratosthenes_sieve(n)

        return sum(primes)

    maria_wins_counter = 0
    ben_wins_counter = 0

    for n in nums:
        primes_count = count_primes_numbers(n)
        if primes_count == 0:
            ben_wins_counter += 1
        elif primes_count % 2 == 1:
            maria_wins_counter += 1
        else:
            ben_wins_counter += 1

    if maria_wins_counter > ben_wins_counter:
        return "Maria"
    elif ben_wins_counter > maria_wins_counter:
        return "Ben"
    else:
        return None
