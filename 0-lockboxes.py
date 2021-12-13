#!/usr/bin/python3
"""
Fun challenge of unlocking boxes
"""


def canUnlockAll(boxes):
    """
    boxes is a list of lists.
    A key with the same number as a box opens that box.
    You can assume all keys will be positive integers.
        There can be keys that do not have boxes.

    The first box boxes[0] is unlocked.
    Return True if all boxes can be opened, else return False.
    """
    keys = set(boxes[0])
    unlocked_boxes = set(range(1, len(boxes)))
    i = 1
    while i < len(boxes):
        if i in keys and i in unlocked_boxes:
            unlocked_boxes.remove(i)
            keys.update(boxes[i])
            Intersection = set(boxes[i]).intersection(unlocked_boxes)
            if Intersection and min(Intersection) < i:
                i = min(set(boxes[i]).intersection(unlocked_boxes))
            else:
                i += 1
        else:
            i += 1
    if unlocked_boxes:
        return False
    else:
        return True
