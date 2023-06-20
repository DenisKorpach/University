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
    void remove_first() {
    if (is_empty()) return;
    Node* p = first;
    first = p->next;
    delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }
    void remove(string _val) {
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
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
};
void doubl_check(int n,int m,list l_list1,list l_list2){
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(l_list1[i]->val==l_list2[j]->val){
                        count+=1;
                        }
                }
        }
        if(count==0){
                cout<<"list1 is not in list2"<<endl;
        }
        else{cout<<"list1 includes in luist2 count : "<<count<<endl;}
}
int main(){
    list l_list1,l_list2;
    cout<<"input how much element in list 1: "<<endl;
    string element;int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>element;
        l_list1.push_back(element);
    }

    cout<<"input how much element in list 2: "<<endl;
    int m; cin>>m;
    for(int i=0;i<m;i++){
        cin>>element;
        l_list2.push_back(element);
    }
    doubl_check(n,m,l_list1,l_list2);
    cout<<endl;
    cout<<"output our list1: "; l_list1.print();
    cout<<"delete all elemens but not first: ";
    for(int i=1,j=1;i<n;i++){
        l_list1.remove(l_list1[j]->val);
    }
    l_list1.print();
    return 0;
}
