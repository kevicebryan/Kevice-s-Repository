#include <stdio.h>
#include <string.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node*next;
}*head,*tail;

void findmid(struct Node*head){
  struct Node*slow = head;
  struct Node*fast = head;
  if (head){
    while (fast != NULL && fast->next != NULL){
      fast = fast->next->next;
      slow = slow->next;
    }
    printf("Mid element is %d\n", slow->data);
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
  pushHead(2);
  pushHead(3);
  pushHead(4);
  pushHead(5);
  printList(head);
  puts("");
  findmid(head);
  return 0;
}