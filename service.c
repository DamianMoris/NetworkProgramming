#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    char* array[10] = {"1","22","333","4444"};

    for(int i = 0; i < 10; i++)
    {
        printf("Enter a word\n");
        scanf("%s", array[i]);
    }

    printf("wheelspin\n");
    array[0] = "azertyop";
    printf("array[random]: %s\n", array[rand() % 4]); //

    return (1);
}
