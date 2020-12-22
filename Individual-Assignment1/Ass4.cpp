#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct Node  {
  int data;
  struct Node*next;
}*head,*tail;

void removeDupes(struct Node*head){
  struct Node*curr= head;
  struct Node *aftercurr;
  if (curr ==NULL){
    return;
  }
  while (curr->next != NULL){
    if (curr-> data == curr->next->data){
      aftercurr =  curr->next->next;
      free(curr->next);
      curr->next=aftercurr;
    }
    else{
      curr= curr->next;
    }
  }
}

//testing
Node *createNode(int data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void pushHead(int data){
  Node *temp = createNode(data);
  if (!head){
    head = tail = temp;
  }else{
    temp->next = head;
    head = temp;
  }
}

void printList(struct Node *node) 
{ 
    while (node!=NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 

int main (){
  pushHead(1);
  pushHead(1);
  pushHead(1);
  pushHead(2);
  pushHead(2);
  pushHead(3);
  printList(head);
  puts("");
  printf("-------------\n");
  puts("");
  removeDupes(head);
  printList(head);
  return 0;
}