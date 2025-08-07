edges = [
    #weight,x,y
    (1, 0, 1),
    (3, 0, 2),
    (3, 1, 2),
    (6, 1, 3),
    (4, 2, 3)
]

V = 4

parent=[]
for i in range(V):
    parent.append(i)

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])  
    return parent[x]

def union(x, y):
    root_x = find(x)
    root_y = find(y)
    if root_x != root_y:
        parent[root_y] = root_x  


edges.sort()  
mst = []
total_weight=0

print("Edge : Weight")
for weight, x, y in edges:
    if find(x) != find(y):
        union(x, y)
        mst.append((x, y, weight))
        total_weight +=weight
        print(f"{x} - {y} :(weight : {weight}) ")

print("The Total weight of MST :",total_weight)