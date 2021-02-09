#pragma once

///Klasa PickUp
/**Klasa potrzebna do stworzenia podobiektu w klasie ElectricGuitar*/
class PickUp
{
private:
	int noMagnets; ///<ilosc magnesow w przetworniku
	int noSolenoids; ///<ilosc cewek w przetworniku

public:
	///Funkcja ustawiajaca parametry
	/**
	\param qos - liczba cewek
	\param qom - liczba magnesow
	*/
	void SetParameters(int qom, int qos);
	///Operator +=
	/**
	\return referencja na klase PickUp
	\param x mowi o ile mamy zwiekszyc ilosc */
	PickUp& operator+=(int x);
};
