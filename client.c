#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <zmq.h>

#define BUF_SIZE 200

void * context;

int main()
{
    printf("Starting Client\n");
    char send[BUF_SIZE + 9] = "Damian>>>";
    char recv[BUF_SIZE + 9] = "Damian<<<";
    char buffer[BUF_SIZE];
    char func[BUF_SIZE];
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
        printf("Ready\n");
    }

    for(int i = 0; i < 200; i++)
    {
        printf("What function do you want to use?\n");
        scanf("%s", func);
        strcat(send, func);

        zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, recv, strlen(recv));
        //strcat(prefix, deck(4)); //coinflip(), rng(50), d4(), d6(), d8(), d12(), d20(), d100(), letter(), magic8ball("?"), card(), deck(4)
        zmq_send(pusher, send, BUF_SIZE, 0);
        zmq_recv(subscriber, buffer, BUF_SIZE, 0);
        printf("%s\n", buffer);
        memset(buffer, 0, strlen(buffer));
        memset(send, 0, strlen(send));
        memset(recv, 0, strlen(recv));
        strcpy(send, "Damian>>>");
        strcpy(recv, "Damian<<<");
    }

    printf("Stopping client\n");
    zmq_close(pusher);
    zmq_close(subscriber);
    zmq_ctx_shutdown(context);
    zmq_ctx_term(context);
    return 0;
}
