#include "Agency.h"


// metodos GET
string Agency::getName() const {

	return nome;
}

string Agency::getVATnumber() const {

	return nif;
}

Adress Agency::getAdress() const {

	return morada;
}

string Agency::getURL() const {

	return url;
}

string Agency::getClients() const {

	return clientes;
}

string Agency::getPackets() const {

	return pacotes;
}


string Agency::getnomeclientes() const
{
	return nome_ficheiro_clientes;
}

string Agency::getnomepacotes() const
{
	return nome_ficheiro_pacotes;
}


// SET Methods

void Agency::agency(string a, string b, Adress c, string d, string e, string f) {
	this->nome = a;
	this->nif = b;
	this->morada = c;
	this->url = d;
	this->nome_ficheiro_clientes = e;
	this->nome_ficheiro_pacotes = f;
}

void Agency::showagency() {
	cout << nome << endl;
	cout << nif << endl;
	cout << morada << endl;
	cout << url << endl;
}


