#include<iostream>

void reference( int &number ){

    number = 100;

}

int main( int argc, char *argv[] ){

    int number = 0;

    reference( number );

    std::cout << number << std::endl;

    return 0;

}
