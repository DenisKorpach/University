#include <iostream>
using namespace std;
struct Node{
    string val;
    Node* next;

    Node(string _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(string _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }
    
    Node* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
    
    void print() {
        if (is_empty()) return;
        Node* p = first;
        while (p){
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    int doubl_check;

};

void doubl_check(int n,int m,list l_listM1,list l_listM2){
    list l_listM;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(l_listM1[i]->val==l_listM2[j]->val){
                        count+=1;
                        l_listM.push_back(l_listM1[i]->val);
                        }
                }
        }
        l_listM.print();
}
   
int main(){
    list l_listM1,l_listM2;
    cout<<"input how much element in list 1: "<<endl;
    string element;int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>element;
        l_listM1.push_back(element);
    }
    cout<<"input how much element in list 2: "<<endl;
    int m; cin>>m;
    for(int i=0;i<m;i++){
        cin>>element;
        l_listM2.push_back(element);
    }
    cout<<"output list1: ";l_listM1.print();
    cout<<"output list2: ";l_listM2.print();
    cout<<"list M from list M1 and M2:  ";
    doubl_check(n,m,l_listM1,l_listM2);
    
    return 0;
}