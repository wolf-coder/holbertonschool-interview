#!/usr/bin/python3

import sys
global N
global L  # list of solution


L = []
Arg_line = sys.argv
if len(Arg_line) != 2:
    print("Usage: nqueens N")
    sys.exit(1)
try:
    N = int(Arg_line[1])
except ValueError:
    print("N must be a number")
    sys.exit(1)

if N < 4:
    print("N must be at least 4")
    sys.exit(1)

N = int(sys.argv[1])


def Validity(P, a):
    """
    Check whether the `a` placement can be
    a part of the part solution P.
    """
    Validity = True
    for item in P:
        if a[1] == item[1] or a[0]-item[0] == abs(a[1] - item[1]):
            return not Validity
    return Validity


def queen(P):
    j = P[-1][0]
    if j < N - 1:
        for i in range(N):
            if Validity(P, [j+1, i]):
                Pc = P.copy()
                Pc.append([j+1, i])
                Res = queen(Pc)
        return False
    else:
        L.append(P)
        return P


for i in range(N):
    queen([[0, i]])
for solution in L:
    print(solution)
