﻿
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
S get_value(S left_border, S right_border) {
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
	return new_truba;
}

cs create_cs() {
	cs new_cs;
	cout << "Введите имя:";
	cin.ignore(256, '\n');
	getline(cin, new_cs.name, '\n');
	cout << "Введите число цехов: " << endl;
	new_cs.number_work = get_value(1, 100);
	cout << "Введите число работающих цехов: " << endl;
	new_cs.number_inwork = get_value(0, new_cs.number_work);
	cout << "Введите эффективность: " << endl;
	new_cs.effect = get_value(0, 100);
	new_cs.id = 1;
	return new_cs;
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
	cout << "Имя:" << c.name << endl;
	cout << "Кол-во цехов: " << c.number_work << endl;
	cout << "Кол-во рабочих цехов: " << c.number_inwork << endl;
	cout << "Эффективность: " << c.effect << endl;
}


void change_status(bool& status) {                            //Изменение статуса трубы "в ремонте"
	status = !status;
}


void save_to_fileTCS(truba t, cs c)                       //Сохранение в файл
{                         
	ofstream fout;
	fout.open("Data.txt", ios::out);
	if (fout.is_open()) {
		fout << t.id << endl << t.diameter << endl << t.length << endl << t.repair << endl;
		fout << c.id << endl << c.name << endl << c.number_work << endl << c.number_inwork << endl << c.effect;
		fout.close();
	}
}




truba load_from_fileT(ifstream& fin) 
{
	truba t;
	fin >> t.id >> t.diameter >> t.length >> t.repair;
	return t;
}

cs load_from_fileC(ifstream& fin)
{
	cs c;
	fin >> c.id;
	fin.ignore(256, '\n');
	getline(fin, c.name);
	fin >> c.number_work >> c.number_inwork >> c.effect;
	return c;
}

void load_from_fileTCS(truba& t, cs& c) 
{
	ifstream fin;
	fin.open("Data.txt", ios::in);
	if (fin.is_open()) {
		t = load_from_fileT(fin);
		c = load_from_fileC(fin);
		fin.close();
	}
}


void stop_work(cs& c) 
{
	if (c.number_inwork > 0) {
		c.number_inwork--;
	}
	else {
		cout << "Число работающих цехов: 0" << endl;
	}
}

void continue_work(cs& c) 
{
	if (c.number_inwork < c.number_work) 
	{
		c.number_inwork++;
	}
	else 
	{
		cout << "Все цеха работают" << endl;
	}
}



void PrintMenu() 
{
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
			if (t.id == 1) {
				change_status(t.repair);
			}
			else {
				cout << "Трубы не существет" << endl;
			}
			break;
		case 5:
			load_from_fileTCS(t, c);
			break;
		case 6:
			save_to_fileTCS(t, c);
			break;
		case 7:
			if (c.id == 1) {
				cout << "\t Выберите действие:" << endl;
				cout << "\t 1. Начать" << endl;
				cout << "\t 2. Остановить" << endl;
				i = get_value(1, 2);
				switch (i)
				{
				case 1:
					continue_work(c);
					break;
				case 2:
					stop_work(c);
					break;
				default:
					cout << "Выбирите действие " << endl;
					break;
				}
			}
			else {
				cout << "Компрессорной станции не существует" << endl;
			}

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

