#include "PCH.h"
#include "ELECGUITAR.h"
#include <limits>

#include <fstream>

void ElectricGuitar::Modyfie()
{
	cin.exceptions(ifstream::failbit | ifstream::badbit);
	int x;
	cout << "To change color type 1 | To change tune type 2" << endl;
	do
	{
		try
		{
			cin >> x;
			if (x == 1)
			{
				this->ChangeColor();
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
	} while (x != 1 && x != 2);
}

void ElectricGuitar::ChangeTune()
{
	int x;
	cout << "To change tune you have to change properties of converter" << endl;
	converter.SetParameters(0, 0);
	cout << "Type new number of magnets and solenoids" << endl;
	cin >> x;
	converter += x;
	cout << "You have changed a tune" << endl;
}
void ElectricGuitar::ChangeColor()
{
	string newcolor;
	cout << "Type new color: ";
	cin >> newcolor;
	this->color = newcolor;
}

void ElectricGuitar::PrintFromFile(ifstream& is)
{
	is >> *this;
}

istream& operator>>(istream& is, ElectricGuitar& eg)
{
	is >> eg.power >> (Guitar&)eg;
	return is;
}

void ElectricGuitar::Report() const
{
	cout << *this << endl;
}

ElectricGuitar::ElectricGuitar(double pwr, int noc, const string& co, const string& br, float pr, float we, unsigned int y) : Guitar(noc, co, br, pr, we, y)
{
	power = pwr;
}

ostream& operator<< (ostream& os, const ElectricGuitar& eg)
{
	os << eg.power << endl;
	os << (Guitar&)eg;
	return os;
}

void ElectricGuitar::SaveToFile(ofstream& os)
{
	os << *this;
}
