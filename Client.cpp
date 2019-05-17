#include "pch.h"
#include "Client.h"


//Client::Client()
//{
//}
//
//
//Client::~Client()
//{
//}

// GET METHODS
string Client::getName() {
	return this->nome;
}
string Client::getVATnumber() {
	return this->nif;
}
string Client::getFamilySize() {
	return this->num_agregado;
}
Adress Client::getAddress() {
	return this->morada;
}
string Client::getPacketList() {
	return this->viagens_feitas;
}
string Client::getTotalPurchases() {
	return this->viagens_feitas;
}

// SET METHODS
void Client::setName(string a){
	this->nome = a;
}

void Client::setVATnumber(string b){
	this->nif = b;
}

void Client::setFamilySize(string c) {
	this->num_agregado = c;
}

void Client::setAddress(Adress d){
	this->morada = d;	
}

void Client::setPacketList(string e) {
	this->viagens_feitas = e;
}

void Client::setTotalPurchases(string f) {
	this->total_compras = f;
}

void Client::showClient() {
	cout << nome << endl;
	cout << nif << endl;
	cout << num_agregado << endl;
	cout << morada << endl;
	cout << viagens_feitas << endl;
	cout << total_compras << endl;
}