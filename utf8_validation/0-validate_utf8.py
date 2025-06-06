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
        byte = number & 0xFF

        if next_octet == 0:
            if byte < 128:
                continue
            elif 192 <= byte <= 223:
                next_octet = 1
            elif 224 <= byte <= 239:
                next_octet = 2
            elif 240 <= byte <= 247:
                next_octet = 3
            else:
                return False
        else:
            if byte < 128 or byte > 191:
                return False
            next_octet -= 1

    return next_octet == 0
