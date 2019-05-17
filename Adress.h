#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Adress
{
private:
	string rua;
	string num;
	string andar;
	string cod_postal;
	string localidade;

public:
	/*Adress();
	~Adress();*/

	// metodos GET
	string getStreet();
	string getDoorNumber();
	string getFloor();
	string getPostalCode();
	string getLocation();

	// metodos SET
	void adress(string a, string b, string c, string d, string e);
	void setStreet(string a);
	void setDoorNumber(string b);
	void setFloor(string c);
	void setPostalCode(string d);
	void setLocation(string e);
	

	friend ostream& operator<<(ostream& out, const Adress adr);
};

