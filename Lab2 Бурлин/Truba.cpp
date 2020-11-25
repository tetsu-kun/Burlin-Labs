#include "Truba.h"
using namespace std


Truba::Truba()
{
	id = 1;
	length = 0;
	diametr = 0;
	repair = true;
	name = "Unknown";
}

Truba::Truba(std::string name)
{
	name = name;
}

Truba::Truba(const Truba * t)
{
}

Truba::Truba()
{
}

std::string Truba::GetName() const
{
	return name;
}

void Truba::SetName(std::string new_name)
{
	name = new_name;
}

ostream& Truba::operator<<(ostream& out, const Truba& t)
{
	return out;
}
