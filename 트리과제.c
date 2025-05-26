#define _CRT_SECURE_NO_WARNINGS
#define min(x, y) (x) < (y) ? (x) : (y)
#define max(a, b) (a) > (b) ? (a) : (b)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, *right;
}TreeNode;

int TreeSum(TreeNode* root) {
	int sum = 0;
	if (root == NULL) return 0;
	sum = root->data + TreeSum(root->left) + TreeSum(root->right);
	return sum;
}

int SubTreeSum(TreeNode* root) {
	int total = 0;
	if (root == NULL) return 0;
	int leftSum = SubTreeSum(root->left);
	int rightSum = SubTreeSum(root->right);
	total = root->data + leftSum + rightSum;
	printf("%d�� ���� ����Ʈ����� ����: %d\n", root->data, total);
	return total;
}

void find(TreeNode* root,int n) {
	if (root == NULL) return;
	
	find(root->left,n);
	if (root->data > n) {
		printf("%d���� ū ���: %d\n", n, root->data);
	}
	find(root->right, n);
}

int Min(TreeNode* root) {
	int �ּ� = 10000;
	if (root == NULL) return �ּ�;
	int ismin = min(root->data, min(Min(root->left), Min(root->right)));
	return ismin;
}

int Max(TreeNode* root) {
	int �ִ� = 0;
	if (root == NULL) return �ִ�;
	int ismax = max(root->data, max(Max(root->left), Max(root->right)));
	return ismax;
}

int �ڽ�(TreeNode* root) {
	int count = 0;
	if (root == NULL) return 0;
	if (root->left != NULL && root->right != NULL) {
		count = 1 + �ڽ�(root->left) + �ڽ�(root->right);
		printf("���: %d\n", root->data);
	}
	return count;
}

/*int �ڽ�2(TreeNode* root) {
	int count = 0;
	if (root == NULL) return 0;
	if (root->left != NULL && root->right != NULL) {
		count += 1;
		�ڽ�(root->left);
		�ڽ�(root->right);
		printf("���: %d\n", root->data);
	}
	return count;
}*/

int main() {
	TreeNode n6 = {9,NULL,NULL};
	TreeNode n5 = {4,NULL,NULL};
	TreeNode n4 = {1,NULL,NULL};
	TreeNode n3 = {5,&n5,&n6};
	TreeNode n2 = {2,&n4,NULL};
	TreeNode n1 = {3,&n2,&n3};

	int sum;
	printf("��� ��� ���� ����: %d\n", TreeSum(&n1));
	printf("���� �Է��Ͻÿ�: ");
	int n;
	scanf("%d", &n);
	find(&n1, n);
	printf("�ּҰ�: %d\n", Min(&n1));
	printf("�ִ밪: %d\n", Max(&n1));
	printf("%d��\n", �ڽ�(&n1));
	//printf("%d��\n", �ڽ�2(&n1));
	printf(SubTreeSum(&n1));

}