#include <iostream>
#include <cmath>
using namespace std;

unsigned long long int isqrt(unsigned long long int n) {
    unsigned long long int x = n;
    unsigned long long int y = (x + n / x) / 2;
    while (y < x) {
        x = y;
        y = (x + n / x) / 2;
    }
    return x;
}

pair<unsigned long long int, unsigned long long int> fermat(unsigned long long int n, bool verbose=true) {
    unsigned long long int a = isqrt(n);
    unsigned long long int b2 = a * a - n;
    unsigned long long int b = isqrt(n);
    int count = 0;
    while (!(b * b == b2)) {
        if (verbose) {
            //cout << "Trying: a=" << a << " b2=" << b2 << " b=" << b << endl;
        }
        a = a + 1;
        b2 = a * a - n;
        b = isqrt(b2);
        count += 1;
    }
    unsigned long long int p = a + b;
    unsigned long long int q = a - b;
    cout << "a=" << a << ", b=" << b <<"    ( pow(a,2) - pow(b,2) = "<<n<<" )"<< endl;
    cout << "p=" << p << ", q=" << q <<"    ( p * q = "<<n<<" )"<< endl;
    
    return make_pair(p, q);
}

int main() {
    unsigned long long int n = 224114414121;
    fermat(n);
    return 0;
}