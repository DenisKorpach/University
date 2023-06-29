#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "../Mg_Square.hh"
using namespace std;

int main() {
    Square algorithm;

    string file1="input.txt",data = "";
    ifstream file(file1);

    if (!file.is_open()) {//считываение данных из файла
        cout << "Ошибка открытия файла " << file1<< endl;
        return 1;
    }else{
        string line;
        while (getline(file, line)) {
            data += line;
        }
        cout << "Содержимое файла " << file1 << ":\n" << data << endl;
    }
    file.close();

    string encryption = algorithm.encryption_txt(data);
    vector<int> compressed = algorithm.LZW_compress(encryption);//сжатие данных

    cout << "Compressed: ";
    for (int code : compressed) {//вывод сжатых данных
        cout << code << " ";
    }cout << endl;


    ofstream outfile("output.txt"); // открываем файл для записи
    if (outfile.is_open()) {
        for (int i = 0; i < compressed.size(); i++) {
            outfile << compressed[i] << "\n"; // записываем каждое значение вектора на отдельной строке
        }
        outfile.close(); // закрываем файл
    } else {
        std::cout << "не удалось открыть файл" << std::endl;
    }

    return 0;
}