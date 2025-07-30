import math
import pprint

W = [
    [0, 4, 11],
    [6, 0, 2],
    [3, math.inf, 0]
]
# for infinite math.info is used

def display(data):
    for row in data:
        print(row)

def FW(W):
    n = len(W)
    D = {}
    D[0] = W
    for k in range(1,n+1):
        D[k] = D[k-1]
        for i in range(1, n+1):
            for j in range(1, n+1):
                D[k][i-1][j-1] = min(D[k-1][i-1][j-1],D[k-1][i-1][k-1] + D[k-1][k-1][j-1])
        print(f'When k = {k}')
        display(D[k])
    return D

ans = FW(W)
print(ans[len(W)])            


