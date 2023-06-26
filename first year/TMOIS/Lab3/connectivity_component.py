import collections as coll
 
def DFS(graph, start, VISITED=None): 
    if VISITED is None:              #
        VISITED = set()              #обход в ширину
    VISITED.add(start)               #
    for next in set(graph[start]) - VISITED: 
        DFS(graph, next, VISITED) 
    return VISITED 
 

def BFS(graph, root):  
    VISITED, queue = set(), coll.deque([root]) 
    VISITED.add(root) 
    while queue:  
        vertex = queue.popleft() 

        for neighbour in graph[vertex]: 
                                          #
            if neighbour not in VISITED:  #обход в глубину
                VISITED.add(neighbour)    #
                queue.append(neighbour)  
    return VISITED 
 

if __name__ == '__main__': 
    graph = {0: [3],  
             1: [3,5],  
             2: [5],  
             3: [0,1,4], 
             4: [3,5], 
             5: [1,2,4],
             6: [7],
             7: [6]}  
 
    VISITED = BFS(graph, 0) 
    count = 1 
    for NODE in graph: 
        if NODE not in VISITED: 
            VISITED = BFS(graph, NODE) 
            count += 1
    print(f'BFS: count = {count}') 
 
    VISITED = DFS(graph, 0) 
    count = 1 
    for NODE in graph: 
        if NODE not in VISITED: 
            VISITED = DFS(graph, NODE) 
            count += 1 
    print(f'DFS: count = {count}')