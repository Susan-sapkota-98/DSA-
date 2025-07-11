import math

# Graph Definition
G = {
    'A':{'B': 3, 'C':1},
    'B':{'A': 3, 'C':7, 'D':5, 'E':1},
    'C':{'A':1, 'B':7, 'D':2},
    'D':{'B':5, 'C':2, 'E':7},
    'E':{'B':1, 'D':7}
}

# Initialize distances and predecessors
def initialize(G, s):
    d = {vertex: math.inf for vertex in G}
    previous = {vertex: '' for vertex in G}
    d[s] = 0
    return d, previous

# Relaxation function
def relax(u, v, G, d, previous):
    if d[v] > d[u] + G[u][v]:
        d[v] = d[u] + G[u][v]
        previous[v] = u
    return d, previous

# Dijkstra's Algorithm
def dj(G, s):
    d, previous = initialize(G, s)
    visited = set()
    PQ = dict()
    for vertex in G:
        PQ[vertex] = math.inf
    PQ[s] = 0 
    while PQ:
        u = min(PQ, key=PQ.get)
        del PQ[u] 
        visited.add(u)
        for v in G[u]:
            if v not in visited:
                old_cost = d[v]
                d, previous = relax(u, v, G, d, previous)
                if d[v] < old_cost:
                    PQ[v] = d[v]  # Update the best cost to the PQ
    return d, previous

# Construct Path
def constructPath(previous, node1, node2):
    if previous[node2] == '' and node1 != node2:  # No path exists
        return "No path"
    path = []
    while node2 != '':
        path.append(node2)
        node2 = previous[node2]
    path.reverse()
    return "->".join(path)

# Driver Code
start = 'C'
cost, previous = dj(G, start)
print("Shortest distances from node", start, "to all other nodes:")
print(cost)
print("\nPredecessors for each node:")
print(previous)

print("\nDetailed Paths and Costs:")
for vertex in G:
    print(f"Shortest path from {start} to {vertex} = {constructPath(previous, start, vertex)} and Cost = {cost[vertex]}")

