#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ListNode{
	struct ListNode* link;
	int data;
}ListNode;

typedef struct {
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

void insert_last(ListType* plist, int data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->link = NULL;

	if (plist->tail == NULL) {
		plist->head = newNode;
		plist->tail = newNode;
	}
	else {
		plist->tail->link = newNode;
		plist->tail = newNode;
	}
	plist->size++;
}

void merge(ListType* plist1, ListType* plist2, ListType* plist3) {   //1과 2를 비교해서 3에 오름차순으로 넣는다.
	ListNode* Current1 = plist1->head;
	ListNode* Current2 = plist2->head;

	while (Current1 != NULL && Current2 != NULL) {
		if (Current1->data >= Current2->data) {
			insert_last(plist3, Current2->data);
			Current2 = Current2->link;
		}
		else {
			insert_last(plist3, Current1->data);
			Current1 = Current1->link;
		}
	}
	while (Current1 != NULL && Current2 == NULL) {
		insert_last(plist3, Current1->data);
		Current1 = Current1->link;
	}
	while (Current1 == NULL && Current2 != NULL) {
		insert_last(plist3, Current2->data);
		Current2 = Current2->link;
	}
}

void print(ListType* plist) {
	ListNode* Current = plist->head;
	while (Current != NULL) {
		printf("%d->", Current->data);
		Current = Current->link;
	}
	printf("NULL\n");
	printf("\n");
}

int main(void) {
	ListType* plist1 = Create();
	ListType* plist2 = Create();
	ListType* plist3 = Create();

	insert_last(plist1, 1);
	insert_last(plist1, 2);
	insert_last(plist1, 6);
	insert_last(plist1, 9);
	insert_last(plist1, 15);
	insert_last(plist1, 18);
	
	insert_last(plist2, 3);
	insert_last(plist2, 4);
	insert_last(plist2, 5);
	insert_last(plist2, 7);
	insert_last(plist2, 11);
	insert_last(plist2, 13);
	insert_last(plist2, 16);

	print(plist1);
	print(plist2);
	merge(plist1, plist2, plist3);
	print(plist3);

	free(plist1);
	free(plist2);
	free(plist3);
}

