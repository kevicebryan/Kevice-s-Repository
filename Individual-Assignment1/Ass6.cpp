#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct Node{
  int data;
  Node *next;
}*head, *tail;

void sortList() {  
 
  struct Node *current = head, *index = NULL;  
  int temp;  
          
  if(head == NULL) {  
    return;  
  }  
  else {  
    while(current != NULL) {  
                
      index = current->next;  
                  
      while(index != NULL) {  
                   
       if(current->data < index->data) {  
        temp = current->data;  
        current->data = index->data;  
        index->data = temp;  
       }  
        index = index->next;  
      }  
    current = current->next;  
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

int main (){
  pushTail(1);
  pushTail(2);
  pushTail(3);
  pushTail(4);
  pushTail(5);
  printList(head);
  puts("");
  sortList();
  printList(head);
  return 0;
}