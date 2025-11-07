#!/usr/bin/python3
"""
    A function that returns a list of lists of integers representing
    the Pascal's triangle of n.
"""


def compute_factorial(number):
    """
        Compute the factorial of a number.

        Args:
            number (int): the number to compute.

        Returns:
            The factorial of the number.
    """
    if number == 0 or number == 1:
        return 1

    return number * compute_factorial(number - 1)


def pascal_triangle(n):
    """
        Returns a list of lists of integers representing
        the Pascal's triangle of n.

        Args:
            n (int): an integer.

        Returns:
            A list of lists of integers representing
            the Pascal's triangle of n
            or an empty list if n <= 0.
    """
    pascals_triangle = []
    if n <= 0:
        return pascals_triangle

    for i in range(n):
        row = []
        for j in range(i+1):
            row.append(compute_factorial(i) //
                       (compute_factorial(j) * compute_factorial(i-j)))
        pascals_triangle.append(row)

    return pascals_triangle
