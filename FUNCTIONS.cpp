#include "Functions.h"

using namespace std;

void DeleteProduct(vector<Instrument*>& tab)
{
	int k;
	cin.exceptions(ifstream::failbit | ifstream::badbit);
	cout << "Choose index of product to remove " << endl;
	do
	{
		try
		{
			cin >> k;
			if (k < 0 || k >= tab.size())
			{
				throw string("Out of range");
			}
			else
			{
				delete tab[k];
				tab.erase(tab.begin() + k);
				break;
			}

		}
		catch (string error)
		{
			cout << error << endl;
		}
		catch (ifstream::failure)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Not a number" << endl;
		}
	} while (true);
}

void AddProduct(vector<Instrument*>& tab)
{
	int l, s;
	string brand;
	float price;
	unsigned int year;
	string color;
	float power;
	string material;
	float weight;
	int noch;
	int nodr;
	float lenght;

	cin.exceptions(ifstream::failbit | ifstream::badbit);
	cout << "Type a number of position which you want to insert product on" << endl;
	do
	{

		try
		{
			cin >> l;
			if (l < 0 || l > tab.size())
				throw string("Out of range");
			else
				break;
		}
		catch (string error)
		{
			cout << error << endl;
		}
		catch (ifstream::failure)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Not a number" << endl;
		}

	} while (true);

	cout << "Which product do you want to insert? " << endl << "1.Guitar, 2.ElectricGuitar, 3.Drums" << endl;
	do
	{
		try
		{

			cin >> s;
			auto it = tab.begin();
			switch (s)
			{

			case Guitars:
				cout << "Get Brand[without space]: ";
				cin >> brand;
				cout << "Get Color: ";
				cin >> color;
				cout << "Get Price: ";
				cin >> price;
				cout << "Get Weight: ";
				cin >> weight;
				cout << "Get no.Chords: ";
				cin >> noch;
				cout << "Get year of production: ";
				cin >> year;
				tab.insert(it + l, new Guitar(noch, color, brand, price, weight, year));
				break;
			case ElectricGuitars:
				cout << "Get Brand [without space]: ";
				cin >> brand;
				cout << "Get Color: ";
				cin >> color;
				cout << "Get Price: ";
				cin >> price;
				cout << "Get Weight: ";
				cin >> weight;
				cout << "Get no.Chords: ";
				cin >> noch;
				cout << "Get year of production: ";
				cin >> year;
				cout << "Get power: ";
				cin >> power;
				tab.insert(it + l, new ElectricGuitar(power, noch, color, brand, price, weight, year));
				break;
			case Drum:
				cout << "Get Brand [without space]: ";
				cin >> brand;
				cout << "Get material of drumsticks: ";
				cin >> material;
				cout << "Get Price: ";
				cin >> price;
				cout << "Get Weight: ";
				cin >> weight;
				cout << "Get length of drumsticks: ";
				cin >> lenght;
				cout << "Get year of production: ";
				cin >> year;
				cout << "Get no.Drums: ";
				cin >> nodr;
				tab.insert(it + l, new Drums(lenght, material, nodr, brand, price, weight, year));
				break;
			default:
				cout << "Wrong input" << endl;
			}
		}
		catch (ifstream::failure)
		{
			cout << "Wrong Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (s != 1 && s != 2 && s != 3);
}

void ShowProducts(vector<Instrument*>& tab)
{
	if (!(tab.empty()))
	{
		for (int i = 0; i < tab.size(); i++)
			tab[i]->Report();
	}
	else
		cout << "Container is empty" << endl;
}

void ClearContainer(vector<Instrument*>& tab)
{
	if (!tab.empty())
	{
		for (int i = 0; i < tab.size(); i++)
		{
			delete tab[i];
		}
		tab.clear();
	}
}
void GetFromFile(vector<Instrument*>& tab)
{
	ClearContainer(tab);
	string linia, check;
	int w;
	ifstream plik;
	plik.open("Config.txt", ios::in);
	if (plik.good())
	{
		plik >> w;
		for (int i = 0; i < w; i++)
		{
			plik >> linia;
			if (linia == "G")
			{
				Guitar* g = new Guitar();
				g->PrintFromFile(plik);
				tab.push_back(g);

			}
			else if (linia == "ELG")
			{
				ElectricGuitar* eg = new ElectricGuitar();
				eg->PrintFromFile(plik);
				tab.push_back(eg);
			}
			else if (linia == "D")
			{
				plik >> check;
				if (check == "TRUE")
				{
					Drums* d = new Drums();
					d->PrintFromFile(plik);
					tab.push_back(d);
				}
				else if (check == "FALSE")
				{
					Drums* d = new Drums();
					d->DeleteSticks();
					d->PrintFromFile(plik);
					tab.push_back(d);
				}
			}
		}
		plik.close();
	}
}

void GetToFile(vector<Instrument*>& tab)
{
	Guitar* g;
	ElectricGuitar* eg;
	Drums* d;
	if (!tab.empty())
	{
		ofstream file;
		file.open("Config.txt", ios::out | ios::app);
		if (file.good())
		{
			file << tab.size() << endl;

			for (int i = 0; i < tab.size(); ++i)
			{
				if (eg = dynamic_cast<ElectricGuitar*>(tab[i]))
				{
					file << "ELG" << endl;
					eg->SaveToFile(file);
				}
				else if (g = dynamic_cast<Guitar*>(tab[i]))
				{
					file << "G" << endl;
					g->SaveToFile(file);
				}

				else if (d = dynamic_cast<Drums*>(tab[i]))
				{
					file << "D" << endl;
					d->SaveToFile(file);
				}
			}
			file.close();
		}
	}
}

void Modyfication(vector<Instrument*>& tab)
{
	cin.exceptions(ifstream::failbit | ifstream::badbit);
	int y;
	cout << "Type index of element to modyfie: ";
	do
	{

		try
		{
			cin >> y;
			if (y < 0 || y >= tab.size())
				throw string("Out of range");
			else
				tab[y]->Modyfie();
			break;
		}
		catch (string error)
		{
			cout << error << endl;
		}
		catch (ifstream::failure)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Not a number" << endl;
		}

	} while (true);
}