#include "PCH.h"
#include "GUITAR.h"
#include <fstream>

Guitar::Guitar(int noc, const string& co, const string& br, float pr, float we, unsigned int y) : Instrument(br, pr, we, y)
{
	color = co;
	number_of_chords = noc;
}

void Guitar::Report() const
{
	cout << *this << endl;
}


ostream& operator<< (ostream& os, const Guitar& g)
{
	os << g.color << endl;
	os << g.number_of_chords << endl;
	os << (Instrument&)g;
	return os;
}



void Guitar::SaveToFile(ofstream& os)
{
	os << *this;
}
	

istream& operator>>(istream& is, Guitar& gu)
{
	is >> gu.color >> gu.number_of_chords >> (Instrument&)gu;
	return is;
}



void Guitar::PrintFromFile(ifstream& is)
{
	is >> *this;
}

Guitar& Guitar::operator+=(int l)
{
	this->number_of_chords += l;
	return *this;
}

void Guitar::Modyfie()
{
	cin.exceptions(ifstream::failbit | ifstream::badbit);
	int x;
	cout << "To change box type: 1 | To change tune type: 2" << endl;
	do
	{
		try {
			cin >> x;
			if (x == 1)
			{
				this->ChangeBox();
				break;
			}
			else if (x == 2)
			{
				this->ChangeTune();
				break;
			}
			else
				cout << "Unknown" << endl;
		}
		catch (ifstream::failure)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Not a number" << endl;
		}
	} while (true);
}
void Guitar::ChangeBox()
{
	string mat;
	float dp;
	cout << "Material of resonance box: ";
	cin >> mat;
	cout << "Depth of resonance box: ";
	cin >> dp;
	body.SetParameters(dp, mat);
}

void Guitar::ChangeTune()
{
	cout << "To change tune add some chords" << endl;
	int j;
	cout << "How many chords to add? : ";
	cin >> j;
	*this += j;
}

