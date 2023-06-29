#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>
#include <map>
#include <unordered_map>
using namespace std;
class Square{
	public:
		vector<vector<int>> tcmagic(int n) const {
		vector<vector<int>> matris(n,vector<int>(n,0));

		int m=0;
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				matris[i][k]=k+1+n*m;
			}
			m++;
		}
		int k,mi,mj;
		k = (n - 2) / 4;
		for (mi = 0; mi < k; mi++){
			for (mj = k + 1; mj < 2 * k + 1; mj++){
				swap(matris[mi][mj],matris[mi][4 * k + 2 - mj - 1]);
			}
		}

		for (mi = 3 * k + 2; mi < 4 * k + 2; mi++){
			for (mj = k + 1; mj < 2 * k + 1; mj++){
				swap(matris[mi][mj],matris[mi][4 * k + 2 - mj - 1]);
			}
		}

		for (mj = 0; mj < k; mj++){
			for (mi = k + 1; mi < 2 * k + 1; mi++){
				swap(matris[mi][mj],matris[4 * k + 2 - mi - 1][mj]);
			}
		}

		for (mj = 3 * k + 2; mj < 4 * k + 2; mj++){
			for (mi = k + 1; mi < 2 * k + 1; mi++){
				swap(matris[mi][mj],matris[4 * k + 2 - mi - 1][mj]);
			}
		}

		for (mi = 0; mi < k; mi++){
			for (mj = k + 1; mj < 3 * k + 1; mj++){
				swap(matris[mi][mj],matris[4 * k + 2 - mi - 1][mj]);
			}
		}

		for (mj = 0; mj < k; mj++){
			for (mi = k + 1; mi < 3 * k + 1; mi++){
				swap(matris[mi][mj],matris[mi][4 * k + 2 - mj - 1]);
			}
		}

		for (int a = 0; a < n / 2; a++){
			if (a != k){
				swap(matris[a][3 * k + 1],matris[4 * k + 2 - a - 1][3 * k + 1]);
			}
		}
		for (int a = k + 1; a <= 3 * k; a++){
			swap(matris[a][k],matris[a][3 * k + 1]);
		}

		swap(matris[n / 2][k],matris[n / 2][3 * k + 1]);

		for (int a = 0; a < n / 2; a++){
			if (a != k){
				swap(matris[3 * k + 1][a],matris[3 * k + 1][4 * k + 2 - a - 1]);
			}
		}

		for (int a = 0; a < n / 2; a++){
			if (a != k){
				swap(matris[k][a],matris[k][4 * k + 2 - a - 1]);
			}
		}

		for (int a = k + 1; a <= 3 * k; a++){
			swap(matris[k][a],matris[3 * k + 1][a]);
		}

		swap(matris[k][0],matris[3 * k + 1][0]);

		for (int a = k + 1; a < n / 2; a++){
			swap(matris[0][a],matris[0][4 * k + 2 - a - 1]);
		}

		for (int a = 0; a < k; a++){
			swap(matris[n / 2][a],matris[n / 2][4 * k + 2 - a - 1]);
		}
				
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				cout<<setw(5)<<matris[i][k];
			}
			cout<<endl;
		}
		cout<<endl;	
		
		int toplam=0;
		
		for(int i=0;i<n;i++){
			toplam=toplam+matris[1][i];
		}
		cout<<"Sum of Rows : "<<toplam<<endl;
			cout<<endl;
		return matris;
	}

	vector<vector<int>> ccmagic(int n) const {

		vector<vector<int>> matris(n+1,vector<int>(n+1,0));
		vector<int> yenimatris((n*n)/8,0);
		vector<int> yenimatris1((n*n)/8,0);
		vector<int> yenimatris2((n*n)/8,0);
		vector<int> yenimatris3((n*n)/8,0);
		
		int m=0;
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				matris[i][k]=k+n*m;
			}
			m++;
		}
		
		int sayici=0;
		for(int i=1;i<=n/4;i++){
			for(int k=n/4+1;k<=3*n/4;k++){
				yenimatris[sayici]=matris[i][k];
			sayici++;
			}
		}
		int sayici1=0;
		for(int i=3*n/4+1;i<=n;i++){
			for(int k=n/4+1;k<=3*n/4;k++){
				yenimatris1[sayici1]=matris[i][k];
			sayici1++;
			}
		}

		for(int i=3*n/4+1;i<=n;i++){
			for(int k=n/4+1;k<=3*n/4;k++){
				matris[i][k]=yenimatris[sayici-1];
			sayici--;
			}
		}
		
		for(int i=1;i<=n/4;i++){
			for(int k=n/4+1;k<=3*n/4;k++){
				matris[i][k]=yenimatris1[sayici1-1];
			sayici1--;
			}
		}

		int sayici2=0;
		for(int i=n/4+1;i<=3*n/4;i++){
			for(int k=1;k<=n/4;k++){
				yenimatris2[sayici2]=matris[i][k];
			sayici2++;
			}
		}
		int sayici3=0;
		for(int i=n/4+1;i<=3*n/4;i++){
			for(int k=3*n/4+1;k<=n;k++){
				yenimatris3[sayici3]=matris[i][k];
			sayici3++;
			}
		}

		for(int i=n/4+1;i<=3*n/4;i++){
			for(int k=1;k<=n/4;k++){
				matris[i][k]=yenimatris3[sayici3-1];
			sayici3--;
			}
		}
		
		for(int i=n/4+1;i<=3*n/4;i++){
			for(int k=3*n/4+1;k<=n;k++){
				matris[i][k]=yenimatris2[sayici2-1];
			sayici2--;
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				cout<<setw(5)<<matris[i][k];
			}
			cout<<endl;
		}cout<<endl;	
		int toplam=0;
		
		for(int i=1;i<=n;i++){
			toplam=toplam+matris[1][i];
		}
		cout<<"Sum of Rows : "<<toplam<<endl;
		return matris;
	}

	vector<vector<int>> tmagic(int n) const {
		vector<vector<int>> matrix(n,vector<int>(n,0));
		int bas=n/2;
		int bas1=n-1;
		int a=1;
		while(a!=(n*n)+1){
			if(matrix[bas%n][bas1%n]==0){
				matrix[bas%n][bas1%n]=a;
			}
			else{
				if((bas-1)%n<0){
					bas=bas+3;
				}
				if((bas1-2)%n<0){
					bas1=bas1+3;
				}
				matrix[(bas-1)%n][(bas1-2)%n]==a;
			}
			
			if(matrix[(bas+1)%n][(bas1+1)%n]==0){
				bas1++;
				bas++;
			}
			else{
				bas1--;
			}
			a++;
		}
		
		for(int i=0;i<n;i++){
			for(int k=0;k<n;k++){
				cout<<setw(5)<<matrix[i][k];
			}
			cout<<endl;
		}

		int toplam=0;	
		for(int i=0;i<n;i++){
			toplam=toplam+matrix[1][i];
		}
		cout<<"Sum of Rows : "<<toplam<<endl;
		return matrix;
	}
	pair<int, int> find_index(vector<vector<int>>& matrix, int target) const {
		int n = matrix.size();
		int m = matrix[0].size();

		// Проходим по всем элементам и сравниваем их значения с целевым значением
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == target) {
					return make_pair(i, j);
				}
			}
		}

		// Если элемент не найден, возвращаем (-1, -1)
		return make_pair(-1, -1);
	}
	
	string decryption_txt(string txt){
		int size = sqrt(txt.size());
		vector<vector<int>> magic_matrix;
		vector<vector<char>> decryption;

		if(size%2==0 && size!=0){
			if(size%4==0){
				magic_matrix = ccmagic(size);//тут цикл с единицы
				decryption.assign(size, vector<char>(size, 0));
				for(int i=0;i<size+1;i++){
					magic_matrix[i].erase(magic_matrix[i].begin()+0);
				}
					magic_matrix.erase(magic_matrix.begin()+0);
			}
			else{
				magic_matrix = tcmagic(size);
				decryption.assign(size, vector<char>(size, 0));
			}
		}
		else{
			magic_matrix = tmagic(size);
			decryption.assign(size, vector<char>(size, 0));
		}cout<<endl;


		vector<vector<char>> temp_matrix(size,vector<char>(size,0));
		int index_txt=0;
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				temp_matrix[i][j]= txt[index_txt];
				index_txt++;
			}
		}
		string new_txt = "";
		index_txt = 0;
		for(int i=0;i<size;i++){
			for(int j = 0;j<size;j++){
				pair<int,int> index = find_index(magic_matrix, index_txt+1);
				if(index_txt < size*size){
					new_txt += temp_matrix[index.first][index.second];
				}
				else break;
				index_txt++;
			}
		}

		cout<<new_txt<<endl;
		return new_txt;
	}

	string encryption_txt(string txt){
		vector<vector<int>> magic_matrix;
		double result =  sqrt(txt.length());//находим квадрат длины строки, для магического квадрата
		int n = ceil(result);//округляем вверх
		cout << "бляжайший корен: "<<n<<" длина строки "<< txt.length()<<endl<<endl;
		vector<vector<char>> encryption;


		if(n%2==0 && n!=0){//проверяем четность размера матрицы
			if(n%4==0){
				magic_matrix = ccmagic(n);//магический квадрат размером который делиться без остатка на 4
				encryption.assign(n, vector<char>(n, 0));//объявляем нужного размера матрицу шифра
				for(int i=0;i<n+1;i++){//удаляем нулевую строку и нулевой столбец
					magic_matrix[i].erase(magic_matrix[i].begin()+0);
				}
					magic_matrix.erase(magic_matrix.begin()+0);
			}
			else{//магический квадрат размером который делиться без остатка на 2
				magic_matrix = tcmagic(n);
				encryption.assign(n, vector<char>(n, 0));
			}
		}
		else{//если n нечётное число
			magic_matrix = tmagic(n);
			encryption.assign(n, vector<char>(n, 0));
		}cout<<endl;

		int index_txt = 0;
		for(auto row : encryption){
			for(auto col : row){
				pair<int, int> index = find_index(magic_matrix, index_txt+1);//ищем индекс числа в магическом квадрате
				if (index_txt < txt.size()){
					encryption[index.first][index.second] = txt[index_txt];//помещаем по этому индеку символ из строки
				}
				else{//если длина строки меньше чем n*n заполняем пробелами строку до конца
					encryption[index.first][index.second] = ' ';
				}
				index_txt++;
			}
		}cout<<endl;

		string encryption_txt = "";
		for(auto row : encryption){//получаем зашифрованную строку
			for(auto col : row){
				encryption_txt+=col;
			}
		}
		cout<<"зашифрованная строка "<<encryption_txt<<endl;
		for(auto row : encryption){
			for(auto col : row){
				cout<<col<<" ";
			}
			cout<< endl;
		}cout<<endl;


		return encryption_txt;


	}
	vector<int> LZW_compress(string input) {
		unordered_map<string, int> dict;
		int dict_size = 256;
		for (int i = 0; i < 256; i++) {
			dict[string(1, i)] = i;
		}

		string curr = "";
		vector<int> output;

		for (char c : input) {
			string temp = curr + c;
			if (dict.count(temp)) {
				curr = temp;
			} else {
				output.push_back(dict[curr]);
				dict[temp] = dict_size++;
				curr = string(1, c);
			}
		}

		if (!curr.empty()) {
			output.push_back(dict[curr]);
		}
		
		for (auto it = dict.begin(); it != dict.end(); ++it) {
        	std::cout << "Key: " << it->first << " | Value: " << it->second << std::endl;
    	}
		return output;
	}
	string LZW_decompressing(vector<int> op){
		string result = "";
		cout << endl;
		cout << "Unzip: ";
		unordered_map<int, string> table;
		for (int i = 0; i <= 255; i++) {
			string ch = "";
			ch += char(i);
			table[i] = ch;
		}
		int old = op[0], n;
		string s = table[old];
		string c = "";
		c += s[0];
		result += s;
		int count = 256;
		for (int i = 0; i < op.size() - 1; i++) {
			n = op[i + 1];
			if (table.find(n) == table.end()) {
				s = table[old];
				s = s + c;
			}
			else {
				s = table[n];
			}

			result += s;
			c = "";
			c += s[0];
			table[count] = table[old] + c;
			count++;
			old = n;
		}

		return result;
	}
	double entropy(string input) {
		int len = input.length();
		map<char, int> freq;
		
		// считаем частоту каждого символа
		for (int i = 0; i < len; i++) {
			freq[input[i]]++;
		}
		
		double result = 0;
		
		// считаем энтропию
		for (auto& p : freq) {
			double prob = (double)p.second / len;
			result += (-1 * prob) * log2(prob);
		}
		
		return result;
	}


};