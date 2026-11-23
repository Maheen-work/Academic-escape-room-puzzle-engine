#include<stdio.h>
#include<ctype.h>

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

            printf("\n50-50 LIFELINE ACTIVATED!");
            printf("\nTwo incorrect options have been removed.\n");

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
            printf("\n50-50 lifeline is not available!");
        }

        printf("\n\nEnter your answer (A/B/C/D): ");
        scanf(" %c",&answer);
        answer=toupper((unsigned char)answer);
    }

    if(answer!='A' && answer!='B' && answer!='C' && answer!='D')
    {
        printf("\nInvalid answer! Counted as incorrect.\n");
        return 0;
    }

    if(answer==correctAnswer)
    {
        printf("\nCorrect Answer!\n");
        return 1;
    }
    else
    {
        printf("\nIncorrect Answer!\n");
        return 0;
    }
}

int room2level1(int firstAttempt)
{
    int score=0;
    int lifelineAvailable=firstAttempt;

    printf("\n\n\t\t========== LEVEL 1: EASY ==========\n");

    score+=room2AskMCQ("Question 1. What is 25 percent of 360?","90","80","100","120",'A',&lifelineAvailable);

    score+=room2AskMCQ("Question 2. Solve: 3x + 7 = 28.","5","7","6","8",'C',&lifelineAvailable);

    score+=room2AskMCQ("Question 3. What is the square root of 2025?","35","45","40","50",'B',&lifelineAvailable);

    score+=room2AskMCQ("Question 4. Divide 120 in the ratio 2:3. What is the larger share?","48","72","60","80",'B',&lifelineAvailable);

    score+=room2AskMCQ("Question 5. Find the area of a rectangle with length 12 cm and width 8 cm.","96","80","88","100",'A',&lifelineAvailable);

    r2_lvl1_correct=score;
    r2_lvl1_incorrect=5-score;

    printf("\nLEVEL 1 SCORE: %d/5",score);

    return score;
}

int room2level2(int firstAttempt)
{
    int score=0;
    int lifelineAvailable=firstAttempt;

    printf("\n\n\t\t========== LEVEL 2: MEDIUM ==========\n");

    score+=room2AskMCQ("Question 1. Solve: x^2 - 7x + 12 = 0.","1 and 12","3 and 4","2 and 6","4 and 5",'B',&lifelineAvailable);

    score+=room2AskMCQ("Question 2. Simplify: 2 raised to power 3 multiplied by 2 raised to power 4.","32","64","128","256",'C',&lifelineAvailable);

    score+=room2AskMCQ("Question 3. Find the value of log base 2 of 64.","4","6","5","8",'B',&lifelineAvailable);

    score+=room2AskMCQ("Question 4. Two numbers have a sum of 15 and a difference of 3. What is the larger number?","9","6","8","12",'A',&lifelineAvailable);

    score+=room2AskMCQ("Question 5. What is the probability of getting an even number when rolling a fair dice?","1/6","1/3","1/2","2/3",'C',&lifelineAvailable);

    r2_lvl2_correct=score;
    r2_lvl2_incorrect=5-score;

    printf("\nLEVEL 2 SCORE: %d/5",score);

    return score;
}

int room2level3(int firstAttempt)
{
    int score=0;
    int lifelineAvailable=firstAttempt;

    printf("\n\n\t\t========== LEVEL 3: HARD ==========\n");

    score+=room2AskMCQ("Question 1. If f(x) = 2x + 5, what is f(3)?","9","10","11","12",'C',&lifelineAvailable);

    score+=room2AskMCQ("Question 2. Evaluate: lim x->2 (x + 3).","5","3","4","6",'A',&lifelineAvailable);

    score+=room2AskMCQ("Question 3. Differentiate: f(x) = x^3.","3x^2","2x","x^2","3x",'A',&lifelineAvailable);

    score+=room2AskMCQ("Question 4. Differentiate: f(x) = 5x^2 + 3x.","5x + 3","10x + 3","10x","5x^2",'B',&lifelineAvailable);

    score+=room2AskMCQ("Question 5. Integrate: integral of 2x dx.","2x^2 + C","x + C","x^2 + C","x^2/2 + C",'C',&lifelineAvailable);

    r2_lvl3_correct=score;
    r2_lvl3_incorrect=5-score;

    printf("\nLEVEL 3 SCORE: %d/5",score);

    return score;
}

void room2()
{
    int score1,score2,score3;
    int firstAttempt1=1;
    int firstAttempt2=1;
    int firstAttempt3=1;

    printf("\n\n\t\t====================================");
    printf("\n\t\t   WELCOME TO MATHEMATICS ESCAPE ROOM");
    printf("\n\t\t====================================");

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

    do
    {
        score1=room2level1(firstAttempt1);
        firstAttempt1=0;

        if(score1<3)
        {
            printf("\n\nYou need to score at least 3/5 to unlock the next level.");
            printf("\nPlease try LEVEL 1 again.\n");
        }
    }while(score1<3);

    printf("\n\nLEVEL 1 UNLOCKED! Moving to LEVEL 2...\n");

    do
    {
        score2=room2level2(firstAttempt2);
        firstAttempt2=0;

        if(score2<3)
        {
            printf("\n\nYou need to score at least 3/5 to unlock the next level.");
            printf("\nPlease try LEVEL 2 again.\n");
        }
    }while(score2<3);

    printf("\n\nLEVEL 2 UNLOCKED! Moving to LEVEL 3...\n");

    do
    {
        score3=room2level3(firstAttempt3);
        firstAttempt3=0;

        if(score3<3)
        {
            printf("\n\nYou need to score at least 3/5 to escape.");
            printf("\nPlease try LEVEL 3 again.\n");
        }
    }while(score3<3);

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
}

int main()
{
    room2();
    return 0;
}


