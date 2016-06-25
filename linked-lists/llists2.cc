#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct node{
    T data;
    std::shared_ptr<node<T> > next;
    node(T d): data(d),next(nullptr) {};
};

template <typename T>
void printlist(const std::shared_ptr <node <T> > &n){
    auto it = n;
    while(it){
	cout << it->data << "->";
	it = it->next;
    }
    cout << "null" << endl;
}

template <typename T>
void insert_head(std::shared_ptr <node<T> > &n, T d){
    if (n == nullptr){
	n.reset(new node<T> (d));
    } else {
	auto new_head = std::make_shared <node <T>>(d);
	new_head->next = n;
    	n = std::move(new_head);
    }
}

int main(int argc, char *argv[])
{
    std::shared_ptr<node <int>> N;
    insert_head(N,2);
    insert_head(N,1);
    printlist(N);
    return 0;
}
