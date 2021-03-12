def bfs(adjList, distance, parent, source):
    q = []  # a queue
    q.append(source)
    distance[source] = 0  # source distance is ZERO

    while q:  # queue not equals to empty
        u = q.pop(0)

        for i in range(len(adjList[u])):
            v = adjList[u][i]

            if distance[v] == -1:
                distance[v] = distance[u] + 1
                parent[v] = u
                q.append(v)


# driver code / Global code

numOfNodes, numOfEdges = map(int, input().split())

adjList = [[] for _ in range(numOfNodes + 1)]
distance = [-1 for _ in range(numOfNodes + 1)]
parent = [-1 for _ in range(numOfNodes + 1)]


for i in range(numOfEdges):
    u, v = map(int, input().split())
    adjList[u].append(v)
    adjList[v].append(u)

source = int(input())

bfs(adjList, distance, parent, source)


# printing source to destination path

destination = int(input())
copyDestination = destination
result = []

while parent[destination] != source:
    result.append(parent[destination])
    destination = parent[destination]

result = reversed(result)
print(source, end=" ")
for i in result:
    print(f'{i} ', end="")
print(copyDestination)
