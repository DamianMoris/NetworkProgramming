/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

unsigned int coinflip();
unsigned int rng();
unsigned int d4();
unsigned int d6();
unsigned int d8();
unsigned int d12();
unsigned int d20();
unsigned int d100();
char letter();
int wheelspin();
char* magic8ball();
char* card();
char* deck();

int main()
{
    srand(time(NULL));

    //printf("%d\n\n", coinflip());

    printf("%d\n", wheelspin("a1,b2,c3,damn"));

    //printf("%s", magic8ball("is this a question?"));

    //printf("%s", deck(52));

    //printf("%s\n", card());

    //printf("%s\n", str);

    //printf("♥/%c  ♦/%c  ♣/%c  ♠/%c \n", 3, 4, 5, 6);
    //for(int i = 0; i < 100; i++) {card();}

    //for(int i = 0; i < 300; i++) {printf("%c", i);}

    //for(int i = 0; i < 100; i++) {printf("%c\n", letter());}

    //wheelspin();

    //printf("%d\n", rng(100));

    //printf("d4: %d\nd6: %d\nd8: %d\nd12: %d\nd20: %d\nd100: %d\n", d4(), d6(), d8(), d12(), d20(), d100());

    return 0;
}

unsigned int coinflip()             {return (rand() % 2);}          // random value 0 or 1
unsigned int rng(unsigned int i)    {return (rand() % (i + 1));}    // random value between 1 and i
unsigned int d4()                   {return (rand() % 4 + 1);}      // random value between 1 and 4
unsigned int d6()                   {return (rand() % 6 + 1);}      // random value between 1 and 6
unsigned int d8()                   {return (rand() % 8 + 1);}      // random value between 1 and 8
unsigned int d12()                  {return (rand() % 12 + 1);}     // random value between 1 and 12
unsigned int d20()                  {return (rand() % 20 + 1);}     // random value between 1 and 20
unsigned int d100()                 {return (rand() % 100 + 1);}    // random value between 1 and 100
char letter()                       {return (rand() % 26 + 97);}    // ASCII values 97 - 122 (letters a - z)

int wheelspin(char* list)
{
    int words = 1;
    int jlist = 0;
    int j = 0;
    //char** wheel;
    for(int i = 0; list[i] != '\0'; i++)
    {
        if(list[i] == ',' && list[i + 1] != '\0')
        {
            words++;
        }
    }
    //wheel = (char**) malloc(words * sizeof(char*));
    char* wheel[words];
    //wheel[words] = NULL;

    for(int i = 0; i < words; i++)
    {
        for(j = 0; list[jlist] != ',' && list[jlist] != '\0'; j++, jlist++)
        {
            printf("i: %d j: %d jlist: %d\n", i, j, jlist);
            printf("before: %c %c\n", wheel[i][j], list[jlist]);
            wheel[i][j] = (char) malloc(sizeof(char));
            sprintf(&wheel[i][j], "%c", list[jlist]);
            //wheel[i][j] = list[jlist];
            printf("after: %c %c\n", wheel[i][j], list[jlist]);
        }
        printf("%d\n", j);
        wheel[i][j] = (char) malloc(sizeof(char));
        sprintf(&wheel[i][j], "%c", '\0');
        printf("%s\n", wheel[0]);
        jlist++;
    }

    printf("list[]: %s\n", list);
    printf("wheel[]: %s\n", wheel[0]);

    //int i = 0;
    //int words = 0;
    //char* array[10];
    //array = (char**) malloc(10 * sizeof(char*));

    //printf("How many words do you want to insert (max 10)?\n");
    //scanf("%d", &words);

    //for(i = 0; i < words; i++)
    //{
    //    printf("Enter a word\n");
    //    array[i] = (char*) malloc(30 * sizeof(char));
    //    scanf("%s", array[i]);
    //    printf("%s\n", array[i]);
    //}

    //printf("%s\n", array[rand() % words]);

    //for(int j = 0; j < i; j++){free(array[j]);}

    //for(int i = 0; i < 3; i++){printf("array[%d]: %s\n",i , array[i]);}

    return words;
}

char* magic8ball(char* question)
{
    char* responses[20] = {"It is Certain.\n", "It is decidedly so.\n", "Without a doubt.\n", "Yes definitely.\n", "You may rely on it.\n",
                           "As I see it, yes.\n", "Most likely.\n", "Outlook good.\n", "Yes.\n", "Signs point to yes.\n",
                           "Reply hazy, try again.\n", "Ask again later.\n", "Better not tell you now.\n", "Cannot predict now.\n", "Concentrate and ask again.\n",
                           "Don't count on it.\n", "My reply is no.\n", "My sources say no.\n", "Outlook not so good.\n", "Very doubtful.\n"};
    for(int i = 0; i < (int) strlen(question); i++)
    {
        if(question[i] == '?') {return (responses[rand() % 20]);}
    }
    return "That is not a question\n";
}

char* card() // (char)3 == ♥   (char)4 == ♦   (char)5 == ♣   (char)6 == ♠
{
    char* ns = (char*) malloc(2 * sizeof(char));
    char number[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K'};
    char symbol[4] = {3, 4, 5, 6}; // {♥, ♦, ♣, ♠}

    sprintf(ns, "%c%c", number[rand() % 13], symbol[rand() % 4]);

    return ns;
}

char* deck(int amount)
{
    int pos = 0;
    int returnpos = 0;
    char* returncards = (char*) malloc(3 * amount * sizeof(int));
    char cards[104];
    sprintf(cards, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
                   "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
                   ,'A',3,'2',3,'3',3,'4',3,'5',3,'6',3,'7',3,'8',3,'9',3,'0',3,'J',3,'Q',3,'K',3     // (char)3 == ♥
                   ,'A',4,'2',4,'3',4,'4',4,'5',4,'6',4,'7',4,'8',4,'9',4,'0',4,'J',4,'Q',4,'K',4     // (char)4 == ♦
                   ,'A',5,'2',5,'3',5,'4',5,'5',5,'6',5,'7',5,'8',5,'9',5,'0',5,'J',5,'Q',5,'K',5     // (char)5 == ♣
                   ,'A',6,'2',6,'3',6,'4',6,'5',6,'6',6,'7',6,'8',6,'9',6,'0',6,'J',6,'Q',6,'K',6);   // (char)6 == ♠

    for(int i = 0; i < amount; i++)
    {
        pos = 2 * (rand() % 52);
        if(cards[pos] != '\n')
        {
            returncards[returnpos++] = cards[pos];
            returncards[returnpos++] = cards[pos + 1];
            returncards[returnpos++] = '\n';
            cards[pos] = '\n';
            cards[pos + 1] = '\n';
        }
        else
        {
            i--;
        }
    }
    returncards[3 * amount] = '\0';

    return returncards;
}*/
