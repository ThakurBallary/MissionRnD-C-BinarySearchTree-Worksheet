/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node *insert(struct node *root, int data) {
	if (!root) {
		return newNode(data);
	}
	else if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root;
}

void printBST(struct node *root){
	if (!root){
		return;
	}
	printf("%d ", root->data);
	printBST(root->left);
	printBST(root->right);
}

int main(){

	//Use it for testing ,Creating BST etc
	int arr[] = { 9, 4, 20, 1, 30 };
	int len = sizeof(arr) / sizeof(arr[0]);
	struct node *root = NULL;
	for (int i = 0; i < len; i++) {
		root = insert(root, arr[i]);
	}
	printBST(root);
	printf("\n");
	
	// BSTTransversals
	/*
	int *arr1 = (int *)malloc(sizeof(int) * len);
	inorder(root, arr1);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
	preorder(root, arr1);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
	postorder(root, arr1);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");
	*/

	// HeightofBST
	/*
	printf("%d\n", get_height(root));
	printf("%d\n", get_left_subtree_sum(root));
	printf("%d\n", get_right_subtree_sum(root));
	*/

	// BSTRows
	/*
	int *arr1 = (int *)malloc(sizeof(int) * len);
	arr1 = BSTRighttoLeftRows(root);
	for (int i = 0; i < len; i++) {
		printf("%d ", arr1[i]);
	}
	*/

	//FixBST
	/*
	int temp = ((root)->right)->data;
	((root)->right)->data = (((root)->left)->left)->data;
	(((root)->left)->left)->data = temp;
	printf("BST after misplaced\n");
	printBST(root);
	printf("\n");
	fix_bst(root);
	printf("BST after fix\n");
	printBST(root);
	printf("\n");
	*/
}
