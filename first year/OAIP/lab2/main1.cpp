#include<iostream>
using namespace std;
int tabs=0,cnt, val;
struct Branch{
  int Data;
  Branch *LeftBranch;
  Branch *RightBranch;
};
void Add(int aData, Branch *&aBranch){//создание бинарного дерева
	if (!aBranch){                   //и запонение его веток
		aBranch = new Branch;
		aBranch->Data = aData;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	if (aBranch->Data>aData){
		Add(aData, aBranch->RightBranch);
	}
	else {
		Add(aData, aBranch->LeftBranch);
	}
}
void print(Branch *aBranch){//вывод бинарного дерева
	if (!aBranch) return;
	tabs++;

    print(aBranch->LeftBranch);
	
	for (int i = 0; i < tabs; i++){
		cout<<" | ";
	}
	cout << aBranch->Data <<endl;
	
    print(aBranch->RightBranch);
	tabs--;
	return;
}
bool findDouble(Branch *aBranch){
    if(aBranch){
        findDouble(aBranch->LeftBranch);
        if(cnt && (aBranch->Data == val)){
            ++cnt;
            if((cnt > 1) && (0 == aBranch->RightBranch)){
                for(int i = 0; i < cnt; ++i){
                    return true;
                }
                cnt = 1;
            }
        }
        else{
            if(cnt > 1){
                for(int i = 0; i < cnt; ++i){
                    return true;
                }
            }
            val = aBranch->Data;
            cnt = 1;
        }
        findDouble(aBranch->RightBranch);
    }
}
void FreeTree(Branch *aBranch){//высвобождение памяти от бин дерева
	if (!aBranch) return;
 	FreeTree(aBranch->LeftBranch);
 	FreeTree(aBranch->RightBranch);
 	delete aBranch;
 	return;
}
int main(){
	Branch *Root = 0;
	int n, *even_number;
	int cifr;
	bool double_element=false;
    cout<<"input count cifr: ";cin >>n;
	for (int i = 0;i< n; i++){
        cin>>cifr;
		Add(cifr, Root);
	}
	print(Root);
	double_element=findDouble(Root);
	if(double_element==true){
		cout<<"bin tree have double element"<<endl;
	}
	else{cout<<"bin tree not to have double element"<<endl;}
	FreeTree(Root);

	return 0;
}
