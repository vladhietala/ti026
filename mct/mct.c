#include <stdio.h>
#include <stdlib.h>

int main() {
	int numCasos, vitAlice = 0, vitBeto = 0;
	int i;
	char s[20001], s2[6];

	fgets(s2, 7, stdin);
	numCasos = atoi(s2);
	getc(stdin);
	while (numCasos != 0)
	{
		//if ((s = (char *)malloc((numCasos * sizeof(char) * 2) + 1)) == NULL) {
		//	return EXIT_FAILURE;
		//}
		fgets(s, (numCasos * 2) + 1, stdin);
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] != ' ')
			{
				if (s[i] == '0')
					vitAlice++;
				else
					if (s[i] == '1')
						vitBeto++;
			}
			i++;
		}
		//free(s);
		s[1] = '\0';
		printf("Alice ganhou %d e Beto ganhou %d\n", vitAlice, vitBeto);
		vitAlice = vitBeto = 0;
		fgets(s2, 5, stdin);
		numCasos = atoi(s2);
	}

	return 0;
}