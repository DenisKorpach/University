#include <iostream>
#include<vector>
#include "../graph_LIB.hh"
using namespace std;
int main()
{
	convert c;
	std::string file_path = "inf.txt";
	std::vector<int> nodes = c.reading_file(file_path);
	int max_node = c.count_of_nodes(nodes);
	std::vector<std::vector<int>> adjacencyMatrix = c.adjancy(nodes, max_node);

    for(auto row : adjacencyMatrix){
        for(auto col : row){
            cout<< col<<" ";
        }cout<<endl;
    }

    queue que;
    alg calculation;
    std::cout<<"hamiltonian cycle: ";
    que = calculation.Hamilton_cycle(adjacencyMatrix);
    std::vector<int> ham_path;
    for(int i=0;i<que.size();i++){
        ham_path.push_back(que[i]);
    }
    for(int i=0;i<ham_path.size();i++){
        if(i==ham_path.size()-1){
            std::cout<<ham_path[i]+1;
        }
        else{
            std::cout<<ham_path[i]+1<<" -> ";
        }
    }

    std::cout<<std::endl<<std::endl<<"check eulerian cycle"<<std::endl;
	file_path = "inf2.txt";
	nodes = c.reading_file(file_path);
    std::cout<<"nodes"<<endl;
    for(int i=0;i<nodes.size();i++){
        std::cout<<nodes[i]<<" ";
    }std::cout<<std::endl;

	max_node = c.count_of_nodes(nodes);
	std::vector<std::vector<int>> adjacencyMatrix2 = c.adjancy(nodes, max_node);

	if (calculation.conCompDFS(adjacencyMatrix2) != 1)//поиск количества компонент связности
                                                      //если больше 1 то граф не связный и не эйлеров
    {
        std::cout << "The graph not coherent";
        exit(0);
    }

    // second requirement
    std::vector<int> degrees(max_node);
    for (int i = 0; i < max_node; i++){//проверка на четность
        for (int j = 0; j < max_node; j++){
            if (adjacencyMatrix2[i][j]){
                degrees[i]++;
            }
        } 
    }
    for(int i=0;i < adjacencyMatrix2.size();i++){//просто вывод матрицы смежности
        for(int j=0;j < adjacencyMatrix2[i].size();j++){
            std::cout<<adjacencyMatrix2[i][j]<<" ";
        }std::cout<<std::endl;
    }std::cout<<std::endl;



	for(int i=0;i<max_node;i++){
		std::cout<<degrees[i]<<" ";
	}std::cout<<std::endl;
	
    for (int i = 0; i < max_node; i++){
        if (degrees[i] % 2 != 0){//проверка на четность
            std::cout << "The graph not Eulerian";
            exit(0);
        }
    }

    std::vector<int> euler_path;
    euler_path = calculation.euler(adjacencyMatrix2);
    std::cout << "The euleran cycle is: ";
    for (int i = 0; i < euler_path.size(); i++){
        if(i == euler_path.size() - 1){
            std::cout << euler_path[i];
        }
        else{
            std::cout << euler_path[i] << " -> ";
        }
        
    }

return 0;
}