#include "GTN.h"

int GTN::GetCSIndex(int id) const
{
	return IdIndexCS.find(id)->second;
}

void GTN::AddCS(const unordered_map<int, CS>& map, int id)
{
	edges.insert(map.find(id)->first);
	IdIndexCS.insert({ id, edges.size() - 1 });
	cout << "Компрессорная станция добавлена: " << IdIndexCS.find(id)->first << "Индекс: " << IdIndexCS.find(id)->second << endl;
	change = true;
}

void GTN::AddTruba(const unordered_map<int, Truba>& map, int id)
{
	vertex.insert(map.find(id)->first);
	IdIndexTruba.insert({ id, vertex.size() - 1 });
	cout << "Труба добавлена: " << IdIndexTruba.find(id)->first << "Индекс: " << IdIndexTruba.find(id)->second << endl;
	change = true;
}

void GTN::CreateAMatrix(unordered_map<int, CS>& mapCS, unordered_map<int, Truba>& mapTruba)
{

	int n = edges.size();
	if (change) {
		AMatrix.clear();
		AMatrix.resize(n);
		for (int i = 0; i < n; i++) {
			AMatrix[i].resize(n);
			change = false;
		}
	}
	for (auto itr = mapTruba.begin(); itr != mapTruba.end(); itr++) {
		if (itr->second.GetStart() != -1) {
			AMatrix[GetCSIndex(itr->second.GetStart())][GetCSIndex(itr->second.GetEnd())] = 1;
		}
	}
	for (int i = 0; i < n; i++) {  
		for (int j = 0; j < n; j++) {
			cout << AMatrix[i][j] << " ";
		}
		cout << endl;
	}
}
}

void GTN::ConnectEdges(unordered_map<int, CS>&, unordered_map<int, Truba>&)
{
}

void GTN::DeleteEdge(int, unordered_map<int, Truba>&)
{
}

void GTN::DeleteVertex(int)
{
}

void GTN::TopologicalSort(int, vector<int>&, bool&, vector<int>&)
{
}
