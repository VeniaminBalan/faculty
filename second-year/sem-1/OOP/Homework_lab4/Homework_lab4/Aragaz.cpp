#include <iostream>
#include <string>

#include "Electrocasnice.cpp"

using namespace std;

#ifndef Aragaz_H
#define Aragaz_H

namespace program
{
	class Aragaz : public Electrocasnice
	{
		string culoare;
	public:
		void set_culoare(string culoare)
		{
			this->culoare = culoare;
		}
		string get_culoare()
		{
			return this->culoare;
		}
		void Info()
		{
			cout << "\nAragaz: \n";
			Electrocasnice::Info();
			cout << "Culoare " << culoare << endl;
		}
		Aragaz() : Electrocasnice()
		{
			cout << "Culoare: ";
			cin >> culoare;
		}
		Aragaz(string producator, float pret, string culoare) : Electrocasnice(producator, pret)
		{
			this->culoare = culoare;
		}
	};
}

#endif // !Aragaz_H