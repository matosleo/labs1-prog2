#include "jogador.h"


Jogador::Jogador() {
	m_status = ativo;
	m_total_pontos = 0;
}

Jogador::~Jogador(){}

std::string
Jogador::getNome() {
	return m_nome;
}

int
Jogador::getPontos() {
	return m_total_pontos;
}

void 
Jogador::setPontos(int pontos) {
	m_total_pontos += pontos;
}

int
Jogador::getStatus() {
	return m_status;
}

void 
Jogador::setStatus(int s) {
	m_status = s;
}

Jogador& 
Jogador::operator=(Jogador const &j) {
	m_status = j.m_status;
	m_nome = j.m_nome;
	m_total_pontos = j.m_total_pontos;
	return *this;
}

std::ostream& 
operator<< (std::ostream &o, Jogador const j) {
	o << std::setw(12) << std::left << j.m_nome << " | " << j.m_total_pontos << " pontos" << std::endl;
	return o;
}

std::istream& 
operator>>(std::istream &i, Jogador &j) {	
	i >> j.m_nome;
	return i;
}
