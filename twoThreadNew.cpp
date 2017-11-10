#include<iostream>	//input,output
#include<thread>	//thread
#include<sys/sem.h>	//semaphore

//値を出力する関数
void NumberOutput( int number ){
    for( int i = number; i <= 10; i+=2 ){
        std::cout << i << std::endl;
    }
}

int main( int argc, char *argv[] ){

    int semId;
    union semun{
        int val;
        struct semidDs *startSetBuf;
        unsigned short array;
        struct semInfo *infoBuf;
    };

    semId = semget( IPC_PRIVATE, 2, IPC_CREAT );

    //スレッドの生成
    std::thread oddNumberThread( NumberOutput, 1 );
    std::thread evenNumberThread( NumberOutput, 2 );

    //スレッドの終了待ち
    oddNumberThread.join();
    evenNumberThread.join();

    return 0;
}
