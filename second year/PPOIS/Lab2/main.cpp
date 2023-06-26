#include <iostream>
#include <string>
#include <ctime>
using namespace std;
 
class Product {
    private:
        int weight;
        string name;
        int product_price[5];
        double averweight_prodect_price;
    public:
    Product(int weight,string name,int product_price1[], double averweight_prodect_price1){
        this->weight = weight;
        this->name = name;
        for (int i = 0; i < 5; i++) {
            this->product_price[i] = product_price1[i];
        }
        this->averweight_prodect_price =averweight_prodect_price1 ;
        }
   
    Product(const Product &pp){
        this->weight=pp.weight;
        this->name=pp.name;
        for(int i=0;i<3;i++){
        	this->product_price[i]=pp.product_price[i];
        }
        this->averweight_prodect_price =pp.averweight_prodect_price ;

    }
    Product() {
        this->weight = 1000;
        this->name = "flour";
        for (int i = 0; i < 5; i++) {
            this->product_price[i] = 1 + rand() % 20;
        }
        this->averweight_prodect_price = 6;
        }

        void TO_SET(int Value_averweight_prodect_price) {
            this->averweight_prodect_price = Value_averweight_prodect_price;
        }
        void TO_SET(double Value_averweight_prodect_price) {
            this->averweight_prodect_price = Value_averweight_prodect_price;
        }
        void TO_SET(float Value_averweight_prodect_price){
            this->averweight_prodect_price = Value_averweight_prodect_price;
        }

        Product operator--() {
            for (int i = 0; i < 5; i++) {
                --(this->product_price[i]);
            }
            return*this;
        }
        void TO_GET() {
            cout << endl << endl << "введите вес товара: "; cin >> this->weight;
            cout << endl << "Введите название товара: "; cin >> this->name;
            for (int i = 0; i < 5; i++) {
                cout << endl << "Введите цены товара: "; cin >> this->product_price[i];
            }
        }
        void TO_SHOW() {
            cout << endl << endl << "название товара: " << this->name;
            cout << endl << "вес товара: " << this->weight;
            for (int i = 0; i < 5; i++) {
                cout << endl << "цена товара: " << this->product_price[i];
            }
            cout << endl << "средняя цена товара: " << this->averweight_prodect_price;
        }
};
 
class Person {
    private:
        int height;
        string name_person;
        int mark_laba[5];
        double averweight_mark_laba;
    public:
        Person() {
            this->height = 194;
            this->name_person = "denis";
            for (int i = 0; i < 5; i++) {
                this->mark_laba[i] = i;
            }
            averweight_mark_laba = 6;
        }
        Person(int heught,string name_person,int mark_laba[], double averweight_mark_laba){
        this->height = height;
        this->name_person = name_person;
        for (int i = 0; i < 5; i++) {
            this->mark_laba[i] = mark_laba[i];
        }
        this->averweight_mark_laba =averweight_mark_laba ;
        }
   
    Person(const Person &kk){
        this->height=kk.height;
        this->name_person=kk.name_person;
        for(int i=0;i<3;i++){
        	this->mark_laba[i]=kk.mark_laba[i];
        }
        this->averweight_mark_laba =kk.averweight_mark_laba ;

    }
    

        void TO_SET_person(int Value_averweight_mark_laba) {
            this->averweight_mark_laba = Value_averweight_mark_laba;
        }
        void TO_SET_person(double Value_averweight_mark_laba,double k) {
            this->averweight_mark_laba = (Value_averweight_mark_laba+k)/2;
        }
        void TO_SET_person(float Value_averweight_mark_laba, float k,float c){
            this->averweight_mark_laba = (Value_averweight_mark_laba+k+c)/3;
        }

        Person operator--() {
            for (int i = 0; i < 5; i++) {
                --(this->mark_laba[i]);
            }
            return*this;
        }
        void TO_GET_person() {
            cout << endl << endl << "введите рост человека : "; cin >> this->height;
            cout << endl << "Введите название человека: "; cin >> this->name_person;
            for (int i = 0; i < 5; i++) {
                cout << endl << "Введите оценки лаб: "; cin >> this->mark_laba[i];
            }
        }
        void TO_SHOW_person() {
            cout << endl << endl << "имя человека: " << this->name_person;
            cout << endl << "рост человека: " << this->height;
            for (int i = 0; i < 5; i++) {
                cout << endl << "оценка лабы: " << this->mark_laba[i];
            }
            cout << endl << "средняя щценка лаб: " << this->averweight_mark_laba;
        }
};
class Person2 {
    private:
        int height2;
        string name_person2;
        int mark_laba2[5];
        double averweight_mark_laba2;
    public:
        Person2() {
            this->height2 = 10000000;
            this->name_person2 = "denis";
            for (int i = 0; i < 5; i++) {
                this->mark_laba2[i] = i;
            }
            averweight_mark_laba2 = 6;
        }
        Person2(int heught2,string name_person2,int mark_laba2[], double averweight_mark_laba2){
        this->height2 = height2;
        this->name_person2 = name_person2;
        for (int i = 0; i < 5; i++) {
            this->mark_laba2[i] = mark_laba2[i];
        }
        this->averweight_mark_laba2 =averweight_mark_laba2 ;
        }
   
    Person2(const Person2 &kk2){
        this->height2=kk2.height2;
        this->name_person2=kk2.name_person2;
        for(int i=0;i<3;i++){
        	this->mark_laba2[i]=kk2.mark_laba2[i];
        }
        this->averweight_mark_laba2 =kk2.averweight_mark_laba2 ;

    }

        void TO_SET_person2(int Value_averweight_mark_laba2, double k) {
            this->averweight_mark_laba2 = Value_averweight_mark_laba2+k;
        }
        void TO_SET_person2(double Value_averweight_mark_laba2,int c,float d) {
            this->averweight_mark_laba2 = (Value_averweight_mark_laba2+c+d)/3;
        }
        void TO_SET_person2(float Value_averweight_mark_laba2, int k){
            this->averweight_mark_laba2 = (Value_averweight_mark_laba2+k)/2;
        }

        Person2 operator--() {
            for (int i = 0; i < 5; i++) {
                --(this->mark_laba2[i]);
            }
            return*this;
        }
        void TO_GET_person2() {
            cout << endl << endl << "введите рост человека : "; cin >> this->height2;
            cout << endl << "Введите название человека: "; cin >> this->name_person2;
            for (int i = 0; i < 5; i++) {
                cout << endl << "Введите оценки лаб: "; cin >> this->mark_laba2[i];
            }
        }
        void TO_SHOW_person2() {
            cout << endl << endl << "имя человека: " << this->name_person2;
            cout << endl << "рост человека: " << this->height2;
            for (int i = 0; i < 5; i++) {
                cout << endl << "оценка лабы: " << this->mark_laba2[i];
            }
            cout << endl << "средняя щценка лаб: " << this->averweight_mark_laba2;
        }
};

int main() {
setlocale(LC_ALL, "RUS");
srand(time(NULL));
 
Product A; 
A.TO_SHOW();
A.TO_SET(5); 
A.TO_SHOW();

A.TO_SET(12.056); 
A.TO_SHOW();

A.TO_SET(8.09386218);
A.TO_SHOW();

A.TO_GET(); 
A.TO_SHOW();

A.operator--(); 
A.TO_SHOW();

Person B; 
B.TO_SHOW_person();
B.TO_SET_person(5); 
B.TO_SHOW_person();

B.TO_SET_person(12.05698765,5.98814525); 
B.TO_SHOW_person();

B.TO_SET_person(8.09,4.09,2.06);
B.TO_SHOW_person();

B.TO_GET_person(); 
B.TO_SHOW_person();

B.operator--(); 
B.TO_SHOW_person();


Person2 B2; 
B2.TO_SHOW_person2();
B2.TO_SET_person2(5, 7.98709356); 
B2.TO_SHOW_person2();

B2.TO_SET_person2(12.05698765, 5 , 6.98); 
B2.TO_SHOW_person2();

B2.TO_SET_person2(8.09, 4);
B2.TO_SHOW_person2();

B2.TO_GET_person2(); 
B2.TO_SHOW_person2();

B2.operator--(); 
B2.TO_SHOW_person2();


system ("pause");
}
