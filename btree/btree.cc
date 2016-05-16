#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *right;
    Node *left;
}

// Printing nodes in a pre-order traversal
void PreOrder(Node *root){
    if (root != nullptr){
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
    }
}

void PostOrder(Node *root){
    if (root != nullptr){
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
    }
}

void inOrder(node *root) {
    if(root != nullptr){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
