#include<iostream>
#include<pthread.h>
#include<thread>
#include<unistd.h>
#include<semaphore.h>

void method( sem_t sem ){
    sem_wait( &sem );
    sem_post( &sem );
}

int main( int argc, char *argv[] ){

    sem_t sem;
    sem_init( &sem, 0, 1 );

    std::thread th( method, sem );

    sem_wait( &sem );

    th.join();

    return 0;
}
