#!/usr/bin/python3
"""Exercise to practice interview"""


def canUnlockAll(boxes):
    """Checks if all boxes can be unlocked"""
    if not boxes:
        return False

    # Initialize a set to keep track of opened boxes
    opened_boxes = {0}

    # Initialize a queue for BFS traversal
    queue = [0]

    while queue:
        current_box = queue.pop(0)

        # Iterate through the keys in the current box
        for key in boxes[current_box]:
            # If the key opens a new box and that box hasn't been opened yet
            if key < len(boxes) and key not in opened_boxes:
                opened_boxes.add(key)
                queue.append(key)

    # If all boxes have been opened, return True
    return len(opened_boxes) == len(boxes)
