#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

int find(int element, const vector<int> &list);
void unionOfSets(
	int setOne, 
	int setTwo,
	int currentLadder,
	vector<vector<int>> &set, 
	vector<vector<int>> &qSet,
	vector<int> &item,
	vector<pair<int,int>> &qItem,
	vector<int> &qLadder);

int main(int argc, char* argv[]){
	
	int numOfRow;
	int numOfColumn;
	int numOfQuery;

	ifstream inFile(argv[1]);
	inFile >> numOfRow;
	inFile >> numOfColumn;

	//keeps height of the points
	vector<int> vertex(numOfRow*numOfColumn);
	
	//keeps height differences between two points
	vector<pair<int,pair<int,int>>> edges;
	
	//serves set of vertex
	vector<int> elements(numOfRow*numOfColumn);

	//keeps elements of sets in their index
	vector<vector<int>> sets(numOfRow*numOfColumn);

	

	//reads height of points from input file
	for(int i=0; i<numOfColumn*numOfRow; i++)
	{		
		inFile >> vertex[i];
		elements[i] = i;
		sets[i].push_back(i);
	}


	
	inFile >> numOfQuery;

	//keeps minumum ladder for queries
	vector<int> qLadder(numOfQuery);

	//keeps matches in between query and sets
	vector<pair<int,int>> qElements(numOfQuery);


	//keeps queries of sets in their index
	vector<vector<int>> qSets(numOfColumn*numOfRow);

	int r;
	int c;
	int r2;
	int c2;
	//reads query from input file
	for(int i=0; i<numOfQuery; i++)
	{
	
		inFile >> r;
		inFile >> c;
		r = ((r-1)*numOfColumn) + (c-1);
		r = find(r, elements);

		inFile >> r2;
		inFile >> c2;
		r2 = ((r2-1)*numOfColumn) + (c2-1);
		r2 = find(r2, elements);
		
		qElements[i] = make_pair(r,r2);
		qSets[r].push_back(i);
		qSets[r2].push_back(i);  
	
	}
	inFile.close();


	//calculates edges' values 
	for(int i=0; i<vertex.size(); i++)
	{
		if(((i+1)%numOfColumn != 0)&&(i+1)<vertex.size())
		{	
			edges.push_back(make_pair(abs(vertex[i]-vertex[i+1]),make_pair(i,i+1)));
			//right edge
		}
		if((i+numOfColumn)<vertex.size())
		{	
			edges.push_back(make_pair(abs(vertex[i]-vertex[i+numOfColumn]),make_pair(i,i+numOfColumn)));
			//down edge
			
		}
		
		
	}
	int setOne;
	int setTwo;
	
	sort(edges.begin(),edges.end());

	for(auto i: edges)
	{
		
		setOne = find(i.second.first ,elements);
		setTwo = find(i.second.second ,elements);

		if(setOne!=setTwo)
			unionOfSets(setOne,
			setTwo,
			i.first,
			sets,
			qSets,
			elements,
			qElements,
			qLadder);

		
	}

	ofstream outFile(argv[2]);
	for(auto i: qLadder)
	{
		outFile<<i<<endl;
	}


}


int find(int element, const vector<int> &list)
{
	return list[element];
}

void unionOfSets(
	int setOne,
	int setTwo,
	int currentLadder,
	vector<vector<int>> &set, 
	vector<vector<int>> &qSet,
	vector<int> &item, 
	vector<pair<int,int>> &qItem,
	vector<int> &qLadder)
{
	
	//moving operations on set
	if(set[setOne].size() < set[setTwo].size())
	{
		swap(setOne,setTwo);
	}

	
	while(set[setTwo].size()!=0)
	{	
		int i = set[setTwo].back();
		item[i] = setOne;
		set[setOne].push_back(i);
		set[setTwo].pop_back();
	}
	
	


	
	//moving on querySet
	while(qSet[setTwo].size() != 0)
	{	
		int i = qSet[setTwo].back();
		if(setOne+setTwo == qItem[i].first+qItem[i].second)
		{	
			qLadder[i] = currentLadder;
			qItem[i].first = setOne;
			qItem[i].second = setOne;
		}else
		{	
			if(qItem[i].first == setTwo)
			{
				qItem[i].first = setOne;
				if(qItem[i].second == setTwo)
				{
					qItem[i].second = setOne;
				}
			}else 
			{	
				qItem[i].second = setOne;
			}
			qSet[setOne].push_back(i);
		}
		qSet[setTwo].pop_back();
	}
}
