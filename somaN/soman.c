#include <stdlib.h>
#include <stdio.h>


int main() {

	int i, qtdeNum, x, soma = 0;
	scanf("%d", &qtdeNum);

	for (i = 0; i < qtdeNum; i++)
	{
		scanf("%d", &x);
		soma += x;
	}
	printf("%d\n", soma);
	return 0;
}