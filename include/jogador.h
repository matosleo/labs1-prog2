#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include <iomanip>
#include "dado.h"


enum Status {exlcuido, ativo};

class Jogador {

private:
	int m_status;
	std::string m_nome;
	int m_total_pontos;

public:
	Jogador();
	~Jogador();

	std::string getNome();
	int getPontos();
	void setPontos(int);
	int getStatus();
	void setStatus(int);

	Jogador& operator=(Jogador const &j);
	friend std::ostream& operator<< (std::ostream &o, Jogador const j);
	friend std::istream& operator>>(std::istream &i, Jogador &j);
};

#endif