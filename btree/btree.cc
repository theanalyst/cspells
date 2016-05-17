#include <iostream>
#include <queue>

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

void levelOrder(node *root) {
    if (root != nullptr){
	std::queue<node *> lq;
	lq.push(root);

	while (!lq.empty()){
	    cout << lq.front()->data << " ";
	    node *iter = lq.front();
	    lq.pop();
	    if (!iter->left){
		lq.push(iter->left);
	    }
	    if (!iter->right){
		lq.push(iter->right);
	    }
	}
    }
}

int height(node  *root){
    if (root == nullptr)
	return 0;

    return std::max(height(root->left)+1,height(root->right)+1);
}
