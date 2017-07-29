'''
Author: Sofen Hoque Anonta
Problem: Given a 3*3 grid that represents an 8 puzzle game.
Find the shortest number of steps needed to reach a goal state (the squares are  in ascending order)
'''
import sys, re, cmd, PyQt5

# --------------------------------------------------------------


def readPuzzle(readable):
    grid = []
    for s in readable:
        grid.append([int(a) for a in s.split()])

    return grid


def printPuzzle(grid):
    print('------------------')
    for x in range(3):
        print(' '.join([str(y) for y in grid[x]]))
    print('------------------')


def genHash(grid):
    '''
    generate hash of a grid
    '''
    sum= []
    for r in grid:
        sum.extend(r)

    return int(''.join([str(x) for x in sum])[::-1])

# moves
movx= (1, 0, -1, 0)
movy= (0, 1, 0, -1)


def findSpaceSquare(g):
    for x in range(3):
        for y in range(3):
            if g[x][y] == 0: return (x,y)


# goalHash= genHash([[0,1,2],[3,4,5],[6,7,8]])
goalHash= genHash([[1,2,3],[4,5,6],[7,8,0]])

visited = set()

outputf= None

def dfs(cost, x, y, g):

    # depth limit for dfs
    if cost > 900 :
        return

    hash = genHash(g)

    if hash == goalHash:
        print(cost)
        return

    if hash in visited: return
    visited.add(hash)

    # debug code
    # printPuzzle(g)
    # print(x,y)
    # print(visited)
    # print(hash, goalHash)
    # input()

    for i in range(4):

        #calculate next position
        nx = movx[i]+x
        ny = movy[i]+y

        #see if next move is valid
        if nx < 0 or nx > 2 or ny < 0 or ny > 2:
            continue

        # swap current and next position
        temp = g[x][y]
        g[x][y]= g[nx][ny]
        g[nx][ny]= temp

        dfs(cost+1, nx, ny, g)

        temp = g[x][y]
        g[x][y] = g[nx][ny]
        g[nx][ny] = temp



def main():
    with open('F:/input.txt', 'r') as fin:
        # g= readPuzzle(fin)
        g= readPuzzle(sys.stdin)
        # printPuzzle(g)


        dfs(0, *findSpaceSquare(g),g)


if __name__ == '__main__':
    main()