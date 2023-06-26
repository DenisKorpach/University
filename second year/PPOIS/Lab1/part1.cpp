#include <iostream>

using namespace std;

class Product
{
	private:
		int arr[3];
		string name;
		int weight;
	public:
		Product(string value_name,int value_weight, int arr[])// конструктор с параметрами
		{
			this->name = value_name;
			this->weight = value_weight;
			for(int i=0; i<3; i++)
			{
				this->arr[i]=arr[i];
			}
		}
		Product()//конструктор по умолчанию
		{
			this->name="flour";
			this->weight=145;
			for(int i=0; i<3; i++)
			{
				this->arr[i]=i;
			}
		}
		Product(Product &pp)//конструктор копироваания
		{
			this->name=pp.name;
			this->weight=pp.weight;
			for(int i=0; i<3; i++)
			{
				this->arr[i]=pp.arr[i];
			}
		}
		int *get_arr(){
        	
			return this->arr;
    	}
		int get_weight()
		{
			return this->weight;
		}
		string get_name()
		{
			return this->name;
		}


		void set_arr(int arr1[]){
    		for(int i=0;i<3;i++){
        		this->arr[i]=arr1[i];
        	}
    	}
		void set_weight(int value_weight)
		{
			this->weight=value_weight;
		}
		void set_name(string value_name)
		{
			this->name=value_name;
		}

		int operator+(int dog)//перегрузка оператора +
		{
			return this->weight + dog;
		}

		void operator=(const Product &k)//перегрузка оператора =
		{
			this->name=k.name;
			this->weight=k.weight;
			for(int i=0; i<3; i++)
			{
				this->arr[i]=k.arr[i];
			}
		}
		bool operator==(const Product &kk)//перегрузка оператора  ==
		{
			return this->name==kk.name;
		}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	Product a;
	Product a1;//создали второй объект класса для проверки перегрузки ==
	cout<<"вывод для проверки геттера: "<<a.get_weight()<<endl;
	a.set_weight(200);//изменение веса муки с помощью сеттера
	cout<<"вывод для проверки геттера после присваивания нового значения через сеттер: "<<a.get_weight()<<endl;
	cout<<"проверка перегрузки + "<<a+100<<endl;
	
	int ar[3]={4,5,7};
	a.set_arr(ar);

	cout<<"проверка работы геттера для массива ";
	
	int *ptr = a.get_arr();
	for (int  i = 0; i < 3; i++)
	{
		cout << *(ptr+i)<<" ";
	}
	cout<<endl;
	


	if(a == a1){//проверка перегрузки == т.к. функция имеет bool она вернёт 1 или 0 и мы узнаем
		cout<<"оператор == перегружен"<<endl;//перегрузили ли мы ==
	}
	
	cout<<"изначальное имя товара "<<a.get_name()<<endl;
	a1.set_name("working");//изменяем имя второго объекта класса с помощью сеттера
	a=a1;//присваиваем первому объекту класса имя второго объекта класса с помощью перегруженного =
	cout<<"вывод для проверки перегрузки = "<<a.get_name()<<endl;//выводим новое имя первого объекта класса
	
	return 0;
}


