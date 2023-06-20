#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>
#include "Header.h"
#include "Header1.h"
#include <omp.h>
using namespace std;
int main(){
     srand((unsigned)time(NULL));
    double y, xa = 0, x0, a = 6, b, sh, y1 = 1, rnd, i = 1, number1, number2 = 0, result;
    int row, column;
    double numbers[1000][3];
    rnd = (-1*pow(10,6) + rand()%(int)(1*pow(10,4)+1*pow(10,4)))/pow(10,4);
    cout << "random number: " << rnd << endl;
    cout << "input number b[2,10]: ";
    cin >> b;
    while (b > 10 || b < 2) {
        cout << "input number b[2,10]: ";
        cin >> b;
    }
    cout << "input step: ";
    cin >> sh;
    unsigned int start_time = clock();
#pragma omp parallel
    {
#pragma omp crtical
        {
            //cout << "Поток" << endl; для проверки многопоточности
            for (row = 0; row < 1000; row++) {
                for (column = 0; column < 3; column++) {
                    double x0 = (-10.0 + static_cast <float> (rand())) / (static_cast <float> (RAND_MAX / (30.0)));
                    //cout << "Начальные значения: " << x0 << endl;  для проверки рандома
                    xa = x0;
                    y = calculation1(xa, a, b);
                    numbers[row][column] = y;
                    do {
                        //заменить в отдельный файл
                        double x1 = x0 + sh * rnd;
                        xa = x1;
                        double y1 = cos(xa) + (1 / b) * cos(a * xa + 1) + 
                        (1 / pow(b, 2)) * cos(pow(a, 2) * xa + 2) + 
                        (1 / pow(b, 3)) * cos(pow(a, 3) * xa + 3) + 
                        (1 / pow(b, 4)) * cos(pow(a, 4) * xa + 4);
                        if (y1 < y) {
                            x0 = x1;
                            y = y1;
                        }
                        sh = 0.75 * sh;
                        //заменить в отдельный файл
                        numbers[row][column] = y1;

                    } while (sh > 0.0001);
                }
            }
        }


        cout << "array: " << endl;
        cout << "---------------------------------------------" << endl;
        for (row = 0; row < 1000; row++) {
            for (column = 0; column < 3; column++) {
                cout << numbers[row][column] << " ";
            }
            cout << endl;
        }
        cout << "---------------------------------------------" << endl;
        for (row = 0; row < 1000; row++) {
            for (column = 0; column < 3; column++) {
                number1 = numbers[row][column];
                number2 = number2 + number1;
            }
        }
    }
     result = number2 / (3000);
     cout << "result: " << result << endl;
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "execution time: " << search_time / 1000.0 << "seconds" << endl;
   
}