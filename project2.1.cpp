// project2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>
#include <stdlib.h>
#include "Date.h"
#include "Adress.h"
#include "Client.h"
#include "Packet.h"
#include "Agency.h"
#include "Menu.h"

using namespace std;


//MUDAR LINHA PELO INDEX
void change_line(const char *file_name, int id, string new_value, bool needs_newline = true)
{
	// open file in read mode or in mode 
	ifstream is(file_name);

	// open file in write mode or out mode 
	ofstream ofs;
	ofs.open("temp_dl.txt");

	// loop getting a line
	string c;
	int line_no = 0;
	while (getline(is, c))
	{
		if (line_no == id) {
			ofs << new_value;
			if (needs_newline) {
				ofs << endl;
			}
		}
		else {
			ofs << c << endl;
		}
		line_no++;
	}

	// closing output file 
	ofs.close();

	// closing input file 
	is.close();

	// remove the original file 
	remove(file_name);

	// rename the file 
	rename("temp_dl.txt", file_name);
}

//LER LINHA POR INDEX
void read_line(const char *file_name, int nif)
{
	// open file in read mode or in mode 
	ifstream is(file_name);

	// loop getting a line
	string c;
	int line_no = 0;
	while (getline(is, c))
	{

	}

	// closing input file 
	is.close();
}

//Passar Adress para string
string to_string(Adress a) {
	return a.getStreet() + " / " + a.getDoorNumber() + " / " + a.getFloor() + " / " + a.getPostalCode() + " / " + a.getLocation();
}


//////////////////////////////////// C L I E N T E S ///////////////////////////////////////////////////////////////

//ADICIONAR CLIENTE
Client add_info_cliente() {
	Client cliente;
	Adress morada;
	string ans, a, b, c, d, e;
	cout << "\n-------- - ADICIONAR NOVO CLIENTE------------\n";
	cout << "\nNome: ";
	getline(cin, ans);
	cliente.setName(ans);
	cout << "\nNIF: ";
	getline(cin, ans);
	cliente.setVATnumber(ans);
	cout << "\nNumero de pessoas no agregado familiar: ";
	getline(cin, ans);
	cliente.setFamilySize(ans);
	cout << "\nMorada";
	cout << "\nRua: ";
	getline(cin, a);
	cout << "\nNumero da Porta: ";
	getline(cin, b);
	cout << "\nAndar(se nao tiver andar escreva '-'): ";
	getline(cin, c);
	cout << "\nCodigo Postal: ";
	getline(cin, d);
	cout << "\nLocalidade: ";
	getline(cin, e);
	morada.adress(a, b, c, d, e);
	cliente.setAddress(morada);
	cout << "\nLista de Pacotes Turisticos Comprados: ";
	getline(cin, ans); //vai buscar os pacotes turisticos como string
	cliente.setPacketList(ans);// fazer o set para adicionar a lista de pacotes turisticos ao cliente
	return cliente;
}
void add_cliente() {

	ofstream Clientes;
	Clientes.open("clients.txt", ios::ios_base::app);

	Client cliente = add_info_cliente();

	Clientes << "\n::::::::::" << endl;
	Clientes << cliente.getName() << endl;
	Clientes << cliente.getVATnumber() << endl;
	Clientes << cliente.getFamilySize() << endl;
	Clientes << cliente.getAddress() << endl;
	Clientes << cliente.getPacketList() << endl;
	Clientes.close();
}

//LER FICHEIRO CLIENTS
void ler_clientes() {
	string getcontent;
	ifstream openfile("clients.txt");
	if (openfile.is_open()) {
		while (!openfile.eof()) {
			getline(openfile, getcontent);
			cout << getcontent << endl;
		}
	}
}

//Encontrar NIF
int find_nif(string name_file, const string nif) {

	string temp;
	ifstream infile(name_file);
	int i = 0;
	while (getline(infile, temp)) {
		if (nif == temp) {
			infile.close();
			return i;
		}
		i++;

	}
	infile.close();
	return -1;
}

//ALTERAR FICHEIRO CLIENTE
Client modify_clients() {
	Client cliente;
	Adress morada;
	int value;
	string val;
	string search = cliente.getVATnumber();
	int index;
	fstream file;
	int nif;
	string ans, a, b, c, d, e;
	cout << "qual o nif do cliente que queres alterar? " << endl;
	cin >> nif;

	int index_a_mudar = find_nif("clients.txt", to_string(nif));

	cout << "O que pretende mudar?" << endl;
	cout << "[1] nome" << endl;
	cout << "[2] nif" << endl;
	cout << "[3] numero de pessoas do agregado familiar" << endl;
	cout << "[4] morada" << endl;
	cout << "[5] pacotes turisticos comprados" << endl;
	cin >> value;

	index = (index_a_mudar - 1) + (value - 1);

	switch (value) {
	case 1:
		cout << "Insere o novo Nome: " << endl;
		cin.ignore();
		getline(cin, ans);
		cliente.setName(ans);
		val = cliente.getName();
		break;

	case 2:
		cout << "Insere o novo NIF: " << endl;
		cin.ignore();
		getline(cin, ans);
		cliente.setVATnumber(ans);
		val = cliente.getVATnumber();
		break;

	case 3:
		cout << "Insere o número de pessoas no agregado familar: " << endl;
		cin.ignore();
		cin >> ans;
		cliente.setFamilySize(ans);
		val = cliente.getFamilySize();
		break;

	case 4:
		cout << "Insere a nova morada" << endl;
		cout << "Rua: ";
		cin.ignore();
		getline(cin, a);
		morada.setStreet(a);
		cout << "Numero: ";
		getline(cin, b);
		morada.setDoorNumber(b);
		cout << "Andar(se não tiver escreva '-'): ";
		getline(cin, c);
		morada.setLocation(c);
		cout << "Código Postal: ";
		cin.ignore();
		getline(cin, d);
		morada.setPostalCode(d);
		cout << "Localidade: ";
		getline(cin, e);
		morada.setLocation(e);
		morada.adress(a, b, c, d, e);
		cliente.setAddress(morada);
		val = to_string(morada);
		break;

	case 5:
		cout << "Pacotes Turisticos comprados: " << endl;
		cin.ignore();
		getline(cin, ans);
		cliente.setPacketList(ans);
		val = cliente.getPacketList();
		cout << val << endl;
		break;
	}

	cout << index;
	change_line("clients.txt", index, val);
	return cliente;
}

//ELIMINAR CLIENTE
void apagar_cliente()
{
	int nif;
	cout << "Qual o NIF do cliente que queres apagar? " << endl;
	cin >> nif;
	int x;
	string val = "";
	x = find_nif("clients.txt", to_string(nif));
	for (int i = 0; i < 6; i++) {
		change_line("clients.txt", x - 1, val, false);
	}

}

//FORMATAR UM CLIENTE
void cliente_formatado() {
	string choice, l;
	string nif;
	Client cliente;
	int x;
	int index = 0;

	cout << "Qual o NIF do cliente que quer visualizar? " << endl;
	cin >> nif;
	x = find_nif("clients.txt", nif);

	ifstream openfile("clients.txt");

	while (getline(openfile, l)) {
		if (index == x - 1) {
			cout << endl;
			cout << "Nome: " << l << endl;

			getline(openfile, l);
			cout << endl;
			cout << "NIF: " << l << endl;

			getline(openfile, l);
			cout << endl;
			cout << "Numero de Pessoas no Agregado Familiar: " << l << endl;

			getline(openfile, l);
			cout << endl;
			cout << "Morada: " << l << endl;

			getline(openfile, l);
			cout << endl;
			cout << "Pacotes Comprados: " << l << endl;
			cout << endl << endl;

			break;
		}
		index++;
	}
}

//FORMATAR TODOS OS CLIENTES
void todos_clientes_formatados() {
	string choice, l;
	ifstream openfile("clients.txt");

	if (openfile.is_open())
	{
		while (getline(openfile, l))					//enquanto houver linhas para ler
		{

			if (l != "::::::::::") {
				int line = 0;

				cout << endl;
				cout << "Nome do Cliente: " << l << endl;

				getline(openfile, l);
				cout << endl;
				cout << "NIF do Clientes: " << l << endl;

				getline(openfile, l);
				cout << endl;
				cout << "Numero de Elementos da Familia: " << l << endl;

				getline(openfile, l);
				cout << endl;
				cout << "Morada: " << l << endl;

				getline(openfile, l);
				cout << endl;
				cout << "Pacotes Comprados: " << l << endl;
				cout << endl << endl;


			}

		}
	}
}


//////////////////////////////////// P A C O T E S ///////////////////////////////////////////////////////////////

//LER LINHA DE FICHEIRO
string ler_linha(int line, string file) {
	ifstream openfile(file);
	string temp1;
	int index = 0;
	while (getline(openfile, temp1)) {
		if (index == line)
			return temp1;
		index++;
	}
	openfile.close();
}

//ADICIONAR PACOTE
Packet add_info_pacote() {
	Packet pacote;
	bool second_place = true;
	Date data1, data2;
	Adress morada;
	string decisao, ans;
	string temp;
	string a, b, c;

	cout << "ID: " << endl;
	getline(cin, ans);
	pacote.setId(ans);

	cout << "Destino: " << endl;
	getline(cin, ans);
	pacote.set_locais_visitar(ans);

	cout << "Pretende adicionar mais algum local?(SIM/NAO) " << endl;
	cin >> decisao;
	cin.ignore();
	while (decisao == "SIM") {

		if (second_place) {
			pacote.get_locais_visitar() += " - ";
			second_place = false;
		}
		cout << "Insira onde mais pretende ir: " << endl;
		getline(cin, temp);
		pacote.get_locais_visitar() += temp;
		pacote.get_locais_visitar() += ", ";
		cout << "Pretende adicionar mais algum local?(SIM/NAO)" << endl;
		cin >> decisao;
		cin.ignore();
	}
	pacote.get_locais_visitar() = pacote.get_locais_visitar().substr(0, pacote.get_locais_visitar().length() - 2);
	cout << pacote.get_locais_visitar();

	cout << "\nData de inicio(ano mês dia): " << endl;
	cout << "Dia: " << endl;
	getline(cin, a);
	cout << "Mes: " << endl;
	getline(cin, b);
	cout << "Ano: " << endl;
	getline(cin, c);
	data1.date(a, b, c);

	cout << "\nData de fim(ano mês dia): " << endl;
	cout << "Dia: " << endl;
	getline(cin, a);
	cout << "Mes: " << endl;
	getline(cin, b);
	cout << "Ano: " << endl;
	getline(cin, c);
	data2.date(a, b, c);

	cout << "\nPreço por pessoa: ";
	getline(cin, ans);
	pacote.set_preco_pessoa(ans);

	cout << "\nNumero Máximo de pessoas que se podem inscrever: " << endl; 
	getline(cin, ans);
	pacote.set_lugares_max(ans);

	cout << "\nNumero de Reservas Feitas no Pacote: " << endl;
	getline(cin, ans);
	pacote.set_lugares_reserv(ans);

	return pacote;
}
void add_pacote() {
	ifstream infile("packs.txt");
	bool ficheiro_vazio = false;

	string string_id;
	getline(infile, string_id);

	if (string_id == "") {
		string_id = "0";
		ficheiro_vazio = true;
	}

	int id = stoi(string_id);
	id++;

	infile.close();

	//atualiza numero de pacotes existentes em packs.txt
	if (!ficheiro_vazio) {
		change_line("packs.txt", 0, to_string(id));

	}

	ofstream Pacotes;
	Pacotes.open("packs.txt", ios::ios_base::app);

	Packet pacote = add_info_pacote();

	Pacotes << "\n:::::::::" << endl;
	Pacotes << pacote.getId() << endl;
	Pacotes << pacote.get_locais_visitar() << endl;
	Pacotes << pacote.get_data_ini() << endl;
	Pacotes << pacote.get_data_fim() << endl;
	Pacotes << pacote.get_preco_pessoa() << endl;
	Pacotes << pacote.get_lugares_max() << endl;
	Pacotes << pacote.get_lugares_reserv() << endl;
	Pacotes.close();
}

//LER FICHEIRO PACKS
void ler_pacotes() {
	Packet pacotes;
	string getcontent;
	ifstream openfile("packs.txt");
	if (openfile.is_open()) {
		while (!openfile.eof()) {
			getline(openfile, getcontent);
			cout << getcontent << endl;
		}
	}
}

//ALTERAR FICHEIRO PACKS
Packet modify_packages(){
	Packet pacote;
	Date data1, data2;
	int value;
	string val;
	bool second_place = true;
	string decision;
	string temporary;
	int index;
	int id;
	string a, b, c;

	cout << "Qual o ID do pacote que queres alterar?: " << endl;
	cin >> id;

	cout << "O que pretende alterar?" << endl;
	cout << "[1] sitio a visitar" << endl;
	cout << "[2] data de inicio" << endl;
	cout << "[3] data de fim" << endl;
	cout << "[4] preço por pessoa" << endl;
	cout << "[5] número máximo de pessoas a comprar o pacote" << endl;
	cin >> value;
	cin.ignore();

	index = 1 + (abs(id) - 1) * 9 + value;

	switch (value) {
	case 1:
		cout << "O novo sitio a visitar: " << endl;
		cin.ignore();
		getline(cin, val);
		pacote.set_locais_visitar(val);
		cout << "Tens mais sitios a visitar?(SIM/NÃO)" << endl;
		cin >> decision;
		while (decision == "SIM") {

			if (second_place) {
				pacote.get_locais_visitar() += " - ";
				second_place = false;
			}
			cout << "O novo sitio a visitar: " << endl;
			cin.ignore();
			getline(cin, temporary);
			pacote.get_locais_visitar() += temporary;
			pacote.get_locais_visitar() += ", ";

			cout << "Tens mais sitios a visitar?(SIM/NÃO)" << endl;
			cin >> decision;

		}

		pacote.get_locais_visitar() = pacote.get_locais_visitar().substr(0, pacote.get_locais_visitar().length() - 2);
		val = pacote.get_locais_visitar();
		break;

	case 2:
		cout << "Insere a nova data de inicio: " << endl;
		cout << "Dia: ";
		getline(cin, a);
		cout << "\nMes: ";
		getline(cin, b);
		cout << "\nAno: ";
		getline(cin, c);
		data1.date(a, b, c);
		break;

	case 3:
		cout << "Insere a nova data de fim: " << endl;
		cout << "Dia: ";
		getline(cin, a);
		cout << "\nMes: ";
		getline(cin, b);
		cout << "\nAno: ";
		getline(cin, c);
		data2.date(a, b, c);
		break;

	case 4:
		cout << "Introduz o preço por passageiro: " << endl;
		cin.ignore();
		getline(cin, val);
		pacote.set_preco_pessoa(val);
		cout << val << endl;
		break;

	case 5:
		cout << "Insere o numero maximo de pessoas que podem comprar este pacote: " << endl;
		cin.ignore();
		getline(cin, val);
		pacote.set_lugares_max(val);
		break;

	case 6:
		cout << "Insere o numero de pessoas que reservaram este pacote: " << endl;
		cin.ignore();
		getline(cin, val);
		pacote.set_lugares_reserv(val);
		break;
	}

	change_line("packs.txt", index, val);
	return pacote;
}

//ELIMINAR PACOTE
void apagar_pacote()
{
	int id;
	cout << "Qual o ID do pacote que queres apagar? " << endl;
	cin >> id;
	int x;
	string val = "";
	x = find_nif("packs.txt", to_string(id));
	for (int i = 0; i < 9; i++) {
		change_line("packs.txt", x - 1, val, false);
	}

}

//FORMATAR PACOTE
void pacote_formatado() {
	string choice, l;
	string id;
	int x;
	int index = 0;

	cout << "Insira o ID do Pacote: " << endl;
	cin >> id;
	x = find_nif("packs.txt", id);

	ifstream openfile("packs.txt");

	while (getline(openfile, l)) {
		if (index == x) {
			cout << endl;
			cout << "ID: " << l << endl;

			getline(openfile, l);
			cout << endl;
			cout << "Destino: " << l << endl;

			getline(openfile, l);
			cout << endl;
			cout << "Data de Inicio: " << l << endl;

			getline(openfile, l);
			cout << endl;
			cout << "Data de Fim: " << l << endl;

			getline(openfile, l);
			cout << endl;
			cout << "Preço: " << l << endl;

			getline(openfile, l);
			cout << endl;
			cout << "Lugares Disponiveis: " << l << endl;

			getline(openfile, l);
			cout << endl;
			cout << "Lugares Vendidos: " << l << endl;
			cout << endl << endl;


			break;
		}
		index++;
	}
}

//FORMATAR TODOS OS PACOTES
void todos_pacotes_formatados() {
	string choice, l;
	ifstream openfile("packs.txt");
	getline(openfile, l);								//descarta a primeira linha
	if (openfile.is_open())
	{
		while (getline(openfile, l))					//enquanto houver linhas para ler
		{

			if (l != "::::::::::") {


				cout << endl;
				cout << "Id: " << l << endl;

				getline(openfile, l);
				cout << endl;
				cout << "Destino: " << l << endl;

				getline(openfile, l);
				cout << endl;
				cout << "Data de Inicio: " << l << endl;

				getline(openfile, l);
				cout << endl;
				cout << "Data de Fim: " << l << endl;

				getline(openfile, l);
				cout << endl;
				cout << "Preço: " << l << endl;

				getline(openfile, l);
				cout << endl;
				cout << "Lugares Disponiveis: " << l << endl;

				getline(openfile, l);
				cout << endl;
				cout << "Lugares Vendidos: " << l << endl;
				cout << endl << endl;

			}

		}
	}
}

//COMPRAR PACOTES
void comprar_pacote() {
	string nif;
	int x;
	int id;
	string pacotes;
	cout << "Insira o seu NIF: " << endl;
	cin >> nif;
	x = find_nif("clients.txt", nif);
	int index = x + 3;

	pacotes = ler_linha(index, "clients.txt");

	cout << "Insira o ID do pacote que quer comprar: ";
	cin >> id;
	if (pacotes == "-") {
		change_line("clients.txt", index, to_string(id));
	}
	else
		change_line("clients.txt", index, pacotes + " ; " + to_string(id));
}



//////////////////////////////////// A G E N C I A ///////////////////////////////////////////////////////////////
//LER FICHEIRO AGENCY
void ler_agencia() {
	Agency agencia;
	string getcontent;
	ifstream openfile("agency.txt");
	if (openfile.is_open()) {
		while (!openfile.eof()) {
			getline(openfile, getcontent);
			cout << getcontent << endl;
		}
	}
}

//FORMATAR AGENCIA
void agencia_formatada() {
	Packet pacote;
	int line = 0;
	string l;
	ifstream openfile("agency.txt");

	while (line != 1 && getline(openfile, l)) {
		line++;
	}
	cout << "Nome: " << l << endl;

	while (line != 2 && getline(openfile, l)) {
		line++;
	}
	cout << "NIF: " << l << endl;

	while (line != 3 && getline(openfile, l)) {
		line++;
	}
	cout << "URL: " << l << endl;

	while (line != 4 && getline(openfile, l)) {
		line++;
	}
	cout << "Morada: " << l << endl;
}


int main()
{
	int val;

menu_inicial:
	cout << "---------------------MENU INICIAL---------------------\n";
	cout << "\nSelecione uma opcao:\n";
	cout << "\n[1] - AGENCIA\n";
	cout << "\n[2] - CLIENTE\n";
	cout << "\n[3] - PACOTES DE VIAGENS\n";

	cin >> val;
	system("cls");
	cin.ignore();

	switch (val) {
	case 1:
	{
	menu_agencia:
		cout << "---------------------AGENCIA---------------------\n";
		cout << "\nSelecione uma opcao:\n";
		cout << "\n[1] - Ver Dados da Agencia\n";
		cout << "\n[2] - Voltar para Menu inicial\n";
		cout << "\n[3] - Sair\n";

		cin >> val;

		system("cls");

		switch (val) {
		case 1:
			agencia_formatada();
			break;

		case 2:
			goto menu_inicial;
			break;

		case 3:
			exit(0);
			break;

		default:
			cout << "\nOpcao Invalida! Selecione uma das opcoes em baixo: " << endl;
			system("cls");
			goto menu_agencia;
		}
		break;
	}
	case 2: {
	menu_clientes:
		cout << "---------------------CLIENTES---------------------\n";
		cout << "\nSelecione uma opcao:\n";
		cout << "\n[1] - Ver Dados dos Clientes\n";
		cout << "\n[2] - Alterar dados dos clientes\n";
		cout << "\n[3] - Adicionar Cliente\n";
		cout << "\n[4] - Remover Cliente\n";
		cout << "\n[5] - Voltar para Menu Inicial\n";

		cin >> val;
		cin.ignore();
		system("cls");

		switch (val) {
		case 1:
			cout << "\nSelecione uma opcao:\n";
			cout << "\n[1] - Ver Dados de Todos os Clientes\n";
			cout << "\n[2] - Ver Dados de um específico cliente\n";
			cout << "\n[3] - Voltar para Menu Clientes\n";

			cin >> val;
			cin.ignore();
			system("cls");

			switch (val)
			{
			case 1:
				todos_clientes_formatados();
				break;

			case 2:
				cliente_formatado();
				break;

			case 3:
				goto menu_clientes;
				break;

			default:
				cout << "\nOpcao Invalida! Selecione uma das opcoes em baixo: " << endl;
				goto menu_clientes;
				break;
			}
			break;

		case 2:
			modify_clients();
			break;

		case 3:
			add_cliente();
			break;

		case 4:
			apagar_cliente();
			break;

		case 5:
			goto menu_inicial;
			break;

		default:
			cout << "\nOpcao Invalida! Selecione uma das opcoes em baixo: " << endl;
			goto menu_clientes;
		}
		break;
	}

	case 3:
	{
	menu_pacotes:
		cout << "---------------------PACOTES---------------------\n";
		cout << "\nSelecione uma opcao:\n";
		cout << "\n[1] - Visualizar Pacotes\n";
		cout << "\n[2] - Alterar dados dos Pacotes\n";
		cout << "\n[3] - Comprar Pacote\n";
		cout << "\n[4] - Adicionar Pacote\n";
		cout << "\n[5] - Eliminar Pacote\n";
		cout << "\n[6] - Voltar para Menu Inicial\n";

		cin >> val;
		system("cls");

		switch (val) {
		case 1:
			cout << "\nSelecione uma opcao:\n";
			cout << "\n[1] - Ver Dados de Todos os Pacotes\n";
			cout << "\n[2] - Ver Dados de um específico pacote\n";
			cout << "\n[3] - Voltar para Menu Pacotes\n";

			cin >> val;
			cin.ignore();
			system("cls");

			switch (val)
			{
			case 1:
				todos_pacotes_formatados();
				break;

			case 2:
				pacote_formatado();
				break;

			case 3:
				goto menu_pacotes;
				break;

			default:
				cout << "\nOpcao Invalida! Selecione uma das opcoes em baixo: " << endl;
				goto menu_pacotes;
				break;
			}
			break;
		case 2:
			modify_packages();
			break;

		case 3:
			comprar_pacote();
			break;

		case 4:
			add_pacote();
			break;

		case 5:
			apagar_pacote();
			break;

		case 6:
			goto menu_inicial;
			break;

		default:
			cout << "\nOpcao Invalida! Selecione uma das opcoes em baixo: " << endl;
			goto menu_pacotes;
		}
		break;
	}


	default:
		cout << "\nOpcao Invalida! Selecione uma das opcoes em baixo: " << endl;
		goto menu_inicial;
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
