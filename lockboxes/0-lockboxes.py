#!/usr/bin/env python3
""" A method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    """
        Determines if all the boxes can be opened.

        Parameters:
            boxes (list of lists): The boxes.

        Returns:
            True if all boxes can be opened, else return False.
    """
    number_of_boxes = len(boxes)
    opened_box = set([0])
    keys = set(boxes[0])

    while keys:
        key = keys.pop()
        if key not in opened_box:
            opened_box.add(key)
            keys.update(boxes[key])

    if len(opened_box) == number_of_boxes:
        return True

    return False
