from cmath import sqrt
import pandas as pd

names_columns=['id','sepal_len','sepal_wid','petal_len','petal_wid','names']
data=pd.read_csv("Iris.csv",names=names_columns)
data.drop('id', axis=1, inplace=True)#удаление ненужного столбца

data_test=pd.read_csv("Iris_test_data.csv",names=names_columns)
data_test.drop('id', axis=1, inplace=True)#удаление ненужного столбца

size_data=len(data)
min_max_colums={'sepal_len':[data['sepal_len'].min(),data['sepal_len'].max()],#словарь содержащий минимум 
                'sepal_wid':[data['sepal_wid'].min(),data['sepal_wid'].max()],# и максимум каждого столбца
                'petal_len':[data['petal_len'].min(),data['petal_len'].max()],
                'petal_wid':[data['petal_wid'].min(),data['petal_wid'].max()]
                }
for line in range(size_data):#нормализуем каждое значение в диапазоне[0;1]
    for cols in data.columns:#по формуле x=(x-min)/(max-min)
        if cols!='names':
            data.loc[line,cols]=(data.loc[line,cols]- min_max_colums[cols][0])/    \
                (min_max_colums[cols][1]- min_max_colums[cols][0])

#print(f' нормализованные данные \n{data}')

#print(data_test,"\n")
line_test=int(input("введите номер строки данные которого хотите проверить: "))
KNN=int(input("введите количество ближайших соседей: "))

for cols in data.columns:# нормализуем данные iris_test_data той строки  которую выбрали для 
    if cols!='names':#дальнейшего определения классификации цветка
        data_test.loc[line_test,cols]=(data_test[cols][line_test]- min_max_colums[cols][0])/    \
            (min_max_colums[cols][1]- min_max_colums[cols][0])
        

for lines in range(size_data):#вычисление растояний и занесение их в столбец  sepal_len
    temp=0                    
    for cols in data.columns:
        if cols!='names':
            temp+=(data_test.loc[line_test,cols]-data.loc[lines,cols])**2
    data.loc[lines,"sepal_len"]= sqrt(temp)

data = data.sort_values(by='sepal_len')#сортируем полученные расстояния в порядке возрастания

distance_cols=data["sepal_len"].tolist()#массив расстояний

name_cols=data["names"].tolist()#массив имён цветков относительно расстояний

value={'distance': distance_cols,'names':name_cols}
new_data=pd.DataFrame(value)
print(new_data)

name_setosa=0
name_versicolor=0
name_virginica=0
for i in range(KNN):#проверка классификации цветка по n-ближайшим соседям
    if new_data.loc[i,'names']=='Iris-versicolor':
        name_versicolor+=1
    if new_data.loc[i,'names']=='Iris-setosa':
        name_setosa+=1
    if new_data.loc[i,'names']=='Iris-virginica':
        name_virginica+=1
print(f'Iris-setosa: {name_setosa}, Iris-versicolor: {name_versicolor}, Iris-virginica: {name_virginica}')



