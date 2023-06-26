#include <iostream>
#include <iomanip>
#include "../graph_LIB.hh"

int main(){
	convert c;
	std::string file_path = "inf5.txt";
	std::string file_weight = "weight5.txt";
	std::vector<int> nodes = c.reading_file(file_path);
	std::vector<int> weight = c.reading_file(file_weight);
	int max_node = c.count_of_nodes(nodes);
	std::vector<std::vector<int>> adjacencyMatrix = c.adjancy(nodes, max_node);
    

    alg calculation;                                                                                //если флаг равен 1 то матрица смежности весов сделана для алгоритма прима, Крускала и Дейкстры
    std::vector<std::vector<int>> adjancy_prim=c.adjancy_for_deikstra_floid(nodes, weight, max_node,1);//если флаг равен 0 то матрица смежности весов сделана для алгоритма Флойда
    std::cout<<std::endl<<"algorithm prim"<<std::endl<<"vertex"<<"\t"<<"distance"<<std::endl;
    calculation.prima(adjancy_prim);//выводится вес ребра и вершины к которой оно принадлежит
    std::cout<<std::endl;



    std::cout<<"algorith kruskal"<<std::endl;
    std::vector<std::vector<int>> adjancy_kruskal=c.adjancy_for_deikstra_floid(nodes, weight, max_node,1);
    std::vector<std::vector<int>> distance_kryskal = calculation.kruskal(adjancy_kruskal);
    //изменение получившейся матрицы смежности по арлгоритму крускала в массив вершин по которым прошелся алгоритм
    std::vector<int> vertices;
    for(int i=0;i<distance_kryskal.size();i++){
        for(int j=0;j<distance_kryskal.size();j++){
            if(i<j){
            if(distance_kryskal[i][j]!=0){
                vertices.push_back(i+1);
                vertices.push_back(j+1);
            }}
        }
    }
    for(int i=0;i<vertices.size();i++){
        if(i%2==0){
            std::cout<<"("<<vertices[i]<<",";
        }else{
            std::cout<<vertices[i]<<"), ";
        }
    }
    return 0;
}