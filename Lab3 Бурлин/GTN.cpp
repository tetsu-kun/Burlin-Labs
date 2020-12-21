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


void GTN::ConnectEdges(unordered_map<int, CS>& mapCS, unordered_map<int, Truba>& mapTruba)
{
	cout << "Введите начало компрессорной станции: " << endl;
	int CSId1 = get_value(0, CS::GetMaxid());
	cout << "Введите трубу" << endl;
	int pipeId = get_value(0, Truba::GetMaxid()); 
	cout << "Введите конец компрессорной станции: " << endl;
	int CSId2 = get_value(0, CS::GetMaxid());
	mapTruba.find(pipeId)->second.SetStart(CSId1);
	mapTruba.find(pipeId)->second.SetEnd(CSId2);
	cout << "Компрессорная станция: " << CSId1 << "была соединена с компрессорной станцией: " << CSId2 << "по трубе с id: " << pipeId << endl;
	change = true;
}

void GTN::DeleteEdge(int id, unordered_map<int, Truba>& mapTruba)
{
	change = true;
	edges.erase(id);
	IdIndexCS.erase(id);

	for (auto iter = mapTruba.begin(); iter != mapTruba.end(); iter++) {
		if (iter->second.GetStart() == id || iter->second.GetEnd() == id) {
			DeleteVertex(iter->first);
		}
	}
}

void GTN::DeleteVertex(int id)
{
	change = true;
	vertex.erase(vertex.find(id));
	IdIndexTruba.erase(id);
}

void GTN::TopologicalSort(int index, vector<int>& colors, bool& cycl, vector<int>& TopSortedVector)
{
	if (colors[index] == 2)
		return;
	if (cycl)
		return;
	if (colors[index] == 1) {
		cycl = true;
		return;
	}
	colors[index] = 1;
	for (int i = 0; i < edges.size(); i++) {
		if (AMatrix[index][i] == 1) {
			int AdjacencyEdge = i;
			TopologicalSort(AdjacencyEdge, colors, cycl, TopSortedVector);
			if (cycl)
				return;
		}

	}
	colors[index] = 2;
	TopSortedVector.push_back(index);
}

void GTN::TopSort()
{
	vector<int> colors;
	colors.resize(edges.size());
	vector<int> TopSortedVector;
	bool cycl = false;
	for (int i = 0; i < edges.size(); i++) {
		TopologicalSort(i, colors, cycl, TopSortedVector);
	}
	if (cycl) {
		cout << "Есть цикл" << endl;
	}
	else {
		cout << "Топологическая сортировка: " << endl;
		for (int i = 0; i < TopSortedVector.size(); i++) {
			cout << TopSortedVector[i] << " ";            
		}
		cout << endl;
	}
}
