#include<iostream>
#include<vector>
#include "../graph_LIB.hh"
using namespace std;
int main(){
    convert c;
	std::string file_path = "inf2.txt";
	std::vector<int> nodes = c.reading_file(file_path);
	
	int max_node = c.count_of_nodes(nodes);
	std::vector<std::vector<int>> adjance_matrix_ambiguity = c.adjancy(nodes, max_node);
    int n = nodes.size()/2;

    
    alg calculation;
    std::cout<<std::endl<<"points of articulation: ";
    std::vector<int> articulation_points = calculation.points_of_articulation(adjance_matrix_ambiguity, max_node);//поиск точки сочленения
    for(int i=0;i<articulation_points.size();i++){
        std::cout<<articulation_points[i]<<" ";
    }std::cout<<std::endl;
    


    std::cout<<std::endl<<"bridges: "<<std::endl;
    int m = 2;
	std::vector<std::vector<int>> array_edge(n, std::vector<int>(m));
    for (int i = 0, j = 0; i < n, j < 2 * n; i++, j+=2){
	    	array_edge[i][0] = nodes[j];
	    }
	for (int i = 0, j = 1; i < n, j < 2 * n; i++, j+=2){
	    	array_edge[i][1] = nodes[j];
	}
    std::vector<std::vector<int>> Graph_edges(max_node + 1, std::vector<int>());  // your Graph
    for (int i = 0; i < n; ++i) {  // read edges with weigths
        Graph_edges[array_edge[i][0]].push_back(array_edge[i][1]);
        Graph_edges[array_edge[i][1]].push_back(array_edge[i][0]);
        
    }
    calculation.DFS_for_bridges(max_node, Graph_edges);//поиск мостов



    std::cout<<"components double connected: "<<std::endl;
    int size_articulation_points = articulation_points.size();
    std::vector<std::vector<int>> number_subgraphs_in_graph=adjance_matrix_ambiguity;
    int double_connected_components = calculation.component_double_conected(adjance_matrix_ambiguity, articulation_points,max_node);//поиск компоненты двусвязности
    std::cout<<double_connected_components<<std::endl;
   


    return 0;
}