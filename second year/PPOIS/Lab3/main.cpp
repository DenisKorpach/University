#include <iostream>
#include<string>
#include <conio.h>
using namespace std;
class Reference {
private:
	string name;
	string not_my_name;
	string& my_name = name;
	string& his_name = not_my_name;
public:
	Reference() {
		my_name = "Denis";
		his_name = "Sined";
	}
	Reference(Reference& obj) {
		this->my_name = obj.my_name;
		this->his_name = obj.his_name;
	}
	Reference(string& _fname, string& _sname) {
		his_name = _sname;
		my_name = _fname;
	}
	~Reference() {
		//cout<<"первый класс удалён "<<endl;
	}
	string& GetMyName() {
		return my_name;
	}
	string& GetNotMyName() {
		return not_my_name;
	}
	void SetMyName(string& obj) {
		this->my_name = obj;
	}
	void SetNotMyName(string& obj) {
		this->not_my_name = obj;
	}
	void Show() {
		cout << my_name << " - My name\n";
		cout << his_name << " -Not my name\n";
	}
	void Show(Reference& names) {
		names.Show();
		this->Show();
	}
	Reference operator=(Reference& obj) {
		this->my_name = obj.my_name;
		this->his_name = obj.not_my_name;
		return *this;
	}
};
class Book {
private:
	int length;
	string name_;
	int& size = length;
	string& name = name_;
public:
	Book() {
		size = 0;
		name = "Harry potter";
	}
	Book(int& size, string& name) {
		this->name = name;
		this->size = size;
	}
	Book(Book& obj) {
		this->name = obj.name;
		this->size = obj.size;
	}
	~Book(){
		//cout<<"второй класс удалён "<<endl;
	}
	string& GetName() {
		return this->name;
	}
	int& GetSize() {
		return this->size;
	}
	void SetName(string& _name) {
		this->name = _name;
	}
	void SetSize(int& _size) {
		this->size = _size;
	}
	void Show() {
		cout << "name book: " << this->name << endl;
		cout << "number pages of book: " << this->size << endl;
	}
	void foon1(int a){  
        a = 0;  
    }  
    void foon2(int &a){  
        a = 0;  
    }  
    void foon3(int *a){  
        *a = 0;  
    }  
};
class Person {
private:
	string color_of_clothes;
	int height;
	int& heh = height;
	string& color = color_of_clothes;
public:
	Person() {
		heh = 0;
		color = "black";
	}
	Person(int& height, string& _color) {
		this->heh = height;
		this->color = _color;
	}
	Person(Person& obj) {
		this->heh = obj.heh;
		this->color = obj.color;
	}
	~Person(){
		//cout<<"третий класс удалён "<<endl;
	}
	string& GET_color() {
		return this->color;
	}
	int& GET_height() {
		return this->heh;
	}
	void GET_color(string& _color) {
		this->color = _color;
	}
	void GET_height(int& _height) {
		this->heh = _height;
	}
	Person operator=(Person& obj) {
		this->heh = obj.heh;
		this->color = obj.color;
		return*this;
	}
	void Show() {
		cout << "clothing color: " << this->color << endl;
		cout << "height: " << this->heh << endl;
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	char choose{ '-' };
	cout << "1)class reference, 2)class book, 3) class person, n - exit\n";
	do {
		choose = _getch();
		switch (choose) {
		case '1': {
			string a{ "Umpa" }, b{ "Lumpa" };
			Reference first, second(a, b), third(second);
			first.Show();
			second.Show();
			third.Show();
			cout << third.GetNotMyName();
			cout << endl << "--------------------------------------" << endl;
			break;
		}
		case '2': {
			int size=584;
			string name = "Lord of the Rings";
			Book war_and_peace(size, name), fathers_and_sons, book(war_and_peace);
			war_and_peace.Show();
			fathers_and_sons.Show();
			book.Show();
			cout << "name book: " << war_and_peace.GetName()<<endl;
			war_and_peace.foon1(size);cout<<"передача по значению: "<<size<<endl;size=584;
			war_and_peace.foon2(size);cout<<"передача по ссылке: "<<size<<endl;size=584;
			war_and_peace.foon3(&size);cout<<"передача по указателю: "<<size<<endl;

			cout << endl << "--------------------------------------" << endl;
			break;
		}
		case '3': {
			int height{ 181 };
			string color{ "red" };
			Person letchenya(height, color), egor, small_letchenya(letchenya);
			letchenya.Show();
			egor.Show();
			small_letchenya.Show();
			cout << "color jacket: " << small_letchenya.GET_color();
			cout << endl << "--------------------------------------" << endl;
			break;
		}
		default: {
			cout << "Error\n";
			break;
		}
		}
	} while (choose != 'n');
	system("pause");
	return 0;
}
