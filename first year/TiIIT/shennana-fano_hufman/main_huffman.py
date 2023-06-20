import heapq
from collections import Counter
from collections import namedtuple

class node(namedtuple("node",["left","right"])):
    def walk(self,code,acc):

        self.left.walk(code,acc + "0")
        self.right.walk(code,acc + "1")

class leaf(namedtuple("Leaf",["char"])):
    def walk(self,code,acc):

        code[self.char]=acc or "0"
    

def huffman(s):
    h=[]
    for ch,freq in Counter(s).items():
        h.append((freq,len(h),leaf(ch)))
    heapq.heapify(h)
    count = len(h)

    while len(h)>1:
        freq1,_count1,left=heapq.heappop(h)
        freq2,_count2,right=heapq.heappop(h)

        heapq.heappush(h,(freq1+freq2,count,node(left,right)))

        count+=1

    code={}
    if h:
        [(_freq,_count,root)]=h
        root.walk(code,"")
    return code

def main():
    s='''значительная корреляция между двумя случайными величинами всегда 
является свидетельством существования некоторой статистической связи данной выборке, 
но эта связь не обязательно должна наблюдаться для другой выборки и иметь 
причинно-следственный характер. часто заманчивая простота корреляционного 
исследования подталкивает следователя делать ложные, интуитивные выводы о 
наличии причинно-следственной связи между парами признаков.'''
    s=s.replace("\n","")
    code=huffman(s)
    encoded="".join(code[ch] for ch in s)
    print(len(code)<len(encoded))
    for ch in sorted(code):
        print("{} : {}".format(ch,code[ch]))
    print(encoded)

if __name__=="__main__":
    main()