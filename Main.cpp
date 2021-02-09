#include "Functions.h"

using namespace std;
vector<Instrument*>tab;
int x;

int main()
{
	tab.push_back(new Guitar(4, "DARK", "BRANDY", 125.99, 2.50, 2001));
	tab.push_back(new ElectricGuitar(250, 5, "YELLOW", "BRANDR", 205.99, 1.99, 2009));
	tab.push_back(new Drums(0.45, "PLASTIC", 8, "BRANDZ", 1050.20, 120, 2008));
	tab.push_back(new Drums(0.5, "WOOD", 11, "BRANDK", 1100.99, 125.5, 2012));
	tab.push_back(new Guitar(5, "BROWN", "BRANDX", 155.99, 2.90, 1999));

	cout << "Welcome" << endl;
	cout << "1.Show products" << endl;
	cout << "2.Delete certain product from the vector" << endl;
	cout << "3.Add product to the vector" << endl;
	cout << "4.Save products to a file" << endl;
	cout << "5.Load products from the file" << endl;
	cout << "6.Modyfie certain product" << endl;
	cout << "7.Clear Container" << endl;
	cout << "8.Quit the application" << endl;
	cout << "Select a number : ";


	cin.exceptions(ifstream::failbit | ifstream::badbit);
	while (true)
	{

		try
		{
			cout << endl;
			cin >> x;
			cout << "----------------------------------------" << endl;
			switch (x)
			{
			case 1:
				ShowProducts(tab);
				break;
			case 2:
				DeleteProduct(tab);
				break;
			case 3:
				AddProduct(tab);
				break;
			case 4:
				GetToFile(tab);
				break;
			case 5:
				GetFromFile(tab);
				break;
			case 6:
				Modyfication(tab);
				break;
			case 7:
				ClearContainer(tab);
				break;
			case 8:
				ClearContainer(tab);
				exit(0);
			default:
				cout << "Wrong input, try again" << endl;
			}
		}
		catch (ifstream::failure)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Wrong input, try again" << endl;
		}

		cout << "----------------------------------------" << endl;
		cout << "1.Show products" << endl;
		cout << "2.Delete certain product from the vector" << endl;
		cout << "3.Add product to the vector" << endl;
		cout << "4.Save products to a file" << endl;
		cout << "5.Load products from the file" << endl;
		cout << "6.Modyfie certain product" << endl;
		cout << "7.Clear Container" << endl;
		cout << "8.Quit the application" << endl;
		cout << "Select a number : ";


	}

	return 0;
}