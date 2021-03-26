#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* L = (List*)malloc(sizeof(List));
    L->head = NULL;
    L->tail = NULL;
    L->current = NULL;
    return L;
}

void * firstList(List * list) { 
    list->current = list->head;
    return (void*)(list->current->data);
}

void * nextList(List * list) {
  if(list->current==NULL) return NULL;
  if(list->current->next==NULL) return NULL;

    list->current = list->current->next;
    return (void*)(list->current->data);
}
//-------------> HASTA AQUI ESTA DE PANA <-------------//
void * lastList(List * list) {
    if(list->current==NULL){
      return NULL;
      }
    if(list->current->next==NULL){ 
    return (void*)list->current->data;
      }
    while(list->current->next!=NULL){
      list->current = list->current->next;
      }
    return (void*)list->current->data;
}
//-----> NO SE QUE DEBE HACER LA FUNCION CUANDO CURRENT ES NULL :C
void * prevList(List * list) {
  if(list->current!=list->head){
    list->current = list->current->prev;
  }
    return (void*) list->current->data; 
}

void pushFront(List * list, const void * data) {
  Node* aux = NULL;
  if(list->head!=NULL){
    aux = list->head;
    list->head=createNode(data);
    list->head->next=aux;
    list->head->next->prev=list->current;
  }
  else{
    list->head=createNode(data);
  }
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}