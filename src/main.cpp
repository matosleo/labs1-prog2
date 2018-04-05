#include <iostream>
#include "jogo.h"

int main(int argc, char const *argv[]) {

	int quant;
	std::cout << "Quantos jogadores irão participar do jogo? ";
	std::cin >> quant;
	Jogo::setQtdJogadores(quant);

	Jogo jogo(Jogo::getQtdJogadores());
	jogo.run();

	return 0;
}