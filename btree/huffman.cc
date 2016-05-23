#include <iostream>
#include <string>

using namespace std;

struct node
{
    int freq;
    char data;
    node * left;
    node * right;


    node(int f, char c) : freq(f), data(c), left(nullptr), right(nullptr){};
    node(int f, node *left, node *right) : freq(f), data('\0'), left(left), right(right) {};
    node(int f, char c, node *left, node * right) : freq(f), data(c), left(left), right(right) {};
};

string decode_huff(node * root,string s)
{
    string out;
    node * iter = root;
    for (auto const &i:s){
	iter = i == '0' ? iter->left : iter->right;
	if (iter->data){
	    out += iter->data;
	    iter = root;
	}
    }
    return out;
}

int main(int argc, char *argv[])
{
    node A = node(3, 'A');
    node B = node(1, 'B');
    node C = node(1, 'C');

    node left = node(2, &B, &C);
    node top = node(5, &left, &A);

    cout << decode_huff(&top,"1001011");
    return 0;
}
