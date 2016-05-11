#include <iostream>
#include <set>
using namespace std;

bool unique(string s){
    std::set <char> char_set;
    for (const auto &i: s){
	auto status = char_set.insert(i);
	if (!status.second)
	    return false;
    }
    return true;
}
int main(int argc, char *argv[])
{
    string s;
    
    if (unique(argv[1]))
	cout << "unique";
    else
	cout << "not unique";
    return 0;
}
