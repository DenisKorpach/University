class Graph():
 
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)]
                      for row in range(vertices)]
 
    def printSolution(self, dist):
        print("Vertex \t Distance from Source")
        for node in range(self.V):
            print(node, "\t\t", dist[node])

    def minDistance(self, dist, sptSet):
 
        # Initialize minimum distance for next node
        min = 1e7

        for v in range(self.V):
            if dist[v] < min and sptSet[v] == False:
                min = dist[v]
                min_index = v
 
        return min_index

    def dijkstra(self, src):
 
        dist = [1e7] * self.V
        dist[src] = 0
        sptSet = [False] * self.V
 
        for cout in range(self.V):
            u = self.minDistance(dist, sptSet)
            sptSet[u] = True
 
            for v in range(self.V):
                if (self.graph[u][v] > 0 and
                   sptSet[v] == False and
                   dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]
 
        self.printSolution(dist)

g = Graph(7)
g.graph = [[0, 3, 7, 4, 0, 0, 0],
           [3, 0, 5, 2, 0, 0, 10],
           [7, 5, 0, 0, 0, 4, 0],
           [4, 2, 0, 0, 4, 0, 0],
           [0, 0, 0, 4, 0, 5,6],
           [0, 0, 4, 0, 5, 0,7],
           [0, 10, 0, 0, 6, 7, 0]
           ]
 
g.dijkstra(0)
