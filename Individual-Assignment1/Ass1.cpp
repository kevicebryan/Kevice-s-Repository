#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
  int val;
  Node *next;
}*heada, *taila, *headb, *tailb;

Node *createNode(int val){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = NULL;
  return newNode;
}

void pushTailA(int value){
  Node *temp = createNode(value);
  if(!heada){
    heada =taila = temp;
  }else{
    taila->next = temp;
    taila = temp;
  }
}


void pushTailB(int value){
  Node *temp = createNode(value);
  if(!headb){
    headb =tailb = temp;
  }else{
    tailb->next = temp;
    tailb = temp;
  }
}


struct Node* SortMerge(struct Node* a, struct Node*b){
  struct Node*result = NULL;
  if (a == NULL){
    return b;
  }else if ( b ==NULL){
    return a;
  }
  if (a->val <= b->val){
    result = a;
    result->next = SortMerge(a->next, b);
  }else{
    result = b;
    result->next = SortMerge(a, b->next);
  }
  return(result);
}

void printList(struct Node *node) 
{ 
    while (node!=NULL) 
    { 
        printf("%d ", node->val); 
        node = node->next; 
    } 
} 

int main (){
  pushTailA(1);
  pushTailA(3);
  pushTailA(5);
  pushTailB(2);
  pushTailB(4);
  pushTailB(6);
  printList(heada);
  puts("");
  printList(headb);
  puts("");
  struct Node* Result = SortMerge(heada, headb);
  printList(Result);


  return 0;
}