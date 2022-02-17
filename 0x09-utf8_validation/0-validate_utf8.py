#!/usr/bin/python3
"""
    UTF-8 the great hack.
"""


def validUTF8(data):
    """
    UTF-8 the great hack.
    """
    sig_byte = 0

    for item in data:
        Byte = format(item, '#010b')[2:]
        if sig_byte == 0:
            for bit in Byte:
                if bit == '0':
                    break
                sig_byte += 1

            if sig_byte == 0:
                continue

            if sig_byte == 1 or sig_byte > 4:
                return False
        else:
            if not (Byte[0] == '1' and Byte[1] == '0'):
                return False

        sig_byte -= 1
    return sig_byte == 0
