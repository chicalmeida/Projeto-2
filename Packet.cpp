#include "pch.h"
#include "Packet.h"


//Packet::Packet()
//{
//}
//
//
//Packet::~Packet()
//{
//}


  // metodos GET

string Packet::getId() const {

	return id;
}

string Packet::get_locais_visitar() const {

	return locais_visitar;
}

Date Packet::get_data_ini() const {

	return data_ini;
}

Date Packet::get_data_fim() const {

	return data_fim;
}

string Packet::get_preco_pessoa() const {

	return preco_pessoa;
}

string Packet::get_lugares_max() const {

	return lugares_max;
}

string Packet::get_lugares_reserv() const {

	return lugares_reserv;
}

void Packet::setId(string a) {

	id = a;
}

void Packet::set_locais_visitar(string b) {

	locais_visitar = b;
}

void Packet::set_data_ini(Date c) {

	data_ini = c;
}

void Packet::set_data_fim(Date d) {

	data_fim = d;
}

void Packet::set_preco_pessoa(string e) {

	preco_pessoa = e;
}

void Packet::set_lugares_max(string f) {

	lugares_max = f;
}

void Packet::set_lugares_reserv(string g) {

	lugares_reserv = g;
}

void Packet::showpacket() {
	cout << id << endl;
	cout << locais_visitar << endl;
	cout << data_ini << endl;
	cout << data_fim << endl;
	cout << preco_pessoa << endl;
	cout << lugares_max << endl;
	cout << lugares_reserv << endl;
}