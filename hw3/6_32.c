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
}data;

typedef struct Inode
{
    data *p;
    struct Inode *next;
}Inode;

typedef Inode *list;

list copy_list(list l)
{
    list L1, L2;
    if (l == NULL) return L1 = NULL;
    L1 = (list)malloc(sizeof(Inode));
    L2 = L1;
    for (; l->next != NULL; l = l->next)
    {
        memcpy(L2->p, l->p, sizeof(data));
        L2->next = (list)malloc(sizeof(Inode));
        L2 = L2->next;
    }
    memcpy(L2->p, l->p, sizeof(data));
    L2->next = NULL;
    return L1;
}
