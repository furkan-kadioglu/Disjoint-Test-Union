#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
#include "Graph.h"

vector<int> tempVector;
bool *visited; 
int *label;
int currentLabel;

Graph::Graph(int V)
{
    this->V = V;
    adjacency = new vector<int>[V+1];
    
}


void Graph::addEdge(int source, int sink)
{
    adjacency[source].push_back(sink);
    
}


void Graph::DFSOne(int source)
{   
    visited[source] = true;
    for(auto i: adjacency[source])
    {
        if(!visited[i])
        {
            DFSOne(i);
        }

    }
    tempVector.push_back(source);
}

Graph Graph::transpose()
{

    Graph g(V);
    
    
    for(int i=1; i<=V; i++)
    {
        for(auto iter: adjacency[i])
        {
            g.addEdge(iter, i);
        }
    }
    return g;
}

void Graph::DFSTwo(int source)
{

    visited[source] = true;
    label[source] = currentLabel;
    for(auto i: adjacency[source])
    {
       
        if(!visited[i])
        {
            DFSTwo(i);
        }
    }

}

void Graph::SCC(ofstream &outFile)
{
    visited = new bool[V+1];
    fill(visited, visited+(V+1), false); 
    
    for(int i=1; i<=V; i++)
    {
        if(!visited[i])
        {
            DFSOne(i);
        }
    }

    reverse(tempVector.begin(), tempVector.end());
    
    Graph trans = transpose();

    fill(visited, visited+(V+1), false); 
    currentLabel = 0;
    label = new int[V+1];

    for(auto i: tempVector)
    {
        if(!visited[i])
        {
            ++currentLabel;
            trans.DFSTwo(i);
        }
    }
    
    bool *zeroIndegreeLabel = new bool[currentLabel+1];
    fill(zeroIndegreeLabel, zeroIndegreeLabel+currentLabel+1, true);

    for (int i = 1; i<=V; i++)
    {
        for (auto j: adjacency[i])
        {
            if(label[i] != label[j])
            {
                zeroIndegreeLabel[label[j]] = false;
            }
        }
    }

    vector<int> keys;
    for(int i=1; i<=V; i++)
    {
        if(zeroIndegreeLabel[label[i]])
        {
            zeroIndegreeLabel[label[i]] = false;
            keys.push_back(i);
        }
    }
    outFile << keys.size()<<" ";
    for(auto i: keys)
    {
        outFile<<i<<" ";
    }
    delete[] visited;
    delete[] label;
}
