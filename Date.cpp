#include "pch.h"
#include "Date.h"


//Date::Date()
//{
//}


//Date::~Date()
//{
//}

string Date::getDay() {

	return this->dia;

}


string Date::getMonth() {

	return this->mes;

}

string Date::getYear() {

	return this->ano;

}

/*********************************
 * SET Methods
 ********************************/

void Date::date(string a, string b, string c){
	this->dia = a;
	this->mes = b;
	this->ano = c;

}

void Date::show() const
{
	cout << ano << '/' << mes << '/' << dia << endl;
};

ostream& operator<<(ostream& out, const Date dt)
{
	return out << dt.ano << "/" << dt.mes << "/" << dt.dia;
}

