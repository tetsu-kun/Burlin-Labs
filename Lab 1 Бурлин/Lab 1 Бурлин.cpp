
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

bool check_value(int x) {
	return x > 0 ? true : false;
}
bool check_value(double x) {
	return x > 0 ? true : false;
}


truba create_truba() {                          //Создание трубы (ввод данных)
	truba new_truba;
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите диаметр: " << endl;
		cin >> new_truba.diameter;
	} while (!check_value(new_truba.diameter) || cin.fail());
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введит длину: " << endl;
		cin >> new_truba.length;
	} while (!check_value(new_truba.length) || cin.fail());
	new_truba.repair = false;
	new_truba.id = -1;
	return new_truba;
}

cs create_cs() {                             //Создание КС (ввод данных)
	cs new_cs;
	cout << "Введите имя: " << endl;
	cin >> new_cs.name;
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите кол-во цехов: " << endl;
		cin >> new_cs.number_work;
	} while (!check_value(new_cs.number_work) || cin.fail());
	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите кол-во рабочих цехов: " << endl;
		cin >> new_cs.number_inwork;
	} while (!(check_value(new_cs.number_inwork) && (new_cs.number_inwork <= new_cs.number_work)) || cin.fail());

	do {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Введите эффективность: " << endl;
		cin >> new_cs.effect;
	} while (!check_value(new_cs.effect) || cin.fail());
	new_cs.id = -1;
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
	cout << "5. Загрузить файл" << endl;
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
			change_status(t.repair);
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
		/*case 7:
			cout << "\t Выберите действие:" << endl;
			cout << "\t 1. Начало работы" << endl;
			cout << "\t 2. Прекращение работы" << endl;
			cout << "\t 0. Назад" << endl;
			cin >> i;
			switch (i)
			{
			case 1:
				continue_work(c);
				break;
			case 2:
				stop_work(c);
				break;
			case 0:
				break;
			default:
				cout << "Выберите действие: " << endl;
				break;
			}
			break;*/
		case 0:
			return 0;
			break;
		default:
			cout << "Выберите действие: " << endl;
			break;
		}

	}
}

