#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

HANDLE h;

//room 1
int roomonelevelonecorrect = 0;
int roomoneleveloneincorrect = 0;

int roomoneleveltwocorrect = 0;
int roomoneleveltwoincorrect = 0;

int roomonelevelthreecorrect = 0;
int roomonelevelthreeincorrect = 0;


int room1AskMCQ(char question[], char optionA[], char optionB[],
                char optionC[], char optionD[], char correctOption)
{
    char userAnswer;

    printf("\n%s\n", question);
    printf("A. %s\n", optionA);
    printf("B. %s\n", optionB);
    printf("C. %s\n", optionC);
    printf("D. %s\n", optionD);

    printf("\nEnter your answer (A/B/C/D): ");
    scanf(" %c", &userAnswer);

    userAnswer = toupper((unsigned char)userAnswer);

    if(userAnswer == correctOption)
    {
        SetConsoleTextAttribute(h, 10);
        printf("\nCorrect Answer!\n");
        Sleep(1500);
        system("cls");
        SetConsoleTextAttribute(h, 7);
        return 1;
    }
    else
    {
        SetConsoleTextAttribute(h, 12);
        printf("\nIncorrect Answer!\n");
        Sleep(1500);
        system("cls");
        SetConsoleTextAttribute(h, 7);
        return 0;
    }
}


int room1level1()
{
    SetConsoleTextAttribute(h, 11);
    printf("\n========== EASY LEVEL ==========\n");
    SetConsoleTextAttribute(h, 7);

    if(room1AskMCQ("1. What gets wetter the more it dries?",
    "Sponge", "Towel", "Tissue", "Cloth", 'B'))
        roomonelevelonecorrect++;
    else
        roomoneleveloneincorrect++;

    if(room1AskMCQ("2. Which musical instrument has 88 keys?",
    "Organ", "Harpsichord", "Piano", "Accordion", 'C'))
        roomonelevelonecorrect++;
    else
        roomoneleveloneincorrect++;

    if(room1AskMCQ("3. What follows you in daylight but disappears in complete darkness?",
    "Reflection", "Shadow", "Silhouette", "Footprint", 'B'))
        roomonelevelonecorrect++;
    else
        roomoneleveloneincorrect++;

    if(room1AskMCQ("4. What has many teeth and is used to untangle hair?",
    "Brush", "Comb", "Razor", "Clip", 'B'))
        roomonelevelonecorrect++;
    else
        roomoneleveloneincorrect++;

    if(room1AskMCQ("5. David's father has three sons: Snap, Crackle and _____?",
    "Pop", "David", "Jack", "Crackle", 'B'))
        roomonelevelonecorrect++;
    else
        roomoneleveloneincorrect++;

    SetConsoleTextAttribute(h, 14);
    printf("\nEasy Level Results:\n");
    SetConsoleTextAttribute(h, 7);
    printf("Correct Answers: %d/5\n", roomonelevelonecorrect);
    printf("Incorrect Answers: %d/5\n", roomoneleveloneincorrect);

    if(roomonelevelonecorrect >= 3)
    {
        SetConsoleTextAttribute(h, 10);
        printf("\nCongratulations! EASY LEVEL CLEARED!\n");
        printf("You have unlocked the NORMAL LEVEL!\n");
        SetConsoleTextAttribute(h, 7);
        return 1;
    }
    else
    {
        SetConsoleTextAttribute(h, 12);
        printf("\nYou failed the EASY LEVEL!\n");
        printf("You need at least 3 correct answers to pass.\n");
        SetConsoleTextAttribute(h, 7);
        return 0;
    }
}


int room1level2()
{
    Sleep(2000);
    system("cls");
    SetConsoleTextAttribute(h, 11);
    printf("\n========== NORMAL LEVEL ==========\n");
    SetConsoleTextAttribute(h, 7);

    if(room1AskMCQ("1. The more you take, the more you leave behind. What am I?",
    "Footprints", "Footsteps", "Tracks", "Shadows", 'B'))
        roomoneleveltwocorrect++;
    else
        roomoneleveltwoincorrect++;

    if(room1AskMCQ("2. What travels around the world while staying in one corner?",
    "Postcard", "Envelope", "Stamp", "Sticker", 'C'))
        roomoneleveltwocorrect++;
    else
        roomoneleveltwoincorrect++;

    if(room1AskMCQ("3. I have cities but no houses, forests but no trees, and water but no fish. What am I?",
    "Globe", "Map", "Atlas", "Blueprint", 'B'))
        roomoneleveltwocorrect++;
    else
        roomoneleveltwoincorrect++;

    if(room1AskMCQ("4. What can fill an entire room but takes up no physical space?",
    "Sound", "Air", "Light", "Heat", 'C'))
        roomoneleveltwocorrect++;
    else
        roomoneleveltwoincorrect++;

    if(room1AskMCQ("5. What has one eye but cannot see?",
    "Camera", "Needle", "Storm", "Potato", 'B'))
        roomoneleveltwocorrect++;
    else
        roomoneleveltwoincorrect++;

    SetConsoleTextAttribute(h, 14);
    printf("\nNormal Level Results:\n");
    SetConsoleTextAttribute(h, 7);
    printf("Correct Answers: %d/5\n", roomoneleveltwocorrect);
    printf("Incorrect Answers: %d/5\n", roomoneleveltwoincorrect);

    if(roomoneleveltwocorrect >= 3)
    {
        SetConsoleTextAttribute(h, 10);
        printf("\nCongratulations! NORMAL LEVEL CLEARED!\n");
        printf("You have unlocked the DIFFICULT LEVEL!\n");
        SetConsoleTextAttribute(h, 7);
        return 1;
    }
    else
    {
        SetConsoleTextAttribute(h, 12);
        printf("\nYou failed the NORMAL LEVEL!\n");
        printf("You need at least 3 correct answers to pass.\n");
        SetConsoleTextAttribute(h, 7);
        return 0;
    }
}


int room1level3()
{
    Sleep(2000);
    system("cls");
    SetConsoleTextAttribute(h, 11);
    printf("\n========== DIFFICULT LEVEL ==========\n");
    SetConsoleTextAttribute(h, 7);

    if(room1AskMCQ("1. I speak without a mouth and hear without ears. I have no body, but come alive with the wind. What am I?",
    "Whisper", "Thunder", "Echo", "Wind", 'C'))
        roomonelevelthreecorrect++;
    else
        roomonelevelthreeincorrect++;

    if(room1AskMCQ("2. What disappears as soon as you say its name?",
    "Secret", "Silence", "Darkness", "Quietness", 'B'))
        roomonelevelthreecorrect++;
    else
        roomonelevelthreeincorrect++;

    if(room1AskMCQ("3. I am taken from a mine, ground into powder, and used inside a pencil to leave marks. What am I?",
    "Charcoal", "Coal", "Graphite", "Ink", 'C'))
        roomonelevelthreecorrect++;
    else
        roomonelevelthreeincorrect++;

    if(room1AskMCQ("4. I have keys, a space bar, and an enter key, but no locks or rooms. What am I?",
    "Remote Control", "Piano", "Calculator", "Keyboard", 'D'))
        roomonelevelthreecorrect++;
    else
        roomonelevelthreeincorrect++;

    if(room1AskMCQ("5. The more there is of me, the less you are able to see. What am I?",
    "Fog", "Smoke", "Darkness", "Shadow", 'C'))
        roomonelevelthreecorrect++;
    else
        roomonelevelthreeincorrect++;

    SetConsoleTextAttribute(h, 14);
    printf("\nDifficult Level Results:\n");
    SetConsoleTextAttribute(h, 7);
    printf("Correct Answers: %d/5\n", roomonelevelthreecorrect);
    printf("Incorrect Answers: %d/5\n", roomonelevelthreeincorrect);

    if(roomonelevelthreecorrect >= 3)
    {
        SetConsoleTextAttribute(h, 10);
        printf("\nCongratulations! DIFFICULT LEVEL CLEARED!\n");
        SetConsoleTextAttribute(h, 7);
        return 1;
    }
    else
    {
        SetConsoleTextAttribute(h, 12);
        printf("\nYou failed the DIFFICULT LEVEL!\n");
        printf("You need at least 3 correct answers to pass.\n");
        SetConsoleTextAttribute(h, 7);
        return 0;
    }
}


int room1()
{
    SetConsoleTextAttribute(h, 13);
    printf("\n====================================\n");
    printf("       WELCOME TO ROOM 1\n");
    printf("          RIDDLE ROOM\n");
    printf("====================================\n");
    SetConsoleTextAttribute(h, 7);

    printf("\nInstructions:\n");
    printf("- There are 3 difficulty levels.\n");
    printf("- Each level contains 5 questions.\n");
    printf("- You need at least 3 correct answers out of 5 to pass.\n");
    printf("- Clear each level to unlock the next one.\n");
    printf("- LETSSS GOOOO :D  \n");
    Sleep(3000);
    system("cls");

    if(room1level1() == 0)
    {
        SetConsoleTextAttribute(h, 12);
        printf("\n====================================\n");
        printf("       ROOM 1 NOT CLEARED!\n");
        printf("====================================\n");
        SetConsoleTextAttribute(h, 7);
        return 0;
    }

    if(room1level2() == 0)
    {
        SetConsoleTextAttribute(h, 12);
        printf("\n====================================\n");
        printf("       ROOM 1 NOT CLEARED!\n");
        printf("====================================\n");
        SetConsoleTextAttribute(h, 7);
        return 0;
    }

    if(room1level3() == 0)
    {
        SetConsoleTextAttribute(h, 12);
        printf("\n====================================\n");
        printf("       ROOM 1 NOT CLEARED!\n");
        printf("====================================\n");
        SetConsoleTextAttribute(h, 7);
        return 0;
    }

    SetConsoleTextAttribute(h, 14);
    printf("\n====================================\n");
    printf("          ROOM 1 LEADERBOARD\n");
    printf("====================================\n");
    SetConsoleTextAttribute(h, 7);

    printf("\nEasy Level:\n");
    printf("Correct: %d | Incorrect: %d\n",
    roomonelevelonecorrect, roomoneleveloneincorrect);

    printf("\nNormal Level:\n");
    printf("Correct: %d | Incorrect: %d\n",
    roomoneleveltwocorrect, roomoneleveltwoincorrect);

    printf("\nDifficult Level:\n");
    printf("Correct: %d | Incorrect: %d\n",
    roomonelevelthreecorrect, roomonelevelthreeincorrect);

    int totalCorrect = roomonelevelonecorrect +
                       roomoneleveltwocorrect +
                       roomonelevelthreecorrect;

    int totalIncorrect = roomoneleveloneincorrect +
                         roomoneleveltwoincorrect +
                         roomonelevelthreeincorrect;

    printf("\nTotal Correct Answers: %d\n", totalCorrect);
    printf("Total Incorrect Answers: %d\n", totalIncorrect);
    printf("Final Score: %d/15\n", totalCorrect);

    SetConsoleTextAttribute(h, 10);
    printf("\n====================================\n");
    printf(" CONGRATULATIONS! YOU PASSED ROOM 1!\n");
    printf(" You have successfully completed all three levels :D \n");
    printf(" Proceeding to ROOM 2...\n");
    printf("====================================\n");
    SetConsoleTextAttribute(h, 7);

    return 1;
}
//room 1 end
//room 2

int r2_lvl1_correct=0;
int r2_lvl1_incorrect=0;

int r2_lvl2_correct=0;
int r2_lvl2_incorrect=0;

int r2_lvl3_correct=0;
int r2_lvl3_incorrect=0;

int room2AskMCQ(const char question[],const char optionA[],const char optionB[],const char optionC[],const char optionD[],char correctAnswer,int *lifelineAvailable)
{
    char answer;
    const char *options[4]={optionA,optionB,optionC,optionD};
    char labels[4]={'A','B','C','D'};
    int correctIndex=correctAnswer-'A';
    int wrongIndex=-1;
    int i;

    printf("\n%s\n",question);

    for(i=0;i<4;i++)
    {
        printf("\n%c. %s",labels[i],options[i]);
    }

    printf("\n\nEnter your answer (A/B/C/D or L for 50-50): ");
    scanf(" %c",&answer);
    answer=toupper((unsigned char)answer);

    while(answer=='L')
    {
        if(*lifelineAvailable==1)
        {
            *lifelineAvailable=0;

            for(i=0;i<4;i++)
            {
                if(i!=correctIndex)
                {
                    wrongIndex=i;
                    break;
                }
            }

            SetConsoleTextAttribute(h, 14);
            printf("\n50-50 LIFELINE ACTIVATED!");
            printf("\nTwo incorrect options have been removed.\n");
            SetConsoleTextAttribute(h, 7);

            for(i=0;i<4;i++)
            {
                if(i==correctIndex || i==wrongIndex)
                {
                    printf("\n%c. %s",labels[i],options[i]);
                }
            }
        }
        else
        {
            SetConsoleTextAttribute(h, 12);
            printf("\n50-50 lifeline is not available!");
            SetConsoleTextAttribute(h, 7);
        }

        printf("\n\nEnter your answer (A/B/C/D): ");
        scanf(" %c",&answer);
        answer=toupper((unsigned char)answer);
    }

    if(answer!='A' && answer!='B' && answer!='C' && answer!='D')
    {
        SetConsoleTextAttribute(h, 12);
        printf("\nInvalid answer! Counted as incorrect.\n");
        Sleep(1500);
        system("cls");
        SetConsoleTextAttribute(h, 7);
        return 0;
    }

    if(answer==correctAnswer)
    {
        SetConsoleTextAttribute(h, 10);
        printf("\nCorrect Answer!\n");
        Sleep(1500);
        system("cls");
        SetConsoleTextAttribute(h, 7);
        return 1;
    }
    else
    {
        SetConsoleTextAttribute(h, 12);
        printf("\nIncorrect Answer!\n");
        Sleep(1500);
        system("cls");
        SetConsoleTextAttribute(h, 7);
        return 0;
    }
}

int room2level1(int firstAttempt)
{
    int score=0;
    int lifelineAvailable=firstAttempt;

    SetConsoleTextAttribute(h, 11);
    printf("\n\n\t\t========== LEVEL 1: EASY ==========\n");
    SetConsoleTextAttribute(h, 7);

    score+=room2AskMCQ("Question 1. What is 25 percent of 360?","90","80","100","120",'A',&lifelineAvailable);

    score+=room2AskMCQ("Question 2. Solve: 3x + 7 = 28.","5","7","6","8",'C',&lifelineAvailable);

    score+=room2AskMCQ("Question 3. What is the square root of 2025?","35","45","40","50",'B',&lifelineAvailable);

    score+=room2AskMCQ("Question 4. Divide 120 in the ratio 2:3. What is the larger share?","48","72","60","80",'B',&lifelineAvailable);

    score+=room2AskMCQ("Question 5. Find the area of a rectangle with length 12 cm and width 8 cm.","96","80","88","100",'A',&lifelineAvailable);

    r2_lvl1_correct=score;
    r2_lvl1_incorrect=5-score;

    SetConsoleTextAttribute(h, 14);
    printf("\nLEVEL 1 SCORE: %d/5",score);
    SetConsoleTextAttribute(h, 7);

    return score;
}

int room2level2(int firstAttempt)
{
    int score=0;
    int lifelineAvailable=firstAttempt;

    SetConsoleTextAttribute(h, 11);
    printf("\n\n\t\t========== LEVEL 2: MEDIUM ==========\n");
    SetConsoleTextAttribute(h, 7);

    score+=room2AskMCQ("Question 1. Solve: x^2 - 7x + 12 = 0.","1 and 12","3 and 4","2 and 6","4 and 5",'B',&lifelineAvailable);

    score+=room2AskMCQ("Question 2. Simplify: 2 raised to power 3 multiplied by 2 raised to power 4.","32","64","128","256",'C',&lifelineAvailable);

    score+=room2AskMCQ("Question 3. Find the value of log base 2 of 64.","4","6","5","8",'B',&lifelineAvailable);

    score+=room2AskMCQ("Question 4. Two numbers have a sum of 15 and a difference of 3. What is the larger number?","9","6","8","12",'A',&lifelineAvailable);

    score+=room2AskMCQ("Question 5. What is the probability of getting an even number when rolling a fair dice?","1/6","1/3","1/2","2/3",'C',&lifelineAvailable);

    r2_lvl2_correct=score;
    r2_lvl2_incorrect=5-score;

    SetConsoleTextAttribute(h, 14);
    printf("\nLEVEL 2 SCORE: %d/5",score);
    SetConsoleTextAttribute(h, 7);

    return score;
}

int room2level3(int firstAttempt)
{
    int score=0;
    int lifelineAvailable=firstAttempt;

    SetConsoleTextAttribute(h, 11);
    printf("\n\n\t\t========== LEVEL 3: HARD ==========\n");
    SetConsoleTextAttribute(h, 7);

    score+=room2AskMCQ("Question 1. If f(x) = 2x + 5, what is f(3)?","9","10","11","12",'C',&lifelineAvailable);

    score+=room2AskMCQ("Question 2. Evaluate: lim x->2 (x + 3).","5","3","4","6",'A',&lifelineAvailable);

    score+=room2AskMCQ("Question 3. Differentiate: f(x) = x^3.","3x^2","2x","x^2","3x",'A',&lifelineAvailable);

    score+=room2AskMCQ("Question 4. Differentiate: f(x) = 5x^2 + 3x.","5x + 3","10x + 3","10x","5x^2",'B',&lifelineAvailable);

    score+=room2AskMCQ("Question 5. Integrate: integral of 2x dx.","2x^2 + C","x + C","x^2 + C","x^2/2 + C",'C',&lifelineAvailable);

    r2_lvl3_correct=score;
    r2_lvl3_incorrect=5-score;

    SetConsoleTextAttribute(h, 14);
    printf("\nLEVEL 3 SCORE: %d/5",score);
    SetConsoleTextAttribute(h, 7);

    return score;
}

void room2()
{
    int score1,score2,score3;
    int firstAttempt1=1;
    int firstAttempt2=1;
    int firstAttempt3=1;

    SetConsoleTextAttribute(h, 13);
    printf("\n\n\t\t====================================");
    printf("\n\t\t   WELCOME TO MATHEMATICS ESCAPE ROOM");
    printf("\n\t\t====================================");
    SetConsoleTextAttribute(h, 7);

    printf("\n\n\t\t========== GAME INSTRUCTIONS ==========");
    printf("\n\t\t1. The Mathematics Escape Room has 3 levels.");
    printf("\n\t\t2. Each level contains 5 multiple-choice questions.");
    printf("\n\t\t3. Select your answer by entering A, B, C or D.");
    printf("\n\t\t4. Each correct answer earns 1 point.");
    printf("\n\t\t5. You need at least 3/5 to clear a level.");
    printf("\n\t\t6. Enter L to activate the 50-50 lifeline.");
    printf("\n\t\t7. Each level has one lifeline in its first attempt only.");
    printf("\n\t\t8. The lifeline removes two incorrect options, leaving two options to choose from.");
    printf("\n\t\t9. Lifelines are not available during retries.");
    printf("\n\t\t10. Using a lifeline does not affect your score.");
    printf("\n\t\t11. Clear all 3 levels to escape the room!");
    printf("\n\t\t========================================");
    printf("\n\n\t\tGOOD LUCK, PLAYER! YOUR ADVENTURE BEGINS NOW!\n");
    Sleep(3000);
    system("cls");

    do
    {
        score1=room2level1(firstAttempt1);
        firstAttempt1=0;

        if(score1<3)
        {
            SetConsoleTextAttribute(h, 12);
            printf("\n\nYou need to score at least 3/5 to unlock the next level.");
            printf("\nPlease try LEVEL 1 again.\n");
            SetConsoleTextAttribute(h, 7);
            Sleep(2500);
            system("cls");
        }
    }while(score1<3);

    SetConsoleTextAttribute(h, 10);
    printf("\n\nLEVEL 1 UNLOCKED! Moving to LEVEL 2...\n");
    SetConsoleTextAttribute(h, 7);
    Sleep(2500);
    system("cls");

    do
    {
        score2=room2level2(firstAttempt2);
        firstAttempt2=0;

        if(score2<3)
        {
            SetConsoleTextAttribute(h, 12);
            printf("\n\nYou need to score at least 3/5 to unlock the next level.");
            printf("\nPlease try LEVEL 2 again.\n");
            SetConsoleTextAttribute(h, 7);
            Sleep(2500);
            system("cls");
        }
    }while(score2<3);

    SetConsoleTextAttribute(h, 10);
    printf("\n\nLEVEL 2 UNLOCKED! Moving to LEVEL 3...\n");
    SetConsoleTextAttribute(h, 7);
    Sleep(2500);
    system("cls");

    do
    {
        score3=room2level3(firstAttempt3);
        firstAttempt3=0;

        if(score3<3)
        {
            SetConsoleTextAttribute(h, 12);
            printf("\n\nYou need to score at least 3/5 to escape.");
            printf("\nPlease try LEVEL 3 again.\n");
            SetConsoleTextAttribute(h, 7);
            Sleep(2500);
            system("cls");
        }
    }while(score3<3);

    SetConsoleTextAttribute(h, 10);
    printf("\n\n\t\t====================================");
    printf("\n\t\t CONGRATULATIONS! YOU ESCAPED!");
    printf("\n\t\t====================================");

    printf("\n\n\t\t========== LEADERBOARD ==========");

    printf("\n\n\t\tLEVEL 1");
    printf("\n\t\tCorrect Answers: %d",r2_lvl1_correct);
    printf("\n\t\tIncorrect Answers: %d",r2_lvl1_incorrect);

    printf("\n\n\t\tLEVEL 2");
    printf("\n\t\tCorrect Answers: %d",r2_lvl2_correct);
    printf("\n\t\tIncorrect Answers: %d",r2_lvl2_incorrect);

    printf("\n\n\t\tLEVEL 3");
    printf("\n\t\tCorrect Answers: %d",r2_lvl3_correct);
    printf("\n\t\tIncorrect Answers: %d",r2_lvl3_incorrect);

    printf("\n\n\t\tTOTAL SCORE: %d/15",score1+score2+score3);
    printf("\n\t\t====================================\n");

    printf("\n\n\t\t====================================");
    printf("\n\t\t       ROOM 2 COMPLETED!");
    printf("\n\t\t====================================");
    printf("\n\n\t\tYou have conquered the Mathematics Escape Room!");
    printf("\n\t\tYour next adventure awaits...");
    printf("\n\t\tGet ready to enter ROOM 3!");
    printf("\n\n\t\t       THE ADVENTURE CONTINUES!");
    printf("\n\t\t====================================\n");
    SetConsoleTextAttribute(h, 7);
}
//room 3 begains

/*Restructured code

The 15 repeated blocks are now one table of questions (a struct array) and a single playLevel() function. To add or edit a question, you only change the table.
Per-level counts live in the Level struct, so the 6 global variables are gone.
readAnswer() keeps asking until the player types A–D, and it clears leftover typing so one stray input can’t mess up the next question.
When an answer is wrong, the game now shows the correct one.
The leaderboard shows the score out of 15.*/


int threeonecount = 0;
int threeonedcount = 0;
int threetwocount = 0;
int threetwodcount = 0;
int threethreecount = 0;
int threethreedcount = 0;

int intro(){
    h = GetStdHandle(STD_OUTPUT_HANDLE);


    printf("\n==================================================\n");
    SetConsoleTextAttribute(h, 13);

    printf("\n=====  WELCOME TO THE ACADEMIC ESCAPE ROOM  ===== ");
    SetConsoleTextAttribute(h, 7);

    printf("\n=====================================================\n");
    Sleep(3000);
    system("cls");
    printf("\n\n");
    Sleep(2000);
    printf("\n        A ROOM BUILT TO TEST YOUR KNOWLEDGE ");
    Sleep(3000);
    system("cls");
    printf("\n\n");
    Sleep(2000);
    SetConsoleTextAttribute(h, 13);
    Sleep(3000);
    system("cls");
    printf("\n*******************************************************\n");
    SetConsoleTextAttribute(h, 12);
    printf(" \n               CAN YOU ESCAPE IT?\n");
    SetConsoleTextAttribute(h, 13);
    printf("\n********************************************************\n");
    Sleep(3000);
    system("cls");
    Sleep(2000);
    SetConsoleTextAttribute(h, 10);
    printf("\n==================   GAME INFO   ===================");
    SetConsoleTextAttribute(h, 7);
    printf("\n There are three rooms ;\nRoom 1: Ridles\nRoom 2: Questions based on Mathematics\nRoom 3: Problem solving based on c language");
    printf("\nEach room has 3 levels \n1, Easy \n2, Medium\n3, Hard");
    printf("\n !  Player can  only progress to the next roon if he/she gets atleast 3 correct answers in each level\n! otherwise the that level will repeat again");
    Sleep(6000);
    system("cls");
    Sleep(3000);
    printf(" \n  GAME STARTING.......");
    return 0;
}

int room3level1(){
    Sleep(3000);
    system("cls");

    printf("==================ROOM 3 : coding with C language =================== \n LEVEL 1: EASY MODE \n");
    system("cls");
    printf("\n\n\nQuestion 1. Which library is used for mathematical operations in c? \n");
    printf("\n A. stdio.h \n B. stdlib.h \n C. math.h \n D. string.h \n");
    printf("\n Enter your answer: ");
    char ans1;
    scanf(" %c",&ans1);
    if(ans1 == 'C' || ans1 == 'c'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threeonecount++;
    } else {
        SetConsoleTextAttribute(h, 12); 
        printf("Incorrect Answer!\nCorrect answer: C. math.h\n");
        threeonedcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 2. What is the correct way to declare a constant in C? \n");
    printf("\n A. const int x = 5; \n B. #define PI 3.14 \n C. constant int x = 5; \n D. int const x = 5; \n");
    printf("\n Enter your answer: ");
    char ans2;
    scanf(" %c",&ans2);
    if(ans2 == 'B' || ans2 == 'b'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threeonecount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: B. #define PI 3.14\n");
        threeonedcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 3. Find the output of:\n printf(\"%%d\", 10 %% 3);\n");
    printf("\n A. 1 \n B. 2 \n C. 3 \n D. 0 \n");
    printf("\n Enter your answer: ");
    char ans3;
    scanf(" %c",&ans3);
    if(ans3 == 'A' || ans3 == 'a'){
        SetConsoleTextAttribute(h, 10);
        printf("\nCorrect Answer!\n");
        threeonecount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: A. 1\n");
        threeonedcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 4. Which of the following is a valid variable name in C? \n");
    printf("\n A. 1variable \n B. variable_1 \n C. variable-1 \n D. variable 1 \n");
    printf("\n Enter your answer: ");   
    char ans4;
    scanf(" %c",&ans4); 
    if(ans4 == 'B' || ans4 == 'b'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threeonecount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: B. variable_1\n");
        threeonedcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 5. What is the output of the following code?\n int x = 5; \n printf(\"%%d\", x++ + 2); \n");
    printf("\n A. 7 \n B. 6 \n C. 5 \n D. 8 \n");
    printf("\n Enter your answer: ");
    char ans5;
    scanf(" %c",&ans5); 
    if(ans5 == 'A' || ans5 == 'a'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threeonecount++;
    } else {


        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: A. 7\n");
        threeonedcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);

    return 0;
}
int room3level2(){
    printf("\n\n\nROOM 3 : coding with C language  \n LEVEL 2: MEDIUM MODE \n");
    system("cls");
    printf("\n\nQuestion 1. What is the output of the following code?\n int a = 5; \n int b = 10; \n printf(\"%%d\", a > b ? a : b); \n");
    printf("\n A. 5 \n B. 10 \n C. 15 \n D. Error \n");
    printf("\n Enter your answer: ");
    char ans1;
    scanf(" %c",&ans1);
    if(ans1 == 'B' || ans1 == 'b'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threetwocount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: B. 10\n");
        threetwodcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 2. Which of the following is used to allocate memory dynamically in C? \n");
    printf("\n A. malloc() \n B. calloc() \n C. realloc() \n D. All of the above \n");
    printf("\n Enter your answer: ");
    char ans2;
    scanf(" %c",&ans2);
    if(ans2 == 'D' || ans2 == 'd'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threetwocount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: D. All of the above\n");
        threetwodcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 3. Find the output:\n for(int i=0;i<5;i++){\nif(i==3)continue;\nprintf(\"%%d\",i);}");
    printf("\n A. 01234 \n B. 0124 \n C. 1234 \n D. 123 \n");
    printf("\n Enter your answer: ");
    char ans3;
    scanf(" %c",&ans3);
    if(ans3 == 'B' || ans3 == 'b'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threetwocount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: B. 0124\n");
        threetwodcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 4. Which of the following is used to read a character from the user in C? \n");
    printf("\n A. scanf() \n B. getchar() \n C. getchar() \n D. All of the above \n");
    printf("\n Enter your answer: ");
    char ans4;
    scanf(" %c",&ans4);
    if(ans4 == 'D' || ans4 == 'd'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threetwocount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: D. All of the above\n");
        threetwodcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 5. What is the output of the following code?\n int x = 5; \n int y = 10; \n printf(\"%%d\", x ^ y); \n");
    printf("\n A. 0 \n B. 5 \n C. 10 \n D. 15 \n");
    printf("\n Enter your answer: ");
    char ans5;
    scanf(" %c",&ans5);
    if(ans5 == 'D' || ans5 == 'd'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threetwocount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: D. 15\n");
        threetwodcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);

    return 0;
}
int room3level3(){
    printf("\n\n\nROOM 3 : coding with C language  \n LEVEL 3: HARD MODE \n");
    Sleep(3000);
    system("cls");
    printf("\n\nQuestion 1. What is the output of the following code?\n int x = 5; \n int y = 10; \n printf(\"%%d\", x & y); \n");
    printf("\n A. 0 \n B. 5 \n C. 10 \n D. 15 \n");
    printf("\n Enter your answer: ");
    char ans1;
    scanf(" %c",&ans1);
    if(ans1 == 'A' || ans1 == 'a'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threethreecount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: A. 0\n");
        threethreedcount++;
    }
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 2. Which of the following is used to terminate a program in C? \n");
    printf("\n A. exit() \n B. return() \n C. break() \n D. continue() \n");
    printf("\n Enter your answer: ");
    char ans2;
    scanf(" %c",&ans2);
    if(ans2 == 'A' || ans2 == 'a'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threethreecount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: A. exit()\n");
        threethreedcount++;
    }
    Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 3. Find the output of the following code:\n int arr[5] = {1, 2, 3, 4, 5}; \n printf(\"%%d\", *(arr + 2)); \n");
    printf("\n A. 1 \n B. 2 \n C. 3 \n D. 4 \n");
    printf("\n Enter your answer: ");
    char ans3;
    scanf(" %c",&ans3);
    if(ans3 == 'C' || ans3 == 'c'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        
        threethreecount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: C. 3\n");
        threethreedcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 4. Which of the following is used to read a string from the user in C? \n");
    printf("\n A. scanf() \n B. gets() \n C. fgets() \n D. All of the above \n");
    printf("\n Enter your answer: ");
    char ans4;
    scanf(" %c",&ans4);
    if(ans4 == 'D' || ans4 == 'd'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threethreecount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: D. All of the above\n");
        threethreedcount++;
    }Sleep(3000);

    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n\nQuestion 5. What is the output of the following code?\n int x = 5; \n int y = 10; \n printf(\"%%d\", x | y); \n");
    printf("\n A. 0 \n B. 5 \n C. 10 \n D. 15 \n");
    printf("\n Enter your answer: ");
    char ans5;
    scanf(" %c",&ans5);
    if(ans5 == 'D' || ans5 == 'd'){
        SetConsoleTextAttribute(h, 10);
        printf("Correct Answer!\n");
        threethreecount++;
    } else {
        SetConsoleTextAttribute(h, 12);
        printf("Incorrect Answer!\nCorrect answer: D. 15\n");
        threethreedcount++;
    }Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    
    return 0;

}
int room3(){
    room3level1();
    Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 10);
    printf("\n                   loading reults.....");
    Sleep(2000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n               =======Level 1 results=======\n");
    printf("\n       Total correct answers in LEVEL 1: %d \n", threeonecount);
    printf("\n       Total incorrect answers in LEVEL 1: %d \n", threeonedcount);

    room3level2();
    Sleep(7000);
    system("cls");
    SetConsoleTextAttribute(h, 10);
    printf("\n                   loading reults.....");
    Sleep(2000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n           ===========Level 2 Results===========\n");
    printf("\n       Total correct answers in LEVEL 2: %d \n", threetwocount);
    printf("\n       Total incorrect answers in LEVEL 2: %d \n", threetwodcount);

    room3level3();
    Sleep(7000);
    system("cls");
    SetConsoleTextAttribute(h, 10);
    printf("\n                   loading reults.....");
    Sleep(3000);
    system("cls");
    SetConsoleTextAttribute(h, 7);
    printf("\n           ==========Level 3 Results===========\n");
    printf("\n        Total correct answers in LEVEL 3: %d \n", threethreecount);
    printf("\n        Total incorrect answers in LEVEL 3: %d \n", threethreedcount);

    return 0;
}

int main(void){
    
    intro();
    if(room1() == 0){
        return 0;
    }
    room2();
    room3();


    printf("\n\n===============LEADER BOARD================\n\n");
    printf("\nRoom 3 score: %d/15\n", threeonecount + threetwocount + threethreecount);
    return 0;
}

