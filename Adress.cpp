#include "pch.h"
#include "Adress.h"

//
//Adress::Adress()
//{
//}
//
//
//Adress::~Adress()
//{
//}

// metodos GET


string Adress::getStreet() {

	return this->rua;
}

string Adress::getDoorNumber() {

	return this->num;
}

string Adress::getFloor() {

	return this->andar;
}

string Adress::getPostalCode() {

	return this->cod_postal;
}

string Adress::getLocation() {

	return this->localidade;
}


// metodos SET
void Adress::adress(string a, string b, string c, string d, string e) {
	this->rua = a;
	this->num = b;
	this->andar = c;
	this->cod_postal = d;
	this->localidade = e;
}
void Adress::setStreet(string a) {
	this->rua = a;
}
void Adress::setDoorNumber(string b) {
	this->num = b;
}
void Adress::setFloor(string c) {
	this->andar = c;
}
void Adress::setPostalCode(string d) {
	this->cod_postal = d;
}
void Adress::setLocation(string e) {
	this->localidade = e;
}

ostream& operator<<(ostream& out, const Adress adr)
{
	return out << adr.rua << " / " << adr.num << " / " << adr.andar << " / " << adr.cod_postal << " / " << adr.localidade;
}

