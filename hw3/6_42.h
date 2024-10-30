//
//  n6_42.h
//  VMK
//
//  Created by Екатерина Китова on 30.10.2024.
//

//Очередь
#ifndef n6_42_h
#define n6_42_h
#include <stdlib.h>

typedef struct node
{
    void *data;
    struct node *next;
}node;

typedef node *queue;

void put_q(queue *q, void *data);

void *get_q(queue *q);

int size_q(queue q);

void print_q(queue q);

void del_q(queue *q);
#endif /* n6_42_h */
