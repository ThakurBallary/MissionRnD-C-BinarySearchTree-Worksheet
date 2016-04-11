/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

struct node * get_parent_node(struct node *root, struct node *child, int *isLeftChild) {
	if (!root) {
		return NULL;
	}
	if (root->left == child) {
		*isLeftChild = 1;
		return root;
	}
	if (root->right == child) {
		return root;
	}
	struct node *left = get_parent_node(root->left, child, isLeftChild);
	if (left) {
		return left;
	}
	return get_parent_node(root->right, child, isLeftChild);
}

int get_min_distance(struct node *root) {
	if (!root->left && !root->right) {
		return 0;
	}
	if (root->left && root->right) {
		int leftDistance = get_min_distance(root->left);
		int rightDistance = get_min_distance(root->right);
		if (leftDistance < rightDistance) {
			return leftDistance + 1;
		}
		return rightDistance + 1;
	}
	if (root->left) {
		return get_min_distance(root->left) + 1;
	}
	if (root->right) {
		return get_min_distance(root->right) + 1;
	}
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (!root || !temp) {
		return -1;
	}
	if (root == temp) {
		return get_min_distance(root);
	}
	int isLeftChild = 0;
	struct node * parent_node = get_parent_node(root, temp, &isLeftChild);
	int childDistance = get_min_distance(temp);
	int parentDistance = 1;
	if (isLeftChild) {
		parentDistance += get_min_distance(parent_node->right);
	}
	else {
		parentDistance += get_min_distance(parent_node->left);
	}
	if (childDistance <= parentDistance) {
		return childDistance;
	}
	return parentDistance + 1;
}