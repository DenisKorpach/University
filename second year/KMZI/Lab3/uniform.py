import numpy as np
from scipy.stats import chi2

# задаем последовательность
string_sequence = "2 9 3 5 1 6 6 6 3 4 6 0 0 3 7"
sequence = [int(x) for x in string_sequence.split()]

# вычисляем количество интервалов
k = int(np.ceil(1 + np.log2(len(sequence))))
alpha = 0.05

# вычисляем ожидаемое количество элементов в каждом интервале
n = len(sequence) / k

# вычисляем наблюдаемое количество элементов в каждом интервале
observed_counts, _ = np.histogram(sequence, bins=k)

# вычисляем статистику хи-квадрат
expected_counts = np.full(k, n)
chi_squared_statistic = np.sum((observed_counts - expected_counts) ** 2 / expected_counts)

# вычисляем критическое значение хи-квадрат с (k-1) степенями свободы на уровне значимости alpha
critical_value = chi2.ppf(1 - alpha, k - 1)

print(f"critical_value: {critical_value} \n chi_squared_statistic: {chi_squared_statistic}")
# выводим результаты теста
if chi_squared_statistic > critical_value:
    print("последовательность не имеет равномерного распределения.")
else:
    print("последовательность имеет равномерное распределение.")
