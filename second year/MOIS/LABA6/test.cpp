#include<iostream>
#include<vector>
#include<iomanip>
#include "../graph_LIB.hh"
using namespace std;

void add_column_row(vector<vector<int>> &matrix, int size){
    for(int i=0;i<size;i++){
        matrix[i].push_back(0);
    }
    matrix.push_back(vector<int>(size+1, 0));
}
void delete_row_column(vector<vector<int>> &matrix, int size, int row, int column){
    for(int i=0;i<size;i++){
        matrix[i].erase(matrix[i].begin()+column);
    }
    matrix.erase(matrix.begin()+row);
}

int main(){
    convert c;
	std::string file_path = "inf2.txt";
	std::vector<int> nodes = c.reading_file(file_path);
	
	int max_node = c.count_of_nodes(nodes);
	std::vector<std::vector<int>> adjance_matrix_ambiguity = c.adjancy(nodes, max_node);
    int n = nodes.size()/2;

    
    alg calculation;
    std::cout<<std::endl<<"points of articulation: ";
    std::vector<int> articulation_points = calculation.points_of_articulation(adjance_matrix_ambiguity, max_node);
    
        int size_articulation_points = articulation_points.size();
        std::vector<std::vector<int>> number_subgraphs_in_graph=adjance_matrix_ambiguity;
        int new_vertex = max_node-1;
        for(int k=0;k<size_articulation_points;k++){
                for(int j=0;j<adjance_matrix_ambiguity.size();j++){
                    if(number_subgraphs_in_graph[articulation_points[k]-1][j] == 1){
                        new_vertex++;
                        number_subgraphs_in_graph[articulation_points[k]-1][j] = 0;
                        number_subgraphs_in_graph[j][articulation_points[k]-1] = 0;
                        add_column_row(number_subgraphs_in_graph, new_vertex);
                        number_subgraphs_in_graph[new_vertex][j] = 1;
                        number_subgraphs_in_graph[j][new_vertex] = 1;
                        
                    }
                }
            }


        int del=1;
        for(int i=0;i<articulation_points.size();i++){
            delete_row_column(number_subgraphs_in_graph, number_subgraphs_in_graph.size(), articulation_points[i]-del, articulation_points[i]-del);
            del++;
        }
        

        int count_component = calculation.conCompDFS(number_subgraphs_in_graph);
        std::cout<<std::endl<<"count_component: "<<count_component<<std::endl;


return 0;
}

