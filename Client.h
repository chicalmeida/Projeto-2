#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Adress.h"

using namespace std;

class Client
{
private:
	string nome;
	string nif;
	string num_agregado;
	Adress morada;
	string viagens_feitas;
	string total_compras;

public:
	/*Client();
	~Client();*/

	// GET METHODS
	string getName();
	string getVATnumber();
	string getFamilySize();
	Adress getAddress();
	string getPacketList();
	string getTotalPurchases();

	// SET METHODS
	void setName(string a);
	void setVATnumber(string b);
	void setFamilySize(string c);
	void setAddress(Adress d);
	void setPacketList(string f);
	void setTotalPurchases(string g);
	void showClient();
};

