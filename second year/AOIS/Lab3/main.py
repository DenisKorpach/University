import numpy as np

class HopfieldNetwork:
    def __init__(self, Y):
        self.I_matrix = np.eye(Y.shape[1])
        self.weight = np.dot((2 * Y - 1).T, (2 * Y - 1)) - self.I_matrix
    
    def next(self, Y, weight):
        return np.where(np.dot(Y, weight) <= 0, 0, 1)
    
    def synchronous(self, Y):
        temp = Y.copy()  # Создаем копию Y
        for _ in range(20):  
            Y = self.next(temp, self.weight)
            if np.all(Y == self.next(Y, self.weight)):
                return Y
            if np.all(temp == self.next(Y, self.weight)):
                return None  # Возвращаем None, если условие не выполнилось
            temp = Y
        return None  # Возвращаем None, если количество итераций достигло 20

    def asynchronous(self, Y):
        temp = Y.copy()  # Создаем копию Y
        for _ in range(20):  
            indices = np.arange(Y.shape[1])  
            np.random.shuffle(indices)
            for i in indices:
                Y[0, i] = self.next(Y, self.weight[:, i])
            if np.all(Y == temp):
                return Y
            temp = Y
        return None  # Возвращаем None, если количество итераций достигло 20

Y1 = [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0]
Y2 = [1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0]
Y3 = [0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1]
Y4 = [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0]

My_work = HopfieldNetwork(Y=np.array([Y1, Y2, Y3, Y4]))

noise_Y = [1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0]

sync = My_work.synchronous(np.array([noise_Y]))
print(sync)

a_sync = My_work.asynchronous(np.array([noise_Y]))
print(a_sync)
