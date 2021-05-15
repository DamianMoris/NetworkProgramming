#include <stdio.h>
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
int wheelspin();

int main()
{
    srand(time(NULL));

    wheelspin();

    //printf("%d\n",rng(100));

    //for(int i = 0; i < 50; i++)
    //{
    //    printf("%d, %d, %d, %d, %d, %d \n", d4(), d6(), d8(), d12(), d20(), d100());
    //}

    //printf("d4: %d\nd6: %d\nd8: %d\nd12: %d\nd20: %d\nd100: %d\n", d4(), d6(), d8(), d12(), d20(), d100());

    return 0;
}

unsigned int coinflip()             {return (rand() % 2);}
unsigned int rng(unsigned int i)    {return (rand() % (i + 1));}
unsigned int d4()                   {return (rand() % 4 + 1);}
unsigned int d6()                   {return (rand() % 6 + 1);}
unsigned int d8()                   {return (rand() % 8 + 1);}
unsigned int d12()                  {return (rand() % 12 + 1);}
unsigned int d20()                  {return (rand() % 20 + 1);}
unsigned int d100()                 {return (rand() % 100 + 1);}

int wheelspin()
{
    int i = 0;
    int iWords = 0;
    char* sWords = (char*) malloc(30 * sizeof(char));
    char** array;
    array = (char**) malloc(10 * sizeof(char*));

    printf("How many words do you want to insert?\n");
    scanf("%d", &iWords);

    for(i = 0; i < iWords; i++) //strcmp(array[i], "stop") == 0
    {
        printf("Enter a word\n");
        array[i] = (char*) malloc(30 * sizeof(char));
        //word = (char*) malloc(30 * sizeof(char));
        gets(array[i]);

        //strcpy(array[i], word);
        //printf("%s\n", array[i]);
        //printf("%s\n", word);
        //free(word);
        printf("%s\n", array[i]);
        //array[i] = (char*) realloc(array[i], sizeof(array[i]));
    }

    printf("%s\n", array[rand() % iWords]);

    //for(int i = 0; i < 3; i++)
    //{
    //    printf("Enter a word\n");
    //    array[i] = (char*) malloc(100 * sizeof(char));
    //    scanf("%s", array[i]);
    //    array[i] = (char*) realloc(array[i], sizeof(array[i]));
    //}
    //printf("\n");

    for(int j = 0; j < i; j++){free(array[j]);}
    free(array);

    //for(int i = 0; i < 3; i++){printf("array[%d]: %s\n",i , array[i]);}

    return (1);
}
