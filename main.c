//#include <stdio.h>
//#include <string.h>
//#include <zmq.h>
//
//void * context; //Global context, because you only need one !
//
//int main( int argc, char * argv[] )
//{
//    printf("Start\n");
//    void * context = zmq_ctx_new();
//
//    void * pusher = zmq_socket(context, ZMQ_PUSH);
//    void * subscriber = zmq_socket(context, ZMQ_SUB);
//
//    zmq_connect(pusher, "tcp://benternet.pxl-ea-ict.be:24041");
//    zmq_connect(subscriber, "tcp://benternet.pxl-ea-ict.be:24042");
//
//    //zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "example>task? >", strlen("example>task? >"));
//
//    for(int request_nbr = 0; request_nbr != 1; request_nbr++)
//    {
//        char buffer[10];
//        zmq_send(pusher, "Worp", 4, 0);
//        zmq_recv(pusher, buffer, 10, 0);
//    }
//
//    //zmq_send(pusher, "Damian Moris", 12, 0);
//
//	//ALL MAGIC HAPPENS HERE
//	printf("Magic!\n");
//
//    zmq_close(pusher);
//    zmq_ctx_shutdown(context); //optional for cleaning lady order (get ready you l*zy f*ck)
//    zmq_ctx_term(context); //cleaning lady goes to work
//	printf("KTNXBYE!\n");
//	return 0;
//}
