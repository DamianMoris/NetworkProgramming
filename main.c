#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zmq.h>
#include "service.h"

#define BUF_SIZE 113

void * context; //Global context, because you only need one !

int main()
{
    printf("Start\n");
    srandStart();
    char prefix[BUF_SIZE] = "Damian>>>";
    char buffer[BUF_SIZE];
    void * context = zmq_ctx_new();
    void * pusher = zmq_socket(context, ZMQ_PUSH);
    void * subscriber = zmq_socket(context, ZMQ_SUB);
    zmq_connect(pusher, "tcp://benternet.pxl-ea-ict.be:24041");
    zmq_connect(subscriber, "tcp://benternet.pxl-ea-ict.be:24042");

    //ALL MAGIC HAPPENS HERE

    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, prefix, strlen(prefix));
    strcat(prefix, rng(100)); //coinflip(), rng(50), d4(), d6(), d8(), d12(), d20(), d100(), letter(), magic8ball("?"), card(), deck(4)
    zmq_send(pusher, prefix, BUF_SIZE, 0);
    printf("waiting...\n");
    zmq_recv(subscriber, buffer, BUF_SIZE, 0);
    printf("%s\n", buffer);

    printf("Stop\n");
    zmq_close(pusher);
    zmq_ctx_shutdown(context);
    zmq_ctx_term(context);
    return 0;
}
