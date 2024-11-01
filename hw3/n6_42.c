//
//  n6_42.c
//  VMK
//
//  Created by Екатерина Китова on 30.10.2024.
//

//  Очередь
#include <stdio.h>
#include "n6_42.h"

void put_q(queue *q, void *val)
{
    queue new = (queue)malloc(sizeof(node));
    new -> data = val;
    new -> next = NULL;
    if (*q == NULL)
    {
        *q = new;
        return;
    }
    for (; (*q) -> next != NULL; q = &((*q) -> next));
    (*q) -> next = new;
}

void *get_q(queue *q)
{
    if (*q == NULL) return NULL;
    queue f = *q;
    void *val = f-> data;
    *q = (*q) -> next;
    free(f);
    return val;
}

int size_q(queue q)
{
    int n = 0;
    for(; q != NULL; q = q -> next) n++;
    return n;
}

void print_q(queue q)
{
    queue current = q;
    while (current != NULL)
    {
        printf("%d ", *(int*)current->data);
        current = current->next;
    }
    printf("\n");
}

void del_q(queue *q)
{
    if (q == NULL) return;
    queue del;
    for(del = *q; del != NULL; del = *q)
    {
        *q = del -> next;
        free(del);
    }
}
