#include <iostream>

template  <typename T>{
    void setbit(T &word, short pos){
	word |= (1 << pos);
    }
    bool checkbit(T &word, short pos){
	return word & (1 << pos);
    }
    void clearbit(T &word, short pos){
	word ^= (word << pos);
    }
}

void main(){
    int a = 4; short  pos= 2;

    cout << checkbit(4,1) ;
    
}
