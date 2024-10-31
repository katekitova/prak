//
//  n6_45e.h
//  VMK
//
//  Created by Екатерина Китова on 30.10.2024.
//

#ifndef n6_45e_h
#define n6_45e_h

#include <stdio.h>

#include "n6_42.h" //использую наработки для очереди

typedef struct tnode
{
    int data;
    struct tnode *left;
    struct tnode *right;
} tnode;

typedef tnode *tree;

int count_lvl_t(tree t, int num);

void add_t(tree *t, int val);

void del_t(tree *t);

void print_t(tree t);
#endif /* n6_45e_h */
