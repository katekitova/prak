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

void add_node(list *p, double *value)
{
    list new = (list)malloc(sizeof(node));
    new -> data = value;
    new -> next = *p;
    *p = new;
}

void print_list(list *p)
{
    list current = *p;
    while (current != NULL)
    {
        printf("%3.1f ", *current->data);
        current = current->next;
    }
    printf("\n");
}

int main(void)
{
    list p = NULL;
    double val[] = {7.0, 4.0, 3.0, -10.0, 3.0, 5.0, 5.0, 3.0, 5.0, -1.0};
    for (int i =0 ; i<10; i++) add_node(&p, &val[i]);
    
    printf("\nlist:");
    print_list(&p);
    
    swap_first_last(&p);
    printf("\na)list:");
    print_list(&p);
    
    del_first_oc(&p, &val[2]);
    printf("\nb1)list:");
    print_list(&p);
    printf("first occurrence of %lf was deleted\n", val[2]);
    
    del_elem(&p, &val[5]);
    printf("\nc1)list:");
    print_list(&p);
    printf("%lf was deleted\n", val[5]);
    
    double_el(&p, &val[0]);
    printf("\nd)list:");
    print_list(&p);
    printf("%lf was doubled\n", val[0]);
    return 0;
}
