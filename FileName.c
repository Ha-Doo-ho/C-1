#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef int element;
typedef struct ListNode {
    int data;
    struct ListNode* link;
}ListNode;

typedef struct ListType {
    ListNode* head;
    ListNode* tail;
    int size;
}ListType;

ListType* create() {
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->head = NULL;
    plist->tail = NULL;
    plist->size = 0;
    return plist;
}

void insert_last(ListType* plist, element value) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = value;
    node->link = NULL;
    if (plist->head == NULL) {
        plist->head = node;
        plist->tail = node;
    }
    else {
        plist->tail->link = node;
        plist->tail = node;
    }
    plist->size++;
}

void alternate_merge(ListType* plist1, ListType* plist2, ListType* plist3) {
    ListNode* p1 = plist1->head;
    ListNode* p2 = plist2->head;
    ListNode* p3 = plist3->head;

    while (plist1->size > 0 && plist2->size > 0) {
        if (plist1->size > 0) {
            insert_last(plist3, p1->data);
            p1 = p1->link;
            plist1->size--;
        }
        if (plist2->size > 0) {
            insert_last(plist3, p2->data);
            p2 = p2->link;
            plist2->size--;
        }
    }
    if (plist1->size > 0) {
        insert_last(plist3, p1->data);
        p1 = p1->link;
        plist1->size--;
    }
    if (plist2->size > 0) {
        insert_last(plist3, p2->data);
        p2 = p2->link;
        plist2->size--;
    }
    free(p1);
    free(p2);
}

void print_list(ListType* plist) {
    ListNode* Current = plist->head;
    while (Current != NULL) {
        printf("%d ->", Current->data);
        Current = Current->link;
    }
    printf("NULL\n");
}

void delete_odd(ListType* plist) {
	ListNode* Current = plist->head;
    ListNode* prev = NULL;
    int count = 1;
    while (Current != NULL) {
        if (plist->head == NULL) {
            printf("List is empty\n");
        }
        if (count % 2 == 1) {
            if (prev == NULL) {
                plist->head = Current->link;
                free(Current);
                Current = plist->head;
            }
            else {
                prev->link = Current->link;
                free(Current);
                Current = prev->link;
            }
        }
        else {
             prev = Current;
             Current = Current->link;
        }
        count++;
    }
}

int main() {
    ListType* list1 = create();
    ListType* list2 = create();
    ListType* list3 = create();

    insert_last(list1, 1);
    insert_last(list1, 3);
    insert_last(list1, 5);

    insert_last(list2, 2);
    insert_last(list2, 4);
    insert_last(list2, 6);

    alternate_merge(list1, list2, list3);

    delete_odd(list3);
    print_list(list3);

    free(list1);
    free(list2);
    free(list3);

    return 0;
}