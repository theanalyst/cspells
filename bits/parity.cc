#include <bitset>
#include <iostream>
#include <cstdint>
#include <cmath>

#define check_bit(n,pos) (n & (1<<pos))

using namespace std;
bool odd_parity(unsigned long n){
    std::bitset<64> bits (n);
    return bits.count()%2 != 0;
}

bool odd_parity2(unsigned long n){
    int count=0;
    for(int i=0;i<sizeof(n);i++){
	if(n & (1 << i)){
	    count++;
	}
	    
	
    }
	
    return count%2 != 0;
}

bool odd_parity3(unsigned long n){
    int parity;
    while(n){
	parity ^= 1;
	n=n & (n - 1);
    }
    return parity != 0;
}

int main(int argc, char *argv[])
{
    unsigned long n1(2),n2(10),n3(7);
    cout << odd_parity(n1) << endl;
    cout << odd_parity2(n1) << endl;
    cout << odd_parity3(n1) << endl;
    cout << odd_parity(n2) << endl;
    cout << odd_parity2(n2) << endl;
    cout << odd_parity3(n2) << endl;
    cout << odd_parity(n3) << endl;
    cout << odd_parity2(n3) << endl;
    cout << odd_parity3(n3) << endl;
    return 0;
}
