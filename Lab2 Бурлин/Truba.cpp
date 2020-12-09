#include "Truba.h"
#include <iostream>
#include <string>
#include "utils.h"

using namespace std;


int Truba::Maxid = 0;

std::string Truba::GetName() const
{
	return name;
}


int Truba::Getid() const
{
	return id;
}


int Truba::GetDiametr() const
{
	return diametr;
}


double Truba::GetLength() const
{
	return length;
}


bool Truba::GetStatus() const
{
	return repair;
}


void Truba::change_status()
{
	repair = !repair;
}

std::ostream& operator << (std::ostream& out, const Truba& t) {
	if (t.id >= 0) {
		out << "\t ���������� � �����" << std::endl;
		out << "���: " << t.name << std::endl;
		out << "�������: " << t.diametr << std::endl;
		out << "�����: " << t.length << std::endl;
		out << "id: " << t.id << std::endl;
		out << (t.repair ? "� �������" : "�� � �������") << std::endl;
	}
	else {
		std::cout << "����� �� ����������" << std::endl;
	}
	return out;
}

std::istream& operator >> (std::istream& in, Truba& t) {
	std::cout << "������� ���:" << std::endl;
	std::cin.ignore(256, '\n');
	getline(in, t.name, '\n');
	std::cout << "������� �������: " << std::endl;
	t.diametr = get_value(1, 3000);
	std::cout << "������� �����: " << std::endl;
	t.length = get_value(1.0, 10000.0);
	t.repair = false;
	return in;
}

std::ofstream& operator << (std::ofstream& out, const Truba& t)
{
	out << t.GetName() << std::endl << t.GetDiametr() << std::endl << t.GetLength() << std::endl << t.GetStatus() << std::endl;
	return out;
}


std::ifstream& operator >> (std::ifstream& in, Truba& t)
{
	in.ignore(256, '\n');
	std::getline(in, t.name);
	in >> t.diametr >> t.length >> t.repair;
	return in;
}

Truba::Truba()
{
	id = Maxid++;
	length = 0;
	diametr = 0;
	repair = false;
	name = "Unknow";
}