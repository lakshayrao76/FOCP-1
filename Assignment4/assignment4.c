#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void displayChoice(int choice, char player) {
    if (player == 'U') {  
        switch(choice) {
            case 0: printf("You chose: Rock\n"); break;
            case 1: printf("You chose: Paper\n"); break;
            case 2: printf("You chose: Scissors\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    } else {  
        switch(choice) {
            case 0: printf("Computer chose: Rock\n"); break;
            case 1: printf("Computer chose: Paper\n"); break;
            case 2: printf("Computer chose: Scissors\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    }
}

void determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoice == 0 && computerChoice == 2) || 
               (userChoice == 1 && computerChoice == 0) ||
               (userChoice == 2 && computerChoice == 1)) { 
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

int main() {
    int userChoice, computerChoice;
    
    srand(time(NULL));

    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("Enter your choice:\n");
    printf("0 for Rock\n1 for Paper\n2 for Scissors\n");
    printf("Enter your choice (0/1/2): ");
    scanf("%d", &userChoice);

    if (userChoice < 0 || userChoice > 2) {
        printf("Invalid choice! Please enter a number between 0 and 2.\n");
        return 1; 
    }

   
    displayChoice(userChoice, 'U');

   
    computerChoice = rand() % 100; 


    if (computerChoice >= 0 && computerChoice <= 33) {
        computerChoice = 0; 
    } else if (computerChoice >= 34 && computerChoice <= 66) {
        computerChoice = 1; 
    } else {
        computerChoice = 2; 
    }

    displayChoice(computerChoice, 'C');

   
    determineWinner(userChoice, computerChoice);

    return 0;
}
