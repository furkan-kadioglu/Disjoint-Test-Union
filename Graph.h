// C++ Implementation of Kosaraju's algorithm to print all SCCs 
#include <iostream> 
#include <list> 
#include <stack>
#include <vector> 
using namespace std; 

class Graph 
{ 
	int V; 
	vector<int> *adjacency;

    Graph transpose(); 
    
	void DFSOne(int source); 

	void DFSTwo(int v); 
public: 

	Graph(int V); 

	void addEdge(int source, int sink); 
 
	void SCC(ofstream &outputFile); 

	
}; 
