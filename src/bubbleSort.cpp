//	BubbleSort.cpp
//
//	Criado por Leonardo dos Santos Matos
//	Código criado em aula na disciplina de Estrutura de Dados I
//ministrada pelo professor Eiji Adachi Medeiros Barbosa.
//	Adaptações foram feitas para que supra nessecidades do programa.

#include "sort.h"


void sort(Jogador* vetor, int tamanho)
{
	bool mudou = true;
	int fim  = tamanho - 1;
	while(mudou)
	{
		mudou = false;
		for(int j = 0; j < fim; j++)
		{
			if(vetor[j].getPontos() < vetor[j + 1].getPontos())
			{
				swap(vetor[j], vetor[j + 1]);
				mudou = true;
			}
		}
		fim -= 1;
	}
}