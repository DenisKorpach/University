#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	int i = 0, a, n, ogr;
	double x1, x2, x3, y, y1 = 0, x, sum = 0, MSE1,MSE2, SE, alfa, rnd,w00,w11,w22,w33;
	double w0 =((0.01 * pow(10, 4) + rand() % (int)(50 * pow(10, 4) - 0.01 * pow(10, 4))) / pow(10, 4));
	double w1 =((0.01 * pow(10, 4) + rand() % (int)(50 * pow(10, 4) - 0.01 * pow(10, 4))) / pow(10, 4));
	double w2 =((0.01 * pow(10, 4) + rand() % (int)(50 * pow(10, 4) - 0.01 * pow(10, 4))) / pow(10, 4));
	double w3 =((0.01 * pow(10, 4) + rand() % (int)(50 * pow(10, 4) - 0.01 * pow(10, 4))) / pow(10, 4));
	cout<<w0<<" "<<w1<<" "<<" "<<w2<<" "<<w2<<endl;
	cout << "how do you sting count" << endl;
	cin >> n;
	ogr = n * 3;
	string path = "x.csv";
	fstream fs;
	fs.open(path, fstream::in);
	string text;
	vector<double> vectorx1, vectorx2, vectorx3, vectory, vectory1, vectorSE;
	while (!fs.eof()){
		a = i % 3;                         //
		text = "";                           
		fs >> text;                        //
		if (text != ""){
			double numtext = stod(text);   //
			switch (a)
			{                              //
			case 0:
				x1 = numtext;              //
				vectorx1.push_back(x1);
				break;                     //вывод x из файла
			case 1:
				x2 = numtext;
				vectorx2.push_back(x2);    //
				break;                            
			case 2:                        // 
				x3 = numtext;
				vectorx3.push_back(x3);    //
				break;
			}
		}                               
		i++;
		if (i == ogr)
		{
			break;
		}
	}
	i = 0;
	string path2 = "y.csv";
	fstream fs2;
	fs2.open(path2, fstream::in);
	string text2;

	while (!fs2.eof()){
		text2 = "";
		fs2 >> text2;
		double y = stod(text2);
		vectory.push_back(y);            //вывод y из файла
		i++;
		if (i == n){
			break;
		}
	}
	cout << "input alfa\n";
	cin >> alfa;
	int kk=400;
	do{
		MSE1=0,MSE2=0;y1=0;
		rnd = ((-1 * pow(10, 4) + rand() % (int)(1 * pow(10, 4) + 1 * pow(10, 4))) / pow(10, 4));
		w00 = w0 +  alfa * rnd;
		w11 = w1 +  alfa * rnd;
		w22 = w2 +  alfa * rnd;
		w33 = w3 +  alfa * rnd;
		for (int i = 0; i < n; i++){//расчёт с w0 w1 w2 w3
			y1 += w1 * vectorx1[i] + w2 * vectorx2[i] + w3 * vectorx3[i];//рассчёт у домик(y^)
			if (i == n - 1)
			{
				y1 += w0;
			}
		}
		for (int i = 0; i < n; i++){
			SE = pow((vectory[i] - y1), 2); //рассчёт  SE1
			MSE1 += SE;
			if (i == n - 1){
				MSE1 /= i;//рассчёт   MSE1
			}
		}


		y1=0;
		for (int i = 0; i < n; i++){//расчёт с w00 w11 w22 w33
			y1 += w11 * vectorx1[i] + w22 * vectorx2[i] + w33 * vectorx3[i];//рассчёт у домик(y^)
			if (i == n - 1){
				y1 += w00;
			}
		}
		for (int i = 0; i < n; i++){
			SE = pow((vectory[i] - y1), 2); //рассчёт  SE2
			MSE2 += SE;
			if (i == n - 1){
				MSE2 /= i;//рассчёт   MSE2
			}
		}
		if(MSE2<MSE1){
			w0=w00;
			w1=w11;
			w2=w22;
			w3=w33;
			cout<<"MSE2: "<<MSE2<<endl;
		}
		alfa*=0.8745;
	    kk--;
	}while (kk>0);
	cout<<w0<<"  "<<w1<<"  "<<w2<<"  "<<w3;
	fs.close();
	fs2.close();
  
}