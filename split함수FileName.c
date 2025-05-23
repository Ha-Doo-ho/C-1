#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
	int 차수;
	int 계수;
	struct ListNode* link;
}ListNode;

typedef struct {
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

void insert_last(ListType* plist, int 계수, int 차수) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->계수 = 계수;
	newNode->차수 = 차수;
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

void add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* Current1 = plist1->head;
	ListNode* Current2 = plist2->head;
	int sum;

	while (Current1 != NULL && Current2 != NULL) {
		if (Current1->차수 == Current2->차수) {
			sum = Current1->계수 + Current2->계수;
			if (sum != 0) {
				insert_last(plist3, sum, Current1->차수);
			}
			Current1 = Current1->link;
			Current2 = Current2->link;
		}
		else if (Current1->차수 > Current2->차수) {
			insert_last(plist3, Current1->계수, Current1->차수);
			Current1 = Current1->link;
		}
		else if (Current1->차수 < Current2->차수) {
			insert_last(plist3, Current2->계수, Current2->차수);
			Current2 = Current2->link;
		}
	}
	while (Current1 != NULL && Current2 == NULL) {
		insert_last(plist3, Current1->계수, Current1->차수);
		Current1 = Current1->link;
	}
	while (Current1 == NULL && Current2 != NULL) {
		insert_last(plist3, Current2->계수, Current2->차수);
		Current2 = Current2->link;
	}
}

void print(ListType* plist) {
	ListNode* Current = plist->head;

	while (Current != NULL) {
		printf("%dx^%d + ", Current->계수, Current->차수);
		Current = Current->link;
	}
	printf("\n");
}

int main(void) {
	ListType* plist1 = create();
	ListType* plist2 = create();
	ListType* plist3 = create();

	insert_last(plist1, 3,6);
	insert_last(plist1, 7,3);
	insert_last(plist1, -2,2);
	insert_last(plist1, -9,0);

	insert_last(plist2, -2, 6);
	insert_last(plist2, -4, 4);
	insert_last(plist2, 6, 2);
	insert_last(plist2, 6, 1);
	insert_last(plist2, 1, 0);

	print(plist1);
	print(plist2);

	add(plist1, plist2, plist3);
	print(plist3);

	free(plist1);
	free(plist2);
	free(plist3);
	return 0;
}

