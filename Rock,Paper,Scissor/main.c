#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void gameLogic();

int main() {
    char userInput[10];
    srand(time(NULL));

    printf("[INFO] Type 'quit' to stop the game.\n");
    printf("Start game? (yes/no): ");

    // Avoids buffer overflow (refering to fgets()), and
    // automatically appends '\0'. Also, reads the entire line
    // without crashing or splitting input 
    // (this includes whitespaces as well).
    fgets(userInput, sizeof(userInput), stdin);
    
    // Remove the trailing newline character 
    userInput[strcspn(userInput, "\n")] = '\0';
    
    for(;;) {
        if (strcmp(userInput, "yes") == 0) {
            gameLogic();
        }
        else if (strcmp(userInput, "no") == 0) {
	    printf("Shutting game down...\n");
	    exit(0);
        }
        else {
	    printf("Invalid option. Try again: ");
	    fgets(userInput, sizeof(userInput), stdin);
	    userInput[strcspn(userInput, "\n")] = '\0';
        }
    }

    return 0;
}

void gameLogic() {
    char playerInput[10];
    const char *choices[] = {"rock", "paper", "scissor"};
    
    // Player's turn
    printf("Rock, Paper, or Scissor?: ");
    fgets(playerInput, sizeof(playerInput), stdin);
    playerInput[strcspn(playerInput, "\n")] = '\0';

    int array_size = sizeof(choices) / sizeof(choices[0]);
    int found_choice = -1;

    for (int i = 0; i < array_size; i++) {
        if (strcmp(choices[i], playerInput) == 0) {
	    found_choice = i;
	    break;
	    }
    }

    // Computer's turn 
    int computerInput = rand() % 3;
    const char *computerChoice = choices[computerInput];
        
    // Quit game, check input, then game logic
    if (strcmp(playerInput, "quit") == 0) {
    	exit(0);
    }
    else if (found_choice == -1) {
        printf("Invalid game choice\n");
    }
    else {
	    printf("\n");
        printf("User choice: %s\n", playerInput);
	    printf("Computer choice: %s\n", computerChoice);
 	    printf("\n");
	
	    // -----------------
	    // Logic (Who wins?)
	    // -----------------

	    // ----------------- Architecture -----------------------
	    // rock vs rock, rock vs paper, rock vs scissor
	    // paper vs rock, paper vs paper, paper vs scissor
	    // scissor vs rock, scissor vs paper, scissor vs scissor
	    // ------------------------------------------------------
	
	    // rock vs paper
	    if (strcmp(playerInput, choices[1]) == 0 && strcmp(computerChoice, choices[0]) == 0) {
	        printf("Player wins!\n\n");
	    }
	    else if (strcmp(playerInput, choices[0]) == 0 && strcmp(computerChoice, choices[1]) == 0) {
	        printf("Computer wins!\n\n");
	    }
	
	    // rock vs scissor
	    else if (strcmp(playerInput, choices[0]) == 0 && strcmp(computerChoice, choices[2]) == 0) {
	        printf("Player wins!\n\n");
	    }
	    else if (strcmp(playerInput, choices[2]) == 0 && strcmp(computerChoice, choices[0]) == 0) {
	        printf("Computer wins!\n\n");
	    }
        
	    // paper vs rock
	    else if (strcmp(playerInput, choices[1]) == 0 && strcmp(computerChoice, choices[0]) == 0) {
	        printf("Player wins!\n\n");
	    }
	    else if (strcmp(playerInput, choices[0]) == 0 && strcmp(computerChoice, choices[1]) == 0) {
	        printf("Computer wins!\n\n");
	    }

	    // paper vs scissor
	    else if (strcmp(playerInput, choices[2]) == 0 && strcmp(computerChoice, choices[1]) == 0) {
	        printf("Player wins!\n\n");
	    }
	    else if (strcmp(playerInput, choices[1]) == 0 && strcmp(computerChoice, choices[2]) == 0) {
	        printf("Computer wins!\n\n");
	    }

	    // scissor vs rock and scissor vs paper not needed
	    // logic was implemented, so now the remaining thing left is draw
	    else {
            printf("Draw!\n\n");
	    }
    }
}
