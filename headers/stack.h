#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>

// #include "main.h"

typedef struct
{
    int value;
    int tp_X;
    int tp_Y;
    void * entity;

} Map;



typedef struct MapData
{
    Map** map;
    int rows;
    int collums;
} MapData;


typedef struct Node Node;

typedef struct Node
{
    MapData mapData;
    Node *next;
    Node *prev;
}Node;


Node* constructor_node(MapData value)
{
    Node* new_ = (Node*) malloc(sizeof(Node));
    new_->next = NULL;
    new_->prev = NULL;
    new_->mapData = value;
    
    return new_;
}


typedef struct 
{
    Node *head;
    Node *tail;
    int size;
}Stack;


Stack constructor_list()
{
    Stack new_;
    new_.head = NULL;
    new_.tail = NULL;
    new_.size = 0;

    return new_;
}


void push(Stack *linkedList, MapData event)
{
    Node *node = constructor_node(event);

    if(linkedList->head == NULL)
    {
        linkedList->head = node;    
        linkedList->tail = node; 
        linkedList->size++;
        return;
    }
    linkedList->tail->next = node;
    node->prev = linkedList->tail;
    linkedList->tail = node;
    linkedList->size++;
}


void pop(Stack *linkedList)
{
    if(linkedList->head == NULL)
        return;
    
    linkedList->size--;
    linkedList->tail = linkedList->tail->prev;
    linkedList->tail->next = NULL;
}


MapData peek(Stack *LinkedList)
{
    if (LinkedList->size == 0)
        return;
    
    return LinkedList->tail->mapData;
}



#endif