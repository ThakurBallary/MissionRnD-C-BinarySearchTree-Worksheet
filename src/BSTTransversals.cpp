/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

int inorder_rec(struct node *root, int *arr, int i) {
	if (!root) {
		return i;
	}
	i = inorder_rec(root->left, arr, i);
	arr[i++] = root->data;
	i = inorder_rec(root->right, arr, i);
	return i;
}
void inorder(struct node *root, int *arr) {
	if (!root || !arr) {
		return;
	}
	int i = 0;
	i = inorder_rec(root, arr, i);
}

int preorder_rec(struct node *root, int *arr, int i) {
	if (!root) {
		return i;
	}
	arr[i++] = root->data;
	i = preorder_rec(root->left, arr, i);
	i = preorder_rec(root->right, arr, i);
	return i;
}
void preorder(struct node *root, int *arr){
	if (!root || !arr) {
		return;
	}
	int i = 0;
	i = preorder_rec(root, arr, i);
}

int postorder_rec(struct node *root, int *arr, int i) {
	if (!root) {
		return i;
	}
	i = postorder_rec(root->left, arr, i);
	i = postorder_rec(root->right, arr, i);
	arr[i++] = root->data;
	return i;
}
void postorder(struct node *root, int *arr){
	if (!root || !arr) {
		return;
	}
	int i = 0;
	i = postorder_rec(root, arr, i);
}

