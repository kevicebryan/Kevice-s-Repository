#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node*next;
  int flag;
}*head,*tail;
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

//detection function
int detectloop(struct Node*h){
  while (h){
    if (h->flag == 1){
      return 1;
   
    }
    h->flag = 1;
    h = h->next;
  }
  return 2;
}

int main (){
  pushHead(1);
  pushHead(2);
  pushHead(3);
  pushHead(4);
  // membuat loop
  head->next->next->next->next = head;


  int detect = detectloop(head);
  if (detect == 2){
    printf("Not Loop\n");
  }else{
    printf("Loop!\n");
  }
  
  return 0;
}