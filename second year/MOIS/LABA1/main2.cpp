#include <iostream>
#include "../graph_LIB.hh"

int main(){
	convert c;
	std::string file_path = "inf.txt";
	std::vector<int> nodes = c.reading_file(file_path);
	int max_node = c.count_of_nodes(nodes);
	std::vector<std::vector<int>> adjacencyMatrix = c.adjancy(nodes, max_node);
    int n = nodes.size()/2;


	alg search;
    std::vector<int> visited(max_node);
    int count_BFS;
    count_BFS = search.find_component_with_bfc(adjacencyMatrix);  
    std::cout << "BFS: count_BFS = " << count_BFS << std::endl; 

    int count_DFS;
    count_DFS = search.conCompDFS(adjacencyMatrix);
    std::cout << "DFS: count_DFS = " << count_DFS << std::endl;
    

    
    return 0;
}
