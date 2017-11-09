#include<iostream>	//cout,endl
#include<unistd.h>	//sleep()
#include<thread>	//thread

//スレッドで行う処理
void output( const std::string &text ){

    int counterStop = text.size();

    //1文字ずつ表示する毎に１秒停止
    for( int i = 0; i < counterStop; i++ ){
        std::cout << text[i] << std::endl;
        sleep( 1 );
    }
}

int main( int argc, char *argv[] ){

    if( argc == 2 ){
        //文字数と値をスレッドに投げて、処理が終了するまで待機
        std::thread th( output, argv[1] );
        th.join();
    } else {
        //コマンドライン引数が未入力か2つ以上入力された場合は
        //コマンドライン引数の入力が正しくない旨を出力する。
        std::cout << "incorrect command-line argument" << std::endl;
    }
    return 0;
}
