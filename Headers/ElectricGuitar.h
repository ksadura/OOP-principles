#pragma once
#include "Guitar.h"

class ElectricGuitar : public Guitar
{
private:
	double power;
	PickUp converter;

public:
	ElectricGuitar() {}
	~ElectricGuitar() {}
	ElectricGuitar(double pwr, int noc, const string& co, const string& br, float pr, float we, unsigned int y);
	virtual void Report() const;
	friend ostream& operator<<(ostream& os, const ElectricGuitar& eg);
	virtual void SaveToFile(ofstream& os);
	friend istream& operator>>(istream& is, ElectricGuitar& eg);
	virtual void PrintFromFile(ifstream& is);
	virtual void Modyfie();
	void ChangeTune();
	void ChangeColor();

};
