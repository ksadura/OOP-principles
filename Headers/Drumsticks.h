#pragma once
#include <iostream>
#include <string>

using namespace std;

///Klas Drumsticks 
//**Klasa ta nie jest dziedziczona przez nasza klase abstrakcyjna*/
/**.Stanowi klase obiektu dynamicznego w klasie Drums*/
class Drumsticks
{
private:
	float length; ///<dlugosc paleczek do perkusji
	string material; ///<material z jakiego wykonano paleczki

public:
	///Konstruktor domyslny
	Drumsticks() {}
	///Destruktor
	~Drumsticks() {}
	///Konstruktor z parametrami
	Drumsticks(float, const string&);
	///Operator strumieniowy <<
	friend ostream& operator<<(ostream& os, const Drumsticks& ds);
	///Operator strumieniowy >>
	friend istream& operator>>(istream& is, Drumsticks& ds);

};
