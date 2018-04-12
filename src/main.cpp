/**
 * @file	main.cpp
 * @brief	aquivo main que executa o jogo
 * @author	Leonardo dos Santos Matos
 * @since	20/03/2018
 * @date	05/04/2018
 * @sa		https://github.com/matosleo
 */

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