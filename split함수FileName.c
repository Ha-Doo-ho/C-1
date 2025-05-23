#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ListNode {
	int ����;
	int ���;
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

void insert_last(ListType* plist, int ���, int ����) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->��� = ���;
	newNode->���� = ����;
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
		if (Current1->���� == Current2->����) {
			sum = Current1->��� + Current2->���;
			if (sum != 0) {
				insert_last(plist3, sum, Current1->����);
			}
			Current1 = Current1->link;
			Current2 = Current2->link;
		}
		else if (Current1->���� > Current2->����) {
			insert_last(plist3, Current1->���, Current1->����);
			Current1 = Current1->link;
		}
		else if (Current1->���� < Current2->����) {
			insert_last(plist3, Current2->���, Current2->����);
			Current2 = Current2->link;
		}
	}
	while (Current1 != NULL && Current2 == NULL) {
		insert_last(plist3, Current1->���, Current1->����);
		Current1 = Current1->link;
	}
	while (Current1 == NULL && Current2 != NULL) {
		insert_last(plist3, Current2->���, Current2->����);
		Current2 = Current2->link;
	}
}

void print(ListType* plist) {
	ListNode* Current = plist->head;

	while (Current != NULL) {
		printf("%dx^%d + ", Current->���, Current->����);
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

