#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Movie {
	char title[50];
	int year;
	char genre[30];
}Movie;

typedef struct ListNode {
	Movie movie;
	struct ListNode* left;
	struct ListNode* right;
}ListNode;

void init(ListNode* phead) {
	phead->left = phead;
	phead->right = phead;
}

void add(ListNode* phead, Movie movie) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->movie.genre, movie.genre);
	newNode->movie.year = movie.year;
	strcpy(newNode->movie.title, movie.title);

	ListNode* Current = phead->right;
	while (Current != phead && Current->movie.year <= movie.year) {
		Current = Current->right;
	}
	newNode->left = Current;
	newNode->right = newNode->left->right;
	Current->right->left = newNode;
	Current->right = newNode;
}

bool duplicate(ListNode* phead, Movie movie) {
	ListNode* Current = phead->right;
	while (Current != phead) {
		if (strcmp(Current->movie.title, movie.title) == 0) {
			return true; // �ߺ���
		}
		Current = Current->right;
	}
		return false; // �ߺ����� ����
}

void deleteNode(ListNode* phead, Movie movie) {
	ListNode* Current = phead->right;
	while (Current != phead && strcmp(Current->movie.title, movie.title) != 0) {
		Current = Current->right;
	}
	if (Current == phead) {
		printf("�ش� ��ȭ�� �����ϴ�\n");
		return;
	}
	printf("%s ��ȭ�� �����մϴ�.\n", Current->movie.title);
	Current->left->right = Current->right;
	Current->right->left = Current->left;
	free(Current);
}

void printNode(ListNode* phead) {
	ListNode* Current = phead->right;
	while (Current != phead) {
		printf("%s %d %s \n", Current->movie.title, Current->movie.year, Current->movie.genre);
		Current = Current->right;
	}
}

void searchGenre(ListNode* phead, Movie movie) {
	ListNode* Current = phead->right;
	while (Current != phead) {
		if (strcmp(Current->movie.genre, movie.genre) == 0) {
			printf("%s \n", Current->movie.title);
		}
		Current = Current->right;
	}
}

void DownCaseSort(ListNode* phead) {
	ListNode* Current = phead->left;
	while (Current != phead) {
		printf("%s %d %s\n", Current->movie.title, Current->movie.year, Current->movie.genre);
		Current = Current->left;
	}
}




int main()
{
	ListNode head;
	init(&head);

	while (true) {
		printf("1.��ȭ �߰� || 2.��ȭ ���� || 3.��ü ��ȭ ��� ��� || 4.�帣�� ��ȭ �˻� 5.���� ���� ���� �������� ���� ��� 6.���α׷� ����");
		int choice;
		scanf("%d", &choice);

		if (choice == 1) {
			Movie movie;
			printf("��ȭ ����");
			scanf("%s", movie.title);
			printf("������");
			scanf("%d", &movie.year);
			printf("�帣");
			scanf("%s", &movie.genre);
			if (duplicate(&head, movie)) {
				printf("��ȭ�� �ߺ��Ǿ����ϴ�.\n");
			}
			else {
				add(&head, movie);
				printf("��ȭ�� �߰��Ǿ����ϴ�.\n");
			}
		}
		else if (choice == 2) {
			Movie movie;
			printf("��ȭ ����\n");
			printf("� ��ȭ�� �����ұ��? : ");
			scanf("%s", movie.title);
			deleteNode(&head, movie);
		}
		else if (choice == 3) {
			printf("��ȭ ���\n");
			Movie movie;
			printNode(&head);
		}
		else if (choice == 4) {
			Movie movie;
			printf("�帣�� ��ȭ �˻�\n");
			printf("�˻��ϰ� ���� ��ȭ�� �帣�� �Է��ϼ���\n");
			scanf("%s", movie.genre);
			searchGenre(&head, movie);
		}
		else if (choice == 5) {
			printf("���� �⵵ ���� �������� ���� ���\n");
			printf("��ȭ ���\n");
			DownCaseSort(&head);
		}
		else if (choice == 6) {
			break;
		}
		else {
			printf("\n �ٽ� �����ϼ���");
		}
	}
	return 0;
}
