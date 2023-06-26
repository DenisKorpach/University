Данная программа моделирует процесс сдачи лабораторных работ студентами в университете начиная с 9:00 и заканчивая сдачу в 15:20. Она использует две функции распределения для моделирования вероятности сдачи работы студентом и лояльности (максимальной вероятности) преподавателя.<br>

Основная функция main() содержит следующие шаги:<br>

1)Вычисление производительности студента и преподавателя в определенное время с помощью функций Func_P(x) и Normal_K(x). Результаты выводятся в процентах.<br>

2)Создание словаря mid_value_days, где каждому времени отведена пустая список.<br>

3)Инициализация переменных для отслеживания времени, количества лабораторных работ, сданных лабораторных работ, дополнительного времени и дней.<br>

4)Внешний цикл выполняется 100 раз для поиска лучшего времени.<br>

5)Внутренний цикл проходит по каждой минуте в диапазоне от 0 до 380 (6 часов 20 минут).<br>

6)Внутри внутреннего цикла моделируется процесс сдачи лабораторных работ студентами. Время проходит от предыдущего значения до текущего значения, добавляя время, если лабораторная работа сдана, и сбрасывая время на начальное значение, если лабораторная работа не сдана.<br>

7)Запись числа дней, за которые сдана лабораторная работа, в соответствующий список в словаре mid_value_days.<br>

8)Вывод времени, при котором лабораторные работы сдаются в среднем за 10 дней или меньше.<br>

Данная программа позволяет исследовать, в какое время лучше посещать университет, чтобы сдавать лабораторные работы в сжатые сроки (10 дней или меньше).