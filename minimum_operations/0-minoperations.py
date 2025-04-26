#!/usr/bin/python3
"""
    A script that determines the number of operations needed
    to obtain n H in a text file with minimum operations.
"""


def minOperations(n):
    """
        Returns the number of operations (copy all or paste)
        with minimum operations.

        Arg:
            n (int): a given number.

        Returns:
            The number of operations or
            0 if n is impossible to achieve.
    """
    if n < 2:
        return 0

    for i in range(2, n + 1):
        if n % i == 0:
            number_of_operations = i + minOperations(n // i)

            return number_of_operations
