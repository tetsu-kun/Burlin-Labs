#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"

class CS
{
	std::string name;
	int id;
	int work;
	int inwork;
	double effect;


public:
	static int Maxid;

	std::string GetName() const;

	int Getid() const;

	int GetInWork() const;

	int GetWork() const;

	double GetEffect() const;

	friend std::ostream& operator << (std::ostream& out, const CS& c);
	friend std::istream& operator >> (std::istream& in, CS& c);
	friend std::ofstream& operator << (std::ofstream& out, const CS& c);
	friend std::ifstream& operator >> (std::ifstream& in, CS& c);

	void stop_work();
	void continue_work();

	CS();

};