#include <iostream>
#include <vector>
#include <chrono>
#include <unordered_map>
#include "../combinatoric.hh"

using namespace std;

int main() {
    combinatoric algorithm;
    auto t1 = chrono::high_resolution_clock::now();//начало отсчёта времени


    vector<vector<int>> temp_tree1 = algorithm.reading_tree("input_T1.txt");//первое дерево
    vector<vector<int>> tree1 = algorithm.transform_to_tree(temp_tree1);//создание дерева похожего на дерево, без помощи структур))) а не в виде списков рёбер
    cout << "Прямой обход дерева T1: ";
    algorithm.preorderTraversal(tree1, 1);// Прямой обход дерева T1
    cout << endl;

    vector<vector<int>> temp_tree2 = algorithm.reading_tree("input_T2.txt");//второе дерево
    vector<vector<int>> tree2 = algorithm.transform_to_tree(temp_tree2);//создание дерева похожего на дерево, без помощи структур))) а не в виде списков рёбер
    cout << "Прямой обход дерева T2: ";
    algorithm.preorderTraversal(tree2, 1);// Прямой обход дерева T2
    cout << endl<<endl;

    //обратный обход дерева Т1
    vector<bool> visited(tree1.size(), false);//вектор посещённых вершин
    cout<<"обратый обход дерева Т1: ";
    algorithm.postOrder(1, tree1, visited);cout<<endl;


    //обратный обход дерева Т2
    vector<bool> visited2(tree2.size(), false);//вектор посещённых вершин
    cout<<"обратый обход дерева Т2: ";
    algorithm.postOrder(1,tree2,visited2);cout<<endl<<endl;


    int treeHeight1 = algorithm.height(tree1, 1);//высота первого дерева
    int treeHeight2 = algorithm.height(tree2, 1);//высота второго дерева
    cout << "высота дерева Т1: " << treeHeight1 << endl;
    cout << "высота дерева Т2: " << treeHeight2 << endl;

    
    bool is_balanced = true;// Устанавливаем флаг сбалансированности для первого дерева в true
    int height = algorithm.get_balans(1, tree1, is_balanced);
    if (is_balanced) cout << "первое дерево сбалансировано" << endl;
    else  cout << "первое дерево не сбалансировано" << endl;


    is_balanced = true;// Устанавливаем флаг сбалансированности для второго дерева в true
    height = algorithm.get_balans(1, tree2, is_balanced);
    if (is_balanced) cout << "второе дерево сбалансировано" << endl;
    else  cout << "второе дерево не сбалансировано" << endl;


    unordered_map<int, combinatoric::Node*> nodes1;//создание узлов для первого дерева         
    for(int i=0;i<temp_tree1.size();i++){                                                       
        algorithm.addNode(nodes1, temp_tree1[i][0], temp_tree1[i][1]);//добавление узлов в дерево
    }
    combinatoric::Node* T1 = algorithm.createTree(nodes1, 1);//создание дерева
    cout<<"Tree 1: "<<endl;
    algorithm.print(T1);
    cout<<endl;


    unordered_map<int, combinatoric::Node*> nodes2;//создание узлов для второго дерева
    for(int i=0;i<temp_tree2.size();i++){//добавление узлов в дерево
        algorithm.addNode(nodes2, temp_tree2[i][0], temp_tree2[i][1]);
    }
    combinatoric::Node* T2 = algorithm.createTree(nodes2, 1);//создание дерева
    cout << "Tree 2: "<<endl;                                           
    algorithm.print(T2);                                                
    cout << endl;

    algorithm.mergeTrees(T1, T2);//слияние деревьев
    cout << "Merged Tree 1: "<<endl;
    algorithm.print(T1);
    cout << endl;
    

   
    auto t2 = chrono::high_resolution_clock::now();//конец отсчёта времени
    auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();//вычисление времени выполнения
    cout << "Время выполнения: " << duration << " микросекунд" << endl; 
    return 0;
}


































































































/*bool isomorphic = algorithm.isIsomorphic(T1, T2);
    cout << "два дерева " << (isomorphic ? "" : "не ") << "изоморфны" << endl;*/
    //тут костыль, проверка на изоморфность работает в 30% случаев, поэтому лучше из кода это убрать 
    //и не выводить что деревья не изоморфны или изоморфны, а просто сливать их
    //поэтому строчку 90 можно удалить и вместо этого написать следующее
    
    //cout << "приведение к изоморфному виду: "<<endl;
