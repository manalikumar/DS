// Basic functionalities of binary search trees
#include <iostream>
#include <stack>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

// Function to insert new node in bst
void insert(node** rootRef, int n) {
	node* root = *rootRef;
	node* temp = new node();
	temp->data = n;
	temp->left = temp->right = NULL;
	if(root == NULL) {
		root = temp;
	}
	else if(root->data < n) {
		insert(&root->right, n);
	}
	else {
		insert(&root->left, n);
	}
	*rootRef = root;
}

void preOrder(node* root) {
	if(root == NULL)
		return;
	cout << root->data << "  ";
	preOrder(root->left);
	preOrder(root->right); 
}

void inorder(node* root) {
	if(root == NULL)
		return;
	inorder(root->left);
	cout << root->data << "  ";
	inorder(root->right);
}

void postOrder(node* root) {
	if(root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << "  ";

}

void levelOrder(node* root) {

}

void deleteNode(node** root) {

}

int main() {
	node* root = NULL;
	insert(&root, 10);
	insert(&root, 5);
	insert(&root, 24);

	cout << "Inorder traversal of bst: ";
	inorder(root);
	cout << endl << "Preorder traversal of bst: ";
	preOrder(root);
	cout << endl << "Postorder traversal of bst: ";
	postOrder(root);
	cout << endl;
	return 0;
}