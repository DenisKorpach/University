#include <iostream>

#include "../graph_LIB.hh"

int main(){
	convert c;
	std::string file_path = "inf1.txt";
	std::vector<int> nodes = c.reading_file(file_path);
	
	int max_node = c.count_of_nodes(nodes);
	std::vector<std::vector<int>> oriented_adjacencyMatrix = c.oriented_adjancy(nodes, max_node);
    int n = nodes.size()/2;

    for(int i=0;i<oriented_adjacencyMatrix.size();i++){
        for(int j=0;j<oriented_adjacencyMatrix.size();j++){
            std::cout<<oriented_adjacencyMatrix[i][j]<<" ";
        }std::cout<<std::endl;
    }

    alg calculation;
    std::cout<<std::endl<<"algorithm kosaraju"<<std::endl;
    std::vector<std::vector<int>> component = calculation.kosaraju(oriented_adjacencyMatrix);
   

    return 0;
}