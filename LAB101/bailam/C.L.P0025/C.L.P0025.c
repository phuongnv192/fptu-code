
/* 
 * Simulate ATM’s operation
 * File:   C.L.P0025.c
 * Author: phuong
 *
 * Created on June 12, 2020, 9:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

/*
 * 
 */
struct Card {
    char ID[15];
    char PIN[7];
};

struct User {
    char ID[15];
    char AccName[31];
    double Balance;
    char mType[4];
};

void getch(void); /* pauses the Output console until Enter is pressed */
void buffer(void); /* temp statement to clear buffer */
double floatcheck(double min, double max, char msg[], char err[]); /* Check input float number in range (min, max] */
int IDcheck(char id[]); /* check validation ID */
int mTypecheck(char mt[]); /* check validation Money type */
void deletecard(struct Card c[], int *k, int pos); /* delete 1 card information */
int loadcards(struct Card c[]); /* Load cards.txt */
int loadusers(struct User u[]); /* Load users.txt */
void savedata(struct Card c[], struct User u[], int num); /* save data to file */
int info(struct Card c[], struct User u[]); /* Clean duplicate & match info between to file cards.txt & users.txt */
void getID(char id[], struct Card c[], int n1); /* get a random ID */
void inputPIN(char pin[]); /* input PIN & check */
void cfPIN(char pin[], char msg[]); /* confirm PIN again */
void inputName(char name[]); /* input a string & check */
void inputMT(char mt[]); /* input money type & check */
void reg(struct Card c[], struct User u[], int *num); /* Register new account */
int menuATM(char msg1[], char msg2[], char msg3[]); /* Display a menu with 3 option */
int existID(char id[], struct Card c[], int num); /* check exist ID */
int logcheck(struct Card c[], int num); /* Login */
void receipt(char id[], char mode[], double amount); /* print receipt to file transactions.txt */
void withdraw(char pin[], struct User *u); /* withdraw */
void transfer(struct Card c[], struct User u[], int num, int pos); /* transfer */
void login(struct Card cards[], struct User users[], int num); /* Login and process withdraw/ transfer money */

int main() {
    int choice;
    struct Card *cards;
    struct User *users;
    int num;

    cards = calloc(MAX, sizeof (struct Card));
    users = calloc(MAX, sizeof (struct User));
    num = info(cards, users);
    loadcards(cards);
    loadusers(users);

    while (1) { // loop until choice = 0: exit
        choice = menuATM("Login", "Register account", "Exit");
        printf("\n");

        if (choice == 0) {
            savedata(cards, users, num);
            break; // break while (1)
        } else if (choice == 1) login(cards, users, num); // Login
        else reg(cards, users, &num); // Register
        printf("\nPress Enter to continue.");
        getch();
    }
    return 0;
}

/* Pauses the Output console until Enter is pressed */
void getch(void) {
    while (getchar() != '\n');
}

/* temp statement to clear buffer */
void buffer(void) {
    char temp;
    scanf("%c", &temp);
}

/* Check input float number in range (min, max] */
double floatcheck(double min, double max, char msg[], char err[]) {
    double num;
    char *x;
    int i, check, start, len, dotcount;

    x = (char *) malloc(20 * sizeof (char));
    while (1) {
        printf("%s", msg);
        fflush(stdout);
        scanf("%[^\n]", x);
        buffer();
        check = 1;
        len = strlen(x);
        dotcount = 0;
        if (len > 0 && len < 20) { // check validation string
            if (x[0] == '-') { // first character can be minus sign
                start = 1;
                if (len == 1) check = 0;
            } else start = 0;
            for (i = start; i < strlen(x); i++) { // check validation double number
                if (x[i] == '.') dotcount++;
                else if (x[i] < '0' || x[i] > '9' || dotcount > 1) {
                    check = 0;
                    break;
                }
            }
            if (check == 1) { // if it is a float number, convert string ~> double
                num = atof(x);
                if (num > min && num <= max)
                    return (num);
            }
        }
        printf("%s", err);
    }
    free(x);
}

/* check validation ID */
int IDcheck(char id[]) {
    if (strlen(id) == 14 && strncmp(id, "42710", 5) == 0) return 1;
    else return 0;
}

/* check validation Money type */
int mTypecheck(char mt[]) {
    char currency[] = "VND,USD,EUR,JPY,CNY,GBP,AUD";
    char *p;

    p = strstr(currency, mt);
    if (p != NULL) return 1;
    else return 0;
}

/* delete 1 card information */
void deletecard(struct Card c[], int *k, int pos) {
    int i;

    for (i = pos; i < *k - 1; i++) {
        strcpy(c[i].ID, c[i + 1].ID);
        strcpy(c[i].PIN, c[i + 1].PIN);
    }
    (*k)--;
}

/* Load cards.txt */
int loadcards(struct Card c[]) {
    FILE *fp;
    int check, i, k;

    fp = fopen("cards.txt", "r");
    k = 0;
    while (!feof(fp)) {
        check = fscanf(fp, "%14[^/]/%6[^\n]\n", c[k].ID, c[k].PIN);

        /* Clear file and re-write valid information to file */
        if (check != 2 || IDcheck(c[k].ID) == 0 || strlen(c[k].PIN) != 6) {
            freopen("cards.txt", "w", fp);
            for (i = 0; i < k; i++) {
                fprintf(fp, "%s/%s\n", c[i].ID, c[i].PIN);
            }
            break;
        }
        k++;
    }
    fclose(fp);
    return k;
}

/* Load users.txt */
int loadusers(struct User u[]) {
    FILE *fp;
    int check, i, k;

    fp = fopen("users.txt", "r");
    k = 0;
    while (!feof(fp)) {
        check = fscanf(fp, "%14[^/]/%30[^/]/%9lf/%3[^\n]\n", u[k].ID, u[k].AccName, &u[k].Balance, u[k].mType);

        /* Clear file and re-write valid information to file */
        if (check != 4 || IDcheck(u[k].ID) == 0) {
            freopen("users.txt", "w", fp);
            for (i = 0; i < k; i++) {
                fprintf(fp, "%s/%s/%.2lf/%s\n", u[i].ID, u[i].AccName, u[i].Balance, u[i].mType);
            }
            break;
        }
        k++;
    }
    fclose(fp);
    return k;
}

/* save data to file */
void savedata(struct Card c[], struct User u[], int num) {
    FILE *fp1, *fp2;
    int i;

    fp1 = fopen("cards.txt", "w");
    fp2 = fopen("users.txt", "w");
    for (i = 0; i < num; i++) {
        fprintf(fp1, "%s/%s\n", c[i].ID, c[i].PIN);
        fprintf(fp2, "%s/%s/%.2lf/%s\n", u[i].ID, u[i].AccName, u[i].Balance, u[i].mType);
    }
    fclose(fp1);
    fclose(fp2);
}

/* Clean duplicate & match info between to file cards.txt & users.txt */
int info(struct Card c[], struct User u[]) {
    int n1, n2, i, j, exist;
    struct User *uclone;

    n1 = loadcards(c);
    n2 = loadusers(u);
    uclone = calloc(n2, sizeof (struct User)); // store clean info from users.txt
    int mask[n2]; // Masking u[] ~> 1 = hide, 0 = unhide
    for (i = 0; i < n2; i++) mask[i] = 0;

    for (i = 0; i < n1; i++) {
        exist = 0;
        for (j = 0; j < n2; j++) {
            if (mask[j] == 0 && strcmp(c[i].ID, u[j].ID) == 0) {
                if (exist == 0) { // not stored in uclone[] ~> copy it to uclone[]
                    strcpy(uclone[i].ID, u[j].ID);
                    strcpy(uclone[i].AccName, u[j].AccName);
                    uclone[i].Balance = u[j].Balance;
                    strcpy(uclone[i].mType, u[j].mType);
                    mask[j] = 1; // hide this line
                    exist = 1; // c[].ID exists in u[].ID
                } else mask[j] = 1; // already stored in uclone[] ~> hide
            }
        }
        if (exist == 0) { // c[].ID not exists in u[].ID ~> delete
            deletecard(c, &n1, i);
            i--;
        }
    }
    savedata(c, u, n1);
    return n1;
}

/* get a random ID */
void getID(char id[], struct Card c[], int n1) {
    int a, i;
    char surfix[10];

    srand(time(NULL));
    do {
        a = rand() % 1000000000; // only 9 digits
        sprintf(surfix, "%d", a);
        strcpy(id, "42710");
        strcat(id, surfix);
        for (i = 0; i < n1; i++) {
            if (strcmp(id, c[i].ID) == 0) break;
        }
    } while (i != n1);
}

/* input PIN & check */
void inputPIN(char pin[]) {
    char *strtemp;
    int i;

    strtemp = (char *) calloc(7, sizeof (char));
    while (1) {
        printf("PIN: ");
        fflush(stdout);
        scanf("%[^\n]", strtemp);
        buffer();
        if (strlen(strtemp) == 6) {
            for (i = 0; i < 6; i++) {
                if (strtemp[i] < '0' || strtemp[i] > '9') break; // if it's not a number ~> break
            }
            if (i == 6) { // all are numbers
                strcpy(pin, strtemp);
                break; //break while (1)
            }

        }
        printf("Invalid PIN, please re-enter.\n");
    }
    free(strtemp);
}

/* confirm PIN again */
void cfPIN(char pin[], char msg[]) {
    char *cfp;

    cfp = (char *) calloc(7, sizeof (char));
    while (1) {
        printf("%s", msg);
        fflush(stdout);
        scanf("%[^\n]", cfp);
        buffer();
        if (strcmp(pin, cfp) == 0) break;
        printf("Invalid PIN, please re-enter.\n");
    }
    free(cfp);
}

/* input a string & check */
void inputName(char name[]) {
    char *strtemp;
    int len;

    strtemp = (char *) calloc(31, sizeof (char));
    while (1) {
        printf("Account Name: ");
        fflush(stdout);
        scanf("%[^\n]", strtemp);
        buffer();
        len = strlen(strtemp);
        if (len > 0 && len <= 30) {
            strcpy(name, strtemp);
            break;
        }
        printf("Invalid Account Name, please re-enter.\n");
    }
    free(strtemp);
}

/* input money type & check */
void inputMT(char mt[]) {
    char *temp;
    int len;

    temp = (char *) calloc(4, sizeof (char));
    while (1) {
        printf("Money Type: ");
        fflush(stdout);
        scanf("%[^\n]", temp);
        buffer();
        len = strlen(temp);
        if (len == 3 && mTypecheck(temp) == 1) {
            strcpy(mt, temp);
            break;
        }
        printf("Invalid Money Type, please re-enter.\n");
    }
    free(temp);
}

/* Register new account */
void reg(struct Card c[], struct User u[], int *num) {
    char newid[15];

    getID(newid, c, *num);
    strcpy(c[*num].ID, newid);
    strcpy(u[*num].ID, newid);
    printf("ID: %s\n", newid);

    inputPIN(c[*num].PIN);
    cfPIN(c[*num].PIN, "Confirm your PIN: ");
    inputName(u[*num].AccName);
    u[*num].Balance = floatcheck(0, 999999999, "Balance: ", "Invalid balance, please re-enter.\n");
    inputMT(u[*num].mType);
    (*num)++;
    printf("\nRegistration successful.\n");
}

/* Display a menu with 3 option */
int menuATM(char msg1[], char msg2[], char msg3[]) {
    char *x;

    x = (char *) malloc(2 * sizeof (char));
    while (1) {
        system("clear");
        printf("ATM\n");
        printf("------------------------------\n\n");
        printf("1- %s.\n", msg1);
        printf("2- %s.\n", msg2);
        printf("0- %s.\n", msg3);
        printf("Enter your choice: ");

        scanf("%[^\n]", x);
        buffer();
        fflush(stdin);
        if (strlen(x) == 1 && strcmp(x, "2") <= 0 && strcmp(x, "0") >= 0) {
            return (atoi(x));
        }
        printf("Invalid choice, press Enter to continue.");
        getch();
    }
}

/* check exist ID */
int existID(char id[], struct Card c[], int num) {
    int i;
    
    if (strlen(id) == 14) {
        for (i = 0; i < num; i++) {
            if (strcmp(c[i].ID, id) == 0) {
                return i;
            }
        }
    }
    return -1;
}

/* Login */
int logcheck(struct Card c[], int num) {
    char *id;
    int pos;

    id = (char *) calloc(15, sizeof (char));
    while (1) {
        printf("ID: ");
        fflush(stdout);
        scanf("%[^\n]", id);
        buffer();
        pos = existID(id, c, num);
        if (pos != -1) break;
        printf("Invalid ID, please re-enter.\n");
    }
    cfPIN(c[pos].PIN, "PIN: ");
    return pos;
}

/* print receipt to file transactions.txt */
void receipt(char id[], char mode[], double amount) {
    FILE *fp;
    time_t now;
    
    time(&now);
    fp = fopen("transactions.txt", "a");
    if (strcmp(mode, "withdraw") == 0) {
        fprintf(fp,"%s/withdraw/%.2lf/%s", id, amount, ctime(&now));
    } else { // if transfer: mode[] store destination id 
        fprintf(fp,"%s/transfer/%s/%.2lf/%s", id, mode, amount, ctime(&now));
    }
    fclose(fp);
}

/* withdraw */
void withdraw(char pin[], struct User *u) {
    double amount;
    
    printf("\nYour balance: %.2lf %s\n", u->Balance, u->mType);
    amount = floatcheck(0, u->Balance, "Amount withdraw: ", "Invalid amount, please re-enter.\n");
    cfPIN(pin, "Confirm your PIN: ");
    u->Balance -= amount;
    receipt(u->ID, "withdraw", amount);
    printf("\nWithdrawal successful.\n\nPress Enter to continue.");
    getch();
}

/* transfer */
void transfer(struct Card c[], struct User u[], int num, int pos) {
    int i, des;
    char *desid;
    double amount;

    desid = (char *) calloc(15, sizeof (char));
    printf("\nYour balance: %.2lf %s\n\n", u[pos].Balance, u[pos].mType);
    while (1) {
        printf("Receiver's ID: ");
        fflush(stdout);
        scanf("%[^\n]", desid);
        buffer();
        des = existID(desid, c, num);
        if (des != -1 && strcmp(u[pos].ID, desid) != 0) break;
        printf("Invalid ID, please re-enter.\n");
    }
    amount = floatcheck(0, u[pos].Balance, "Amount transfer: ", "Invalid amount, please re-enter.\n");
    cfPIN(c[pos].PIN, "Confirm your PIN: ");
    u[pos].Balance -= amount;
    u[des].Balance += amount;
    receipt(u[pos].ID, u[des].ID, amount);
    printf("\nTransfer successful.\n\nPress Enter to continue.");
    getch();
}

/* Login and process withdraw/ transfer money */
void login(struct Card cards[], struct User users[], int num) {
    int choice, pos;
    pos = logcheck(cards, num);
    
    while (1) {
        choice = menuATM("Withdraw money", "Transfer money", "Logout");
        if (choice == 1) withdraw(cards[pos].PIN, &users[pos]);
        else if (choice == 2) transfer(cards, users, num, pos);
        else break; // choice = 0
    }
}