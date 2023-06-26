import pandas 
import random as rnd 
def change_data(student_mat):#замена данных в таблице
    student_mat.loc[student_mat['school'] == "GP" , 'school'] = 0
    student_mat.loc[student_mat['school'] == "MS", 'school'] = 1

    student_mat.loc[student_mat['sex'] == "F", 'sex'] = 0
    student_mat.loc[student_mat['sex'] == "M", 'sex'] = 1

    student_mat.loc[student_mat['address'] == "U", 'address'] = 0
    student_mat.loc[student_mat['address'] == "R", 'address'] = 1

    student_mat.loc[student_mat['Pstatus'] == "T", 'Pstatus'] = 0
    student_mat.loc[student_mat['Pstatus'] == "A", 'Pstatus'] = 1
    
    student_mat.loc[student_mat['famsize'] == "LE3", 'famsize'] = 0
    student_mat.loc[student_mat['famsize'] == "GT3", 'famsize'] = 1

    student_mat.loc[student_mat['Mjob'] == "teacher", 'Mjob'] = 0
    student_mat.loc[student_mat['Mjob'] == "health", 'Mjob'] = 1
    student_mat.loc[student_mat['Mjob'] == "services", 'Mjob'] = 2
    student_mat.loc[student_mat['Mjob'] == "at_home", 'Mjob'] = 3
    student_mat.loc[student_mat['Mjob'] == "other", 'Mjob'] = 4

    student_mat.loc[student_mat['Fjob'] == "teacher", 'Fjob'] = 0
    student_mat.loc[student_mat['Fjob'] == "health", 'Fjob'] = 1
    student_mat.loc[student_mat['Fjob'] == "services", 'Fjob'] = 2
    student_mat.loc[student_mat['Fjob'] == "at_home", 'Fjob'] = 3
    student_mat.loc[student_mat['Fjob'] == "other", 'Fjob'] = 4

    student_mat.loc[student_mat['reason'] == "home", 'reason'] = 0
    student_mat.loc[student_mat['reason'] == "reputation", 'reason'] = 1
    student_mat.loc[student_mat['reason'] == "course", 'reason'] = 2
    student_mat.loc[student_mat['reason'] == "other", 'reason'] = 3

    student_mat.loc[student_mat['guardian'] == "mother", 'guardian'] = 0
    student_mat.loc[student_mat['guardian'] == "father", 'guardian'] = 1
    student_mat.loc[student_mat['guardian'] == "other", 'guardian'] = 2

def Yhome(size_colums,W,array_line):  #рассчет Y^
    temp_value=W[0]
    for i in range(1,size_colums):
        temp_value+=array_line[i-1]*W[i]
    return temp_value

def SE(student_mat,value):#расчёт ошибки 
    return (student_mat-value)**2

if __name__=="__main__":
    
    file_student="student-mat.csv"
    student_mat=pandas.read_csv(file_student)
    change_data(student_mat)
   
    rnd_W=[rnd.uniform(0,0.4) for i in range(33)]#список состоящий из рандомных параметров W
    rnd_addit_W=[0 for i in range(len(rnd_W))]#список дополнительных параметров W

    size_COLUMS=student_mat.shape[1]#количество столбцов
    size_lines=student_mat.shape[0]#количество строк

    alfa=int(input("введите шаг: "))
    number_iterations=int(input(f"сколько строк будем считать(до {size_lines}): "))
    
    for j in range(10500):
        MSE,MSE2=0,0

        for i in range(len(rnd_W)):
            rnd_addit_W[i] = rnd_W[i] + alfa * rnd.uniform(-1, 1)

        for iline in range(number_iterations):#расчёт Y^ до определённой строки
            y1=Yhome(size_COLUMS,rnd_W,student_mat.iloc[iline])
            MSE+=SE(student_mat["G3"][iline],y1)
            if iline==number_iterations-1:
                MSE/=iline
    
        for iline in range(number_iterations):##расчёт Y^ до определённой строки с новыми рандомными W
            y1=Yhome(size_COLUMS,rnd_addit_W,student_mat.iloc[iline])
            MSE2+=SE(student_mat["G3"][iline],y1)
            if iline==number_iterations-1:
                MSE2/=iline

        if(MSE2<MSE):
            for i in range(size_COLUMS):#замена значений W и W дополнительных
                rnd_W[i]=rnd_addit_W[i]
            print(MSE2)
        if(alfa<0.000001):
            break
        alfa*=0.8756

    print("рассчёт 'неизвестных' G3\n")
    sum1=0
    for i in range(number_iterations,size_lines):#рассчёт неизвестных нам оценок G3
        y1=Yhome(size_COLUMS,rnd_W,student_mat.iloc[i])
        print(f"{i})")
        print(f"новые значени G3: {y1}, табличные значения: {student_mat.loc[i,'G3']}")
        sum1+=y1
        print()
    sum2 =0 
    for i in range(number_iterations,size_lines):
        sum2+=student_mat['G3'][i]
    
    print(f'наша средняя оценка {sum1/(size_lines-number_iterations)}, табличная средняя оценка{sum2/(size_lines-number_iterations)}')
    



