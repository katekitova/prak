//
//  n6_43.h
//  VMK
//
//  Created by Екатерина Китова on 30.10.2024.
//

//Стек
#ifndef n6_43_h
#define n6_43_h
#include <stdlib.h>

typedef struct node
{
    void *data;
    struct node *next;
}node;

typedef node *stack;

void push_s(stack *s, void *data);

void *pop_s(stack *s);

int size_s(stack s);

void print_s(stack s);

void del_s(stack *s);
#endif /* n6_43_h */
