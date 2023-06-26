#include <iostream>
#include <iomanip>
#include "../graph_LIB.hh"

int main(){
	convert c;
	std::string file_path = "inf3.txt";
	std::string file_weight = "weight.txt";
	std::vector<int> nodes = c.reading_file(file_path);
	std::vector<int> weight = c.reading_file(file_weight);
	
	int max_node = c.count_of_nodes(nodes);
	std::vector<std::vector<int>> adjacencyMatrix = c.adjancy(nodes, max_node);
    int n = nodes.size()/2;


	std::cout<<"Adjacency matrix with weight: "<<std::endl;
	std::vector<std::vector<int>> adjancy_deikstra=c.adjancy_for_deikstra_floid(nodes, weight, max_node,1);//если флаг равен 1 то матрица смежности весов сделана для алгоритма прима, Крускала и Дейкстры
																										  //иначе для алгоритма Флойда
	for(int i=0;i<adjancy_deikstra.size();i++){															
		for(int j=0;j<adjancy_deikstra.size();j++){
			std::cout<<adjancy_deikstra[i][j]<<" ";
		}std::cout<<std::endl;
	}


	alg calculation;
	std::cout<<std::endl<<"algorithm deikstra"<<std::endl<<"vertex"<<"\t"<<"distance"<<std::endl;
	std::vector<int> distance = calculation.deikstra(adjancy_deikstra, 0);
	for(int i=0;i<distance.size();i++){
		std::cout<<i+1<<"\t"<<distance[i]<<std::endl;
	}std::cout<<std::endl;


	std::cout<<std::endl<<"algorithm floyda"<<std::endl<<"vertex"<<"\t"<<"distance"<<std::endl;
	std::vector<std::vector<int>> adjancy_floyd=c.adjancy_for_deikstra_floid(nodes, weight, max_node,0);
	std::vector<std::vector<int>> distance_floid = calculation.floyd(adjancy_floyd);
		for(int j=0;j<distance_floid.size();j++){
			std::cout<<j+1<<"\t"<<distance_floid[0][j]<<std::endl;
		}std::cout<<std::endl;
	
    return 0;
}