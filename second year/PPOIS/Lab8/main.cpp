#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class first{
    private:
    string stroke_first_1;
    char *stroke_first_2="0980";
    public:
    first(){
        stroke_first_1="ppp";
        }
    first(string s1,char *s){
        stroke_first_1=s1;
        stroke_first_2=s;
        
    }
    first(const first &s){
        stroke_first_1=s.stroke_first_1;
        stroke_first_2=s.stroke_first_2;
    }
    string get_strok1(){
        return this->stroke_first_1;
    }
    int get_strok2(){
       return puts(stroke_first_2);
    }
    void show(){
        cout<<stroke_first_1<<endl;
        cout<<stroke_first_2<<endl;
    }
};
class second{
    private:
        string stroke_second_1;
        string stroke_second_2;
    public:
        second(){
            stroke_second_1="100000";
            stroke_second_2="200000";
        }
        second(string s1,string s2){
            stroke_second_1=s1;
            stroke_second_2=s2;
        }
        second(const second &s){
            stroke_second_1=s.stroke_second_1;
            stroke_second_2=s.stroke_second_2;
        }
        string get_strok1(){
            return this->stroke_second_1;
        }
        string get_strok2(){
            return this->stroke_second_2;
        }
        void show(){
            cout<< setw(15) <<stroke_second_1<<endl;
            cout<< setw(5)<<stroke_second_2<<endl;
        }
        void work_of_stream(string s1,string s2){
            ofstream fout;
            fout.open("inf.txt");
            fout << "first line add: " << s1 << endl;
            fout << "second line add: " << s2 << endl;
            fout << "third line add: " << stroke_second_1 << endl;
            fout << "fourth line add: " << stroke_second_2 << endl;
            fout << endl;
        }
};
class third{
    private:
        string i_doing;
        char *i_tired;
    public:
        third(){
            i_doing="this lab in 00:30";
            i_tired="i am tired";
        }
        third(char *s,string s1){
            i_doing=s1;
            i_tired=s;
        }
        string to_get(){
            return this->i_doing;
        }
        int to_get_2(){
            return puts(i_tired);
        }
        void show(){
            cout<<i_doing<<endl;
            cout<<i_tired<<endl;
        }
        void add_new_strok(string s2){
            ofstream fout;
            fout.open("inf.txt",ios::app);
            fout << "fifth line add: " << s2 << endl;
            fout << "six line add: "<< i_doing << endl;
            fout << "seven line add: " << i_tired << endl;
            fout << endl;
        }


};
int main() {
    cout<<"вывод первого класса: "<<endl;
    setlocale(LC_ALL, "Russian");
    first obj1;
    char s_2[]="kkk";
    string s_1= "lll" ;
    first obj2(s_1,s_2);
    first obj3(obj2);
    obj1.show();
    obj2.show();
    obj3.show();

    cout<<endl<<"вывод второго класса: "<<endl;
    second secn;
    string str1="111111";
    string str2="222222";
    second secn1(str1,str2);
    secn.show();
    secn1.show();
    str1="ура";
    str2="последняя лаба";
    secn1.work_of_stream(str1,str2); 


    cout<<endl<<"вывод третьего класса: "<<endl;
    ifstream fin;
    fin.open("class.txt");
    char stroka[100];
    fin.getline(stroka,100);

    third s1;
    third s2(stroka,s1.to_get());
    s1.show();
    s2.show();
    str1="ура последний класс";
    s2.add_new_strok(str1);

    
    

    
    return 0;
}