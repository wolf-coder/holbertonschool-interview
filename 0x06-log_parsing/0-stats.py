#!/usr/bin/python3

import sys

Files10_Size = 0
counter = 0

Dicts_codes = {'200': 0, '301': 0, '400': 0, '401': 0,
                      '403': 0, '404': 0, '405': 0, '500': 0}

try:
    for line in sys.stdin:
        line_list = line.split(" ")
        if len(line_list) > 2:
            code = line_list[-2]
            size = int(line_list[-1])
            if code in Dicts_codes.keys():
                Dicts_codes[code] += 1
            Files10_Size += size
            counter += 1

        if counter == 10:
            print("File size: {:d}".format(Files10_Size))
            for k, v in sorted(Dicts_codes.items()):
                if v != 0:
                    print("{}: {:d}".format(k, v))
            counter = 0

except Exception:
    pass

finally:
    print("File size: {}".format(Files10_Size))
    for k, v in sorted(Dicts_codes.items()):
        if v != 0:
            print("{}: {}".format(k, v))
