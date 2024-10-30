//
//  6_40.c
//  VMK
//
//  Created by Екатерина Китова on 27.10.2024.
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *data;
    struct node *next;
} node;

typedef node *list;

list XOR_L1_L2(list L1, list L2)
{
    list L3 = NULL;
    for (list tmp1 = L1; tmp1 != NULL; tmp1 = tmp1->next)
    {
        int flag = 0;
        for (list tmp2 = L2; tmp2 != NULL; tmp2 = tmp2->next)
        {
            if (strcmp(tmp1->data, tmp2->data) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            node *new_node = (node *)malloc(sizeof(node));
            new_node->data = strdup(tmp1->data);
            new_node->next = L3;
            L3 = new_node;
        }
    }
    for (list tmp2 = L2; tmp2 != NULL; tmp2 = tmp2->next)
    {
        int flag = 0;
        for (list tmp1 = L1; tmp1 != NULL; tmp1 = tmp1->next)
        {
            if (strcmp(tmp2->data, tmp1->data) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            node *buf = (node *)malloc(sizeof(node));
            buf->data = strdup(tmp2->data);
            buf->next = L3;
            L3 = buf;
        }
    }
    return L3;
}
