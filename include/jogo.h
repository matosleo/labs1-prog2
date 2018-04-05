#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "jogador.h"
#include "sort.h"

#define QTD_DADOS 2

class Jogo {

private:
	static int m_qtd_jogadores;
	int m_meta_pontos;
	int m_rodada;
	Dado m_saco_dados[QTD_DADOS];
	Jogador* m_vencedor = nullptr;
	bool temVencedor;

public:
	Jogo(int quant);
	~Jogo();

	static int getQtdJogadores();
	static void setQtdJogadores(int);

	void addJogadores(Jogador*);
	void imprimeRegra();
	int lancarDados();
	int verificaAtivos(Jogador*);
	void jogarRodada(Jogador*);
	void placarDaRodada(Jogador*);
	void exibeVencedor(Jogador*);
	void run();
};


#endif
