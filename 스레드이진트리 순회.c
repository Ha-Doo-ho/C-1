#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode{
    int data;
    struct TreeNode* left,*right;
    bool is_thread;
}TreeNode;

TreeNode n10 = {10,NULL,NULL,true};
TreeNode n9 = {9,&n10,NULL,true};
TreeNode n8 = {8,&n9,NULL,true};
TreeNode n7 = {7,NULL,NULL,false};
TreeNode n6 = {6,&n8,NULL,true};
TreeNode n5 = {5,NULL,NULL,true};
TreeNode n4 = {4,NULL,NULL,true};
TreeNode n3 = {3,&n6,&n7,false};
TreeNode n2 = {2,&n4,&n5,false};
TreeNode n1 = {1,&n2,&n3,false};

TreeNode* root = &n1;

TreeNode* find_successor(TreeNode* root){
    TreeNode* next = root->right;

    if(next == NULL || root->is_thread == true){
        return next;
    }
    else{
        while(next->left != NULL){
            next = next->left;
        }
        return next;
    }
}

void inorder(TreeNode* root){
    while(root->left != NULL){
        root = root->left;
    }

    do{
        printf("%d->",root->data);
        root = find_successor(root);
    }while(root != NULL);
    
}

int main() {
   n4.right = &n2;
   n5.right = &n1;
   n6.right = &n3;
   n8.right = &n6;
   n9.right = &n8;
   n10.right = &n9; 

  inorder(root);
  return 0;
}
