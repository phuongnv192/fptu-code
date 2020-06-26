/* 
 * Simple Slot Machine
 * File:   C.S.P0003.c
 * Author: phuong
 *
 * Created on June 26, 2020, 10:43 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 */
void buffer(); /* pauses the Output console until Enter is pressed & clear buffer */
float loadbalance(); /* Load balance from file */
void savegame(float bl); /* Save balance to file */
void playgame(float *bl); /* Play game slot machine */
int menuselect(float bl); /* Display a menu and asks users to select an option */

int main() {
    int choice;
    float balance = -1;
 
    while (1) {
        if (balance == -1) balance = loadbalance();
        choice = menuselect(balance);
        if (choice == 1) playgame(&balance); // play game
        else if (choice == 2) { // save money to file
            savegame(balance);
            printf("Your money has saved!\n");
            
        } else { // Cash out and exit game
            printf("Thank you for playing, You end with $%.2f!\n", balance);
            savegame(10); // reset money to 10$
            break; // break while (1)
        }
        printf("\nPress Enter to continue.");
        buffer();
    }
    return 0;
}

/* Pauses the Output console until Enter is pressed & clear buffer */
void buffer(void) {
    while (getchar() != '\n');
}

/* Load balance from file */
float loadbalance() {
    FILE *fp;
    float bl;

    fp = fopen("balance.txt", "r");
    if (fp == NULL) { // neu chua co file balance.txt ~> tao file moi
        fp = fopen("balance.txt", "w");
        fprintf(fp, "10");
        bl = 10;
    }
    fscanf(fp, "%f", &bl); 
    fclose(fp);
    return bl;
}

/* Save balance to file */
void savegame(float bl) {
    FILE *fp;

    fp = fopen("balance.txt", "w+");
    fprintf(fp, "%.2f", bl);
    fclose(fp);
}

/* Play game slot machine */
void playgame(float *bl) {
    int a, b, c;

    srand(time(NULL)); // get random seed by time
    a = rand() % 10;
    b = rand() % 10;
    c = rand() % 10;
    printf("The slot machine show %d%d%d\n", a, b, c);
    if (a == b && a == c) { // 3 of a kind
        printf("You win the big prize, $10.00!\n");
        (*bl) += 10;
    } else if (a == b || b == c || c == a) { // 2 of a kind
        printf("You win 50 cents!\n");
        (*bl) += 0.5;
    } else { // lose
        printf("Sorry you don't win anything.\n");
        (*bl) -= 0.25;
    }
}

/* Display a menu and asks users to select an option */
int menuselect(float bl) {
    int x;

    while (1) {
        system("clear");
        printf("You have $%.2f\n", bl);
        printf("MENU\n");
        printf("------------------------------\n\n");
        printf("1- Play the slot machine.\n");
        printf("2- Save game.\n");
        printf("3- Cash out.\n");
        printf("Enter your choice: ");
        fflush(stdout);
        scanf("%d", &x);
        buffer();
        if (x >= 1 && x <= 3) {
            return x;
        }
        printf("Invalid choice, press Enter to continue.");
        buffer();
    }
}