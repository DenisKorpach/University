﻿Лабораторная работа №4 

Тема: Подключение внешних модулей и применение параллельного подхода 

Задание. 

1\. Выделить в отдельный файл функции: расчёта функционала, пересчёта новой позиции точки (вспомогательные, если есть). 

2\. Реализовать их в виде подключаемых библиотек (создать заголовочный файл \*.h и пр. ) 

3\. Подключить вашу библиотеку к новому проекту( #include). 

4\. Создать в новом проекте популяцию из 1000 элементов (A[1000][3]). 

5\. Реализовать популяционный алгоритм поиска экстремума. Реализация должна использовать метод параллельных потоков. Распараллеливание алгоритма предлагается сделать в месте пересчёта новых значений точек (т.к. их количество 1000 и изменение каждой из них не зависит от других). 

Алгоритм поиска экстремума, используя популяцию: 

1\. Инициализировать: Популяцию, Массив, хранящий текущее значение функции для этой точки. Задать стартовое значение шага и параметр его затухания. 

2\. Для каждого элемента пытаемся передвинуть точку в новое положение, т.е. если значение функции будет улучшено происходит изменение положения точки, иначе возвращается предыдущее значение точки (вызов библиотечной функции // можно вспомнить: передача массива в/из функций). 

3\. После движения всех точек изменить шаг. 

4\. Проверка точки Останова, если выполняется, завершаем алгоритм, иначе переходим к п.2. Условие Останова: значение шаг стало меньше минимального. Решением задачи будет: точка из популяции, которой соответствует наименьшее значение функции.