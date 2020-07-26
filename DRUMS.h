#pragma once
#include "INSTRUMENT.h"
#include "STICKS.h"

class Drums : public Instrument
{
private:
    string warning = "ThereIsNoDrumsticks";
    int number_of_drums;
    Drumsticks* sticks = nullptr;
public:

	Drums();
	~Drums();
    Drums(const Drums&);
	Drums(float lq,const string& mat,int nod, const string& br, float pr, float we, unsigned int y);
	Drums& operator=(const Drums&);
	virtual void Report() const ;
	friend ostream& operator<<(ostream& os,const Drums& d);
	virtual void SaveToFile(ofstream&);
	friend istream& operator>>(istream& is, Drums& d);
	virtual void PrintFromFile(ifstream&);
	virtual void Modyfie();
	void DeleteSticks();
	void AddSticks(float s,const string& x);

};
