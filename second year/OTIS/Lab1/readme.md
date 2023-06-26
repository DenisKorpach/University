Министерство образования Республики Беларусь\
Учреждение образования\
«Брестский государственный технический университет»\
Кафедра ИИТ

Лабораторная работа №1\
За третий семестр\
По дисциплине: «Общая теория интеллектуальных систем»\
Тема: «Modeling controlled object»

Выполнил:\
Студент 1 курса\
Группы ИИ-21(II)\
Корпач Д.Р.

Проверил:\
Иванюк Д.С.

Брест 2022

**Общее задание**

1.  Написать отчет по выполненной лабораторной работе №1 в .md формате
    (readme.md) и с помощью запроса на внесение изменений (**pull
    request**) разместить его в следующем
    каталоге: **trunk\\ii0xxyy\\task_01\\doc** (где **xx** - номер
    группы, **yy** - номер студента, например **ii02102**).

2.  Исходный код написанной программы разместить в
    каталоге: **trunk\\ii0xxyy\\task_01\\src**.

**Task 1. Modeling controlled object**

Let\'s get some object to be controlled. We want to control its
temperature, which can be described by this differential equation:

��(�)��=�(�)�+�0−�(�)��(1)

where � -- time; �(�) -- input temperature; �(�) -- input warm; �0 --
room temperature; �,�� -- some constants.

After transformation we get these linear (2) and nonlinear (3) models:

��+1=���+���(2)��+1=���−���−12+���+�sin⁡(��−1)(3)

where � -- time discrete moments (1,2,3...�); �,�,�,� -- some constants.

Task is to write program (**Julia**), which simulates this object
temperature.

**Код программы**

**using Plots**

**function lin_model(a,b,u,y,t)**

**x=1:t**

**arr_y=\[\]**

**for i in 1:t**

**push!(arr_y,y)**

**println(y)**

**y = a\*y + b\*u**

**end**

**plot(x,arr_y,label=\"liner_model\")**

**end**

**function not_liner_model(a,b,c,d,y,u,t)**

**x=1:t**

**arr_y1=\[\]**

**println(\"not_liner_model\")**

**for i in 1:t**

**println(y)**

**y=a\*y - b\*y\^2 + c\*u + d\*sin(u)**

**push!(arr_y1,y)**

**end**

**plot!(x,arr_y1,label=\"not_liner_model\")**

**end**

**a=0.5**

**b=0.6**

**c=0.7**

**d=0.8**

**t=20**

**y=0.0**

**u=1.0**

**lin_model(a,b,u,y,t)**

**not_liner_model(a,b,c,d,y,u,t)**

![image](./image1.png){width="1.4305555555555556in"
height="7.2555555555555555in"}

![image](./image2.png){width="6.151388888888889in"
height="4.115972222222222in"}
