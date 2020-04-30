#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

/* Check input int number [min, max] with maximum range-digit */
int intcheck(int min, int max, int range, char msg[], char err[]) {
    int num, i, check;
    char *x;
    
	x = (char *) malloc(range * sizeof(char));
    while (1) {
    	printf("%s", msg);
		fflush(stdin);
		scanf("%[^\n]", x);
		check = 1;
		if (strlen(x) > 0 && strlen(x) <= range) {  // check validation string
			for (i = 0; i < strlen(x); i++) {  // check validation int number
				if (x[i] < '0' || x[i] > '9') {
					check = 0;
					break;
				}
			}
			if (check == 1) {  // if it is a int number, convert string ~> int
			num = atoi(x);
			if (num >= min && num <= max)
				return(num);
			}
		}
		printf("%s", err);
	}
	free(x);
}

/* Check input float number in range (min, max] */
double floatcheck(double min, double max, char msg[], char err[]) {
    double num;
    char *x;
    int i, check;
    
	x = (char *) malloc(20 * sizeof(char));
    while (1) {
    	printf("%s", msg);
		fflush(stdin);
		scanf("%[^\n]", x);
		check = 1;
		if (strlen(x) > 0 && strlen(x) < 20) {  // check validation string
			for (i = 0; i < strlen(x); i++) {  // check validation double number
				if (x[i] < '0' || x[i] > '9') {
					if (x[i] != '.') {
						check = 0;
						break;
					}
				}
			}
			if (check == 1) {  // if it is a float number, convert string ~> double
				num = atof(x);
				if (num > min && num <= max)
					return(num);
			}	
		}
		printf("%s", err);
	}
	free(x);
}

int main(){
	char msg[] = "Enter a int number in range [1,255]: ";
	char err[] = "Invalid input, please re-enter.\n";
	int n = intcheck(1, 255, 3, msg, err);
	//int n = inputcheck(1, 255, 3, "Enter a number in range [1,255]: ", "Invalid input, please re-enter.\n");
	printf("%d\n", n);
	
	strcpy (msg, "Enter a float number in range (0, ..] ");
	double x = floatcheck(0, DBL_MAX, msg, err);
	printf("%lf\n", x);
	return 0;
}

