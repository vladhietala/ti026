#include <stdio.h>

int main() {
	int i, j, qtdeAlunos, totalVotos, maiorVotacao = 0;
	int cedula[100][100];

	while (scanf("%d", &qtdeAlunos) && qtdeAlunos != 0) {
		maiorVotacao = 0;
		for (i = 0; i < qtdeAlunos; i++)
			for (j = 0; j < qtdeAlunos; j++)
				scanf("%d", &cedula[i][j]);
		for (i = 0; i < qtdeAlunos; i++) {
			totalVotos = 0;
			for (j = 0; j < qtdeAlunos; j++)
				totalVotos += cedula[j][i];
			if (totalVotos > maiorVotacao)
				maiorVotacao = totalVotos;
		}
		printf("%d\n", maiorVotacao);
	}
	return 0;
}