#include<iostream>	//input,output
#include<thread>	//thread
#include<mutex>		//mutex

//排他制御用
std::mutex oddNumberMtx;
std::mutex evenNumberMtx;

//奇数を出力する関数
void oddNumberOutput( void ){

    for( int i = 1; i < 10; i+=2 ){
        //値を出力して自スレッドにロックをかける
        //偶数を出力するスレッドのロックを解除する
        oddNumberMtx.lock();
        std::cout << i << std::endl;
        evenNumberMtx.unlock();
    }
}

//偶数を出力する関数
void evenNumberOutput( void ){

    for( int i = 2; i <= 10; i+=2 ){
        //値を出力して自スレッドにロックをかける
        //奇数を出力するスレッドのロックを解除する
        evenNumberMtx.lock();
        std::cout << i << std::endl;
        oddNumberMtx.unlock();
    }
}

int main( int argc, char *argv[] ){

    //スレッドの生成
    std::thread oddNumberThread( oddNumberOutput );
    std::thread evenNumberThread( evenNumberOutput );

    //スレッドの終了待ち
    oddNumberThread.join();
    evenNumberThread.join();

    return 0;
}
