﻿Решение задачи аппроксимации методом случайного поиска.

**Задание:**

1) Вспомнить алгоритмы генерации случайных чисел. Использование случайных чисел для решения задач оптимизации.
1) [Вариант](C:\Users\Denis\AppData\Local\Temp\Temp1_lab5-7.zip\lab7\Лабораторная работа #7.docx#oxbpb8m99tne) в соответствии с номером в журнале. 
1) Данные записаны в файлы в csv-формате. Необходимо загрузить их в программу.
1) Реализовать линейную модель для аппроксимации процесса. 

Модель линейной регрессии имеет следующий вид:

`	`y=w0+i=1nwixi,

`	`где	y - выходное значение модели,

`		`xi - входные значения,

wi - параметры модели, которые нам необходимо настроить, 

n - размерность входных значений.

1) Настроить параметры модели методом случайного поиска (см. лекции). Для оценки качества модели можно использовать среднюю квадратичную ошибку:

MSE=1mi=1my-y2

1) В процессе обучения выводить информацию об ошибке. И в результате вывести ответ: Как выглядит ваша модель со всем набором её параметров.
1) Предложить другую модель (использовать тригонометрические функции и пр.), выбрать параметры для нее. Сравнить ошибку с линейной моделью. 

