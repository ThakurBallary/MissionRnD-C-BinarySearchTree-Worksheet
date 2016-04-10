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

void get_misplaced_node(struct node *root, struct node **prev, struct node **misplaced1, struct node **misplaced2, struct node **misplacedRoot) {
	if (!root) {
		return;
	}
	get_misplaced_node(root->left, prev, misplaced1, misplaced2, misplacedRoot);
	if (*prev != NULL) {
		if ((*prev)->data > root->data) {
			if (*misplaced1 == NULL) {
				*misplaced1 = *prev;
				*misplacedRoot = root;
			}
			else {
				*misplaced2 = root;
				return;
			}
		}
	}
	*prev = root;
	get_misplaced_node(root->right, prev, misplaced1, misplaced2, misplacedRoot);

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
	
	struct node *misplaced1 = NULL;
	struct node *misplaced2 = NULL;
	struct node *mispalcedRoot = NULL;
	struct node *prev = NULL;
	get_misplaced_node(root, &prev, &misplaced1, &misplaced2, &mispalcedRoot);
	if (misplaced2) {
		swap(misplaced1, misplaced2);
	}
	else {
		swap(misplaced1, mispalcedRoot);
	}
}