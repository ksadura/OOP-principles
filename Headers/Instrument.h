#pragma once
#include <iostream>
#include <string>

using namespace std;

class Instrument
{
private:
	float price; ///<cena instrumentu
	float weight; ///<waga instrumentu
	unsigned int year; ///<rok produkcji instrumentu
	string brand; ///<marka instrumentu

public:
	///Konstruktor domyslny
	Instrument() {}
	
	///Konstruktor z parametrami
	Instrument(const string& br, float pr, float we, unsigned int y);
	
	///Operator przypisania
	/**
	\param ins Referencja na obiekt klasy Instrument
	\return *this
	*/
	Instrument& operator=(const Instrument& ins);

	///Destruktor klasy bazowej
	virtual ~Instrument() {}
	
	///Metoda czysto wirtulna
	/**Powoduje ze nasza klasa jest klasa abstrakcyjna*/
	virtual void Report() const = 0;
	
	///Operator strumieniowey <<
	friend ostream& operator<<(ostream& os, const Instrument& ins);
	
	///Funkcja sluzaca w naszej aplikacji do zapisu stanu wektora do pliku tekstowego
	virtual void SaveToFile(ofstream&) {}
	
	///Operator strumieniowy >>
	friend istream& operator>>(istream& is, Instrument& ins);
	
	///Funkcja sluzaca w naszej aplikacji do odczytu stanu wektora z pliku tekstowego
	virtual void PrintFromFile(ifstream&) {}
	
	///Metoda czysto wirtualna
	virtual void Modyfie() = 0;
};

