'''
Author: Sofen Hoque Anonta
Problem: Find all posible arrangements in which
8 queens can be placed in an 8 by 8 chess board
such that no queen is under attack 
'''

import sys


def readBoard(readable):
    board = []
    for r in range(8):
        board.append(readable.readline())

    return board


# hold true for columns and rows that are blocked
brow = [False] * 8
bcol = [False] * 8
queen_positions = []  # stores ordered pairs of x y positions of currently inserted queens


def printBoard(board):
    print('---------------')
    for r in board:
        print(' '.join([str(x) for x in r]))
    print('---------------')


def conflicts(x, y):
    ''' return if placing a queen in x y opsition creates conflicts '''
    if brow[x] or bcol[y]: return True

    for r, c in queen_positions:
        if (abs(r - x) == abs(c - y)): return True
    return False



def nQueen(g, n):
    # printBoard(g)
    # input()

    'try to put n queens on the g board'

    if n == 0:
        printBoard(g)
        return

    for r in range(8):
        for c in range(8):
            if conflicts(r, c): continue

            brow[r] = True
            bcol[c] = True
            queen_positions.append((r, c))

            g[r][c] = 'Q'

            nQueen(g, n - 1)

            g[r][c] = '#'
            brow[r] = False
            bcol[c] = False
            queen_positions.remove((r, c))


def main():
    g = [['#' for y in range(8)] for x in range(8)]
    nQueen(g, 8)


if __name__ == '__main__':
    main()





