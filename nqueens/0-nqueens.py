#!/usr/bin/python3
"""
    A program that solves the N queens problem.
"""
import sys


def verify(placing, row, col):
    """
        Checks if the position of a queen at the i-th row and the j-th col
        conflicts with existing queens.

        Args:
            placing (list): a list of positions of already placed queens,
                where each element is [row, col].
            row (int): the horizontal line.
            col (int): the vertical line.

        Returns:
            True if the position is possible, False otherwise.
    """
    for i, j in placing:
        if i == row or j == col:
            return False
        if abs(i - row) == abs(j - col):
            return False

    return True


def solve_nqueens(n, placing, row):
    """
        Recursive backtracking function to solve N Queens
        
        Args:
            n (int): the number of pieces to placing.
            placing (list): a list of positions of already placed queens,
                where each element is [row, col].
            row (int): the horizontal line.
    """
    if row == n:
        print(placing[:])
        return

    for col in range(n):
        if verify(placing, row, col):
            placing.append([row, col])
            solve_nqueens(n, placing, row + 1)
            placing.pop()


def main():
    """
        Checks the number of arguments and displays all the placings.
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    placing = []
    solve_nqueens(n, placing, 0)


if __name__ == "__main__":
    main()
