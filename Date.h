#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date {
private:
	string dia;
	string mes;
	string ano;

public:
	/*Date();
	Date(string date);
	Date(unsigned short day, unsigned short month, unsigned year);*/

	// GET methods
	string getDay();
	string getMonth();
	string getYear();

	// SET methods

	void date(string a, string b, string c);
	void show() const;

	friend ostream& operator<<(ostream& out, const Date dt);
};
