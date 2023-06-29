#include <iostream>
#include <chrono>
#include <vector>
#include <sstream>
#include <fstream>
#include "../combinatoric.hh"
using namespace std;

int main() {
    combinatoric algorithm;
    string fileName = "input9.txt";
    string line;
    int num1, num2;
    ifstream inputFile(fileName);
    if (inputFile.is_open()){
        getline(inputFile, line);
        // Разбиение строки на числа с помощью потоков
        stringstream ss(line);
        char comma;
        ss >> num1 >> comma >> num2;

        // Вывод на экран и закрытие файла
        cout << "Числа из файла " << fileName << ": " << num1 << " и " << num2 << endl;
        inputFile.close();
    }else{
        cout << "Ошибка открытия файла " << fileName << endl;
    }



    vector<pair<int,double>> time;
    for(int j = 2;j <= num1;j++){
        
        auto t1 = chrono::high_resolution_clock::now();//начало отсчёта времени

        int arr[j];
        for(int i = 1; i <=j;i++){
            arr[i-1] = i;
        }
        algorithm.generate_permutations(arr,j);
        auto t2 = chrono::high_resolution_clock::now();//конец отсчёта времени
        auto duration1 = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();//вычисление времени выполнения
        cout << "Время выполнения: " << (double)duration1/1000000 << " секунд" << endl;
        time.push_back({j,(double)duration1/1000000});
    }
    for(int i=0;i<num1-1;i++){
        cout<<"количество элементов: "<<time[i].first<<"  время работы программы: "<<time[i].second<<endl;;
    }



    cout << endl;
    vector<pair<int,double>> time2;
    for(int j = 4;j<=num2;j++){
        auto T1 = chrono::high_resolution_clock::now();//начало отсчёта времени
        int  m = 2;
        vector<vector<int>> perms = algorithm.generate_permutations_from_N_to_M(j, m);
        cout << "перестановки: " << endl;
        for (auto perm : perms) {
            for (auto elem : perm) {
                cout << elem+1 << " ";
            }cout << endl;
        }
        auto T2 = chrono::high_resolution_clock::now();//конец отсчёта времени
        auto duration2 = chrono::duration_cast<chrono::microseconds>(T2 - T1).count();//вычисление времени выполнения
        cout << "Время выполнения: " << (double)duration2/1000000 << " секунд" << endl;
        time2.push_back({j,(double)duration2/1000000});
    }
    for(int i=0;i<num2-3;i++){
        cout<<"количество элементов: "<<time2[i].first<<" время работы программы: "<<time2[i].second<<endl;
    }
    
    return 0;
}