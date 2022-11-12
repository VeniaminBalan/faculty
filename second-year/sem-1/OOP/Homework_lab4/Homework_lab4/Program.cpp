#include <iostream>
#include <list>
#include <algorithm>
#include <string>

#include "Electrocasnice.cpp"
#include "Aragaz.cpp"
#include "Microunda.cpp"

using namespace std;

namespace program 
{
	class Program
	{
		list<Electrocasnice*>* cart; 
	public:
		void start()
		{
			int opt;
			string prod;
			do
			{
				cout << "\nMeniu: \n";
				cout << "1. Introducerea unui nou articol\n";
				cout << "2. Afisare în ordinea producătorului\n";
				cout << "3. Stergere producator\n";
				cout << "4. Afisare\n";
				cout << "5. Exit\n";
				cout << "Optiunea: ";
				cin >> opt;

				switch (opt)
				{
				case 1:
					insert();
					break;
				case 2:
					sortare();
					show_cart();
					break;
				case 3:
					cout << "Introduceti Producatorul: ";
					cin >> prod;
					stergere_prod(prod);
					break;
				case 4:
					show_cart();
					break;
				case 5:
					return;
				default:
					break;
				}
			} while (true);

		}

		void test() 
		{
			cart->push_back(new Aragaz("LG", 1800, "Blue"));
			cart->push_back(new Microunda("Bosch", 1500, 220));
			cart->push_back(new Aragaz("Bosch", 2000, "Red"));
			cart->push_back(new Aragaz("Samsung", 2350, "Blue"));
			cart->push_back(new Microunda("LG", 2000, 300));
			cart->push_back(new Microunda("LG", 1700, 250));
			cart->push_back(new Microunda("Samsung", 1700, 250));

			start();
		}
		Program() 
		{
			cart = new list<Electrocasnice*>();
		}
	private:
		void insert()
		{
			int opt;
			do
			{
				cout << "\nIntroducerea unui nou articol\n";
				cout << "\n1. Aragaz";
				cout << "\n2. Microunda";
				cout << "\n3. Back";
				cout << "\noptiunea: ";
				cin >> opt;
				switch (opt)
				{
				case 1:
					cart->push_back(new Aragaz());
					break;
				case 2:
					cart->push_back(new Microunda());
					break;
				case 3:
					return;
				default:
					cout << "\nInvalid Input\n";
					break;
				}
			} while (true);

		}
		void show_cart()
		{
			for_each( cart->begin(), cart->end(), [](Electrocasnice* el )
				{
					el->Info();
				});
		}
		void stergere_prod(string producator)
		{
			list<Electrocasnice*> ::iterator it;
			int i = 0;
			for (it = cart->begin(); it != cart->end();)
			{
				if ((*it)->get_produactor() == producator)
				{
					it = cart->erase(it);
					i++;
				}
				else  ++it;
			}
			cout << i << " elemente eliminate\n";
		}
		void sortare()
		{
			//cart->sort( comp );
			cart->sort([](Electrocasnice* lhs, Electrocasnice* rhs)
				{
					return lhs->get_produactor() < rhs->get_produactor();
				});
		}
		bool comp(Electrocasnice& a, Electrocasnice& b)
		{
			//	if ( a.get_produactor() > b.get_produactor()) return true;
			//	else return false;
		}
	};

}