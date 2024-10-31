//
//  6_32.c
//  VMK
//
//  Created by Екатерина Китова on 24.10.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    double f;
    char *s[2];
} data;

typedef struct Inode
{
    data *p;
    struct Inode *next;
} Inode;

typedef Inode *list;

list copy_list(list l)
{
    if (l == NULL) return NULL;

    list L1 = (list)malloc(sizeof(Inode));
    L1->p = (data*)malloc(sizeof(data));
    memcpy(L1->p, l->p, sizeof(data));
    L1->next = NULL;
    list L2 = L1;
    l = l->next;
    while (l != NULL)
    {
        L2->next = (list)malloc(sizeof(Inode));
        L2 = L2->next;
        L2->p = (data*)malloc(sizeof(data));
        memcpy(L2->p, l->p, sizeof(data));
        L2->next = NULL;
        l = l->next;
    }
    return L1;
}
