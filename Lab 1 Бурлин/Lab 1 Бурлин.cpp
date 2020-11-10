
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct truba {       //Стуктура тубы
	int id;
	double length;
	double diameter;
	bool repair;
};

struct cs {         //Структура компрессорной станции
	int id;
	string name;
	int number_work;
	int number_inwork;
	double effect;
};


template <typename S>
S get_value(T left_border, T right_border) {
	S i;
	cin >> i;
	while (cin.fail() || i > right_border || i < left_border) {
		cout << "Введите другое значение" << "(" << left_border << " - " << right_border << ")" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> i;
	}
	return i;
}


truba create_truba() {
	truba new_truba;
	cout << "Введите диаметр: " << endl;
	new_truba.diameter = get_value(1, 3000);
	cout << "Ввелите длинну: " << endl;
	new_truba.length = get_value(1, 10000);
	new_truba.repair = false;
	new_truba.id = 1;
	return new_pipe;
}

cs create_cs() {
	cs new_cs;
	cout << "Введите имя:";
	cin.ignore(256, '\n');
	getline(cin, new_cs.Name, '\n');
	cout << "Введите число цехов: " << endl;
	new_cs.number_workshops = get_value(1, 100);
	cout << "Введите число работающих цехов: " << endl;
	new_cs.number_inwork = get_value(0, new_compressor.number_workshops);
	cout << "Введите эффективность: " << endl;
	new_cs.effect = get_value(0, 100);
	new_cs.id = 1;
	return new_compressor;
}

void print_truba_info(const truba& t)                       //Вывод в консоль информации о трубе
{
	cout << "Диаметр: " << t.diameter << endl;
	cout << "Длина: " << t.length << endl;
	cout << "id: " << t.id << endl;
	cout << (t.repair ? "В ремонте" : "Не в ремонте") << endl;
}
void print_cs_info(const cs& c)                              //Вывод в консоль информации о КС
{
	cout << "имя:" << c.name << endl;
	cout << "кол-во цехов: " << c.number_work << endl;
	cout << "Кол-во рабочих цехов: " << c.number_inwork << endl;
	cout << "Эффективность: " << c.effect << endl;
}


void change_status(bool& status) {                            //Изменение статуса трубы "в ремонте"
	status = !status;
}


void save_to_fileTCS(truba t, cs c) {                         //Сохранение в файл
	ofstream fout;
	fout.open("Data.txt", ios::out);
	if (fout.is_open()) {
		fout << t.id << endl << t.diameter << endl << t.length << endl << t.repair;
		fout << c.id << endl << c.name << endl << c.number_work << endl << c.number_inwork << endl << c.effect;
		fout.close();
	}
}



truba load_from_fileT() {                                   //Загрузка из файла трубы
	ifstream fin;
	fin.open("Data.txt", ios::in);
	truba t;
	if (fin.is_open()) {
		fin >> t.id;
		fin >> t.diameter;
		fin >> t.length;
		fin >> t.repair;
		fin.close();
		return t;
	}
}
cs load_from_fileCS() {                                        //Загрузка из файла КС
	ifstream fin;
	fin.open("Data.txt", ios::in);
	cs c;
	if (fin.is_open()) {
		fin >> c.id;
		fin >> c.name;
		fin >> c.number_work;
		fin >> c.number_inwork;
		fin >> c.effect;
		return c;
		fin.close();
	}
}


void stop_work(cs& c)
{
	c.number_inwork--;
}
void continue_work(cs& c)
{
	c.number_inwork++;
}



void PrintMenu() {
	cout << "1. Создать трубу" << endl;
	cout << "2. Создать компрессорную станцию" << endl;
	cout << "3. Вывести информацию" << endl;
	cout << "4. Изменить состояние трубы" << endl;
	cout << "5. Загрузить из файла" << endl;
	cout << "6. Сохранить в файл" << endl;
	cout << "7. Обновить компрессорную станцию" << endl;
	cout << "0. Выход" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cs c;
	truba t;
	int i;
	while (1) {
		cout << "Выберите действие:" << endl;
		PrintMenu();
		cin >> i;
		switch (i)
		{
		case 1:
			t = create_truba();
			break;
		case 2:
			c = create_cs();
			break;
		case 3:
			print_truba_info(t);
			print_cs_info(c);
			break;
		case 4:
			if (p.id == 1) {
				change_status(t.repair);
			}
			else {
				cout << "Трубы не существет" << endl;
			}
			break;
		case 5:
			t = load_from_fileT();
			c = load_from_fileCS();
			break;
		case 6:
			save_to_fileTCS(t, c);
			break;
		case 7:

			break;
		case 0:
			return 0;
			break;
		default:
			cout << "Выберите действие: " << endl;
			break;
		}

	}
}

