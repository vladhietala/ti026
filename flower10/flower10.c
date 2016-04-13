#include <stdio.h>
#include <ctype.h>

#define false 0
#define true 1
#define bool char

int main() {
	char firstCharPhrase;
	bool isTauto = true;
	char c = 'a';

	while ((firstCharPhrase = tolower(getchar())) != '*') {
		isTauto = true;
		while ((c = getchar()) != '\n') {
			if (c == ' ')
				if ((c = tolower(getchar())) != firstCharPhrase) {
					isTauto = false;
				}
		}

		if (c == '\n') {
			if (isTauto)
				printf("Y\n");
			else
				printf("N\n");
		}
	}
	return 0;
}