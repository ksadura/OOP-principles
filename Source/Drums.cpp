#include "../Headers/Drums.h"
#include <fstream>

Drums::Drums()
{
	sticks = new Drumsticks(0.0, "none");
}

Drums& Drums::operator=(const Drums& ds)
{
	if (this == &ds)
		return *this;
	delete sticks;
	sticks = nullptr;
	noDrums = ds.noDrums;
	Instrument::operator=(ds);
	if (ds.sticks != nullptr)
	{
		sticks = new Drumsticks();
		(*this->sticks) = (*ds.sticks);
	}
	return *this;
}

Drums::Drums(const Drums& dr) : Instrument(dr)
{
	delete sticks;
	sticks = nullptr;
	noDrums = dr.noDrums;
	if (dr.sticks != nullptr)
	{
		sticks = new Drumsticks();
		(*this->sticks) = (*dr.sticks);
	}
}
Drums::~Drums()
{
	if (sticks != nullptr)
		delete sticks;
}
Drums::Drums(float len, const string& mat, int nod, const string& br, float pr, float we, unsigned int y) : Instrument(br, pr, we, y)
{
	noDrums = nod;
	sticks = new Drumsticks(len, mat);
}

void Drums::Report() const
{

	cout << *this << endl;

}

ostream& operator<<(ostream& os, const Drums& d)
{

	if ((d.sticks) != nullptr)
	{
		os << "TRUE" << endl; // wypisanie pomocniczne
		os << *(d.sticks) << endl;
	}
	else
	{
		os << "FALSE" << endl; // wypisanie pomocnicze
		os << d.warning << endl;
	}
	os << d.noDrums << endl;
	os << (Instrument&)d;
	return os;
}

void Drums::SaveToFile(ofstream& os)
{
	os << *this;
}

istream& operator>>(istream& is, Drums& d)
{
	if (d.sticks != nullptr)
		is >> *(d.sticks) >> d.noDrums >> (Instrument&)d;
	else
		is >> d.warning >> d.noDrums >> (Instrument&)d;

	return is;
}

void Drums::PrintFromFile(ifstream& is)
{
	is >> *this;
}
void Drums::AddSticks(float len, const string& m)
{
	if (sticks == nullptr)
		sticks = new Drumsticks(len, m);
}

void Drums::DeleteSticks()
{
	if (sticks == nullptr)
		cout << "Sticks have been already removed" << endl;
	else
	{
		delete sticks;
		sticks = nullptr;
	}
}
void Drums::Modyfie()
{
	int lq;
	string mat;
	string option;
	cout << "Add or delete the drumsticks? [type using small words]" << endl;
	cin >> option;
	if (option == "add")
	{
		if (sticks != nullptr)
		{
			cout << "Drumsticks have been already added" << endl;

		}
		else
		{
			cout << "Type length: ";
			cin >> lq;
			cout << "Type material: ";
			cin >> mat;
			AddSticks(lq, mat);
		}
	}
	else if (option == "delete")
	{
		DeleteSticks();
	}
	else
		cout << "Unknown" << endl;
}