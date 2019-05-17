#pragma once
#include "Agency.h"

using namespace std;

Client add_info_cliente();
void add_cliente();
void ler_clientes();
int find_nif(string name_file, const string nif);
Client modify_clients();
void apagar_cliente();
void cliente_formatado();
void todos_clientes_formatados();
string ler_linha(int line, string file);
Packet add_info_pacote();
void add_pacote();
void ler_pacotes();
Packet modify_packages();
void apagar_pacote();
void pacote_formatado();
void todos_pacotes_formatados();
void comprar_pacote();
void ler_agencia();
void agencia_formatada();
