#!/usr/bin/python3
""" A function that rotates a 2D matrix 90 degrees clockwise. """


def rotate_2d_matrix(matrix):
    """ Rotates a 2D matrix 90 degrees clockwise. """
    matrix[:] = [list(row)[::-1] for row in zip(*matrix)]
