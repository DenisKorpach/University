#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
std::string read_out_file(std::string path);
std::vector<std::string> generate_vigenere_table();
std::string vigenere_decrypt(std::string ciphertext, std::string key);
char fo(char subblock, std::string key, int round);
std::string DeCode(std::string mes, std::string key, int n);

int main() {
    int round = 4;
    std::string ciphertext = read_out_file("output.txt");
    std::string key = "bananas";

    std::string decrypted_text = DeCode(vigenere_decrypt(ciphertext,key),key,round);
    std::cout << "Расшифрованное сообщение: " << decrypted_text << std::endl;
    return 0;
}

std::string read_out_file(std::string path){
    std::ifstream input(path); // открываем файл для чтения
    std::string data = "";
    if (!input.is_open()) {
        std::cout << "не удалось открыть файл" << std::endl;
    }else{
        std::string line;
        while (getline(input, line)) { // считываем строки из файла
            data += line; // добавляем содержимое строки в конец строки str
            data += ' '; // добавляем пробел после каждой строки
        }
        input.close(); // закрываем файл
    }
    std::string parsed_str = "";
    for (int i = 0; i < data.length(); i++) {
        if (data[i] != ' ') {
            parsed_str += data[i];
        }
    }
    std::cout <<"содержимое файла "<<path<<" : "<<parsed_str<<std::endl;
    return  parsed_str;
}
std::string vigenere_decrypt(std::string ciphertext, std::string key) {
    /* Функция дешифрует сообщение ciphertext ключом key методом Виженера */
    std::vector<std::string> vigenere_table = generate_vigenere_table();
    std::string plaintext = "";
    int key_index = 0;
    for (char& ch : ciphertext) {
        if (isalpha(ch)) {
            std::string row = vigenere_table[toupper(key[key_index]) - 'A'];
            int col = row.find(toupper(ch));
            plaintext += col + 'A';
            key_index = (key_index + 1) % key.length();
        }
        else {
            plaintext += ch;
        }
    }
    return plaintext;
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
std::string DeCode(std::string mes, std::string key, int n){
    char temp = '0', l = '0', r = '0';
    for (int desc = 0; desc < mes.size(); desc += 2) // рассматриваем блоки по 2 символа
    {
        l = mes[desc];
        r = mes[desc + 1];
        for (int i = n-1; i >= 0; --i)  // n раундов
        {
            temp = l ^ fo(r, key, i);
            l = r;
            r = temp;
        }
        mes[desc] = l;
        mes[desc + 1] = r;
    }
    return mes;
}
