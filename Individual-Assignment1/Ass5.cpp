#include <stdio.h>
#include <string.h>
#include<stdlib.h>

  struct Node{
    int data;
    struct Node *next;
  }*head, *tail;

  void NthFromLast(struct Node*head, int n){
    int len = 0;
    struct Node *temp = head;
    while (temp!= NULL){
      temp = temp->next;
      len++;
    }
    if (len< n){
      ("Invalid N!\n");
      return;
    }
    temp = head;
    for ( int i = 1; i <= len-n; i++){
      temp = temp->next;
    }
    printf("%d\n", temp->data);
    return;
  }

//testing
Node *createNode(int data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void pushTail(int data){
  Node *temp = createNode(data);
  if (!head){
    head = tail = temp;
  }else{
    tail->next = temp;
    tail = temp;
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

  

int main(){
  pushTail(1);
  pushTail(2);
  pushTail(3);
  pushTail(4);
  pushTail(5);
  printList(head);
  puts("");
  NthFromLast(head, 4);
  return 0;
}