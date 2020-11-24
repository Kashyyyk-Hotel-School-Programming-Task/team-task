#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool rooms[6] = {true, true, true, true, true, true}; // Availability of rooms
bool tables[4] = {true, true, true, true}; // Availability of tables

char user_info[6][8][20];
int guest_num = 0;

int check_out(){
    int totalCost=0;
    int roomCost=0;
    int wakeUpCost=0;
    int lengthOfStay = atoi(user_info[guest_num][3]); // atoi converts string to integer
    int numGuests = atoi(user_info[guest_num][1]);
    int costOfBoard = 0;
    int room_prices[5] = {100,100,85,75,75,50};

    switch(user_info[guest_num][7][0]){
        case 1:
            roomCost=room_prices[0]*lengthOfStay;
            printf("Your room will cost:£ %d\n",roomCost);
            break;
        case 2:
            roomCost=room_prices[1]*lengthOfStay;
            printf("Your room will cost:£ %d\n",roomCost);
            break;
        case 3:
            roomCost=room_prices[2]*lengthOfStay;
            printf("Your room will cost:£ %d\n",roomCost);
            break;
        case 4:
            roomCost=room_prices[3]*lengthOfStay;
            printf("Your room will cost:£ %d\n",roomCost);
            break;
        case 5:
            roomCost=room_prices[4]*lengthOfStay;
            printf("Your room will cost:£ %d\n",roomCost);
            break;
        case 6:
            roomCost=room_prices[5]*lengthOfStay;
            printf("Your room will cost:£ %d\n",roomCost);
            break;
        default:
            printf("something has one horribly wrong");
    }

    switch(user_info[guest_num][2][0]){
        case 'F':
            costOfBoard=20*numGuests*lengthOfStay;
            printf("The total cost of your party's board is:%d",costOfBoard);
            break;
        case 'H':
            costOfBoard=15*numGuests*lengthOfStay;
            printf("The total cost of your party's board is:%d",costOfBoard);
            break;
        case 'B':
            costOfBoard=5*numGuests*lengthOfStay;
            printf("The total cost of your party's board is:%d",costOfBoard);
            break;
        default:
            printf("Something has gone horribly wrong\n");
            printf("DEBUG: user_info[guest_num][2][0] = %c",user_info[guest_num][2][0]);
    }
    switch (user_info[guest_num][4][0]){
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


    if(user_info[guest_num][6]>65) {
        roomCost = roomCost * 0.9;
        printf("You qualify for a 10 percent discount on your room rate!\n");
    }
    else if(user_info[guest_num][6]<16){
        costOfBoard=costOfBoard*0.5;
        printf("You qualify for half price on your roomn cost!\n");
    }
    else{
        printf("What on earth did you input");
    }


    totalCost=roomCost+costOfBoard+wakeUpCost;
    printf("ID: %c",user_info[guest_num][0]);
    printf("Your total bill to be paid is:£ %d",totalCost);
    return 0;
}

int check_in(){
    srand(time(NULL)); // seed rng

    // init variables
    int rand_num = (rand() % 30 + 1);
    int room_num = 0;
    char rand_num_str[2];
    char board[2];
    int room_prices[6] = {100,100,85,75,75,50};

    sprintf(rand_num_str, "%d", rand_num);   // make the number into string using sprintf function

    // Ask user for surname
    printf("What is your surname? : ");
    fflush(stdin); scanf("%s", &*user_info[guest_num][0]);

    // ask num of guests
    printf("How many guests are in your group in total? (including you) : ");
    fflush(stdin); scanf("%s", &*user_info[guest_num][1]);
    int guests = atoi(user_info[guest_num][1]); // convert num of guests (string) to integer

    // Validate num of guests
    if(guests > 4 || guests < 0){
        printf("Invalid input, guests must be below 4.\n");
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
    fflush(stdin); scanf("%c", &*user_info[guest_num][6]);

    // validate guest age
    if(atoi(user_info[guest_num][6]) < 1 || atoi(user_info[guest_num][6]) > 140){
        printf("Invalid input, number too high or below 0.");
        return 1; // return error
    }

    // ask for daily wakeup call
    printf("Would you like a daily wake-up call? (£5) (y for yes, n for no) : ");
    fflush(stdin); scanf("%s", &*user_info[guest_num][4]);
    
    // validate daily wakeup call
    if (user_info[guest_num][4][0] != 'y' && user_info[guest_num][4][0] != 'n'){ // validation of wakeup call input
        return 1;
    }

    strcat(user_info[guest_num][0], rand_num_str); // concatenates surname and the random number into "user_id"

    // choosing a room
    printf("Choose a room\n");
    if (guests <= 2){ // If there are 2 or less guests they can choose all the rooms
        for (int i = 1; i < 7; i++){
            if (rooms[i] == true){
                printf("%d: room %d - £%d per night\n", i, i, room_prices[i-1]);
            }
        }
    }else{
        for (int i = 1; i < 5; i++){
            if (rooms[i] == true){
                printf("%d: room %d - £%d per night\n", i, i, room_prices[i-1]);
            }
        }
    }
    printf("Enter the room number you want: ");
    fflush(stdin); scanf(" %c", &user_info[guest_num][7][0]);

    room_num = atoi(user_info[guest_num][7]);
    if(rooms[room_num] == false || room_num > 6 || room_num < 1){ // validate
        return 1;
    }else{
        rooms[room_num] = false; // set availability of selected room to false
    }

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
            case 'B':  // When "Book a Dinner Table" option is chosen
                printf("B\n");  // Placeholder for the "Book a Table" subroutine
                break;
            case 'O':  // When "Check Out" option is chosen
                printf("O\n");  // Placeholder for the "Check Out" subroutine
                check_out();
                break;

            case 'Q':  // When "Quit" option is chosen it will go back to the greeting
                break;
            case '!':
                mainMenuCount = 1;  // If program needs to be killed then "!" is inputted
                break;
            default:
                printf("Invalid Input\n");  // If an input is unrecognised then the program will ask for an input until a valid one is entered
        }
    }

}