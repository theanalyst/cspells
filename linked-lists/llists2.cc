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

template <typename T>
void evenodd(std::shared_ptr <node <T>> &n){
    auto iter = n;
    if (n->next == nullptr)
	return;
    auto odd_head = n->next;
    auto odd_iter = odd_head;
    while (iter->next->next != nullptr){
	iter->next = iter->next->next;
	if (odd_iter->next->next == nullptr){
	    iter = iter->next;
	    odd_iter->next = nullptr;
	    break;
	}
	odd_iter->next = odd_iter->next->next;
	iter = iter->next;
	odd_iter = odd_iter->next;
    }
    cout << endl;
    iter->next = odd_head;
}

int main(int argc, char *argv[])
{
    std::shared_ptr<node <int>> N;
    insert_head(N,2);
    insert_head(N,1);
    insert_head(N,0);
    insert_head(N,10);
    insert_head(N,20);
    insert_head(N,30);
    insert_head(N,42);
    printlist(N);
    evenodd(N);
    printlist(N);
    return 0;
}
