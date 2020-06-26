/* 
 * Simple Slot Machine
 * File:   C.S.P0003.c
 * Author: phuong
 *
 * Created on June 08, 2020, 11:47 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 */
void buffer(void); /* Pauses the Output console until Enter is pressed & clear buffer */
double loaddata(void); /* load money from file */
void savegame(double bl); /* save money to file */
void playgame(double *bl); /* play game slot machine */
int menuselect(double bl); /* Display a menu and asks users to select an option */
int menurun(int choice, double *bl); /* Perform selected function */

int main() {
    int choice;
    char file[12] = "balance.txt";
    double balance = -1;

    while (1) {
        if (balance == -1) balance = loaddata();
        choice = menuselect(balance);
        if (choice == 3) { // Cash out & exit
            printf("Thank you for playing! You end with $%.2lf!\n", balance);
            savegame(0);
            break;
        }
        if (menurun(choice, &balance) == 0) break; // out of money ~> quit
    }
    return 0;
}

/* Pauses the Output console until Enter is pressed & clear buffer */
void buffer(void) {
    while (getchar() != '\n');
}

/* load money from file */
double loaddata(void) {
    FILE *fp;
    double bl;
    int check;

    fp = fopen("balance.txt", "w+");
    check = fscanf(fp, "%*[^ ] %lf$", &bl);
    if (check == EOF || bl == 0) { // default: 10$
        bl = 10;
        fprintf(fp, "Balance: 10$");
    }
    fclose(fp);
    return bl;
}

/* save money to file */
void savegame(double bl) {
    FILE *fp;

    fp = fopen("balance.txt", "w");
    fprintf(fp, "Balance: %.2lf$", bl);
    fclose(fp);
}

/* play game slot machine */
void playgame(double *bl) {
    int a, b, c;

    srand(time(NULL));
    a = rand() % 10; // random from 0-9
    b = rand() % 10; // random from 0-9
    c = rand() % 10; // random from 0-9
    printf("The slot machine show %d%d%d\n", a, b, c);
    if (a == b && b == c) {
        printf("You win the big prize, $10.00!\n");
        (*bl) += 10;
    } else if (a == b || b == c || c == a) {
        printf("You win 50 cents!\n");
        (*bl) += 0.5;
    } else {
        printf("Sorry you don't win anything.\n");
        (*bl) -= 0.25;
    }
}

/* Display a menu and asks users to select an option */
int menuselect(double bl) {
    char x[2];

    while (1) {
        system("clear");
        printf("You have $%.2lf\n", bl);
        printf("MENU\n");
        printf("------------------------------\n\n");
        printf("1- Play the slot machine.\n");
        printf("2- Save game.\n");
        printf("3- Cash out.\n");
        printf("Enter your choice: ");

        scanf("%[^\n]", x);
        buffer();
        fflush(stdout);
        if (strlen(x) == 1 && strcmp(x, "3") <= 0 && strcmp(x, "1") >= 0) {
            return (atoi(x));
        }
        printf("Invalid choice, press Enter to continue.");
        buffer();
    }
}

/* Perform selected function */
int menurun(int choice, double *bl) {

    printf("\n");
    switch (choice) {
        case 1: // play game slot machine
        {
            playgame(bl);
            break;
        }
        case 2: // save game
        {
            printf("Your money had saved!\n");
            savegame(*bl);
            break;
        }
    }
    if (*bl >= 0.25) { // enough money to play next round ~> continue
        printf("\nPress Enter to continue.");
        buffer();
        return 1;
    } else { // not enough money
        printf("\nYou are run out of your money, good bye!\n");
        return 0;
    }
}