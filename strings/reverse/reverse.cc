#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

template <typename T>
void swap1(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void reverse1(char *s){
    char *tail = s;
    if(s){
    	while(*tail)
    	    ++tail;
    	--tail;

    	while (s < tail){
	    std::swap(*s++,*tail--);
	}
    }
}

void reverse2(string& s){
    int len = s.size();
    for (int i=0;i<len/2;i++)
	std::swap(s[i],s[len-i-1]);
}

int main(int argc, char *argv[])
{
    char s[] ="foobar";
    string s2("foobar");
    std::cout << s << std::endl;
    reverse1(s);
    std::cout << s << std::endl;

    std::cout << s2 << std::endl;
    reverse2(s2);
    std::cout << s2 << std::endl;

    return 0;
}
