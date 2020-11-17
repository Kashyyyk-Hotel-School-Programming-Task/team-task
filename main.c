#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool rooms[6] = {true, true, true, true, true, true}; // Availability of rooms
bool tables[4] = {true, true, true, true}; // Availability of tables

char user_info[6][7][20];
int guest_num = 0;

int checkOut(){

    int totalCost=0;
    int wakeUpCost=0;
    int lengthOfStay==user_info[guest_num][3];
    int numGuests==user_info[guest_num][1];
    int costOfBoard=0;

    switch(user_info[guest_num][2]){
        case 'FB':
            costOfBoard=20*numGuests*lengthOfStay;
                    printf("The total cost of your party's board is:%d",&costOfBoard);
                    break;
        case 'HB':
            costOfBoard=15*numGuests*lengthOfStay;
                    printf("The total cost of your party's board is:%d",&costOfBoard);
                    break;
        case 'BB':
            costOfBoard=5*numGuests*lengthOfStay;
                    printf("The total cost of your party's board is:%d",&costOfBoard);
            break;
        default:
            printf("Something has gone horribly wrong\n");
    }
    switch(user_info[guest_num][4]){
        case 'y':
            wakeUpCost=5;
            printf("You asked for daily wake up calls, so you have been charged £5");
            break;
        case 'n':
            wakeUpCost=0;
            break;
        default:
            printf("Something has gone horribly wrong\n");

    }

}

int check_in(){
    srand(time(NULL)); // seed rng

    // init variables
    int rand_num = (rand() % 30 + 1);
    char rand_num_str[2];
    char board[2];

    sprintf(rand_num_str, "%d", rand_num);   // make the number into string using sprintf function

    // Ask user for inputs
    printf("What is your surname? : ");
    fflush(stdin); scanf("%s", &*user_info[guest_num][0]);

    // ask num of guests
    printf("How many guests are in your group? : ");
    fflush(stdin); scanf("%s", &*user_info[guest_num][1]);
    int guests = atoi(user_info[guest_num][1]); // convert num of guests (string) to integer

    // Validate num of guests
    if(guests > 6 || guests < 0){
        printf("Invalid input, guests must be below 6.\n");
        strcpy(user_info[guest_num][1], ""); 
        return 1; // return error
    }

    // Ask board type
    printf("Which board type? (FB for full board, HB for half board, BB for bed and breakfast) : ");
    fflush(stdin);scanf("%s", &*user_info[guest_num][2]);
    strcpy(board, user_info[guest_num][2]);

    // validate board type
    if(strcmp(board, "FB") != 0 && strcmp(board, "HB") != 0  && strcmp(board, "BB") != 0){
        printf("Invalid input\n");
        strcpy(user_info[guest_num][2], "");
        return 1;
    }

    // ask length of stay
    printf("How long will you be staying with us (in days)? : ");
    fflush(stdin); scanf("%s", &*user_info[guest_num][3]);

    // Validate length of stay
    if(atoi(user_info[guest_num][3]) < 0 || atoi(user_info[guest_num][3]) > 30){
        printf("Invalid input, number too high or below 0.");
        strcpy(user_info[guest_num][3], ""); 
        return 1; // return error
    }

    //ask guests age
    printf("What is your age?:\n");
    fflush(stdin); scanf("%d", &*user_info[guest_num][7]);

    printf("Would you like a daily wake-up call? (£5) (y for yes, n for no) : ");
    fflush(stdin); scanf("%s", &*user_info[guest_num][4]);

    strcat(user_info[guest_num][0], rand_num_str); // concatenates surname and the random number into "user_id"

    printf("Your Booking ID is: %s\n", &*user_info[guest_num][0]);

    guest_num++; // increment guest number

    return 0; // return success
}

int main() { 
    char userMenuChoice = 0;
    char mainMenuCount = 0;  //Variable used for the main menu loop char userMenuChoice;

    while (mainMenuCount == 0){  //Main menu will loop while the count remains unchanged
        printf("Welcome to the Kashyyyk Hotel\n"); //Greeting
        printf("Would you like to Check In(I), Book a Dinner Table(B), Check Out(O), or Quit(Q)?  ");  //Gives the user 4 options
        scanf(" %c", &userMenuChoice);  //Reads in the user input and assigns it
        switch (userMenuChoice) {  //Runs a particular part of the code depending on what the user input is
            case 'I':  //When "Check in" option is chosen
                printf("I\n");  //Placeholder for the "Check In" subroutine
                while(check_in() != 0){ // Keep asking until 0 is returned.
                    printf("Invalid input was returned, please try again. \n"); 
                }
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
