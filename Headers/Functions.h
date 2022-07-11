#pragma once
#include <vector>
#include <fstream>
#include "Drums.h"
#include "Guitar.h"
#include "ElectricGuitar.h"
#include <limits>

/// Plik Function.h
/**Sluzy do przechowywania funkcji uzwyanych w menu */

/// Funkcja usuwajaca obiekt z wektora
void DeleteProduct(vector<Instrument*>&);

/// Funkcja dodajaca obiekt do wektora
void AddProduct(vector<Instrument*>&);

/// Wypisanie stanu wektora na ekran konsoli
void ShowProducts(vector<Instrument*>&);

/// Czyszczenie calego wektora
void ClearContainer(vector<Instrument*>&);

/// Zapis aktualnego stanu do pliku tekstowego
void GetToFile(vector<Instrument*>&);

/// Odczyt obiketow z pliku tekstowego
void GetFromFile(vector<Instrument*>&);

/// Funkcja sluzaca do modyfikacji wybranego obiektu z wektora
void ModifyProduct(vector<Instrument*>&);

/// Enumeryczna lista
enum DEVICE 
{ 
	Guitars = 1, 
	ElectricGuitars, 
	Drum 
};

