#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode{
    int coef,expon;
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

void insert_last(ListType* plist, int coef, int expon){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->coef = coef;
    newNode->expon = expon;

    if(plist->tail == NULL){
        plist->head = newNode;
        plist->tail = newNode;
    }else{
        plist->tail->link = newNode;
        plist->tail = newNode;
    }
    plist->size++;
}

void poly_add(ListType* plist1,ListType* plist2, ListType* plist3){ //plist3이 최종결과 저장배열
    ListNode* Current1 = plist1->head;
    ListNode* Current2 = plist2->head;

    while(Current1 != NULL && Current2 != NULL){
        if(Current1->expon == Current2->expon){
            int sum = Current1->coef + Current2->coef;
            if(sum != 0){
                insert_last(plist3, sum, Current1->expon);
            }
            Current1 = Current1->link;
            Current2 = Current2->link;
        }
        else if(Current1->expon > Current2->expon){
            insert_last(plist3, Current1->coef, Current1->expon);
            Current1 = Current1->link;
        }
        else if(Current1->expon < Current2->expon){
            insert_last(plist3, Current2->coef, Current2->expon);
            Current2 = Current2->link;
        }
    }

    while(Current1 != NULL && Current2 == NULL){
        insert_last(plist3, Current1->coef, Current1->expon);
        Current1 = Current1->link;
    }

    while(Current1 == NULL && Current2 != NULL){
        insert_last(plist3, Current2->coef, Current2->expon);
        Current2 = Current2->link;
    }

}

void print_list(ListType* plist){
    ListNode* Current = plist->head;
    while(Current != NULL){
        printf("%d^%d+",Current->coef,Current->expon);
        Current = Current->link;
    }
    printf("\n");
}

int main() {
   ListType* plist1 = Create();
   ListType* plist2 = Create();
   ListType* plist3 = Create();

   insert_last(plist1, 3,12); 
   insert_last(plist1, 2,8); 
   insert_last(plist1, 1,0);
   print_list(plist1);
    
   insert_last(plist2,8,12);
   insert_last(plist2,-3,10);
   insert_last(plist2,10,6);
   print_list(plist2);

   poly_add(plist1,plist2,plist3);
    
    print_list(plist3);

    
  
    
}
