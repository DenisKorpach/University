#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
std::string read_file(std::string path);
void out_file(std::string path,std::string data);
std::string read_out_file(std::string path);
std::vector<std::string> generate_vigenere_table();
std::string vigenere_encrypt(std::string plaintext, std::string key);
std::string vigenere_decrypt(std::string ciphertext, std::string key);
char fo(char subblock, std::string key, int round);
std::string DeCode(std::string mes, std::string key, int n);
std::string Code(std::string mes, std::string key, int n);

int main() {
    int round = 4;
    std::string plaintext = read_file("input.txt");
    std::string key = "bananas";
    std::string ciphertext = vigenere_encrypt(Code(plaintext, key,round),key);
    std::cout << "Зашифрованное сообщение: " << ciphertext << std::endl << std::endl;
    out_file("output.txt",ciphertext);
    
    return 0;
}
std::string read_file(std::string path){
    std::string data = "";
    std::ifstream file(path);

    if (!file.is_open()) {//считываение данных из файла
        std::cout << "Ошибка открытия файла " << path<< std::endl;
    }else{
        std::string line;
        while (getline(file, line)) {
            data += line;
        }
        std::cout << "Содержимое файла " << path <<" : "<< data << std::endl;
    }
    file.close();
    return data;
}

void out_file(std::string path,std::string data){
    std::ofstream outfile("output.txt"); // открываем файл для записи
    if (outfile.is_open()) {
        for (int i = 0; i < data.size(); i++) {
            outfile << data[i] << "\n"; // записываем каждое значение вектора на отдельной строке
        }
        outfile.close(); // закрываем файл
    } else {
        std::cout << "не удалось открыть файл" << std::endl;
    }
}

std::string vigenere_encrypt(std::string plaintext, std::string key) {
    /* Функция шифрует сообщение plaintext ключом key методом Виженера */
    std::vector<std::string> vigenere_table = generate_vigenere_table();
    std::string ciphertext = "";
    int key_index = 0;
    for (char& ch : plaintext) {
        if (isalpha(ch)) {
            std::string row = vigenere_table[toupper(key[key_index]) - 'A'];
            ciphertext += row[toupper(ch) - 'A'];
            key_index = (key_index + 1) % key.length();
        }
        else {
            ciphertext += ch;
        }
    }
    return ciphertext;
}

std::vector<std::string> generate_vigenere_table() {
    /* Функция создает таблицу Виженера */
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::vector<std::string> vigenere_table;
    for (int i = 0; i < alphabet.length(); i++) {
        std::string row = alphabet.substr(i) + alphabet.substr(0, i);
        vigenere_table.push_back(row);
    }
    return vigenere_table;
}

char fo(char subblock, std::string key, int round){
    //std::cout<<"subblock: "<<subblock<<" key[round]: "<<key[round]<<" "<<" static_cast<char>(pow(2, round)+1): "<<static_cast<char>(pow(2, round)+1)<<std::endl;
    return (subblock * key[round]) % static_cast<char>(pow(2, round)+1); // Образующая функция
}
std::string Code(std::string mes, std::string key, int n){
    char temp = '0', l = '0', r = '0';
    for (int desc = 0; desc < mes.size(); desc += 2) // рассматриваем блоки по 2 символа (1 символ = 8 бит)
    {
        l = mes[desc];
        r = mes[desc + 1];
        for (int i = 0; i < n; ++i) // n раундов
        {
            temp = r ^ fo(l, key, i);
            r = l;
            l = temp;
        }
        mes[desc] = l;
        mes[desc + 1] = r;
    }
    return mes;
}