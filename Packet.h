#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Date.h"

using namespace std;

class Packet {
private:
	string id;
	string locais_visitar;
	Date data_ini;
	Date data_fim;
	string preco_pessoa;
	string lugares_max;
	string lugares_reserv;



public:

	// GET methods
	string getId() const;
	string get_locais_visitar() const;
	Date get_data_ini() const;
	Date get_data_fim() const;
	string get_preco_pessoa() const;
	string get_lugares_max() const;
	string get_lugares_reserv() const;



	// SET methods
	void setId(string a);  // to set negatve if "deprecated"
	void set_locais_visitar(string b);
	void set_data_ini(Date c);
	void set_data_fim(Date d);
	void set_preco_pessoa(string e);
	void set_lugares_max(string f);
	void set_lugares_reserv(string g);

	void showpacket();
};

