//
//  Sort.h
//  Aula-Ordenacao
//
//	Criado por Leonardo dos Santos Matos
//	Código criado em aula na disciplina de Estrutura de Dados I
//ministrada pelo professor Eiji Adachi Medeiros Barbosa.
//	Adaptações foram feitas para que supra nessecidades do programa.

#ifndef Sort_h
#define Sort_h

#include "jogador.h"

void sort(Jogador*, int);

inline void swap(Jogador& x, Jogador& y)
{
    Jogador aux = x;
    x = y;
    y = aux;
}

#endif /* Sort_hpp */
