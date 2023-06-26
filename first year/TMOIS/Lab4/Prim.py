from math import inf
G=[[0,2,3,0,0,0,0,0,0],
   [2,0,4,0,0,0,0,0,0],
   [3,4,0,5,0,0,7,0,0],
   [0,0,5,0,3,5,6,0,0],
   [0,0,0,3,0,1,0,0,0],
   [0,0,0,5,1,0,0,0,0],
   [0,0,7,6,0,0,0,1,1],
   [0,0,0,0,0,0,1,0,1],
   [0,0,0,0,0,0,1,1,0]]
V = len(G)
selected=[0 for i in range(V)]
no_edge=0
selected[0]=True
print("edge  :  weight")
while no_edge<V-1:
    min=inf
    x,y=0,0
    for i in range(V):
        if selected[i]:
            for j in range(V):
                if not selected[j] and G[i][j]:
                    if min>G[i][j]:
                        min=G[i][j]
                        x,y=i,j
    print(f"{x+1} - {y+1} : {G[x][y]}")
    selected[y]=True
    no_edge+=1
