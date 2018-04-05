#ifndef DADO_H
#define DADO_H

#include <random>

class Dado {
	private:
		int m_valor;
		std::random_device rd;
		std::default_random_engine gen;
		std::uniform_int_distribution<> dis;
	public:
		Dado();
		~Dado();

		void jogar();
		int getValor();
};

#endif