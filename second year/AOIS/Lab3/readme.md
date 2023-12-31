__Цель:__ Изучить обучение и функционирование релаксационных ИНС в качестве ассоциативной памяти при решении задач распознавания образов.<br>
1.	Написать на любом ЯВУ программу моделирования ИНС для распознавания векторов согласно варианту. ИНС содержит n нейронных элементов в первом слое и m во втором слое. Если n меньше размерности вектора, тогда из вектора использовать только первые n элементов.<br>
2.	Провести исследование полученной модели. При этом на вход сети необходимо подавать искаженные образы, в которых инвертированы некоторые биты. Критерий эффективности процесса распознавания - максимальное кодовое расстояние (количество искаженных битов) между исходным и поданным образом.<br>
**Модель ИНС** : сеть Хопфилда.<br>
**Изначальные вектора:** <br>                                           
![image](https://github.com/DenisKorpach/University/assets/102619109/359f2781-30a7-43e9-89dc-0ac5c87686ca)<br>
**зашумлённый образ(входные данные):** <br>
![image](https://github.com/DenisKorpach/University/assets/102619109/ad13f5f1-1967-48ee-bdf8-87fdfc40d294)<br>
**Выходные данные по синхронному и асинхронному методу соответственно:** <br>
![image](https://github.com/DenisKorpach/University/assets/102619109/fd8a9d0a-4b68-4fee-a37b-5f392ab20e9b)<br>


