#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct NODO
{
	char nome[21];
	struct NODO *prox;
	struct NODO *ant;

}nodo;

nodo* findReg(nodo *, nodo *, int , int );
void isrtLista(nodo *, nodo **, nodo **);

int main() {

	int qdteNomes, numSorteado = 0;
	int i;
	char nome[21];
	nodo *firstReg, *lastReg, *regSorteado, *newReg;
	//nodo regSorteado;
	firstReg = lastReg = regSorteado = newReg = NULL;
	scanf("%d %d", &qdteNomes, &numSorteado);
	for (i = 0; i < qdteNomes; i++)
	{
		scanf("%s", nome);
		if ((newReg = (nodo *)malloc(sizeof(nodo))) == NULL) {
			printf("Erro de alocação de memória");
			exit(EXIT_FAILURE);
		}
		strcpy(newReg->nome, nome);
		newReg->prox = NULL;
		newReg->ant = NULL;
		isrtLista(newReg, &firstReg, &lastReg);
	}
	regSorteado = firstReg;

	regSorteado = findReg(firstReg, regSorteado, numSorteado, 1);
	printf("%s", regSorteado->nome);
	return EXIT_SUCCESS;
}

nodo* findReg(nodo *firstReg, nodo *regAtual, int numSorteado, int numAtual) {

	if (numSorteado == numAtual)
		return regAtual;
	else
		findReg(firstReg, regAtual->prox, numSorteado, ++numAtual);
}

void isrtLista(nodo *newReg /*Novo registro*/, nodo **firstReg /*Primeiro registro*/, nodo **lastReg /*Ultimo registro*/) {
	nodo *old, *aux;

	aux = *lastReg; /* começa no final da lista */
	if (aux == NULL) /* se ultimo registro da lista */
	{
		newReg->prox = NULL;
		newReg->ant = NULL;
		*firstReg = newReg;
		*lastReg = newReg;
		return;
	}
	old = NULL;
	while (aux)
	{
		if (strcmp(aux->nome, newReg->nome) > 0)
		{
			old = aux;
			aux = aux->ant;
		}
		else
		{
			if (aux->prox) {
				aux->prox->ant = newReg;
				newReg->ant = aux;
				newReg->prox = aux->prox;
				aux->prox = newReg;
				return;
			}
			newReg->ant = aux; /* novo primeiro elemento */
			newReg->prox = NULL;
			aux->prox = newReg;
			*lastReg = newReg;
			return;
		}
	}
	old->ant = newReg;    /* coloca no começo */
	newReg->ant = NULL;
	newReg->prox = old;
	*firstReg = newReg;
}