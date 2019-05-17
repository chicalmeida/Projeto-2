#pragma once
#include <iostream>
#include <string>
#include <vector>


#include "Adress.h"
#include "Client.h"
#include "Packet.h"

using namespace std;

class Agency {
private:
	string nome;
	string nif;
	Adress morada;
	string url;
	string pacotes;
	string clientes;
	string nome_ficheiro_clientes;
	string nome_ficheiro_pacotes;


public:

	// methods GET
	string getName() const;
	string getVATnumber() const;
	Adress getAdress() const;
	string getURL() const;
	string getClients() const;
	string getPackets() const;
	string getnomeclientes() const;
	string getnomepacotes() const;


	// methods SET
	void agency(string a, string b, Adress c, string d, string e, string f);
	void showagency();


};