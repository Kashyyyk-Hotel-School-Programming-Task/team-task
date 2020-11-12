#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

char user_info[6][6][20];

void check_in(){
    srand(time(NULL)); // seed rng

    // init variables
    char user_id[20];
    int rand_num = (rand() % 30 + 1);
    char rand_num_str[2];

    sprintf(rand_num_str, "%d", rand_num);   // make the number into string using sprintf function
    
    printf("%s",rand_num_str);

    // Ask user for inputs
    printf("What is your surname? : ");
    scanf("%s", &user_id);

    printf("How many guests are in your group? : ");
    scanf("%s", &user_info[1]);
    int guests = strtonum(user_info[1]);
    
    // validate number of guests
    switch(guests) {

    }

    printf("Which board type? (FB for full board, HB for half board, BB for bed and breakfast) : ");
    scanf("%s", &user_info[1]);

    strcat(user_id, rand_num_str); // concatenates surname and the random number into "user_id"

    printf("Your Booking ID is: %s\n",user_id); // debug printf

}

int main() { 
    int userMenuChoice = 0;
    int mainMenuCount = 0;  //Variable used for the main menu loop char userMenuChoice;//Input for the user to choose one of the 4 main options

    while (mainMenuCount == 0){  //Main menu will loop while the count remains unchanged
        printf("Welcome to the Kashyyyk Hotel\n"); //Greeting
        printf("Would you like to Check In(I), Book a Dinner Table(B), Check Out(O), or Quit(Q)?  ");  //Gives the user 4 options
        scanf(" %c", &userMenuChoice);  //Reads in the user input and assigns it
        switch (userMenuChoice) {  //Runs a particular part of the code depending on what the user input is
            case 'I':  //When "Check in" option is chosen
                printf("I\n");  //Placeholder for the "Check In" subroutine
                check_in();
                break;
            case 'B':  //When "Book a Dinner Table" option is chosen
                printf("B\n");  //Placeholder for the "Book a Table" subroutine
                break;
            case 'O':  //When "Check Out" option is chosen
                printf("O\n");  //Placeholder for the "Check Out" subroutine
                break;
            case 'Q':  //When "Quit" option is chosen it will go back to the greeting
                break;
            case '!':
                mainMenuCount = 1;  //If program needs to be killed then "!" is inputted
                break;
            default:
                printf("Invalid Input\n");  //If an input is unrecognised then the program will ask for an input until a valid one is entered
        }
    }

}
