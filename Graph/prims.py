import heapq  
n = 5
# Each list has (weight, neighbor) pairs
graph = {
    0: [(2, 1), (3, 3)],
    1: [(2, 0), (1, 2), (4, 3)],
    2: [(1, 1), (5, 3), (6, 4)],
    3: [(3, 0), (4, 1), (5, 2)],
    4: [(6, 2)]
}
visited = [0] * n

pq = []
mst = []
total_weight=0

start_vertex = 0
visited[start_vertex] = True

for edge in graph[start_vertex]:
    heapq.heappush(pq, (edge[0], start_vertex, edge[1]))


while len(mst) < n - 1 and pq:
    weight, u, v = heapq.heappop(pq)
    if not visited[v]:
        visited[v] = True
        mst.append((u, v, weight))
        total_weight +=weight
        for next_edge in graph[v]:
            if not visited[next_edge[1]]:
                heapq.heappush(pq, (next_edge[0], v, next_edge[1]))


print("Minimum Spanning Tree:")
for u, v, w in mst:
    print(f"{u} - {v} (weight: {w})")

print(f"The total weight of MST: {total_weight}")

