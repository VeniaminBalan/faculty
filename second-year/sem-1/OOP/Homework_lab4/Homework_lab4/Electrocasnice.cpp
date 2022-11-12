#include <string>
#include <iostream>

using namespace std;

#ifndef Electro_H
#define Electro_H

namespace program
{
	class Electrocasnice
	{
		string producator;
		float pret;

	public:
		void set_producator(string producator)
		{
			this->producator = producator;
		}
		string get_produactor()
		{
			return this->producator;
		}
		void set_pret(float pret)
		{
			this->pret = pret;
		}
		float get_pret()
		{
			return pret;
		}
		Electrocasnice()
		{
			cout << "Producator: ";
			cin >> this->producator;
			cout << "Pret: ";
			cin >> this->pret;
		}
		Electrocasnice(string producator, float pret)
		{		
			this->producator = producator;
			this->pret = pret;
		}
		virtual void Info()
		{
			cout << "Producator: " << producator << endl;
			cout << "Pret: " << pret << endl;
		}
	};
}

#endif // !Electro_H
