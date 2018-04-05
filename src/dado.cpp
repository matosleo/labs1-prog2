#include <random>
#include "dado.h"

Dado::Dado():rd(), gen(rd()), dis(1, 6) {
	m_valor = std::round(dis(gen));
}

Dado::~Dado(){}

void 
Dado::jogar() {
	m_valor = std::round(dis(gen));
}

int 
Dado::getValor() {
	return m_valor;
}