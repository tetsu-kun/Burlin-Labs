#include "CS.h"
#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"

int CS::Maxid = 0;

int CS::GetMaxid()
{
	return Maxid;
}

int CS::Getid() const
{
	return id;
}

std::string CS::GetName() const
{
	return name;
}


int CS::GetInWork() const
{
	return inwork;
}


int CS::GetWork() const
{
	return work;
}


double CS::GetEffect() const
{
	return effect;
}



void CS::stop_work()
{
	if (inwork > 0) {
		inwork--;
	}
	else {
		std::cout << "���-�� ������� ����� = 0" << std::endl;
	}
}

void CS::continue_work()
{
	if (inwork < work) {
		inwork++;
	}
	else {
		std::cout << "��� ���� �������" << std::endl;
	}
}



std::ostream& operator << (std::ostream& out, const CS& c) {
	if (c.id >= 0) {
		out << "\t ���������� � ������������� �������: " << std::endl;
		out << "���: " << c.name << std::endl;
		out << "id: " << c.id << std::endl;
		out << "����� ������� �����: " << c.work << std::endl;
		out << "����� ��������� �����: " << c.inwork << std::endl;
		out << "�������������: " << c.effect << std::endl;
	}
	else {
		out << "������������� ������� �� ����������" << std::endl;
	}
	return out;
}

std::istream& operator >> (std::istream& in, CS& c) {
	std::cout << "������� ���:" << std::endl;
	std::cin.ignore(256, '\n');
	getline(in, c.name, '\n');
	std::cout << "������� ����� �����: " << std::endl;
	c.work = get_value(1, 100);
	std::cout << "������� ����� ������� ����� " << std::endl;
	c.inwork = get_value(0, c.work);
	std::cout << "������� �������������: " << std::endl;
	c.effect = get_value(0.0, 100.0);
	return in;
}

std::ofstream& operator<<(std::ofstream& out, const CS& c)
{
	out << c.GetName() << std::endl << c.GetWork() << std::endl << c.GetInWork() << std::endl << c.GetEffect() << std::endl;
	return out;
}

std::ifstream& operator>>(std::ifstream& in, CS& c)
{
	in.ignore(256, '\n');
	std::getline(in, c.name);
	in >> c.work >> c.inwork >> c.effect;
	return in;
}


CS::CS()
{
	id = Maxid++;
	name = "Unknow";
	work = 0;
	inwork = 0;
	effect = 0.0;
}