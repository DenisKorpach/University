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


![image](https://github.com/DenisKorpach/University/assets/102619109/4b73e4b6-f5fb-40ba-814e-08679b80dbd2)


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

![image](https://github.com/DenisKorpach/University/assets/102619109/41924640-dc26-4dfc-920b-9cc91967eb65)<br>

![image](https://github.com/DenisKorpach/University/assets/102619109/33341ca5-b324-4e9f-81df-cb9b57f9eb85)

