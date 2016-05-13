#include <iostream>
#include <cstring>

using namespace std;
template  <typename T>
void setbit(T &word, const int pos){
    word |= (1 << pos);
}

template <typename T>
bool checkbit(T &word, const int pos){
    return word & (1 << pos);
}

template <typename T>
void clearbit(T &word, const int pos){
    word &= ~(1 << pos);
}


bool unique(string s){
    short n;
    for (const auto &i: s){
	if (checkbit(n,int(i)))
	    return false;
	else
	    setbit(n,i);
    }
    return true;
}

int main(int argc, char **argv){
    string s;
    cin >> s;
    if (unique(s))
	cout<<"unique";
    else
	cout<<"not unique";
    return 0;
}
