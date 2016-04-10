/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \ 
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
	    / \
	   4   1
	  /     \
	 20      30
Nodes 1 and 20 need to be fixed here .

*/
// Two nodes in the BST's swapped, correct the BST.
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node * get_misplaced_node(struct node *root, struct node *misplaced) {
	if (!root) {
		return NULL;
	}
	if (root->left != NULL) {
		if (root->data < root->left->data && root->left != misplaced) {
			return root->left;
		}
	}
	if (root->right != NULL) {
		if (root->data > root->right->data && root->right != misplaced) {
			return root->right;
		}
	}
	
	struct node *misplacedLeft = get_misplaced_node(root->left, misplaced);
	if (misplacedLeft) {
		return misplacedLeft;
	}
	else {
		return get_misplaced_node(root->right, misplaced);
	}	
}

void swap(struct node *a, struct node *b) {
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void fix_bst(struct node *root){
	if (!root) {
		return;
	}
	struct node *misplaced1 = get_misplaced_node(root, NULL);
	struct node *misplaced2 = get_misplaced_node(root, misplaced1);
	swap(misplaced1, misplaced2);
}