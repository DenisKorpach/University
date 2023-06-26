#include <iostream>
#include "../graph_LIB.hh"

int main()
{
	convert c;
	std::string file_path = "inf.txt";
	std::vector<int> nodes = c.reading_file(file_path);
	int max_node = c.count_of_nodes(nodes);
	int n = nodes.size() / 2;
	
	std::cout<<n<<" "<<max_node<<std::endl;

	std::vector<std::vector<int>> adjacencyMatrix = c.adjancy(nodes, max_node);
	std::vector<std::vector<int>> incidenceMatrix = c.incidence(nodes, max_node);

	std::cout<<"матрица смежности: "<<std::endl;
	for (int i = 0; i < max_node; i++)
	{
		for (int j = 0; j < max_node; j++)
		{
			std::cout << adjacencyMatrix[i][j]<<" ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout<<"матрица инциндентности: "<<std::endl;
	for (int i = 0; i < max_node; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << incidenceMatrix[i][j]<<" ";
		}
		std::cout << std::endl;
	}

return 0;
}