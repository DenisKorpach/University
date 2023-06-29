#include <iostream>
#include "../combinatoric.hh"
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>
using namespace std;


int main() {
    combinatoric algorithm;
    std::ifstream infile("input.txt"); // открыть файл для чтения
    std::string line;
    std::string all_lines;

    // Считываем данные построчно и добавляем их в строку
    while (std::getline(infile, line)) {
        // добавляем перенос строки, чтобы строки не склеивались
        line += '\n';
        // добавляем прочитанную строку в итоговую строку
        all_lines += line;
    }

    infile.close(); // закрыть файл

    std::regex digits_regex("\\d+"); // регулярное выражение для поиска цифр
    std::vector<int> numbers; // вектор для хранения найденных чисел

    // Итерируемся по итераторам начала и конца искомых последовательностей в строке
    for (auto it = std::sregex_iterator(all_lines.begin(), all_lines.end(), digits_regex);
         it != std::sregex_iterator();
         ++it) {
        std::string match_str = it->str();
        int number = std::stoi(match_str); // преобразуем найденную подстроку в число
        numbers.push_back(number); // добавляем число в вектор
    }
    
    int n,m;
    n = numbers[0];//колтичесвто строк
    m = numbers[1];//количество столбцов
   
    pair<int, int> start = make_pair(numbers[numbers.size()-4], numbers[numbers.size()-3]);//считываем стартовые точки
    pair<int, int> end = make_pair(numbers[numbers.size()-2], numbers[numbers.size()-1]);//считываем конечные точки

    vector<pair<int, int >> coords_barriers;//считываение координаты барьеров
    for(int i = 2;i<numbers.size()-4;i+=2){
        coords_barriers.push_back({numbers[i],numbers[i+1]});
    }
 
    vector<vector<int>> maze(n,vector<int>(m)); //наше поле
    for(int i = 0;i < n ;i++){
        for(int j = 0; j < m; j++){
            maze[i][j] = 0;
        }
    }
    
    for(auto bar: coords_barriers){//заполнение поля барьерами
        maze[bar.first][bar.second] = 1;

    }
    cout<<"наше поле с препятствиями"<<endl;
    for(int i = 0;i < n ;i++){
        for(int j = 0; j < m; j++){
            cout<<maze[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl<<"пройденный путь: "<<endl;
    auto t1 = chrono::high_resolution_clock::now();//начало отсчёта времени
    vector<pair<int, int>> path = algorithm.find_shortest_path(maze, start, end);
    for (auto point : path) {
        cout << "(" << point.first << ", " << point.second << ") ";
    }
    cout << endl;
    
    auto t2 = chrono::high_resolution_clock::now();//конец отсчёта времени
    auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();//вычисление времени выполнения
    cout << "Время выполнения: " << duration << " микросекунд" << endl; 
    return 0;
}
