#include <iostream>
#include <string>

#include "Electrocasnice.cpp"

using namespace std;

#ifndef Microunda_H
#define Microunda_H

namespace program
{
	class Microunda : public Electrocasnice
	{
		float putere;
	public:
		void set_putere(float putere)
		{
			this->putere = putere;
		}
		float get_putere()
		{
			return this->putere;
		}
		Microunda()
		{
			cout << "Putere: ";
			cin >> putere;
		}
		Microunda(string producator, float pret, float putere) : Electrocasnice(producator, pret)
		{
			this->putere = putere;
		}
		void Info()
		{
			cout << "\nMicrounda:\n";
			Electrocasnice::Info();
			cout << "Putere " << this->putere << " W" << endl;
		}

	};
}

#endif // !Microunda_H
