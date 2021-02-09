#include "Instrument.h"
#include <fstream>


Instrument::Instrument(const string& br, float pr, float we, unsigned int y)
{
	brand = br;
	price = pr;
	weight = we;
	year = y;
}

ostream& operator<<(ostream& os, const Instrument& ins)
{
	os << ins.brand << endl;
	os << ins.price << endl;
	os << ins.weight << endl;
	os << ins.year << endl;
	return os;
}

istream& operator>>(istream& is, Instrument& ins)
{
	is >> ins.brand >> ins.price >> ins.weight >> ins.year;
	return is;

}

Instrument& Instrument::operator=(const Instrument& ins)
{
	brand = ins.brand;
	price = ins.price;
	weight = ins.weight;
	year = ins.year;
	return *this;
}
