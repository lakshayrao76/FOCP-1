#include <stdio.h>
#include <string.h>

#define MAX_TRIES 3


void displayWord(char word[], char guessed[], int length) {
    for (int i = 0; i < length; i++) {
        if (guessed[i] == 1) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}


int isWordGuessed(int guessed[], int length) {
    for (int i = 0; i < length; i++) {
        if (guessed[i] == 0) {
            return 0;
        }
    }
    return 1;  
}

int main() {
    char word[] = "PROGRAM";  
    int wordLength = strlen(word);
    char guessedChar;
    int tries = 0;
    int correctGuess = 0;

    int guessed[wordLength];
    for (int i = 0; i < wordLength; i++) {
        guessed[i] = 0;  
    }

    printf("Welcome to the Hangman Game!\n");
    printf("You have %d chances to guess the word correctly.\n", MAX_TRIES);


    while (tries < MAX_TRIES) {
        printf("\nWord: ");
        displayWord(word, guessed, wordLength);

        printf("Enter a letter: ");
        scanf(" %c", &guessedChar);  
        correctGuess = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guessedChar && guessed[i] == 0) {
                guessed[i] = 1;  
                correctGuess = 1;
            }
        }

        if (correctGuess) {
            printf("Good guess! '%c' is in the word.\n", guessedChar);
        } else {
            tries++;
            printf("Incorrect guess! You have %d tries left.\n", MAX_TRIES - tries);
        }

        if (isWordGuessed(guessed, wordLength)) {
            printf("\nCongratulations! You've guessed the word correctly: %s\n", word);
            break;
        }
    }

    
    if (tries == MAX_TRIES) {
        printf("\nGame over! You've used all your tries. The word was: %s\n", word);
    }

    return 0;
}
