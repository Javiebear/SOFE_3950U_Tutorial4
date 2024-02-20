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
#include "questions.h"

// List of 3 categories as array of strings
char categories[NUM_CATEGORIES][MAX_LEN] = {
        "NBA",
        "MUSIC",
        "GAMES"
};

question questions[12];

// Initializes the array of questions for the game
void initialize_game(void)
{

    // initialize each question struct and assign it to the questions array
    // 1 - NBA ----------------------------------------------------
    strcpy(questions[0].category, categories[0]);
    snprintf(questions[0].question, MAX_LEN, "What is the total amount of rings the Toronto Raptors have?");
    snprintf(questions[0].answer, MAX_LEN, "what is 1\n");
    questions[0].value = 1;
    questions[0].answered = false;

    strcpy(questions[1].category, categories[0]);
    snprintf(questions[1].question, MAX_LEN, "What is the worst team in the league?");
    snprintf(questions[1].answer, MAX_LEN, "what is pistons\n");
    questions[1].value = 10;
    questions[1].answered = false;

    strcpy(questions[2].category, categories[0]);
    snprintf(questions[2].question, MAX_LEN, "Who holds the record for most 3's in a regular season game?");
    snprintf(questions[2].answer, MAX_LEN, "who is curry\n");
    questions[2].value = 100;
    questions[2].answered = false;

    strcpy(questions[3].category, categories[0]);
    snprintf(questions[3].question, MAX_LEN, "Who is the G.O.A.T in basket ball?");
    snprintf(questions[3].answer, MAX_LEN, "who is lebron\n");
    questions[3].value = 1000;
    questions[3].answered = false;

    //Music ----------------------------------------------

    strcpy(questions[4].category, categories[1]);
    snprintf(questions[4].question, MAX_LEN, "What is the most listened to music genre?");
    snprintf(questions[4].answer, MAX_LEN, "what is pop\n");
    questions[4].value = 1;
    questions[4].answered = false;

    strcpy(questions[5].category, categories[1]);
    snprintf(questions[5].question, MAX_LEN, "Who is The Weekend?");
    snprintf(questions[5].answer, MAX_LEN, "who is abel\n");
    questions[5].value = 10;
    questions[5].answered = false;

    strcpy(questions[6].category, categories[1]);
    snprintf(questions[6].question, MAX_LEN, "Who got snubbed at the grammies this year?");
    snprintf(questions[6].answer, MAX_LEN, "who is travis\n");
    questions[6].value = 100;
    questions[6].answered = false;

    strcpy(questions[7].category, categories[1]);
    snprintf(questions[7].question, MAX_LEN, "Who is the artist with platinum teeth?");
    snprintf(questions[7].answer, MAX_LEN, "who is kanye\n");
    questions[7].value = 1000;
    questions[7].answered = false;

    //Video Games -----------------------------------------q1
    strcpy(questions[8].category, categories[2]);
    snprintf(questions[8].question, MAX_LEN, "What is the game that Drake played with the streamer Ninja?");
    snprintf(questions[8].answer, MAX_LEN, "what is fortnite\n");
    questions[8].value = 1;
    questions[8].answered = false;

    strcpy(questions[9].category, categories[2]);
    snprintf(questions[9].question, MAX_LEN, "Who is the creator of minecraft?");
    snprintf(questions[9].answer, MAX_LEN, "who is notch\n");
    questions[9].value = 10;
    questions[9].answered = false;

    strcpy(questions[10].category, categories[2]);
    snprintf(questions[10].question, MAX_LEN, "What is the total amount of rounds you need to win in a CSGO game?");
    snprintf(questions[10].answer, MAX_LEN, "what is 13\n");
    questions[10].value = 100;
    questions[10].answered = false;

    strcpy(questions[11].category, categories[2]);
    snprintf(questions[11].question, MAX_LEN, "What is the max number of Pals that you can have in your party in Pal World?");
    snprintf(questions[11].answer, MAX_LEN, "what is 5\n");
    questions[11].value = 1000;
    questions[11].answered = false;

}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for(int i = 0; i < NUM_QUESTIONS; i++){
        if(questions[i].answered == false){
            printf("%d.\nCategory: %s\nprice: $%d\n \n", i, questions[i].category, questions[i].value);
        }

        //print the next line to separate the categories
        if( ((i+1)%4) == 0 ){
            printf("\n\n");
        }

    }

}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

    for(int i = 0; i < NUM_QUESTIONS; i++){
        if((strcmp(questions[i].category,category) == 0) && value == questions[i].value) {
            printf("%d. Question: %s  \n", i, questions[i].question);
        }
    }

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    //get the correct answer
    for (int i = 0; i < NUM_QUESTIONS; i++){
        if ((strcmp(questions[i].category,category) == 0) && questions[i].value == value){
            //check if answer is correct
            if (strcmp(questions[i].answer, answer) == 0){
                questions[i].answered = true;//set this question as now answered
                return true;
            }
        }
    }

    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    printf("category:%s value:%d\n", category, value);
    for (int i = 0; i < NUM_QUESTIONS; i++){
        if ( (strcmp(questions[i].category,category) == 0) && questions[i].value == value){

            if(questions[i].answered == true){
                return true;
            }
        }
    }

    return false;
}