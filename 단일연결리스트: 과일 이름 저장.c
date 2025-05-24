#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char 단어[30];
}english;

typedef struct ListNode {
	english eng;
	struct ListNode* link;
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

void insert_last(ListType* plist, english eng) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->eng.단어, eng.단어);
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

void print(ListType* plist) {
	ListNode* Current = plist->head;
	while (Current != NULL) {
		printf("%s->", Current->eng.단어);
		Current = Current->link;
	}
	printf("NULL");
	printf("\n");
}


int main(void) {
	ListType* plist = Create();

	printf("몇개의 단어를 넣겠습니까?");
	int num;
	scanf("%d", &num);
	while (num-- > 0) {
		english eng;;
		scanf("%s", eng.단어);
		insert_last(plist, eng);
	}

	print(plist);
	free(plist);
	return 0;
}


