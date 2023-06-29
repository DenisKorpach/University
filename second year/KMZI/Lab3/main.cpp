#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../BigNumber.h"

using namespace std;
using namespace pr0crustes;

BigNumber generate_x() {
    return rand() % 10;
}

BigNumber generate_y() {
    return rand() % 10;
}

vector<BigNumber> init_v() {
    vector<BigNumber> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(generate_x());
    }
    return v;
}

vector<BigNumber> init_w() {
    vector<BigNumber> w;
    for (int i = 0; i < 5; i++) {
        w.push_back(generate_y());
    }
    return w;
}

BigNumber GMM(vector<BigNumber>& v, vector<BigNumber>& w) {
    BigNumber x = generate_x();
    int j = rand() % 5;
    BigNumber result = v[j];
    v[j] = x;
    if (rand() % 5 == 0) {
        j = rand() % 5;
        result = w[j];
    }
    return result;
}


int main() {
    srand(time(NULL));
    vector<BigNumber> v = init_v();
    vector<BigNumber> w = init_w();
    vector<BigNumber> result;
    for (int i = 0; i < 1000; i++) {
        result.push_back(GMM(v, w));
    }
    /*for (int i = 0; i < 1000; i++) {
        cout << result[i] << " ";
    }*/
    vector<int> temp;
    for(int i =0;i<5;i++){
        temp.push_back(result[i]);
    }

    bool flag = true;
    do{
        if()

    }while(true)

    cout << endl;
    return 0;
}
