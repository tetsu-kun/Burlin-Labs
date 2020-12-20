#pragma once
#include "Truba.h"
#include "CS.h"
#include <unordered_set>
#include <unordered_map>
#include <vector>


using namespace std;

class GTN
{
	unordered_set<int> edges; 
	unordered_set<int> vertex; 

	unordered_map<int, int> IdIndexCS;
	unordered_map<int, int> IdIndexTruba;

	vector<vector<int>> AMatrix;
	vector<vector<int>> IMatrix;
	bool change;

public:
	int GetCSIndex(int) const;

	void AddCS(const unordered_map<int, CS>&, int);

	void AddTruba(const unordered_map<int, Truba>&, int);

	void CreateAMatrix(unordered_map<int, CS>&, unordered_map<int, Truba>&);

	void ConnectEdges(unordered_map<int, CS>&, unordered_map<int, Truba>&);

	void DeleteEdge(int, unordered_map<int, Truba>&);

	void DeleteVertex(int);

	void TopologicalSort(int, vector<int>&, bool&, vector<int>&);
	
};
