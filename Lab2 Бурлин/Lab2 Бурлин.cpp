#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Truba.h"
#include "CS.h"
#include "utils.h"
using namespace std;

void save_to_file(const unordered_map<int, Truba>& t, const unordered_map<int, CS>& c) {
	ofstream fout;
	string filename;
	cout << "Введите название файла: " << std::endl;
	cin.ignore(256, '\n');
	getline(cin, filename, '\n');
	fout.open(filename, ios::out);
	if (fout.is_open()) {
		fout << t.size() << endl << c.size() << endl;
		for (const auto& it : t)
		{
			fout << it.second;
		}
		for (const auto& it : c)
		{
			fout << it.second;
		}
		fout.close();
	}
}

void load_from_file(unordered_map <int, Truba>& t, unordered_map <int, CS>& c) {
	ifstream fin;
	int countT, countC;
	string filename;
	cout << "Введите название файла: " << std::endl;
	cin.ignore(256, '\n');
	getline(cin, filename, '\n');
	fin.open(filename, ios::in);
	if (fin.is_open()) {
		fin >> countT >> countC;
		t.reserve(countT);
		c.reserve(countC);
		for (int i = 0; i < countT; i++)
		{
			Truba LoadedTruba;
			fin >> LoadedTruba;
		    t.insert({ LoadedTruba.Getid(),LoadedTruba });
		}
		for (int i = 0; i < countC; i++)
		{
			CS LoadedCS;
			fin >> LoadedCS;
			c.insert({ LoadedCS.Getid(), LoadedCS });
		}
		fin.close();
	}
}




template<typename T>
bool del(unordered_map<int, T>& map, int id) {
	return map.erase(id);
}

template<typename T>
using FilterT = bool(*)(const Truba & t, T param);

bool CheckByName(const Truba& t, string param) {
	return t.GetName() == param;
}
bool CheckByStatus(const Truba& t, bool param) {
	return t.GetStatus() == param;
}

template <typename T>
vector<int> FindTrubaByFilter(const unordered_map<int, Truba>& map, FilterT<T> f, T param)
	{
	vector<int> res;
	for (const auto& it : map) {
		if (f(it.second, param)) {
			res.push_back(it.first);
		}
	}
	return res;
}

template<typename T>
using FilterC = bool(*)(const CS& c, T param);

bool CheckByName(const CS& c, string param) {
	return c.GetName() == param;
}
bool CheckByPercent(const CS& c, double param) {
	return (100.0 * (c.GetWork() - c.GetInWork()) / c.GetWork() >= param);
}

template <typename T>
vector<int> FindCSByFilter(const unordered_map<int, CS>& map, FilterC<T> f, T param) {
	vector<int> res;
	for (const auto& it : map) {
		if (f(it.second, param)) {
			res.push_back(it.first);
		}
	}
	return res;
}


void PacketRedactTrub(unordered_map<int, Truba>& map) {
	cout << "\tВыберите какие трубы редактировать: " << endl;
	cout << "\t1. По статусу в ремонте" << endl;
	cout << "\t2. По статусу не в ремонте" << endl;
	cout << "\t3. По выбору пользователя" << endl;
	cout << "\t0. Назад" << endl;
	switch (get_value(0, 3))
	{
	case 1:
	{
		for (int i : FindTrubaByFilter(map, CheckByStatus, true))
			map.find(i)->second.change_status();
		break;
	}
	case 2:
	{
		for (int i : FindTrubaByFilter(map, CheckByStatus, false))
			map.find(i)->second.change_status();
		break;
	}
	case 3: {
		vector<int> vec;
		while (1) {
			cout << "Введите id" << endl;
			vec.push_back(get_value(0, Truba::Maxid));
			cout << "Добавить" << endl << "\t 0. Нет" << endl << "\t 1. Да" << endl;
			if (get_value(0, 1) == 0)
				break;
		}
		for (auto i : vec) {
			if (map.find(i) != map.end())
				map.find(i)->second.change_status();
		}
		break;
	}
	case 0: {
		return;
	}
	}
}


void PrintMenu() {
	cout << "1. Создать трубу" << endl
	     << "2. Создать компрессорную станцию" << endl
	     << "3. Сохранить в файл" << endl
	     << "4. Загрузить из файла" << endl
	     << "5. Вывести информацию" << endl
	     << "6. Изменить статус трубы" << endl
	     << "7. Изменить компрессор" << endl
	     << "8. Множественное редактирование труб" << endl
	     << "9. Удалить трубу" << endl
	     << "10. Удалить компрессорную станцию" << endl
	     << "11. Поиск трубы по имени" << endl
	     << "12. Поиск трубы по статусу" << endl
	     << "13. Поиск компрессорной станции по именми" << endl
	     << "14. Поиск компрессорной станции по прорценту рабочих цехов" << endl
	     << endl
	     << "0. Выход" << endl;
}




int main()
{
	setlocale(LC_ALL, "Russian");

	unordered_map <int, Truba> Trubas;
	unordered_map <int, CS> CSs;

	while (1)
	{
		cout << "Выберите действие:" << endl;
		PrintMenu();
		switch (get_value(0, 14))
		{
		case 1:
		{
			while (1) 
			{
				Truba t;
				cin >> t;
				Trubas.insert({ t.Getid(), t });
				cout << "Добавить?" << endl << "\t 0. Нет" << endl << "\t 1. Да" << endl;
				if (get_value(0, 1) == 0)
					break;
			}
			break;
		}

		case 2:
		{
			while (1)
			{
				CS c;
				cin >> c;
				CSs.insert({ c.Getid(), c });
				cout << "Добавить?" << endl << "\t 0. Нет" << endl << "\t 1. Да" << endl;
				if (get_value(0, 1) == 0)
					break;
			}
			break;
		}

		case 3:
		{
			save_to_file(Trubas, CSs);
			break;
		}

		case 4:
		{
			load_from_file(Trubas, CSs);
			break;
			break;
		}

		case 5:
		{
			break;
		}

		case 6:
		{
			break;
		}

		case 7:
		{
			break;
		}

		case 8:
		{
			break;
		}

		case 9:
		{
			break;
		}

		case 10:
		{
			break;
		}

		case 11:
		{
			break;
		}

		case 12:
		{
			break;
		}

		case 13:
		{
			break;
		}

		case 14:
		{
			break;
		}
		}



	}
}








//
//void PrintMenu()
//{
//	cout << "1. Создать трубу" << endl;
//	cout << "2. Создать компрессорную станцию" << endl;
//	cout << "3. Вывести информацию" << endl;
//	cout << "4. Изменить состояние трубы" << endl;
//	cout << "5. Загрузить из файла" << endl;
//	cout << "6. Сохранить в файл" << endl;
//	cout << "7. Обновить компрессорную станцию" << endl;
//	cout << "0. Выход" << endl;
//}
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//
//	cs c;
//	truba t;
//	int i;
//	while (1) {
//		cout << "Выберите действие:" << endl;
//		PrintMenu();
//		cin >> i;
//		switch (i)
//		{
//		case 1:
//			t = create_truba();
//			break;
//		case 2:
//			c = create_cs();
//			break;
//		case 3:
//			print_truba_info(t);
//			print_cs_info(c);
//			break;
//		case 4:
//			if (t.id == 1) {
//				change_status(t.repair);
//			}
//			else {
//				cout << "Трубы не существет" << endl;
//			}
//			break;
//		case 5:
//			load_from_fileTCS(t, c);
//			break;
//		case 6:
//			save_to_fileTCS(t, c);
//			break;
//		case 7:
//			if (c.id == 1) {
//				cout << "\t Выберите действие:" << endl;
//				cout << "\t 1. Начать" << endl;
//				cout << "\t 2. Остановить" << endl;
//				i = get_value(1, 2);
//				switch (i)
//				{
//				case 1:
//					continue_work(c);
//					break;
//				case 2:
//					stop_work(c);
//					break;
//				default:
//					cout << "Выбирите действие " << endl;
//					break;
//				}
//			}
//			else {
//				cout << "Компрессорной станции не существует" << endl;
//			}
//
//			break;
//		case 0:
//			return 0;
//			break;
//		default:
//			cout << "Выберите действие: " << endl;
//			break;
//		}
//
//	}
//}
//
//*/
