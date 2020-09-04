import sys


N = int(sys.stdin.readline())
x = 0
o = 0
point = 0
for n in range(N):
    line = sys.stdin.readline()
    x = 0
    o = 0
    point = 0
    for i in range(3):
        if(line[i]=='X' or line[i]=='x'):
            x = x + 1
        elif(line[i]=='O' or line[i]=='o'):
            o = o + 1
        else:
            point = point + 1
    if(o == x-1):
        print("yes")
    elif(o > x):
        print("no")
