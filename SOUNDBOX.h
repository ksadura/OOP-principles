#pragma once
#include <string>

///Klasa Soundbox
/**Klasa potrzebna do stworzenia podobiektu w klasie Guitar*/
class Soundbox
{
private:
	float depth; ///<glebokosc pudla rezonansowego
	std::string material; ///<material pudla rezonasowego

public:
	///Funkcja ustawiajaca parametry
	void SetParameters(float, const std::string&);
};

