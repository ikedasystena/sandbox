//Git練習用ソース
<<<<<<< HEAD
//コメント追加
=======
>>>>>>> work

#include<iostream>	//input,output
#include<thread>	//thread
#include<semaphore.h>	//semaphore

//値を出力する関数
void NumberOutput( int number, sem_t &ownNumberSem, sem_t &otherNumberSem ){

    for( int i = number; i <= 10; i+=2 ){
        sem_wait( &ownNumberSem );
        std::cout << i << std::endl;
        sem_post( &otherNumberSem );
    }
}

int main( int argc, char *argv[] ){

    //セマフォの作成
    sem_t oddNumberSem;
    sem_t evenNumberSem;
    //セマフォの初期化
    sem_init( &oddNumberSem, 0, 1 );
    sem_init( &evenNumberSem, 0, 0 );

    //スレッドの生成
    std::thread oddNumberThread( NumberOutput, 1, std::ref( oddNumberSem ), std::ref( evenNumberSem ) );
    std::thread evenNumberThread( NumberOutput, 2, std::ref( evenNumberSem ), std::ref( oddNumberSem ) );

    //スレッドの終了待ち
    oddNumberThread.join();
    evenNumberThread.join();

    return 0;
}
