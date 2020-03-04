#include <stdio.h>
#include <string.h> 
#include <ctype.h>
int strncmp1(char * string, char * pattern, char * sens) {
	char dest[255] = "";
	int number = 0;
	int transformBoo = 0; // 0 means no whitespace , 1 means got white space

	//Get total number of .'s if there is 
	for (int i = 0; i < strlen(pattern); i++) {
		//Detect if there is a _ in the pattern 
		if (pattern[i] == '_') {
			transformBoo = 1;
		}
		// Adds the total number of dots to a list
		if (pattern[i] == '.') {
			number = i + 1; 
		}
		// Adds the rest of the value to a new string 
		else {
			char array[2];
			array[0] = pattern[i];
			array[1] = '\0';
			// strcat_s(dest, 255, array);
      strcat(dest,array);
		}
	}

	char transform[255] = "";
	if (transformBoo == 1) {
		//If there is a white space, transform the string to search for white string 
		for (int i = 0; i < strlen(string); i++) {
			if (string[i] == ' ') {
				char array[2];
				array[0] = '_';
				array[1] = '\0';
				// strcat_s(transform, 255, array);
        strcat(transform, array);
			}
			else {
				char array[2];
				array[0] = string[i];
				array[1] = '\0';
				// strcat_s(transform, 255, array);
        strcat(transform, array);
			}
		}
		string = transform;
	}
	
	// When case sensitivity is No 
	if (strcmp(sens, "N") == 0) {
    char temps[255];
    for(int i = 0; i < strlen(string); i++){
      temps[i] = tolower(string[i]);
    }
		if (number != 0) {
			//Got dots in front 
			char * ptr = strstr(temps, dest);
			if (ptr != NULL) {
				int pos = ptr - temps;
				//Check to see if its all trailing dots, if it is, return the pos 0 
				if (strlen(pattern) == number) {
					return pos; 
				}
				else {
					return pos - number;
				}
			}
			
			else {
				return -1; // Means no match 
			}
			
		}
		else {
			//No dots
      
			char * ptr = strstr(temps, pattern);
			if (ptr != NULL) {
				int pos = ptr - temps;
				return pos;
			}
			else {
				return -1;
			}

		}

	}
	// When case sensitivity is Yes
	if (strcmp(sens, "Y") == 0) {
		if (number != 0) {
			char * ptr = strstr(string, dest);
			if (ptr != NULL) {
				//means the word exist
				int pos = ptr - string;
				//Check to see if its all trailing dots, if it is, return the pos 0 
				if (strlen(pattern) == number) {
					return pos;
				}
				else {
					return pos - number;
				}
			}
			else {
				return -1;
			};
		}
		else {
			char * ptr = strstr(string, pattern);
			if (ptr != NULL) {
				//means the word exist
				int pos = ptr - string;
				return pos;
			}
			else {
				return -1;
			}
		};
	}
}


int main() {
	char input[255];
	char pattern[255];
	char caseSensitive[4]; 
	char * value;
	char * end; 
	//1. Prompt user to enter a line of text up to 255 characters
	printf("Enter a sentence, up to 255 characters: \n");
	//2. Only takes in 255 characters from stdin and put into the array Input
	fgets(input, 255, stdin);
	input[strcspn(input, "\n")] = 0; // The most OP method to remove the trailing new line wowsie 
	//3. Ask user to enter a pattern(string) of up to 255 characters
	printf("Enter a pattern, up to 255 characters: \n");
	fgets(pattern, 255, stdin);
	pattern[strcspn(pattern, "\n")] = 0; // The most OP method to remove the trailing new line wowsie 

	//4. Ask user if they would like it to be case sensitive or not 
	do{
		printf("Would you like the match to be case-sensitive (Y/N) \n");
		char * value = fgets(caseSensitive, 4, stdin);
		caseSensitive[strcspn(caseSensitive, "\n")] = 0; // The most OP method to remove the trailing new line wowsie 
		if (0 != strcmp(caseSensitive, "Y") && 0 != strcmp(caseSensitive, "N"))
		{
			printf("Invalid Input, Please Try Again! \n"); // Keep asking for input if they anyhow type 
		}
		
	} while (0 != strcmp(caseSensitive, "Y") && 0 != strcmp(caseSensitive, "N"));


	
	//5. Compare 
	int pos = strncmp1(input, pattern, caseSensitive);
	if (pos != -1) {
		printf("Matches at position %d.\n", pos);
	}
	
	return 0; 
}
