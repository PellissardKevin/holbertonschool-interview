#!/usr/bin/python3
"""
Rain method
"""


def rain(walls):
    left = 0
    right = (len(walls) - 1)

    left_max = 0
    right_max = 0

    quantity_rain = 0

    if not walls:
        return 0

    while left <= right:
        if right_max <= left_max:
            quantity_rain += max(0, right_max - walls[right])

            right_max = max(right_max, walls[right])
            right -= 1

        else:
            quantity_rain += max(0, left_max - walls[left])

            left_max = max(left_max, walls[left])

            left += 1

    return quantity_rain
