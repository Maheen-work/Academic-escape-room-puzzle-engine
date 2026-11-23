#include <stdio.h>
#include <ctype.h>

int roomonelevelonecorrect = 0;
int roomoneleveloneincorrect = 0;

int roomoneleveltwocorrect = 0;
int roomoneleveltwoincorrect = 0;

int roomonelevelthreecorrect = 0;
int roomonelevelthreeincorrect = 0;


int room1AskMCQ(const char question[], const char optionA[], const char optionB[],
                const char optionC[], const char optionD[], char correctOption,
                const char hint[], int *hintsLeft)
{
    char userAnswer;
    char choice;

    printf("\n%s\n", question);
    printf("A. %s\n", optionA);
    printf("B. %s\n", optionB);
    printf("C. %s\n", optionC);
    printf("D. %s\n", optionD);

    if(hintsLeft != NULL && hint != NULL && hint[0] != '\0' && *hintsLeft > 0)
    {
        printf("\nWould you like to use a hint? (Y/N): ");
        scanf(" %c", &choice);

        choice = toupper((unsigned char)choice);

        if(choice == 'Y')
        {
            printf("\nHint: %s\n", hint);

            (*hintsLeft)--;

            printf("Hints remaining: %d\n", *hintsLeft);
        }
    }

    printf("\nEnter your answer (A/B/C/D): ");
    scanf(" %c", &userAnswer);

    userAnswer = toupper((unsigned char)userAnswer);

    if(userAnswer == correctOption)
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

int room1level1()
{
    while(1)
    {
        roomonelevelonecorrect = 0;
        roomoneleveloneincorrect = 0;

        printf("\n========== EASY LEVEL ==========\n");

        if(room1AskMCQ("1. What gets wetter the more it dries?",
        "Sponge", "Towel", "Tissue", "Cloth", 'B', "", NULL))
            roomonelevelonecorrect++;
        else
            roomoneleveloneincorrect++;

        if(room1AskMCQ("2. Which musical instrument has 88 keys?",
        "Organ", "Harpsichord", "Piano", "Accordion", 'C', "", NULL))
            roomonelevelonecorrect++;
        else
            roomoneleveloneincorrect++;

        if(room1AskMCQ("3. What follows you in daylight but disappears in complete darkness?",
        "Reflection", "Shadow", "Silhouette", "Footprint", 'B', "", NULL))
            roomonelevelonecorrect++;
        else
            roomoneleveloneincorrect++;

        if(room1AskMCQ("4. What has many teeth and is used to untangle hair?",
        "Brush", "Comb", "Razor", "Clip", 'B', "", NULL))
            roomonelevelonecorrect++;
        else
            roomoneleveloneincorrect++;

        if(room1AskMCQ("5. David's father has three sons: Snap, Crackle and _____?",
        "Pop", "David", "Jack", "Crackle", 'B', "", NULL))
            roomonelevelonecorrect++;
        else
            roomoneleveloneincorrect++;

        printf("\n========== EASY LEVEL RESULTS ==========\n");

        printf("Correct Answers: %d/5\n", roomonelevelonecorrect);
        printf("Incorrect Answers: %d/5\n", roomoneleveloneincorrect);

        if(roomonelevelonecorrect >= 3)
        {
            printf("\nCongratulations! EASY LEVEL CLEARED!\n");
            printf("You have unlocked the NORMAL LEVEL!\n");
            return 1;
        }
        else
        {
            printf("\nYou failed the EASY LEVEL!\n");
            printf("You need at least 3 correct answers to pass.\n");
            printf("Please try again!\n");
        }
    }
}

int room1level2()
{
    while(1)
    {
        int hintsLeft = 1;

        roomoneleveltwocorrect = 0;
        roomoneleveltwoincorrect = 0;

        printf("\n========== NORMAL LEVEL ==========\n");
        printf("You have 1 hint for the entire level.\n");
        printf("You may use it on any question you choose.\n");

        if(room1AskMCQ("1. The more you take, the more you leave behind. What am I?",
        "Footprints", "Footsteps", "Tracks", "Shadows", 'B',
        "Think about what remains on the ground after someone walks.",
        &hintsLeft))
            roomoneleveltwocorrect++;
        else
            roomoneleveltwoincorrect++;

        if(room1AskMCQ("2. What travels around the world while staying in one corner?",
        "Postcard", "Envelope", "Stamp", "Sticker", 'C',
        "Think about something attached to mail before it is sent.",
        &hintsLeft))
            roomoneleveltwocorrect++;
        else
            roomoneleveltwoincorrect++;

        if(room1AskMCQ("3. I have cities but no houses, forests but no trees, and water but no fish. What am I?",
        "Globe", "Map", "Atlas", "Blueprint", 'B',
        "Think about something that represents places without containing them.",
        &hintsLeft))
            roomoneleveltwocorrect++;
        else
            roomoneleveltwoincorrect++;

        if(room1AskMCQ("4. What can fill an entire room but takes up no physical space?",
        "Sound", "Air", "Light", "Heat", 'C',
        "Think about something that allows you to see objects around you.",
        &hintsLeft))
            roomoneleveltwocorrect++;
        else
            roomoneleveltwoincorrect++;

        if(room1AskMCQ("5. What has one eye but cannot see?",
        "Camera", "Needle", "Storm", "Potato", 'B',
        "Think about a small opening found in a sewing tool.",
        &hintsLeft))
            roomoneleveltwocorrect++;
        else
            roomoneleveltwoincorrect++;

        printf("\n========== NORMAL LEVEL RESULTS ==========\n");

        printf("Correct Answers: %d/5\n", roomoneleveltwocorrect);
        printf("Incorrect Answers: %d/5\n", roomoneleveltwoincorrect);

        if(roomoneleveltwocorrect >= 3)
        {
            printf("\nCongratulations! NORMAL LEVEL CLEARED!\n");
            printf("You have unlocked the DIFFICULT LEVEL!\n");
            return 1;
        }
        else
        {
            printf("\nYou failed the NORMAL LEVEL!\n");
            printf("You need at least 3 correct answers to pass.\n");
            printf("Please try again!\n");
        }
    }
}

int room1level3()
{
    while(1)
    {
        int hintsLeft = 2;

        roomonelevelthreecorrect = 0;
        roomonelevelthreeincorrect = 0;

        printf("\n========== DIFFICULT LEVEL ==========\n");
        printf("You have 2 hints for the entire level.\n");
        printf("You may use them on any two separate questions.\n");

        if(room1AskMCQ("1. I speak without a mouth and hear without ears. I have no body, but come alive with the wind. What am I?",
        "Whisper", "Thunder", "Echo", "Wind", 'C',
        "It is something you hear when a sound returns to you.",
        &hintsLeft))
            roomonelevelthreecorrect++;
        else
            roomonelevelthreeincorrect++;

        if(room1AskMCQ("2. What disappears as soon as you say its name?",
        "Secret", "Silence", "Darkness", "Quietness", 'B',
        "Think about the absence of sound.",
        &hintsLeft))
            roomonelevelthreecorrect++;
        else
            roomonelevelthreeincorrect++;

        if(room1AskMCQ("3. I am taken from a mine, ground into powder, and used inside a pencil to leave marks. What am I?",
        "Charcoal", "Coal", "Graphite", "Ink", 'C',
        "It is a naturally occurring form of carbon.",
        &hintsLeft))
            roomonelevelthreecorrect++;
        else
            roomonelevelthreeincorrect++;

        if(room1AskMCQ("4. I have keys, a space bar, and an enter key, but no locks or rooms. What am I?",
        "Remote Control", "Piano", "Calculator", "Keyboard", 'D',
        "Think about a device used to type words.",
        &hintsLeft))
            roomonelevelthreecorrect++;
        else
            roomonelevelthreeincorrect++;

        if(room1AskMCQ("5. The more there is of me, the less you are able to see. What am I?",
        "Fog", "Smoke", "Darkness", "Shadow", 'C',
        "It is the opposite of brightness.",
        &hintsLeft))
            roomonelevelthreecorrect++;
        else
            roomonelevelthreeincorrect++;

        printf("\n========== DIFFICULT LEVEL RESULTS ==========\n");

        printf("Correct Answers: %d/5\n", roomonelevelthreecorrect);
        printf("Incorrect Answers: %d/5\n", roomonelevelthreeincorrect);

        if(roomonelevelthreecorrect >= 3)
        {
            printf("\nCongratulations! DIFFICULT LEVEL CLEARED!\n");
            return 1;
        }
        else
        {
            printf("\nYou failed the DIFFICULT LEVEL!\n");
            printf("You need at least 3 correct answers to pass.\n");
            printf("Please try again!\n");
        }
    }
}

int room1()
{
    int totalCorrect;
    int totalIncorrect;

    printf("\n====================================\n");
    printf("          WELCOME TO ROOM 1\n");
    printf("             RIDDLE ROOM\n");
    printf("====================================\n");

    printf("\nINSTRUCTIONS:\n");
    printf("- There are 3 difficulty levels.\n");
    printf("- Each level contains 5 questions.\n");
    printf("- You need at least 3 correct answers out of 5 to pass.\n");
    printf("- Clear each level to unlock the next one.\n");
    printf("- EASY MODE: No hints are available.\n");
    printf("- NORMAL MODE: One hint can be used on any one question.\n");
    printf("- DIFFICULT MODE: Two hints can be used on any two separate questions.\n");
    printf("- Incorrect answers will not reveal the correct option.\n");
    printf("- Failed levels must be attempted again.\n");

    room1level1();
    room1level2();
    room1level3();

    printf("\n====================================\n");
    printf("          ROOM 1 LEADERBOARD\n");
    printf("====================================\n");

    printf("\nEasy Level:\n");
    printf("Correct: %d | Incorrect: %d\n",
    roomonelevelonecorrect, roomoneleveloneincorrect);

    printf("\nNormal Level:\n");
    printf("Correct: %d | Incorrect: %d\n",
    roomoneleveltwocorrect, roomoneleveltwoincorrect);

    printf("\nDifficult Level:\n");
    printf("Correct: %d | Incorrect: %d\n",
    roomonelevelthreecorrect, roomonelevelthreeincorrect);

    totalCorrect = roomonelevelonecorrect +
                   roomoneleveltwocorrect +
                   roomonelevelthreecorrect;

    totalIncorrect = roomoneleveloneincorrect +
                     roomoneleveltwoincorrect +
                     roomonelevelthreeincorrect;

    printf("\nTotal Correct Answers: %d\n", totalCorrect);
    printf("Total Incorrect Answers: %d\n", totalIncorrect);
    printf("Final Score: %d/15\n", totalCorrect);

    printf("\n====================================\n");
    printf(" CONGRATULATIONS! YOU PASSED ROOM 1!\n");
    printf(" You have successfully completed all three levels :D.\n");
    printf(" Proceeding to ROOM 2...\n");
    printf("====================================\n");

    return 1;
}

int main(void)
{
    return room1() == 1 ? 0 : 1;
}

