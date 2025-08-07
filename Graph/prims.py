graph = {
    0: [(2, 1), (3, 3)],
    1: [(2, 0), (1, 2), (4, 3)],
    2: [(1, 1), (5, 3), (6, 4)],
    3: [(3, 0), (4, 1), (5, 2)],
    4: [(6, 2)]
}
n = 5
def prims_algorithm(graph, n):
    selected = [False] * n
    key = [float('inf')] * n
    parent = [-1] * n

    key[0] = 0

    for _ in range(n):
        min_key = float('inf')
        u = -1
        for v in range(n):
            if not selected[v] and key[v] < min_key:
                min_key = key[v]
                u = v

        if u == -1:  
            break

        selected[u] = True

        for weight, ximeki in graph[u]:
            if not selected[ximeki] and weight < key[ximeki]:
                key[ximeki] = weight
                parent[ximeki] = u

    total_weight = 0
    print("Minimum Spanning Tree:")
    for i in range(1, n):
        if parent[i] == -1:
            continue
        print(f"{parent[i]} - {i} (weight: {key[i]})")
        total_weight += key[i]

    print(f"Total weight of MST: {total_weight}")




prims_algorithm(graph, n)
