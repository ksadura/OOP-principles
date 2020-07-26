#include "PCH.h"
#include "STICKS.h"

Drumsticks::Drumsticks(float lg, const string& mat)
{
	length = lg;
	material = mat;
}

ostream& operator<<(ostream& os, const Drumsticks& ds)
{
	os << ds.material <<endl;
	os << ds.length;
	return os;

}

istream& operator>>(istream& is, Drumsticks& ds)
{
	is >> ds.material;
	is >> ds.length;
	return is;
}