#include<iostream>
#include<thread>
#include<semaphore.h>

void testThread( int &i ){
    std::cout << i << std::endl;
}

int main( int argc, char *argv[] ){
    sem_t sem;
    sem_init( &sem, 1, 0 );

    int i = 100;

    std::thread th( testThread, std::ref( i ) );
    th.join();

    return 0;
}
