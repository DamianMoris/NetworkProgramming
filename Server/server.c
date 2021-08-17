#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>

#define BUF_SIZE 200

void srandStart();
char* coinflip();       // random value 0 or 1
char* rng();            // random value between 1 and i (where i is a user inputted value)
char* d4();             // random value between 1 and 4
char* d6();             // random value between 1 and 6
char* d8();             // random value between 1 and 8
char* d12();            // random value between 1 and 12
char* d20();            // random value between 1 and 20
char* d100();           // random value between 1 and 100
char* letter();         // random letter from a - z by using the ASCII values 97 - 122
char* wheelspin();      // input a list of words, outputs on of the inputted words
char* magic8ball();     // ask a question and you will get an answer
char* card();           // any random possible card
char* deck();           // any number of cards from 1 full deck of 52 cards

void * context;

int main()
{
    printf("Starting Server\n");
    srandStart();
    char recv[BUF_SIZE + 9] = "Damian>>>";
    char send[BUF_SIZE + 9] = "Damian<<<";
    char buffer[BUF_SIZE];
    char temp[BUF_SIZE];
    int j = 0;
    void * context = zmq_ctx_new();
    void * pusher = zmq_socket(context, ZMQ_PUSH);
    void * subscriber = zmq_socket(context, ZMQ_SUB);
    int p = zmq_connect(pusher, "tcp://benternet.pxl-ea-ict.be:24041");
    int s = zmq_connect(subscriber, "tcp://benternet.pxl-ea-ict.be:24042");
    sleep(1);
    if (p != 0 && s != 0)
    {
        printf("Error: %s\n", zmq_strerror(errno));
        return EXIT_FAILURE;
    }
    else
    {
        printf("Ready for request\n");
    }

    while(1)
    {
        zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, recv, strlen(recv));
        zmq_recv(subscriber, buffer, BUF_SIZE, 0);

        if(strcmp(buffer, "Damian>>>coinflip") == 0)
        {
            strcat(send, coinflip());
        }
        else if(strcmp(buffer, "Damian>>>d4") == 0)
        {
            strcat(send, d4());
        }
        else if(strcmp(buffer, "Damian>>>d6") == 0)
        {
            strcat(send, d6());
        }
        else if(strcmp(buffer, "Damian>>>d8") == 0)
        {
            strcat(send, d8());
        }
        else if(strcmp(buffer, "Damian>>>d12") == 0)
        {
            strcat(send, d12());
        }
        else if(strcmp(buffer, "Damian>>>d20") == 0)
        {
            strcat(send, d20());
        }
        else if(strcmp(buffer, "Damian>>>d100") == 0)
        {
            strcat(send, d100());
        }
        else if(strcmp(buffer, "Damian>>>letter") == 0)
        {
            strcat(send, letter());
        }
        else if(strcmp(buffer, "Damian>>>card") == 0)
        {
            strcat(send, card());
        }
        else if(strstr(buffer, "Damian>>>rng>>>") != 0)
        {
            for(int i = strlen("Damian>>>rng>>>"); buffer[i] != '\0'; i++)
            {
                temp[j++] = buffer[i];
            }
            j = 0;
            strcat(send, rng(atoi(temp)));
            memset(temp, 0, strlen(temp));
        }
        else if(strstr(buffer, "Damian>>>deck>>>") != 0)
        {
            for(int i = strlen("Damian>>>deck>>>"); buffer[i] != '\0'; i++)
            {
                temp[j++] = buffer[i];
            }
            j = 0;
            strcat(send, deck(atoi(temp)));
            memset(temp, 0, strlen(temp));
        }
        else if(strstr(buffer, "Damian>>>magic8ball>>>") != 0)
        {
            for(int i = strlen("Damian>>>magic8ball>>>"); buffer[i] != '\0'; i++)
            {
                temp[j++] = buffer[i];
            }
            j = 0;
            strcat(send, magic8ball(temp));
            memset(temp, 0, strlen(temp));
        }
        else
        {
            strcat(send, "That command does not exist!");
        }
        //strcat(send, deck(4)); //coinflip(), rng(50), d4(), d6(), d8(), d12(), d20(), d100(), letter(), magic8ball("?"), card(), deck(4)
        zmq_send(pusher, send, BUF_SIZE, 0);
        printf("Done!\n");
        memset(send, 0, strlen(send));
        memset(recv, 0, strlen(recv));
        strcpy(send, "Damian<<<");
        strcpy(recv, "Damian>>>");
        printf("Ready for new request\n");
        //zmq_recv(subscriber, buffer, BUF_SIZE, 0);
        //printf("%s\n", buffer);
    }

    printf("Stopping server\n");
    zmq_close(pusher);
    zmq_close(subscriber);
    zmq_ctx_shutdown(context);
    zmq_ctx_term(context);
    return 0;
}

void srandStart()
{
    srand(time(NULL));
}

char* coinflip()
{
    char* scoinflip = (char*)malloc(sizeof(char) * 5);
    if(rand() % 2 == 0)
        scoinflip = "heads";
    else
        scoinflip = "tails";
    return scoinflip;
}

char* rng(unsigned int i)
{
    char* srng = (char*)malloc(sizeof(int));
    itoa(rand() % (i + 1), srng, 10);
    return srng;
}

char* d4()
{
    char* sd4 = (char*)malloc(sizeof(int));
    itoa(rand() % 4 + 1, sd4, 10);
    return sd4;
}

char* d6()
{
    char* sd6 = (char*)malloc(sizeof(int));
    itoa(rand() % 6 + 1, sd6, 10);
    return sd6;
}

char* d8()
{
    char* sd8 = (char*)malloc(sizeof(int));
    itoa(rand() % 8 + 1, sd8, 10);
    return sd8;
}

char* d12()
{
    char* sd12 = (char*)malloc(sizeof(int));
    itoa(rand() % 12 + 1, sd12, 10);
    return sd12;
}

char* d20()
{
    char* sd20 = (char*)malloc(sizeof(int));
    itoa(rand() % 20 + 1, sd20, 10);
    return sd20;
}

char* d100()
{
    char* sd100 = (char*)malloc(sizeof(int));
    itoa(rand() % 100 + 1, sd100, 10);
    return sd100;
}

char* letter()
{
    char* sletter = (char*)malloc(sizeof(char));
    sprintf(sletter, "%c", rand() % 26 + 97);
    return sletter;
}

/*char* wheelspin(char* list)   // WIP
{
    int words = 1;
    int jlist = 0;
    int j = 0;
    for(int i = 0; list[i] != '\0'; i++)
    {
        if(list[i] == ',' && list[i + 1] != '\0')
        {
            words++;
        }
    }
    char* wheel[words];

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

    return wheel[rand() % words];
}*/

char* magic8ball(char* question)
{
    char* responses[20] = {"It is Certain.", "It is decidedly so.", "Without a doubt.", "Yes definitely.", "You may rely on it.",
                           "As I see it, yes.", "Most likely.", "Outlook good.", "Yes.", "Signs point to yes.",
                           "Reply hazy, try again.", "Ask again later.", "Better not tell you now.", "Cannot predict now.", "Concentrate and ask again.",
                           "Don't count on it.", "My reply is no.", "My sources say no.", "Outlook not so good.", "Very doubtful."};
    for(int i = 0; i < (int) strlen(question); i++)
    {
        if(question[i] == '?')
            return (responses[rand() % 20]);
    }
    return "That is not a question";
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

    if(amount > 52)
        return "There are only 52 cards in a deck, enter a number less than or equal to 52";

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
}
