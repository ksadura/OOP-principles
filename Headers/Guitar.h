#pragma once
#include "Instrument.h"
#include "PickUp.h"
#include "Soundbox.h"


class Guitar : public Instrument
{
private:
	int number_of_chords; ///<liczba strun
	Soundbox body; ///<pudlo rezonansowe

protected:
	string color; ///<kolor gitary

public:
	///Konstruktor domyslny
	Guitar() {}
	///Destruktor 
	~Guitar() {}
	///Konstrukor z parametrami
	Guitar(int noc, const string& co, const string& br, float pr, float we, unsigned int y);
	///Operator +=
	/**Sluzy do zmieniania liczby strun
	\param l mowi o ile zmienic liczbe strun
	\return referencja na klase Guitar
	*/
	Guitar& operator+=(int l);
	///Wirtualna funkcja sluzaca do odczytu obiektow na ekran konsoli
	virtual void Report() const;
	///Operator strumieniowy <<
	friend ostream& operator<<(ostream& os, const Guitar& g);
	///Funkcja sluzaca w naszej aplikacji do zapisu stanu wektora do pliku tekstowego
	virtual void SaveToFile(ofstream& os);
	///Operator strumieniowy >>
	friend istream& operator>>(istream& is, Guitar& gu);
	///Funkcja sluzaca w naszej aplikacji do odczytu stanu wektora z pliku tekstowego
	virtual void PrintFromFile(ifstream& is);
	///Wirtualna Funkcja sluzaca do modyfkacji poszegolnych obiektow
	virtual void Modyfie();
	///Funkcja zmieniajaca ton dzwieku
	void ChangeTune();
	///Funkcja zmienniajaca parametry podobiektu
	void ChangeBox();

};

