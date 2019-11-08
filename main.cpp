#include <iostream>
#include <fstream>
#include "Graph.h"
using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3) {
        cout << "Run the code with the following command: ./project2 [input_file] [output_file]" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);

    int numberOfVertex;
    int numberOfEdges;
    int source;
    int sink;

    

    infile >> numberOfVertex;
    
    Graph g(numberOfVertex);
    for (int i=1; i<=numberOfVertex; i++){
        source = i;
        infile >> numberOfEdges;
        for(int j=0; j<numberOfEdges; j++){
            infile >> sink;
            g.addEdge(source,sink);
        }
    }
    infile.close();
    g.SCC(outfile);
    outfile.close();   


}