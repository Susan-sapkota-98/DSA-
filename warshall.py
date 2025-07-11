# Warshall Algorithm gives us
# Reachablility Matrix
# Transitive CLousre


import math
import pprint


# Boolean Matrix - Zero-One Matrix 
W = [
    [0, 1, 1, 0], 
    [0, 0, 1, 0], 
    [1, 0, 0, 1], 
    [0, 0, 0, 0]]

def display(data):
    for row in data:
        print(row)

def warshall_algo(W):
    n = len(W)
    D = W
    for k in range(0,n):
        for i in range(0, n):
            for j in range(0, n):
                D[i][j] = D[i][j] or (D[i][k] and D[k][j])
    return D

ans = warshall_algo(W)    
display(ans)    


