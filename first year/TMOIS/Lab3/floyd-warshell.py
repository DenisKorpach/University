from math import inf
maxV,V=1000,7
def FU(D):
    for i in range(V):
        D[i][i]=0
    for k in range(V):
        for i in range(V):
            for j in range(V):
                D[i][j] = min(D[i][j], D[i][k] + D[k][j])
    for i in range(V):
        for j in range(V):
            print(D[i][j],end="\t")
        print()
GR=[[0,3,7,4,inf,inf,inf],
    [3,0,5,2,inf,inf,10],
    [7,5,0,inf,inf,4,inf],
    [4,2,inf,0,4,inf,inf],
    [inf,inf,inf,4,0,5,6,],
    [inf,inf,4,inf,5,0,7],
    [inf,10,inf,inf,6,7,0]]   
FU(GR)
print("yash")