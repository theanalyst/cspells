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

Node * insertNth(Node *head, int data, int position){
    Node *newN = new Node;
    newN->data = data;
    if (position == 0){
	newN->next = head;
	return newN;
    } else {
	Node *iter = head;
	for (int i = 1; i < position; i++) {
	    iter=iter->next;
	}
	newN->next = iter->next;
	iter->next = newN;
    }
    return head;
}

Node * Delete(Node *head,int position){
    if (position == 0){
	return head->next;
    } else {
	Node *iter = head;
	for (int i = 1; i < position; i++) {
	    iter = iter->next;
	}
	Node *tmp = iter->next;
	iter->next = tmp->next;
	return head;
    }
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


Node * mergeLists(Node *head1, Node *head2){
    Node *newhead = head1->data > head2->data ? head2 : head1;
    Node *iter = newhead;
    Node *iter2 = head1->data > head2->data ? head1 : head2;

    while (iter || iter2){
	if (!iter->next){
	    iter->next = iter2;
	    break;
	} else if (iter->next->data > iter2->data){
	    std::swap(iter->next,iter2);
	}

	iter = iter->next;
    }
    return newhead;
}

int main(int argc, char *argv[])
{
    Node * list1;
    list1 = new Node;
    list1 = insert(NULL,2);
    list1 = insert_head(list1,3); // 3 -> 2
    list1 = insertNth(list1,9,0);
    list1 = insertNth(list1,8,1);
    list1 = insertNth(list1,7,4);
    Print(list1);
    cout << "Deleting at position 2" << endl;
    Delete(list1,2);
    Print(list1);

    Node *list2;
    list2 = new Node;
    list2 = insert (NULL, 8);
    list2 = insert_head(list2, 6);
    list2 = insert_head(list2, 4);
    list2 = insert_head(list2, 2);
    // list2 = insert(list2, 6);
    // list2 = insert(list2, 8);

    Node *list3;
    list3 = new Node;
    list3 = insert (NULL, 5);
    list3 = insert_head(list3, 3);
    list3 = insert_head(list3, 1);

    // Node *list3 = new Node;
    // list3 = insert(NULL,1);
    // list3 = insert(list3,3);
    // list3 = insert(list3,5);

    Node *listm  = new Node;
    listm = mergeLists(list2,list3);
    Print(listm);
    return 0;
}
