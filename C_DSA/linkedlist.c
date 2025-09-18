#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



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

void addInShorted(NODE **head,uint32_t data)
{   NODE* HEAD=*head,*prev=NULL;
    NODE *newNode=(NODE*)malloc(sizeof(NODE));
    if(newNode==NULL)return;
    newNode->DATA=data;
    newNode->NEXT=NULL;
    prev=HEAD;
    printNode(*head);
   
    if( HEAD == NULL){
        *head = newNode; return;
    }
     getchar();
    if((HEAD->DATA>data)&&(HEAD->NEXT==NULL)){
        newNode->NEXT=prev;
        *head=newNode;
        return;}
    while((HEAD!=NULL)&&(HEAD->DATA<=data)){
        prev=HEAD;
        HEAD=HEAD->NEXT;
    }
    if (prev == NULL){
        HEAD->NEXT = newNode;
    } else {
        newNode->NEXT=HEAD;
        prev->NEXT = newNode;
    }
    
}


int main(int argc, char *argv[])
{

    NODE *HEAD=NULL;
    addInShorted(&HEAD,4);
    addInShorted(&HEAD,2);
    addInShorted(&HEAD,6);
    addInShorted(&HEAD,3);
    addInShorted(&HEAD,7);
    addInShorted(&HEAD,2);
    addInShorted(&HEAD,9);
    addInShorted(&HEAD,12);
    printNode(HEAD);
    reverseList(&HEAD);
    printNode(HEAD);
    return 0;
}