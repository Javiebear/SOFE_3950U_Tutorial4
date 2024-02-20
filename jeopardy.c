/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];

    // Input buffer and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();
    printf("🎶Welcome to jeopardy!🎶\n");

    // Prompt for players names
    for (int i = 0; i < NUM_PLAYERS; i++){
        printf("Player %d, Enter Your Name: \n", i+1);
        players[i].score = 0;
        // initialize each of the players in the array
        scanf("%s", players[i].name);

    }

    //initialize game questions
    initialize_game();

    //initializing variables
    int playerTurn = 0;
    int questionNum = 0;
    char playerName[MAX_LEN];
    bool playerValid = false;
    char answer[MAX_LEN];
    int gameCounter = 0;

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
        display_categories();

        //prompting for players name to figure out whose turn it is
        while(playerValid == false){
            printf("Who is selecting a question?\nEnter your name: ");
            scanf("%s", playerName);
            if( player_exists(players, NUM_PLAYERS, playerName) == true ){
                playerValid = true;
            }
            //find the players index
            for (int i = 0; i < 4; i++){
                if(strcmp(playerName, players[i].name) == 0){
                    playerTurn = i;
                }
            }

        }


        //asking the player to select a question (number)
        printf("%s please select a number associated with category and cost above (0-11): ", players[playerTurn].name);
        scanf("%d", &questionNum);

        //make sure the question is still valid
        while(already_answered(questions[questionNum].category, questions[questionNum].value) == true){
            //asking the player to select a number
            printf("%s The question you selected has been answered.\nSelect another number (0-11): ", players[playerTurn].name);
            scanf("%d", &questionNum);
        }

        //display the question
        display_question(questions[questionNum].category, questions[questionNum].value);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);//clearing input buffer

        //prompt the player to answer the question
        printf("%s enter your answer with (who is || what is): ", players[playerTurn].name);
        fgets(answer, sizeof(answer), stdin);

        //check if answer is correct if not we restart
        if(valid_answer(questions[questionNum].category, questions[questionNum].value, answer) == true){
            printf("This is a correct answer!\n");
            //add player score and continue game
            update_score(players, NUM_PLAYERS, playerName, questions[questionNum].value);
            gameCounter++;
        }else{
            printf("Incorrect answer!\n");
        }

        //end the game and print the scores
        if (gameCounter == 12){
            int highestScore = 0;
            int indexHighestPlayer = 0;
            printf("You have finished the game\nPrinting Scores\n");
            for (int i = 0; i < 4; i++){
                printf("Player %d:%s Score:%d\n", i+1,players[i].name ,players[i].score);
                //calculating the player with the highest score
                if(players[i].score > highestScore){
                    indexHighestPlayer = i;
                    highestScore = players[i].score;
                }
            }
            printf("Congrats to %s as the winner of this game with the score of %d!\n", players[indexHighestPlayer].name, players[indexHighestPlayer].score);

            return 0;
        }

        //resetting the players turn
        playerValid = false;

        // Execute the game until all questions are answered

        // Display the final results and exit
    }

    return EXIT_SUCCESS;
}