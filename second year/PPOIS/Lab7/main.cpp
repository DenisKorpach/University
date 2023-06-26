#include<iostream>
using namespace std;
template<typename T>
class Book {
private:
	T length;
	T& size = length;
public:
	Book() {
		size = 20;
	}
	Book(T& size ) {
		this->size = size;
	}
	Book(Book& obj) {
		this->size = obj.size;
	}

	~Book(){}
	
	T& GetSize() {
		return this->size;
	}	
	void SetSize(int& _size) {
		this->size = _size;
	}
	void Show() {
		cout << "number pages of book: " << this->size << endl;
	}
	void foon1(T a){  
        a = 0;  
    }  
    void foon2(T &a){  
        a = 0;  
    }  
    void foon3(T *a){  
        *a = 0;  
    }  
};
template<typename T1>
class Student{
  private:
    T1 first;
    T1 second;
    T1 third[3];
  public:
    Student(){
        this->first=1;
        this->second=2;
        for(int i=0;i<3;i++){
    		this->third[i]=i;
    	}
    }
    Student(T1 name,T1 age,T1 third[]){
        this->first=name;
        this->second=age;
        for(int i=0;i<3;i++){
        	this->third[i]=third[i];
       }
   }
    Student(Student &pp){
        this->second=pp.second;
        this->first=pp.first;
        for(int i=0;i<3;i++){
        	this->third[i]=pp.third[i];
        }
    }
    void print(){
        cout<<this->first<<"\t"<<this->second<<"\t";
        for(int i=0;i<3;i++){
        	cout<<this->third[i]<<" ";
        }
        cout<<endl;
    }
    
    void TO_SET_first(T1 first){
        this->first=first;
    }
    void TO_SET_second(T1 second){
        this->second=second;
    }
    void TO_SET_third(T1 third[]){
    	for(int i=0;i<3;i++){
        	this->third[i]=third[i];
        }
    }
    T1 TO_GET_first(){
        return this->second;
    }
    T1 TO_GET_second(){
        return this->second;
    }
    T1 TO_GET_third(){
        return this->third[3];
    }
};
template<typename T_s,typename T_i>
class Reference {
private:
	T_s my_name;
	T_s his_name;
	T_i my_age;
	T_i his_age;
public:
	Reference() {
		my_name = "Denis";
		his_name = "Sined";
		my_age = 18;
		his_age = 81;
	}
	Reference(T_s& my_name, T_s& his_name, T_i& my_age, T_i& his_age) {
		this->my_name = my_name;
		this->his_name = his_name;
		this->my_age = my_age;
		this->his_age = his_age;
	}
	Reference(Reference& obj) {
		this->my_name = obj.my_name;
		this->his_name = obj.his_name;
		this->my_age = obj.my_age;
		this->his_age = obj.his_age;
	}
	~Reference() {}

	T_s& GetMyName() {
		return this->my_name;
	}
	T_s& GetHisName() {
		return this->his_name;
	}
	T_i& GetMyAge() {
		return this->my_age;
	}
	T_i& GetHisAge() {
		return this->his_age;
	}
	void SetMyName(T_s& _my_name) {
		this->my_name = _my_name;
	}
	void SetHisName(T_s& _his_name) {
		this->his_name = _his_name;
	}
	void SetMyAge(T_i& _my_age) {
		this->my_age = _my_age;
	}
	void SetHisAge(T_i& _his_age) {
		this->his_age = _his_age;
	}
	void Show() {
		cout << "my name: " << this->my_name << endl;
		cout << "his name: " << this->his_name << endl;
		cout << "my age: " << this->my_age << endl;
		cout << "his age: " << this->his_age << endl;
	}
	void Show(Reference& names) {
		names.Show();
		this->Show();
	}
	Reference operator=(Reference& obj) {
		this->my_name = obj.my_name;
		this->his_name = obj.his_name;
		this->my_age = obj.my_age;
		this->his_age = obj.his_age;
		return *this;
	}
};

int main(){
	cout<<"первый класс"<<endl;
	Book<int> book1;
	int k=100;
	Book<int> book2(k);
	Book<int> book3(book2);
	book1.Show();
	book2.Show();
	book3.Show();

	cout<<"второй класс"<<endl;
	Student<int> st1;
	int third[3]={11,22,33};
	Student<int> st2(5,78,third);
	Student<int> st3(st2);
	st1.print();
	st2.print();
	st3.print();

	cout<<"третий класс"<<endl;
	Reference<string,int> ref1;
	string my_name="Ivan";
	string his_name="Petr";
	int my_age=20;
	int his_age=21;
	Reference<string,int> ref2(my_name,his_name,my_age,his_age);
	Reference<string,int> ref3(ref2);
	ref1.Show();
	ref2.Show();
	ref3.Show();


    
    return 0;
}