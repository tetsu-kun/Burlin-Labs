#pragma once
#include <iostream>
class Truba
{
public:
	int id;
	double length;
	double diameter;
	bool repair;

public:
	std::string GetName() const;
	void  SetName(std::string);

	ostream& operator << (ostream& out, const Truba& t);
	
};

