#include "Menu.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include <set>

void mainMenu(Agency agency) {

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
