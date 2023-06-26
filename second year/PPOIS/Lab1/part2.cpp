#include <iostream>
using namespace std;
class Student{
  private:
    int first;
    int second;
    int third[3];
  public:
    Student(){
        this->first=1;
        this->second=2;
        for(int i=0;i<3;i++){
    		this->third[i]=i;
    	}
    }
    Student(int name,int age,int third[]){
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
    
    void TO_SET_first(int first){
        this->first=first;
    }
    void TO_SET_second(int second){
        this->second=second;
    }
    void TO_SET_third(int third[]){
    	for(int i=0;i<3;i++){
        	this->third[i]=third[i];
        }
    }
    
    
    int TO_GET_first(){
        return this->second;
    }
    int TO_GET_second(){
        return this->second;
    }
    int TO_GET_third(){
        return this->third[3];
    }
    
    int operator+(int temp){
        int result=this->first+this->second+temp;
        for(int i=0;i<3;i++){
        	result+=this->third[i];
		}
        return result;
    }
    int operator-(int temp){
        int result=this->first-this->second-temp;
        for(int i=0;i<3;i++){
        	result-=this->third[i];
		}
        return result;
    }
    bool operator==(const Student & kk){
        if (this->first == kk.first && this->second == kk.second)
            return 1;
        else
            return 0;
    }
    void operator=(const Student &B){
        this->second=B.second;
        this->first=B.first;
        for(int i=0;i<3;i++){
        	this->third[i]=B.third[i];
		}
    }
};
int main(){
    Student A;
    Student A1;
    cout<<A1+10<<endl;
    A1.print();
    cout<<A1-10<<endl;
    A1.print();
    cout<<(A==A1)<<endl;
    
    return 0;
}
