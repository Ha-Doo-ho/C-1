#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Word {
	char eng[30];
	char kor[30];
}Word;

typedef struct ListNode {
	Word word;
	struct ListNode* link;
}ListNode;

ListNode* insert_last(ListNode* head, Word word) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strcpy(newNode->word.eng, word.eng);
	strcpy(newNode->word.kor, word.kor);
	
	if (head == NULL) {
		head = newNode;
		newNode->link = head;
	}
	else {
		newNode->link = head->link;
		head->link = newNode;
		head = newNode;
	}
	return head;
}

ListNode* search(ListNode* head, Word word) {
	if (head == NULL) {
		printf("�ܾ �����ϴ�.");
		return NULL;
	}
	else {
		ListNode* Current = head->link;
		do {
			if (strcmp(Current->word.kor, word.kor) == 0) {
				printf("%s�� ����ܾ� ���� %s �Դϴ�.\n", Current->word.kor, Current->word.eng);
				return head;
			}
			Current = Current->link;
		} while (Current != head->link);

		printf("�ش� �ܾ �������� �ʽ��ϴ�.\n");
		return head;
	}

}

int getSize(ListNode* head) {
	if (head == NULL) return 0;
	ListNode* Current = head->link;
	int count = 0;
	do {
		count++;
		Current = Current->link;
	} while (Current != head->link);
	return count;
}

int main() {
	ListNode* head = NULL;
	while (true) {
		printf("1: �߰� || 2: �ܾ�˻� || 3: ����� �ܾ� �� üũ\n");
		int choice = 0;
		scanf("%d", &choice);

		if (choice == 1) {
			Word word;
			printf("1: �ܾ��߰�\n");
			printf("����: ");
			scanf("%s", word.eng);
			printf("�ѱ���: ");
			scanf("%s", word.kor);
			head = insert_last(head, word);
		}
	
		else if (choice == 2) {
			Word word;
			printf("2: ���ܾ�˻�\n");
			printf("�ѱ��� ���� �Է����ּ���: ");
			scanf("%s", word.kor);
			search(head, word);
		}
		else if (choice == 3) {
			printf("���� ����� �ܾ� ���� %d �Դϴ�.", getSize(head));
		}
		else {
			break;
		}
	}
	return 0;
}

