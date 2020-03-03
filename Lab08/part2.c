#include <stdio.h>

int main(void) {
	int p1number, p2guess = -1;
	int rounds = 10; 
	//1. Player 1 enters a number between 1 and 1000, if not in range keep repeating 
	do {
		printf("%s", "Player 1, enter a number between 1 and 1000:\n");
		scanf_s("%d", &p1number);
		while (getchar() != '\n');
		if (p1number > 1000 || p1number < 1) {
			printf("%s", "That number is out of range.\n");
			p1number = -1;
		}
	} while (p1number == -1);
	//2. Player 2 guess in 10 rounds what the number player 1 entered 
	do {
		//3. Prompt for player input
		printf("Player 2, you have %d guesses remaining.\n", rounds);
		scanf_s("%d", &p2guess);
		while (getchar() != '\n');
		//4. If value is out of range, prompt user again
		if (p2guess > 1000 || p2guess < 1) {
			printf("%s", "That number is out of range.\n");
			p2guess = -1;
		}
		else {
			//5. Decrement Round 
			rounds = rounds - 1; 
			//6. Check if value is too high or low 
			if (p2guess > p1number) {
				printf("Too high.\n");
				p2guess = -1;
			}
			else if (p2guess < p1number) {
				printf("Too low.\n");
				p2guess = -1;
			}
			//7. If player 2 guesses right, P2 wins -> then break 
			else if (p2guess == p1number) {
				printf("Player 2 wins.\n");
				break;
			}
			//8. If rounds == 0 then player 1 wins -> then break 
			if (rounds == 0) {
				printf("Player 1 wins.\n");
				break;
			}
		}
	} while (p2guess == -1 || rounds != 0);
	return 0; 
}