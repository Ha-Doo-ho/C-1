#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
    int data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, int data){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;

    if(head == NULL){
        head = newNode;
        newNode->link = head;
    }
    else{
        newNode->link = head->link;
        head->link = newNode;
    }
    return head;
}

ListNode* insert_last(ListNode* head, int data){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;

    if(head == NULL){
        head = newNode;
        newNode->link = head;
    }
    else{
        newNode->link = head->link;
        head->link = newNode;
        head = newNode;
    }
    return head;
}

void print(ListNode* head){
    ListNode* Current = head->link;
    do{
        printf("%d->",Current->data);
        Current = Current->link;
    }while(Current != head->link);
}

void free_List(ListNode* head){
    if(head == NULL) return;
    ListNode* Current = head->link;
    while(Current != head){
        
    }
}

int main() {
     ListNode* head = NULL;

    head = insert_first(head, 1);
    head = insert_last(head, 5);
    head = insert_last(head, 8);
    head = insert_first(head, 2);
    head = insert_last(head, 3);

    print(head);
    return 0;
}
