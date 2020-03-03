#include <stdio.h>
#include <string.h> 

int main() {

	char input[255];
	printf("Enter a sentence, up to 255 characters:\n");
	fgets(input, 255, stdin);
	int counter = 0;
	int lencounter = 0;
	int maxlen = 0;
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == ' ' || input[i] == '.') {
			if (lencounter > maxlen) {
				maxlen = lencounter;
			}
			lencounter = 0;
		}
		else {
			lencounter = lencounter + 1;
		}
	}
	maxlen = maxlen + 1;
	
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == ' ') {
			printf(" %*d\n", maxlen-counter ,counter);
			counter = 0; 
		}
		else if (input[i] == '.') {
			printf(" %*d\n", maxlen-counter, counter);
			counter = 0;
		}
		else {
			counter = counter + 1;
			printf("%c" , input[i]);
		}
	}
	char * ptr = strstr(input, "mat");
	if (ptr != NULL) {
		printf("%s", "You found the magic word!\n\n");
	}
	return 0;
};