import random
high,mid,low,stud=2,15,5,3
i,k=1,0
procent=days=0
high_level,mid_level,low_level,student=[],[],[],[]
while k<100:
    if procent>=100:
        print(f"{k}))((")
        print(f"сколько дней выполняется задача: {i}")
        print(f"среднее количество работы: {procent/i} %")
        print(f"роценты: {procent} )) ")
        days+=i
        k+=1
        procent,i=0,1
    for i in range(high):
        rnd=random.uniform(0.2,0.5)
        high_level.append(rnd)
        rnd_hours=random.uniform(5.4,6.6)
        procent+=high_level[i]*rnd_hours

    for i in range(mid):
        rnd=random.uniform(0.1,0.3)
        mid_level.append(rnd)
        rnd_hours=random.uniform(4.5,5.5)
        procent+=mid_level[i]*rnd_hours

    for i in range(low):
        rnd=random.uniform(0.05,0.2)
        low_level.append(rnd)
        rnd_hours=random.uniform(3.6,4.4)
        procent+=low_level[i]*rnd_hours

    for i in range(stud):
        rnd=random.uniform(0.01,0.02)
        student.append(rnd)
        rnd_hours=random.uniform(1.8,2.2)
        procent+=student[i]*rnd_hours
    i+=1
print(f"среднее количество дней: {days/k}")