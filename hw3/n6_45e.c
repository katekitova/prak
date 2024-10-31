//
//  n6_45e.c
//  VMK
//
//  Created by Екатерина Китова on 30.10.2024.
//

#include "n6_45e.h"
int count_lvl_t(tree t, int num)
{
    if ((num < 0) || (t == NULL)) return 0;
    int last = 1, next = 0;
    queue q = NULL;
    put_q(&q, t);
    for(int i = 0; (q != NULL) && (i < num); i++)
    {
        tree buf;
        for(; last > 0; last--)
        {
            buf = (tree)get_q(&q);
            if (buf -> left != NULL)
            {
                next++;
                put_q(&q, buf -> left);
            }
            if (buf -> right != NULL)
            {
                next++;
                put_q(&q, buf -> right);
            }
        }
        if (next == 0) break;
        last = next;
        next = 0;
    }
       del_q(&q);
    return last;
}

void add_t(tree *t, int val)
{
    if (*t == NULL)
    {
        *t = (tree)malloc(sizeof(tnode));
        (*t) -> data = val;
        (*t) -> left = NULL;
        (*t) -> right = NULL;
        return;
    }
    if ((*t) -> data > val) add_t(&((*t) -> left), val);
    else add_t(&((*t) -> right), val);
}

void del_t(tree *t)
{
    if (*t == NULL) return;
    del_t(&((*t) -> left));
    del_t(&((*t) -> right));
    free(*t);
}

void print_t(tree t)
{
    int last = 1, next = 0;
    queue q = NULL;
    put_q(&q, t);
    for(;;)
    {
        tree buf = NULL;
        for(; last > 0; last--)
        {
            buf = (tree)get_q(&q);
            printf("%d ", buf -> data);
            if (buf -> left != NULL)
            {
                next++;
                put_q(&q, buf -> left);
            }
            if (buf -> right != NULL)
            {
                next++;
                put_q(&q, buf -> right);
            }
        }
        if (next == 0)
        {
            printf("%d ",buf -> data);
            break;
        }
        printf("\n");
        last = next;
        next = 0;
    }
    printf("\n");
    del_q(&q);
}
