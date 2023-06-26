#include<iostream>
using namespace std;
namespace firstDNS{
    class first{
        private:
        int x;
        int y;
        public:
        first(int a, int b){
            this->x=a;
            this->y=b;
        }
        first(){
            this->x=5;
            this->y=7;
        }
        first(const first &a){
            this->x=a.x;
            this->y=a.y;
        }
        void TO_SET1(int a, int b){
            this->x=a;
            this->y=b;
        }
        int TO_GET_X1(){
            return x;
        }
        int TO_GET_Y1(){
            return y;
        }
        void TO_SHOW1(){
            cout<<"вывод класса first"<<endl;
            cout<<"x= "<<this->x<<endl;
            cout<<"y= "<<this->y<<endl;
        }
    };
}
namespace secondDNS{
    class second{
        private:
            int z;
            int w;
        public:
        second(int a, int b){
            this->z=a;
            this->w=b;
        }
        second(){
            this->z=55;
            this->w=77;
        }
        second(const second &p){
            this->z=p.z;
            this->w=p.w;
        }
        void TO_SET2(int a, int b){
            this->z=a;
            this->w=b;
        }
        int TO_GET_X2(){
            return z;
        }
        int TO_GET_Y2(){
            return w;
        }
        void TO_SHOW2(){
            cout<<"вывод класса second: "<<endl;
            cout<<"z= "<<this->z<<endl;
            cout<<"w= "<<this->w<<endl;
        }
        double foon(double k,double b){//функция для исключения
            if(b==0){
                throw runtime_error("Math error: Attempted to divide by Zero");
            }
            return (k/b);
        }
    };
}
namespace thirdDNS{
    class third : public firstDNS::first, public secondDNS::second{
        public:
        third(int a, int b, int c, int d):first(a,b),second(c,d){
            }
            third():first(),second(){
            }
            third(const third &p):first(p),second(p){
            }
            void TO_SET3(int a, int b, int c, int d){
                first::TO_SET1(a,b);
                second::TO_SET2(c,d);
            }
            int TO_GET_X3(){
                return first::TO_GET_X1();
            }
            int TO_GET_Y3(){
                return second::TO_GET_Y2();
            }
            void TO_SHOW3(){
                cout<<"вывод наследования: "<<endl;
                first::TO_SHOW1();
                second::TO_SHOW2();
            }
            double foon3(double k,double b){//наследованая функция для исключения
               return second::foon(k,b);
            }
    };
}
int main(){
    firstDNS::first a(1,2);
    secondDNS::second b(3,4);
    thirdDNS::third c(5,6,7,8);
    thirdDNS::third d;
    thirdDNS::third e(c);
    double result,K,B;
    cin>>K>>B;
    try{//исключение
        result=c.foon3(K,B);
        cout<<"Result is: "<<result<<endl;
    }
    catch(runtime_error &e){
        cout<<"Exception: "<<e.what()<<endl;
    }

    
    a.TO_SHOW1();
    b.TO_SHOW2();
    c.TO_SHOW3();
    d.TO_SHOW3();
    e.TO_SHOW3();
    return 0;
}