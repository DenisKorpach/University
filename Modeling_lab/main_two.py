import random as rnd
import math as mh

def Func_P(x):#функция экспоненцияльного распределения для студента 
    return 1/20*mh.exp(-x/2+3)  #где 9 часов утра 100% шанс сдать работу, а в 15:20 стремится к 0%

def Normal_K(x):#нормальное распределения для препода с максимальной вероятностью(лояльностью) 80%
    return (2/(mh.sqrt(2*mh.pi)))*mh.exp((-1/2)*((x-1.5))**2)  


def main():
    for i in range(381):#вывод производительности студента и препода в определённое время и их среднее
        exp_value=Func_P(i/60)*100
        normal_value=Normal_K(i/60)*100
        print(f'hour:{(i//60) + 9}:{i%60} , студент:{round(exp_value,4)}%  , препод: {round(normal_value,4)}%, среднее{round((normal_value+exp_value)/2,4)}%')
    
    mid_value_days={}
    for i in range(381):
        mid_value_days[i]=list()
    
    hours=0
    labs,pass_labs=7,0
    hours2=hours
    days=0
    count=100

    for j in range(count):# 100 прогонов модели для поиска лучшего времени 
        for i in range(380):# 380 - минут , в часах - 6ч 20мин
            hours=i/60
            hours2=hours #дополнительное время 
            pass_labs=0
            days=0
            while pass_labs<=labs:

                time_pass=rnd.uniform(0.25,0.5)#добавляемое время если сдал лабу

                mid_procent=(Func_P(hours)+Normal_K(hours))/2#среднее значение процентов

                rand_procent=rnd.uniform(0.000001,1)

                if mid_procent > rand_procent:#если сдал лабу
                    hours+=time_pass
                    pass_labs+=1
            
    
                if mid_procent < rand_procent:#если не сдал лабу
                    hours=hours2
                    days+=1
            mid_value_days[i].append(days)#словарь содержащий списки каждого времени и дней за сколько сдал лабу

            #вывод для проверки сколько сдаётся лаб в определённое время прихода человека
            #print(f"если человек будет приходить в {(i//60) + 9}:{i%60} то сдаст лабы за {days} дней\n")
    print()
    for i in range(380):
        if sum(mid_value_days[i])/count <=10:#если лабы  сданы в среднем до 10 дней 
            print(f' лучшее время для посещения универа {i//60 + 9}:{i%60}')
main()       




