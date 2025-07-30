# Define the graph as a list of edges: (weight, u, v)
edges = [
    (1, 0, 1),
    (3, 0, 2),
    (3, 1, 2),
    (6, 1, 3),
    (4, 2, 3)
]

# Number of vertices
V = 4

# Disjoint Set (Union-Find) helper functions
parent = [i for i in range(V)]  # Initially, each node is its own parent

def find(u):
    if parent[u] != u:
        parent[u] = find(parent[u])  # Path compression
    return parent[u]

def union(u, v):
    root_u = find(u)
    root_v = find(v)
    if root_u != root_v:
        parent[root_v] = root_u  # Union

# Kruskal's Algorithm
edges.sort()  # Sort edges by weight
mst = []

print("Edge : Weight")
for weight, u, v in edges:
    if find(u) != find(v):
        union(u, v)
        mst.append((u, v, weight))
        print(f"{u} - {v} : {weight}")
