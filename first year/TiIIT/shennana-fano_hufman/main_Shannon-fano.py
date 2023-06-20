import math
class  node :
    def __init__(self) -> None:
        # для хранения символа
        self.sym=''
        #для хранения вероятности или частоты
        self.pro=0.0
        self.arr=[0]*33
        self.top=0
p=[node() for _ in range(33)]
 
# функция поиска кода шеннона
def shannon(l, h, p):
    pack1 = 0; pack2 = 0; diff1 = 0; diff2 = 0
    if ((l + 1) == h or l == h or l > h) :
        if (l == h or l > h):
            return
        p[h].top+=1
        p[h].arr[(p[h].top)] = 0
        p[l].top+=1
        p[l].arr[(p[l].top)] = 1
         
        return
     
    else :
        for i in range(l,h):
            pack1 = pack1 + p[i].pro
        pack2 = pack2 + p[h].pro
        diff1 = pack1 - pack2
        if (diff1 < 0):
            diff1 = diff1 * -1
        j = 2
        while (j != h - l + 1) :
            k = h - j
            pack1 = pack2 = 0
            for i in range(l, k+1):
                pack1 = pack1 + p[i].pro
            for i in range(h,k,-1):
                pack2 = pack2 + p[i].pro
            diff2 = pack1 - pack2
            if (diff2 < 0):
                diff2 = diff2 * -1
            if (diff2 >= diff1):
                break
            diff1 = diff2
            j+=1
         
        k+=1
        for i in range(l,k+1):
            p[i].top+=1
            p[i].arr[(p[i].top)] = 1
             
        for i in range(k + 1,h+1):
            p[i].top+=1
            p[i].arr[(p[i].top)] = 0
             
 
        shannon(l, k, p)
        shannon(k + 1, h, p)
     
 
 
# функция сортировки символов
# на основе их вероятности или частоты
def sortByProbability(n, p):
    temp=node()
    for j in range(1,n) :
        for i in range(n - 1) :
            if ((p[i].pro) > (p[i + 1].pro)) :
                temp.pro = p[i].pro
                temp.sym = p[i].sym
 
                p[i].pro = p[i + 1].pro
                p[i].sym = p[i + 1].sym
 
                p[i + 1].pro = temp.pro
                p[i + 1].sym = temp.sym
             
         
# функция для отображения кодов Шеннона
def display(n, p):
    print("\n\nSymbol\tProbability\tCode",end='')
    for i in range(n - 1,-1,-1):
        print("\n", p[i].sym, "\t", p[i].pro,"\t\t",end='')
        for j in range(p[i].top+1):
            print(p[i].arr[j],end='')
     
if __name__ == '__main__':
    total = 0
    print(" number of symbols\t: ",end='')
    strr='''значительная корреляция между двумя случайными величинами всегда 
является свидетельством существования некоторой статистической связи данной выборке, 
но эта связь не обязательно должна наблюдаться для другой выборки и иметь 
причинно-следственный характер. часто заманчивая простота корреляционного 
исследования подталкивает следователя делать ложные, интуитивные выводы о 
наличии причинно-следственной связи между парами признаков.'''
    n = len(strr)
    print(n)
    temp='абвгдеёжзиклмнопрстуфхцчшщъыьэюя.,- '
    
    k,x=0,[]
    Hx=0 
    for letter in temp:
        if strr.count(letter)!=0:
            print("Enter symbol", k+1," : ",end="")
            print(letter)
            Pi=strr.count(letter)/(n)
            x.append(Pi)
            Hx+=-Pi*math.log2(Pi)
        # вставляем символ в узел
            p[k].sym += letter
            k+=1
     
    print("\nentropia: ",Hx)# энтропия
    
    i=0
    for i in range(len(x)):
        print("Enter probability of", p[i].sym, ": ",end="")
        print(x[i])
 
        #вставляем символ в узел
        p[i].pro = x[i]
        total = total + p[i].pro
 
        #проверка максимальной вероятности
        if (total > 1) :
            print("Invalid. Enter new values")
            total = total - p[i].pro
            i-=1
     
         
    i+=1
    p[i].pro = 1 - total
    # функция сортировки символов
    # на основе их вероятности или частоты
    sortByProbability(len(x), p)
 
    for k in range(len(x)):
        p[i].top = -1
 
    # поиск кода шеннона длля символов
    shannon(0, len(x) - 1, p)
 
    # отображение кодов
    display(len(x), p)
