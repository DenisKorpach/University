import numpy as np
from matplotlib import pyplot as plt
INS = lambda : 3
fun = lambda x : 3 * np.sin(6*x) + 0.1

class Widrow_Hof():
    def __init__(self,weight = np.random.rand(INS(),1)/4,threshold = 4, alfa = 0.1):
        self.threshold = threshold
        self.weight = weight
        self.alfa = alfa
    def prediction(self,input):
        return np.dot(input,self.weight) - self.threshold
    
    def train_data(self,inputs,targets):
        for index,row in enumerate(inputs):
            predict = self.prediction(row)
            for i,w in enumerate(self.weight):
                
                w[0] = w[0] - self.alfa * (predict - targets[index]) * row[i]
            self.threshold = self.threshold + self.alfa * (predict - targets[index])

if __name__ == "__main__":
    AI = Widrow_Hof()

    value_func = [fun(el) for el in np.arange(1, 4, 0.1)] # Заполнение массива реальных значений функции
    inputs1 = np.array([value_func[i-INS():i] for i in range(INS(), len(value_func))]) # Создание массива входных значений
    targets1 = value_func[INS():] # Создание массива целевых значений

    value_func2 = [fun(el) for el in np.arange(3.3, 4.8, 0.1)] # Заполнение массива реальных значений функции
    inputs2 = np.array([value_func2[i-INS():i] for i in range(INS(), len(value_func2))])
    targets2 = value_func2[INS():] # Создание массива целевых значений

    E = []; E_arr_plt = []
    Error = 1e-6
    iter = 0
    print()
    iter = 0
    while True:
        iter += 1
        AI.train_data(inputs1, targets1)
        e = []
        for input, target in zip(inputs2, targets2):
            e.append((AI.prediction(input) - target) ** 2)#среднеквадратичная ошибка
        E = 0.5 * np.sum(e)
        E_arr_plt.append(E)
        print(iter, E, )
        if E < Error:
            break


    result = []
    for input in inputs2:
        result.append(AI.prediction(input))


    x_30 = [i for i in np.arange(1, 4, 0.1)] # Разбиение на 30 точек
    x_15 = [i for i in np.arange(3.3,4.8, 0.1)]

    plt.plot(range(iter), E_arr_plt)
    plt.title('График изменения ошибки обучения')
    plt.xlabel('эпохи')
    plt.ylabel('Ошибка')
    plt.show()

    # График сравнения реальных значений функции и предсказанных моделью
    plt.plot(x_30, value_func, label='Реальные значения')
    plt.plot(x_15[INS():], result, '--',color = 'r', label='Предсказанные значения')
    plt.title('Сравнение реальных и предсказанных значений функции')
    plt.xlabel('Аргумент')
    plt.ylabel('Значение функции')
    plt.legend()
    plt.show()
    


