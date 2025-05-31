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
			return true; // 중복됨
		}
		Current = Current->right;
	}
		return false; // 중복되지 않음
}

void deleteNode(ListNode* phead, Movie movie) {
	ListNode* Current = phead->right;
	while (Current != phead && strcmp(Current->movie.title, movie.title) != 0) {
		Current = Current->right;
	}
	if (Current == phead) {
		printf("해당 영화가 없습니다\n");
		return;
	}
	printf("%s 영화를 삭제합니다.\n", Current->movie.title);
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
		printf("1.영화 추가 || 2.영화 삭제 || 3.전체 영화 목록 출력 || 4.장르로 영화 검색 5.개봉 연도 기준 내림차순 정렬 출력 6.프로그램 종료");
		int choice;
		scanf("%d", &choice);

		if (choice == 1) {
			Movie movie;
			printf("영화 제목");
			scanf("%s", movie.title);
			printf("개봉일");
			scanf("%d", &movie.year);
			printf("장르");
			scanf("%s", movie.genre);
			if (duplicate(&head, movie)) {
				printf("영화가 중복되었습니다.\n");
			}
			else {
				add(&head, movie);
				printf("영화가 추가되었습니다.\n");
			}
		}
		else if (choice == 2) {
			Movie movie;
			printf("영화 삭제\n");
			printf("어떤 영화를 삭제할까요? : ");
			scanf("%s", movie.title);
			deleteNode(&head, movie);
		}
		else if (choice == 3) {
			printf("영화 목록\n");
			Movie movie;
			printNode(&head);
		}
		else if (choice == 4) {
			Movie movie;
			printf("장르로 영화 검색\n");
			printf("검색하고 싶은 영화의 장르를 입력하세요\n");
			scanf("%s", movie.genre);
			searchGenre(&head, movie);
		}
		else if (choice == 5) {
			printf("개봉 년도 기준 내림차순 정렬 출력\n");
			printf("영화 목록\n");
			DownCaseSort(&head);
		}
		else if (choice == 6) {
			break;
		}
		else {
			printf("\n 다시 선택하세요");
		}
	}
	return 0;
}
