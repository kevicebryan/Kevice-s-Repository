#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Linked List
//sebuah linked list punya head dan tail
//pake penanda <curr> u/ mengakses node diantar head & tail
//mempunyai data dan pointer yang mengarah ke pointer selanjutnya
//---Strength & Weakness---
//-->bersifat dinamis(flexible), no indexing
//-->efficient memory alloc
//-->slow search time
//Circuler/Cycle Linkedlist:
//Linked list yang mengunjungi node yg pernah dilewati

//Linked List Code:

struct Node{
  char name[255];
  int score;
  Node *next;//pointer ke Node selanjutnya
}*head, *tail;//head: node 1st, tail: node nth.

//kalo data cuman 1 , dianggap head & tail
//kalo udh ada 2 , cth 3, 4 (3 jdi head, 4 jdi tail)

Node *createNode(const char *name, int score){
  Node *newNode = (Node*)malloc(sizeof(Node));//Node = new Node;
  strcpy (newNode->name, name);
  newNode->score = score;
  newNode->next = NULL;//awal tidak punya node next
  return newNode;
}
//insert di kanan
void pushTail(const char *name, int score){
  Node *temp = createNode(name, score);//buat node dulu
  if(!head){//linked list masih kosong <<0 NODE>>
    head =tail = temp;
  }else{
    tail->next = temp;
    tail = temp;
  }
}
//insert di kiri
void pushHead(const char *name, int score){
  Node *temp = createNode(name, score);//buat node dulu
  if (!head){
    head = tail = temp;
  }else{
    temp->next = head;
    head = temp;
  }
}

void printLinkedList(){

  Node *curr = head; //curr adalah index yang akan berjalan
  while (curr){//while curr masih ada alias bukan NULL
    printf("%s %d\n", curr->name, curr->score);
    curr = curr->next;//curr jalan ke node selanjutnya
  }
}

void popHead(){
  if (!head){
    return;
  }else{
    Node *temp = head;
    head = temp->next;
    temp->next = NULL;
    free(temp);
  }
}

void popTail(){
  if (!head){
    return;
  }
  else if (head ==tail){
    free(head);
  }
  else{
    Node *temp = head;
    while(temp->next != tail){
      temp = temp->next;//temp jalan terus sampe dia nyampe tail-1
    }

    temp->next = NULL;
    free(tail);
    tail = temp;
  }
}

int main(){
  pushHead("Darnell", 95);
  pushTail("Whisper", 90);
  pushHead("Pai", 98);
  pushHead("Romario", 98);
  pushTail("Denny", 93);
  printLinkedList();
  puts("-------POP--------");
  popHead();
  popTail();
  printLinkedList();
  return 0;
}