#include <stdio.h>
#include <stdbool.h>

int main(void) {
	//1. Get the user weight 
	float weightC = -1;
	float heightC = -1;
	float bmi; 
	char underweight[] = "Underweight";
	char normal[] = "Normal";
	char overweight[] = "Overweight";
	char obese[] = "Obese";
	do {
		printf("%s", "Enter your weight in kilograms:");
		scanf_s("%f", &weightC);
		while (getchar() != '\n');

		if (weightC == -1) {
			printf("%s\n", "Invalid Input, Please input a Valid Number");
		}
		else {
			break; 
		}
		
	} while (weightC == -1);

	//2. Get the user height
	do {
		printf("%s", "Enter your height in meters:");
		scanf_s("%f", &heightC);
		while (getchar() != '\n');

		if (heightC == -1) {
			printf("%s\n", "Invalid Input, Please input a Valid Number");
		}
		else {
			break;
		}

	} while (heightC == -1);


	//3. Calculate BMI
	bmi = weightC / (heightC * heightC);
	//4. If BMI < less than 18.5 then Underweight 
	if (bmi < 18.5) {
		//8. Display BMI in one decimal place 
		printf("Your BMI is %.1f. That is within the %s range\n", bmi, underweight);
	}
	//5. If 18.5 <= BMI <= 24.9 then Normal 
	else if (18.5 <= bmi <= 24.9) {
		//8. Display BMI in one decimal place 
		printf("Your BMI is %.1f. That is within the %s range\n", bmi, normal);
	}
	//6. If 25.0 <= BMI <= 29.9 then Overweight 
	else if (25.0 <= bmi <= 29.9) {
		//8. Display BMI in one decimal place 
		printf("Your BMI is %.1f. That is within the %s range\n", bmi, overweight);
	}
	//7. If 30 <= BMI then Obese 
	else if (30 <= bmi) {
		//8. Display BMI in one decimal place 
		printf("Your BMI is %.1f. That is within the %s range\n", bmi, obese);
	}
	return 0;

}