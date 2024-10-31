//
//  n6_43.c
//  VMK
//
//  Created by Екатерина Китова on 30.10.2024.
//

// Стек
#include <stdio.h>
#include <stdlib.h>
#include "n6_43.h"

void push_s(stack *s, void *val)
{
    stack new = (stack)malloc(sizeof(node));
    new -> data = val;
    new -> next = *s;
    *s = new;
}

void *pop_s(stack *s)
{
    if (*s == NULL) return NULL;
    stack first = *s;
    void *value = first -> data;
    *s = (*s) -> next;
    free(first);
    return value;
}

int size_s(stack s)
{
    int n = 0;
    for(; s != NULL; s = s -> next) n++;
    return n;
}

void print_s(stack s)
{
    stack current = s;
    while (current != NULL)
    {
        printf("%d ", *(int*)current->data);
        current = current->next;
    }
    printf("\n");
}

void del_s(stack *s)
{
    stack buf = *s;
    *s = (*s) -> next;
    for (; *s != NULL; *s = (*s) -> next)
    {
        free(buf);
        buf = *s;
    }
}
