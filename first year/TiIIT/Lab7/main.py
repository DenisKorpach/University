import pandas 
import random as rnd
def Yhome(w1,w2,w3,x1,x2,x3):  
    return w1*x1+w2*x2+w3*x3
def SE(y,value):
    return ((y-value)**2)
fileY="y.csv"
y=pandas.read_csv(fileY,names=['y'])
fileX="x.csv"
x=pandas.read_csv(fileX,sep=' ', names=["x1","x2","x3"])


size=int(input())# size of iteration our algorithm
w0=rnd.uniform(0,5)
w1=rnd.uniform(0,5)
w2=rnd.uniform(0,5)
w3=rnd.uniform(0,5)
y1=0
alfa=int(input("input step: "))
for i in range(100):
    MSE,MSE2,y1=0,0,0
    w00=w0+alfa*rnd.uniform(-1,1)
    w11=w1+alfa*rnd.uniform(-1,1)
    w22=w2+alfa*rnd.uniform(-1,1)
    w33=w3+alfa*rnd.uniform(-1,1)

    for i in range(size):
        y1+=Yhome(w1,w2,w3,x["x1"][i],x["x2"][i],x["x3"][i])
        if i==size-1:
            y1+=w0
    for i in range(size):
        MSE+=SE(y["y"][i],y1)
        if i==size-1:
            MSE/=size

    y1=0
    for i in range(size):
        y1+=Yhome(w11,w22,w33,x["x1"][i],x["x2"][i],x["x3"][i])
        if i==size-1:
            y1+=w00
    for i in range(size):
        MSE2+=SE(y["y"][i],y1)
        if i==size-1:
            MSE2/=size
    if(MSE2<MSE):
        w0=w00
        w1=w11
        w2=w22
        w3=w33
        print(MSE2)
    if(alfa<0.000001):break
    alfa*=0.8756


