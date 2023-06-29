#include <iostream>
#include <vector>
#include <chrono>
#include "../combinatoric.hh"
using namespace std;

int main() {
    combinatoric algorithm;
    auto t1 = chrono::high_resolution_clock::now();


    vector<int> permutation = algorithm.reading_file("input.txt");//подстановка
    for(int i =0;i<permutation.size();i++){
        cout<<permutation[i]<<endl;
    }
    vector<vector<int>> cycles = algorithm.get_cycles(permutation);
    cout<<"произведение независимых циклов: ";
    for (vector<int> cycle : cycles) {//вывод циклов
        cout << "(";
        for (int i = 0; i < cycle.size(); i++) {
            cout << cycle[i] + 1;
            if (i != cycle.size() - 1) {
                cout << " ";
            }
        }
        cout << ")";
    }cout << endl<<endl;
    
  
    cout<<"степень подстановки: "<<algorithm.order(cycles)<<endl;//подсчёт и вывод степени подстановки

    algorithm.inversions(permutation);//определение чётности подстановок через число инверсий

    vector<int> transpositions = algorithm.permutationToTranspositions(permutation);//разложение перестановки на произведение транспозиций
    cout<<"разложение подстановки на произведение транспозиций"<<endl;
    for (int i = 0; i < transpositions.size(); i += 2) {//вывод транспозиций 
        cout << "(" << transpositions[i] + 1 << " " << transpositions[i + 1] + 1 << ") ";
    }
    if(transpositions.size() / 2 % 2 == 0) cout<<"транспозиций = "<<transpositions.size() / 2 << " подстановка чётная"<<endl;
    else cout<<"транспозиций = "<<transpositions.size() / 2 << "подстановка чётная"<<endl;
    cout << endl;

    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << "Время выполнения: " << duration << " микросекунд" << endl;    
    return 0;
}