#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, *right;
}TreeNode;

TreeNode n4 = { 1,NULL ,NULL };
TreeNode n5 = { 16,NULL ,NULL };
TreeNode n6 = { 25,NULL ,NULL };
TreeNode n3 = { 20,&n5, &n6 };
TreeNode n2 = { 4,&n4 ,NULL };
TreeNode n1 = { 15,&n2 ,&n3 };

TreeNode* root = &n1;

//������ȸ
void postOrder(TreeNode* root) {
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf("[%d] ", root->data);
	}
}

//������ȸ
void preOrder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

//������ȸ
void inOrder(TreeNode* root) {
	if (root != NULL) {
		inOrder(root->left);
		printf("[%d] ", root->data);
		inOrder(root->right);
	}
}


int main() {

	printf("������ȸ: ");
	preOrder(root);
	printf("\n");

	printf("������ȸ: ");
	inOrder(root);
	printf("\n");

	printf("������ȸ: ");
	postOrder(root);
	printf("\n");

	return 0;
}