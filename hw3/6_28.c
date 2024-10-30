//
//  6_28.c
//  VMK
//
//  Created by Екатерина Китова on 24.10.2024.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    double *data;
    struct node *next;
} node;

typedef node *list;

void swap_first_last(list *p) //a)
{
    if ((*p == NULL) || ((*p) -> next == NULL)) return;
    list buf = *p, last;
    for (; buf -> next -> next != NULL; buf = buf -> next);
    last = buf -> next;
    last -> next = (*p) -> next;
    (*p) -> next = NULL;
    buf -> next  = *p;
    *p = last;
}

void del_first_oc(list *p, double *el) //b1)
{
    if (*p == NULL) return;
    for (; (*p != NULL) && ((*p) -> data != el); p = &((*p) -> next));
    if (*p == NULL) return;
    list buf = *p;
    (*p) = (*p) -> next;
    free(buf);
}

void hdel_first_oc(list p, double *el) //b2)
{
    if (p == NULL) return;
    for (; (p != NULL) && (p -> data != el); p = p -> next);
    if (p == NULL)
    {
        return;
    }
    list buf = p;
    p = p -> next;
    free(buf);
}

void del_elem(list *p, double *el) //c1)
{
    if (*p == NULL) return;
    while (*p != NULL)
    {
        for (;(*p != NULL) && ((*p) -> data != el); p = &((*p) -> next));
        if (*p == NULL)
        {
            return;
        }
        list buf = *p;
        *p = (*p) -> next;
        free(buf);
    }
}

void hdel_elem(list p, double *el) //c2)
{
    if (p == NULL) return;
    while (p != NULL)
    {
        for (;(p != NULL) && (p -> data != el); p = p -> next);
        if (p == NULL)
        {
            return;
        }
        list buf = p;
        p = p -> next;
        free(buf);
    }
}

void double_el(list *p, double *el) //d)
{
    while (*p != NULL)
    {
            if ((*p)->data == el)
            {
                list buf = (list)malloc(sizeof(node));
                buf->data = el;
                buf->next = (*p)->next;
                (*p)->next = buf;
                p = &buf->next;
            }
            else
            {
                p = &((*p)->next);
            }
        }
    }
