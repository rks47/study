#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define DEBUG 0 //0 for no debug, 1 for debug

typedef struct node 
{
    uint32_t DATA;
    struct node * NEXT;
}NODE;

void createNode(NODE** head,uint32_t data){
    NODE *HEAD=*head;
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    if(temp==NULL)return;
    temp->DATA=data;
    temp->NEXT=NULL;
    if(HEAD==NULL)
    *head=temp;
    else{
            while(HEAD->NEXT!=NULL){
                HEAD=HEAD->NEXT;
            }
            HEAD->NEXT=temp;
    }

}


void reverseList(NODE **head){
    NODE *curr=*head,*next=NULL,*prev=NULL;

    while(curr!=NULL){
        next=curr->NEXT;
        curr->NEXT=prev;
        prev=curr;
        curr=next;
    }

    *head=prev;
}

void printNode(NODE *head){
    while(head!=NULL){
        printf("%u->",head->DATA);
        head=head->NEXT;
    }
printf("\n");
}


void addinshorted(NODE **head,uint32_t data){
    NODE *HEAD=*head;
    NODE *newNode=(NODE*)malloc(sizeof(NODE));
    if(newNode==NULL)return;
    newNode->DATA=data;
    newNode->NEXT=NULL;
    if( HEAD == NULL){
        *head = newNode; return;
    }
#if DEBUG
    printNode(*head);
    getchar();
#endif
    if((HEAD->DATA>data)&&(HEAD->NEXT==NULL)){
        newNode->NEXT=HEAD;
        *head=newNode;
        return;}
    while((HEAD->NEXT!=NULL)&&(HEAD->NEXT->DATA<=data)){
        HEAD=HEAD->NEXT;
    }
    newNode->NEXT=HEAD->NEXT;
    HEAD->NEXT=newNode;
}

int main(int argc, char *argv[])
{

    NODE *HEAD=NULL;
    addinshorted(&HEAD,4);
    addinshorted(&HEAD,2);
    addinshorted(&HEAD,6);
    addinshorted(&HEAD,3);
    addinshorted(&HEAD,7);
    addinshorted(&HEAD,2);
    addinshorted(&HEAD,9);
    addinshorted(&HEAD,12);
    printNode(HEAD);
    reverseList(&HEAD);
    printNode(HEAD);
    return 0;
}