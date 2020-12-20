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

	static int Maxid;

	int start;
	int end;
	bool used;

public:

	std::string GetName() const;

	static int GetMaxid();

	int Getid() const;

	double GetDiametr() const;

	double GetLength() const;

	bool GetStatus() const;

	void change_status();

	void SetStart(int);
	void SetEnd(int);

	int GetStart() const;
	int GetEnd() const;

	void ChangeUsed();

	friend std::ostream& operator << (std::ostream& out, const Truba& t);
	friend std::istream& operator >> (std::istream& in, Truba& t);
	friend std::ofstream& operator << (std::ofstream& out, const Truba& t);
	friend std::ifstream& operator >> (std::ifstream& in, Truba& t);

	Truba();
};

