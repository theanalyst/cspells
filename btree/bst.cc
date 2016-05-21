#include <iostream>

template <typename T> struct Node{
    T data;
    Node * left;
    Node * right;
    void Print();
};

// write me
template <typename T>
void Node<T>::Print(){
}

template <typename T>
Node<T> * insert(Node<T> * root,T value){
    if (root == nullptr){
	root = new Node<T>;
	root->data = value;
	root->left = nullptr;
	root->right = nullptr;
    } else {
	if (value < root->data){
	    root->left = insert(root->left, value);
	} else {
	    root->right = insert(root->right, value);
	}
    }
    return root;
}


int main(int argc, char *argv[])
{
    Node <int> * N;
    insert(N,5);
    insert(N,6);
    insert(N,2);
    insert(N,4);
    insert(N,7);
    insert(N,1);
    return 0;
}

