#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


struct ThreadArgs {

	const char * pstr;
	int number;
};

void * start_thread (void *args)
{

	ThreadArgs* pargs = (ThreadArgs*) args;

	printf ("%s %d\n", (const char *) pargs->pstr, pargs->number);

    usleep(30000000);

	return nullptr;
}

int main (void)
{
	pthread_t thing1, thing2;

	const char *message1 = "thing 1";
	const char *message2 = "thing 2";

	int x1 = 8;
	int x2 = 28;

	ThreadArgs arg1{message1, x1};
	ThreadArgs arg2{message2, x2};



	pthread_create (&thing1, NULL, start_thread, (void *) &arg1);
	pthread_create (&thing2, NULL, start_thread, (void *) &arg2);

	
	pthread_join (thing1, NULL);
	pthread_join (thing2, NULL);

    printf("%s\n", "join threads");

	return 0;
}