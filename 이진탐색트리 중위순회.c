#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
    bool is_thread;
}TreeNode;

TreeNode n7 = { 27, NULL , NULL,true };
TreeNode n6 = { 31, &n7, NULL,false };
TreeNode n5 = { 12, NULL, NULL,true };
TreeNode n4 = { 3, NULL, NULL,true };
TreeNode n3 = { 26, NULL, &n6,false };
TreeNode n2 = { 7, &n4, &n5,false };
TreeNode n1 = { 18, &n2, &n3,false };
TreeNode* root = &n1;

TreeNode* find_successor(TreeNode* Current) {
    TreeNode* next = Current->right;

    if (next == NULL || Current->is_thread == true) {  //next�� NULL�̰ų� ���� �ִ� ��ġ�� ������ ����̸�
        return next;
    }
    else {                                           //next�� ������ �ڽ��̸� �� next���� ���� ������ �������� �Ѵ�.
        while (next->left != NULL) next = next->left;
        return next;
    }
}

void thread_inorder(TreeNode* root) {
    TreeNode* q;
    q = root;
    while (q->left) q = q->left;
    do {
        printf("%d->", q->data);
        q = find_successor(q);
    } while (q);

}

TreeNode* new_Node(TreeNode* root, int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert_node(TreeNode* root, int data) {
    if (root == NULL) return new_Node(root, data);

    if (data < root->data)
        root->left = insert_node(root->left, data);
    else if (data > root->data)
        root->right = insert_node(root->right, data);

    return root;
}

TreeNode* min_value_node(TreeNode* root) {
    TreeNode* Current = root;

    while (Current != NULL) {
        Current = Current->left;
    }
    return Current;
}

int find(TreeNode* root, int data) {
    int count = 1;
    while (root != NULL) {
        if (root->data > data) {
            count += 1;
            root = root->left;
        }
        else if (root->data == data) {
            return count;
        }
        else {
            count += 1;
            root = root->right;
        }
    }
    return 0; //��ã�� ���.
}

TreeNode* delete_node(TreeNode* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = delete_node(root->left, data);
    }
    else if (data > root->data) {
        root->right = delete_node(root->right, data);
    }
    else { //data�� ã���� ��
        if (root->left == NULL) { //�ܸ� ���ų� ����Ʈ���� ���ʿ� �ϳ��� ���� ��
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) { //�ܸ� ���ų� ����Ʈ���� �����ʿ� �ϳ��� ���� ��
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = min_value_node(root->right); //�� ���� ������ ����Ʈ������ ���� ���� ��带 ã�ų� ���� ����Ʈ������ ���� ū ��带 ã�°ǵ� ����� ����.
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d->", root->data);
        inorder(root->right);
    }
}


int main(void) {
    /*n4.right = &n2;
    n5.right = &n1;
    n7.right = &n6;*/

    TreeNode* root = NULL;
    root = insert_node(root, 18);
    root = insert_node(root, 7);
    root = insert_node(root, 26);
    root = insert_node(root, 3);
    root = insert_node(root, 31);
    root = insert_node(root, 27);


    //thread_inorder(root);
    printf("%d�� ���� ã�ҽ��ϴ�.\n", find(root, 31));
    printf("������ȸ���\n");
    inorder(root);
    printf("\n");
    insert_node(root, 19);
    printf("������ȸ���\n");
    inorder(root);
    printf("\n");
    delete_node(root, 31);
    printf("������ȸ���\n");
    inorder(root);
    printf("\n");

    printf("\n");
    return 0;
}