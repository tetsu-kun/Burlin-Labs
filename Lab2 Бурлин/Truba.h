#pragma once
#include <iostream>
#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"

class Truba
{
	std::string name;
	int id;
	double length;
	double diametr;
	bool repair;

public:
	static int Maxid;

	std::string GetName() const;
	

	int Getid() const;
	
	int GetDiametr() const;
	
	double GetLength() const;
	
	bool GetStatus() const;
	
	void change_status();

	friend std::ostream& operator << (std::ostream& out, const Truba& t);
	friend std::istream& operator >> (std::istream& in, Truba& t);
	friend std::ofstream& operator << (std::ofstream& out, const Truba& t);
	friend std::ifstream& operator >> (std::ifstream& in, Truba& t);

	Truba();
};

