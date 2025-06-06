#!/usr/bin/python3
"""
    A method that determines if a given data set represents a valid UTF-8
    encoding.
"""


def validUTF8(data):
    """
        A method that determines if a given data set represents a valid UTF-8
        encoding.

        Args:
            data (list): a list of integers.

        Returns:
            True if data is a valid UTF-8 encoding, else return False.
    """
    next_octet = 0

    for number in data:
        if number < 0 or number > 255:
            return False

        if next_octet == 0:
            if number < 128:
                continue
            elif 192 <= number <= 223:
                next_octet = 1
            elif 224 <= number <= 239:
                next_octet = 2
            elif 240 <= number <= 247:
                next_octet = 3
            else:
                return False
        else:
            if number < 128 or number > 191:
                return False
            next_octet -= 1

    return next_octet == 0
