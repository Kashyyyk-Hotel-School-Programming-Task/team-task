#include <stdio.h>

int main() { 
    int userMenuChoice = 0;
    int mainMenuCount = 0;  //Variable used for the main menu loop char userMenuChoice;//Input for the user to choose one of the 4 main options

    while (mainMenuCount == 0){  //Main menu will loop while the count remains unchanged
        printf("Welcome to the Kashyyyk Hotel\n"); //Greeting
        printf("Would you like to Check In(I), Book a Dinner Table(B), Check Out(O), or Quit(Q)?  ");//Gives the user 4 options
        scanf(" %c", &userMenuChoice);  //Reads in the user input and assigns it
        switch (userMenuChoice) {  //Runs a particular part of the code depending on what the user input is
            case 'I':  //When "Check in" option is chosen
                printf("I\n");  //Placeholder for the "Check In" subroutine
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
