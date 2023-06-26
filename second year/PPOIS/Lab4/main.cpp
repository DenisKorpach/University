#include <iostream>
#include<vector>
#include<random>
#include<ctime>
using namespace std;

class first_class{

private:
    double mark;    friend void SET_mark(first_class &m,int mark_value);
    friend void GET_mark(first_class &m);
    friend void mid_value(first_class &m,int mark_value);
public:
    first_class(){
        this->mark=1;
    }
    first_class(int mark_value){
        this->mark=mark_value;
    }
    first_class(const first_class &pp){
        this->mark=pp.mark;
    }
    ~first_class(){
        cout<<"удалён первый класс "<<endl;
    }
};
void SET_mark(first_class &m,int mark_value){
    m.mark=mark_value;
}
void GET_mark(first_class &m){
    cout<<"оценка за лабараторную: "<<m.mark<<endl;
}
void mid_value(first_class &m, int mark_value){
    double k= (m.mark + mark_value)/2;
    cout<<"средняя оценка за лабараторную: "<<k<<endl;
}



class second_class{
private:
    vector<int>values;
    friend int GET_first_val(second_class t);
    friend void PRINT_array(second_class t);
    friend double mid_sum_of_array(second_class t);
public:
    second_class(){
        this->values.push_back(10);
    }
    second_class(const int size){
        for (int i = 0; i < size; i++) {
            this->values.push_back(i);
        }
    }
    second_class(const second_class &pp){
        for(auto &k: pp.values){
            this->values.push_back(k);
        }
    }
};
int GET_first_val(second_class a){
    return a.values[0];
}
void PRINT_array(second_class t){
    for(int a:t.values){
        cout<<a<<" ";
    }
    cout<<endl;
}
double mid_sum_of_array(second_class b){
    int mid_sum=0;
    int k=0;
    for(int a:b.values){
        k++;
        mid_sum+=a;
    }
    return (mid_sum/k);
}



class third_class{
private:
    int x;
    int y;
    int z;
public:
    third_class(){
        this->x=5;
        this->y=8;
        this->z=9;
    }
    third_class(int x_value, int y_value){
        this->x=x_value;
        this->y=y_value;
    }
    third_class(const third_class &pp){
        this->x=pp.x;
        this->y=pp.y;
    }
    ~third_class(){
        cout<<endl<<"удалён третий класс"<<endl;
    }

    void GET_x(){
        cout<<"значение х: "<<this->x<<endl;
    }
    void GET_y(){
        cout<<"значение у: "<<this->y<<endl;
    }
    void GET_z(){
        cout<<"значение z: "<<this->z<<endl;
    }
    friend void CHANGE_x(third_class &value_x,int number);
    friend void CHANGE_y(third_class &value_y,int number);
    friend void foon_z(third_class &value_z,int number);

};

void CHANGE_x(third_class &value_x,int number){
    value_x.x=number;
}
void CHANGE_y(third_class &value_y,int number){
    value_y.y=number;
}
void foon_z(third_class &value_z,int number){
    value_z.z=number;
}

int main(){
    srand(time(NULL));
    
    cout<<"результат работы первого класса: "<<endl;
    first_class one(4);
    GET_mark(one);
    SET_mark(one,10);
    GET_mark(one);
    mid_value(one, 5);
    

    cout<<endl<<"результат работы второго класса: "<<endl;
    second_class two(10);
    cout<<GET_first_val(two)<<endl;
    PRINT_array(two);
    cout<<"среднее значение: "<<mid_sum_of_array(two);

    cout<<endl<<endl<<"результат работы третьего класса: "<<endl;
    third_class three;
    three.GET_x();
    three.GET_y();
    three.GET_z();
    CHANGE_x(three,11111111);
    CHANGE_y(three,22222222);
    foon_z(three,33333333);
    three.GET_x();
    three.GET_y();
    three.GET_z();
return 0;
}

