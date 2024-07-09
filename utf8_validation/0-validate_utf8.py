#!/usr/bin/python3
"""
Definition of validation UTF8
"""


def validUTF8(data):
    # Number of bytes in the current UTF-8 character
    num_bytes = 0

    # Masks to check the significant bits
    mask1 = 1 << 7
    mask2 = 1 << 6

    for num in data:
        mask = 1 << 7
        if num_bytes == 0:
            # Count the number of leading 1's
            while mask & num:
                num_bytes += 1
                mask = mask >> 1

            # 1 byte characters (0xxxxxxx) or invalid starting bytes (10xxxxxx)
            if num_bytes == 0:
                continue
            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            # If this byte doesn't start with 10xxxxxx
            if not (num & mask1 and not (num & mask2)):
                return False

        num_bytes -= 1

    # If num_bytes is not 0, then we have an incomplete character
    return num_bytes == 0
