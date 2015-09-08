#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

// Insert a Node at the tail of a LL
// and return a ptr to head
Node * insert(Node *head, int data){
    Node *tail = new Node;
    tail->data = data;
    tail->next = NULL;

    if (head==NULL){
	head = tail;
    } else {
	Node *iter = new Node;
	iter = head->next;
	while (iter != NULL){
	    iter = iter->next;
	}
	iter->next = tail; // we've reached the end 
    }
    
    return head;
}

Node * insert_head(Node *head, int data){
    Node *newN = new Node;
    newN->data = data;
    newN->next = head;

    return newN;
}

void Print(Node *head){
    Node *iter = new Node;
    iter = head;
    while (iter != NULL){
	cout << iter->data << "->" ;
	iter = iter->next;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    Node * list1;
    list1 = new Node;
    list1 = insert(NULL,2);
    list1 = insert_head(list1,3); // 3 -> 2
    Print(list1);
    return 0;
}