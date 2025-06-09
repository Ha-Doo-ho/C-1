#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode{
    int data;
    struct ListNode* link;
}ListNode;

typedef struct ListType{
    ListNode* head;
    ListNode* tail;
    int size;
}ListType;

ListType* Create(){
    ListType* plist = (ListType*)malloc(sizeof(ListType));
    plist->head = NULL;
    plist->tail = NULL;
    return plist;
}

void insert_last(ListType* plist, int data){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;

    if(plist->tail == NULL){
        plist->head = newNode;
        plist->tail = newNode;
    }else{
        plist->tail->link = newNode;
        plist->tail = newNode;
    }
    plist->size++;
}

int deleteNode(ListType* plist, int data){
    ListNode* prev = NULL;
    ListNode* Current = plist->head;

    while(Current != NULL){
        if(Current->data == data){
            int temp = Current->data;
            if(Current == plist->head){
                plist->head = Current->link;
            }
            else if(Current == plist->tail){
                plist->tail = prev;
                prev->link = NULL;
            }
            else{
                prev->link =Current->link;
            }
             free(Current);
             return temp;
        }
        prev = Current;
        Current = Current->link;
    }
    return -1;
}

int findMax(ListType* plist){
    ListNode* Current = plist->head;
    int max = 0;
    
    while(Current != NULL){
        if(max < Current->data){
            max = Current->data;
        }
        Current = Current->link;
    }
    return max;
}

int findMin(ListType* plist){
    ListNode* Current = plist->head;
    int min = 99999;
    
    while(Current != NULL){
        if(min > Current->data){
            min = Current->data;
        }
        Current = Current->link;
    }
    return min;
}

void split(ListType* plist1, ListType* plist2, ListType* plist3){ //plist1에 있는 것을 2와 3으로 분배
    ListNode* Current = plist1->head;
    int count = 1;
    while(Current!=NULL){
    if(count % 2 == 0){
        insert_last(plist3,Current->data);
    }else{
        insert_last(plist2,Current->data);
    }
    count++;
    Current = Current->link;
    }
} 

void print_list(ListType* plist){
    ListNode* Current = plist->head;
    while(Current != NULL){
        printf("%d->",Current->data);
        Current = Current->link;
    }
    printf("\n");
}

int main() {
   ListType* plist1 = Create();
   ListType* plist2 = Create();
   ListType* plist3 = Create();

   insert_last(plist1, 1); 
    insert_last(plist1, 2);
    insert_last(plist1, 0);
    insert_last(plist1, 3); 
    insert_last(plist1, 4); 
    insert_last(plist1,332);

    printf("가장 큰 수: %d\n",findMax(plist1));
    printf("가장 작은 수: %d\n",findMin(plist1));
    
    print_list(plist1);

    split(plist1,plist2,plist3);
    print_list(plist2);
    
    print_list(plist3);
    
  
    
}
