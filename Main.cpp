#include "Headers/Functions.h"

using namespace std;

static vector<Instrument*> container;
static int option;

int main()
{
	container.push_back(new Guitar(4, "DARK", "BRANDY", 125.99, 2.50, 2001));
	container.push_back(new ElectricGuitar(250, 5, "YELLOW", "BRANDR", 205.99, 1.99, 2009));
	container.push_back(new Drums(0.45, "PLASTIC", 8, "BRANDZ", 1050.20, 120, 2008));
	container.push_back(new Drums(0.5, "WOOD", 11, "BRANDK", 1100.99, 125.5, 2012));
	container.push_back(new Guitar(5, "BROWN", "BRANDX", 155.99, 2.90, 1999));

	cin.exceptions(ifstream::failbit | ifstream::badbit);
	cout << "## WELCOME ##" << endl;
	
	while (true)
	{
		try
		{
			cout << "----------------------------------------" << endl;
			cout << "1.Show products" << endl;
			cout << "2.Delete certain product from the vector" << endl;
			cout << "3.Add product to the vector" << endl;
			cout << "4.Save products to a file" << endl;
			cout << "5.Load products from the file" << endl;
			cout << "6.Modyfie certain product" << endl;
			cout << "7.Clear Container" << endl;
			cout << "8.Quit the application" << endl;
			cout << "Select a number: ";
			cin >> option;
			cout << "----------------------------------------" << endl;
			
			switch (option)
			{
			case 1:
				ShowProducts(container);
				break;
			case 2:
				DeleteProduct(container);
				break;
			case 3:
				AddProduct(container);
				break;
			case 4:
				GetToFile(container);
				break;
			case 5:
				GetFromFile(container);
				break;
			case 6:
				ModifyProduct(container);
				break;
			case 7:
				ClearContainer(container);
				break;
			case 8:
				ClearContainer(container);
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
	}

	return 0;
}