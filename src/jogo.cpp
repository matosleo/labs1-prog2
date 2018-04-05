#include "jogo.h"

int Jogo::m_qtd_jogadores = 0;

Jogo::Jogo(int quant) {
	m_qtd_jogadores = quant;
	m_meta_pontos = 0;
	m_rodada = 1;
	temVencedor = false;
}

Jogo::~Jogo() {}

int 
Jogo::getQtdJogadores(){
	return m_qtd_jogadores;
}

void 
Jogo::setQtdJogadores(int quant){
	m_qtd_jogadores = quant;
}

void
Jogo::addJogadores(Jogador* lista){
	Jogador j;
	for(int i = 0; i < m_qtd_jogadores; i++) {
		std::cout << "Digite o nome do jogador " << i+1 <<std::endl;
		std::cin >> j;
		lista[i] = j;
	}
}


void
Jogo::imprimeRegra() {
	std::cout << std::endl
	<< "**************************** REGRAS DO JOGO ****************************\n"
	<< "\n"
	<< "   O objetivo é tentar atingir através de sucessivos lances de dados,\n"
	<< " a quantidade de pontos estabelecida como meta no início do jogo.\n"
	<< "   A cada rodada os jogadores lançam os dados, acumulam pontos e\n"
	<< " somam no seu placar.\n"
	<< "   Os jogadores podem escolher passar a vez\n"
	<< "   Se todos passarem a vez, o jogo termina. Aquele com o placar\n"
	<< " mais próximo da meta será o vencedor\n"
	<< "\n"
	<< "**************************************************************************\n"
	<< std::endl;
}

int
Jogo::lancarDados() {
	int pontosDados = 0;
	for(int i = 0; i < QTD_DADOS; i++) {
		m_saco_dados[i].jogar();
		pontosDados += m_saco_dados[i].getValor();
	}
	return pontosDados;
}

int
Jogo::verificaAtivos(Jogador* lista) {
	int contAtivos = 0;
	for(int i = 0; i < m_qtd_jogadores; i++) {
		if(lista[i].getStatus() == 1) {
			contAtivos++;
		}
	}
	return contAtivos;
}

void
Jogo::jogarRodada(Jogador* lista) {
	int opcao, flagContadora = 0;
	bool venceu = false, valido = false;
	
	for(int i = 0; i < m_qtd_jogadores; i++) {
		if(!venceu) {
			if(lista[i].getStatus() == 1) {
				do {
					std::cout << lista[i].getNome() << " voce tem " << lista[i].getPontos() << " pontos, deseja lançar os dados?\n"
					<< " 1 - Lançar dados\n"
					<< " 2 - Esperar\n"
					<< "\n"
					<< "opcao: ";
					std::cin >> opcao;
					switch(opcao) {
						case 1:
						{
							int pontos = lancarDados();
							lista[i].setPontos(pontos);
							std::cout << "Voce somou " << lista[i].getPontos() << " pontos nesse lance\n"
							<< std::endl;
							flagContadora++;
							valido = true;
							break;
						}

						case 2:
						{
							std::cout << lista[i].getNome() << " passou a vez!\n" << std::endl;
							valido = true;
							break;
						}

						default:
						{
							std::cout << std::endl << "!ERRO!\n"
							<< "Digite uma opção válida\n" << std::endl;
							break;
						}
					}
				}while(!valido);

			}

			if(lista[i].getStatus() == 1 && lista[i].getPontos() > m_meta_pontos) {
				std::cout << std::endl << "Que pena. Seus pontos passaram do valor da meta\n"
				<< "Voce foi desclassificado.\n" << std::endl;
				lista[i].setStatus(0);
			}

			if(lista[i].getPontos() == m_meta_pontos) {
				m_vencedor = &lista[i];
				temVencedor = true;
				venceu = true;
			}

			if(verificaAtivos(lista) == 1) {
				for(int i = 0; i < m_qtd_jogadores; i++) {
					if(lista[i].getStatus() == 1) {
						m_vencedor = &lista[i];
					}
				}
				venceu = true;
				temVencedor = true;
			}
		}
	}
	if(flagContadora == 0) {
		int maiorPonto = 0;
		for(int i = 0; i < m_qtd_jogadores; i++) {
			if(lista[i].getStatus() == 1) {
				if(lista[i].getPontos() > maiorPonto) {
					maiorPonto = lista[i].getPontos();
					m_vencedor = &lista[i];
				}
			}
		}
		temVencedor = true;
	}		
}

void 
Jogo::placarDaRodada(Jogador* lista) {
	Jogador *tmp = new Jogador [m_qtd_jogadores];
	for(int i = 0; i < m_qtd_jogadores; i++) {
		tmp[i] = lista[i];
	}

	sort(tmp, m_qtd_jogadores);
	std::cout << std::endl << "        PLACAR DA RODADA" << std::endl;
	for(int i = 0; i < m_qtd_jogadores; i++) {
		std::cout << i+1 <<"º " << tmp[i];
	}
	std::cout << std::endl;
}


void
Jogo::exibeVencedor(Jogador* vencedor) {
	std::cout << std::endl << "O GRANDE VENCEDOR FOI " << vencedor->getNome() 
			<< ", COM " << vencedor->getPontos() 
			<< " PONTOS" << std::endl;
}

void
Jogo::run() {
		int opcao;

	do {
		std::cout << std::endl
		<< " 1 - Jogar\n"
		<< " 2 - Regras do jogo\n"
		<< " 0 - Sair\n"
		<< "\n"
		<< " Opção: ";
		std::cin >> opcao;

		switch(opcao) {
			case 1:
			{
				Jogador *lista_jogadores = new Jogador [m_qtd_jogadores];
				addJogadores(lista_jogadores);
				int quantMeta;
				std::cout << "Quantos pontos será a meta a ser atingida na partida? ";
				std::cin >> quantMeta;
				m_meta_pontos = quantMeta;

				while(!temVencedor) {
					std::cout << "------------------- Rodada " << m_rodada << " -------------------" << std::endl;
					jogarRodada(lista_jogadores);
					placarDaRodada(lista_jogadores);
					m_rodada++;
				}
				std::cout << "---------------------------- FIM DE JOGO ----------------------------" << std::endl;
				exibeVencedor(m_vencedor);
				opcao = 0;
				break;
			}
			
			case 2:
			{
				imprimeRegra();
				break;			
			}

			case 0:
			{
				std::cout << std::endl <<  "Até logo!" << std::endl;
				break;
			}

			default:
			{
				std::cout << std::endl << "!ERRO!\n"
				<< "Digite uma opção válida"
				<< std::endl;
				break;
			}
		}

	} while(opcao != 0);
}