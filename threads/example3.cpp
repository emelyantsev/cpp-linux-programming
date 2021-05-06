#include <pthread.h>
#include <iostream>
#include <unistd.h>

#define NUM_THREADS 30
#define NUM_STEPS 100000


int count = 0;
pthread_mutex_t mtx;

class ScopedMutex {

    public:

        ScopedMutex (pthread_mutex_t& mutex) : mutex_ (mutex) {
            
            pthread_mutex_lock (&mutex_);
        }

        ~ScopedMutex () {

            pthread_mutex_unlock (&mutex_);
        }
private:

    pthread_mutex_t& mutex_;
} ;


void* thread_proc(void* args) 
{

    for (int i = 0; i < NUM_STEPS; ++i) {

        {
            ScopedMutex scpmtx(mtx) ;
            ++count;
        }
	
        usleep(1);
    }

	return nullptr;
}


int main() {


    pthread_t threads[NUM_THREADS] ;


    for (int i = 0; i < NUM_THREADS ; ++i) {

        pthread_create (&threads[i], NULL, thread_proc, NULL );
    }


    for (int i = 0; i < NUM_THREADS ; ++i) {

        pthread_join (threads[i], NULL);;
    }

    printf("Count = %d\n", count);

    return 0;
}