#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

typedef struct ListType {
    ListNode* head;
    ListNode* tail;
    int size;
}ListType;

ListType* Create() {
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->head = NULL;
    plist->tail = NULL;
    plist->size = 0;
    return plist;
}

void SortedList(ListType* plist, element data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->link = NULL;

    if (plist->head == NULL) {
        plist->head = newNode;
        plist->tail = newNode;
    }
    else if (data <= plist->head->data) {
        // 맨 앞에 삽입
        newNode->link = plist->head;
        plist->head = newNode;
    }
    else {
        // 중간이나 끝에 삽입
        ListNode* prev = NULL;
        ListNode* curr = plist->head;
        while (curr != NULL && curr->data < data) {
            prev = curr;
            curr = curr->link;
        }
        newNode->link = curr;
        prev->link = newNode;
        if (curr == NULL) {
            // 맨 뒤 삽입이면 tail 갱신
            plist->tail = newNode;
        }
    }
    plist->size++;
}

void print(ListType* plist) {
    ListNode* Current = plist->head;

    while (Current != NULL) {
        printf("%d->", Current->data);
        Current = Current->link;
    }
    printf("NULL\n");
}

int main() {
    ListType* plist = Create();

    SortedList(plist, 6);
    SortedList(plist, 3);
    SortedList(plist, 7);
    SortedList(plist, 9);
    SortedList(plist, 2);
    SortedList(plist, 1);
    SortedList(plist, 8);
    SortedList(plist, 5);

    print(plist);
    free(plist);
    return 0;

}