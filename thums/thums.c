#include <stdio.h>

#define THUMS "THUMS"

int main() {
	int numLinhas, i, numT = 0;

	scanf("%d", &numLinhas);

	for (i = 0; i < numLinhas; i++)
	{
		if ((i % 2) == 0)
			printf("THUMS THUMS THUMS\n");
		else
			printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
	}
	return 0;
}