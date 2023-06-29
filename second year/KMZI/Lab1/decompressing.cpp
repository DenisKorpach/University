#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "../Mg_Square.hh"
using namespace std;
int main(){
	Square algorithm;

    ifstream input("output.txt"); // открываем файл для чтения
    string data = "";
    if (!input.is_open()) {
        cout << "Failed to open input file" << std::endl;
        return 1;
    }else{
        string line;
        while (getline(input, line)) { // считываем строки из файла
            data += line; // добавляем содержимое строки в конец строки str
            data += ' '; // добавляем пробел после каждой строки
        }
        cout<< data;
        input.close(); // закрываем файл
    }


    vector<int> compressed_read_data;
    stringstream ss(data);
    int num;
    while (ss >> num) {//парсим строку разделяя её по пробелам и заносим получившиеся числа в вектор
        compressed_read_data.push_back(num);
    }

    string txt = algorithm.LZW_decompressing(compressed_read_data);//разархивируем наши сжатые данные
    cout<<txt<<endl;

	string decryption = algorithm.decryption_txt(txt);

	double entropy = algorithm.entropy(decryption);
	cout<<"энтропия: "<< entropy <<endl;

    return 0;
}
