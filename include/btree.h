#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/*
    BTree
*/

typedef int elem;

typedef struct tree
{
    struct tree *lchild, *rchild;
    elem data;
} tree;

tree *
RootInit()
{
    tree *op = malloc(sizeof(tree));
    op->data = 0;
    op->lchild = NULL;
    op->rchild = NULL;

    return op;
}

tree *
_SeekElemParent(tree *t, elem e)
{
    for(;;)
    {
        if(e==t->data)
            return t;

        tree *op = NULL;
        if(e<t->data)
        {
            op = t->lchild;
        } else {
            op = t->rchild;
        }
        if(!op)
            return t;

        t = op;
    }
}

int
InsertElem(tree *t, elem e)
{
    if(!t)
        return FALSE;

    tree *parent = _SeekElemParent(t, e);
    if(parent->data==e)
        return FALSE;

    tree *op = malloc(sizeof(tree));
    op->data = e;
    op->lchild = NULL;
    op->rchild = NULL;

    if(op->data<parent->data)
    {
        parent->lchild = op;
    } else {
        parent->rchild = op;
    }
}

int
PreOrderPrintElem(tree *t, int depth, int tag) // tag = 1 means from lchild
{
    if(t==NULL)
        return --depth;
    if(tag==1)
        printf("|depth:%d|L child|%d|\n", depth, t->data);
    else
        printf("|depth:%d|R child|%d|\n", depth, t->data);
    depth = PreOrderPrintElem(t->lchild, ++depth, 1);
    depth = PreOrderPrintElem(t->rchild, ++depth, 0);
    return --depth;
}

int
InOrderPrintElem(tree *t, int depth, int tag) // tag = 1 means from lchild
{
    if(t==NULL)
        return --depth;
    depth = InOrderPrintElem(t->lchild, ++depth, 1);
    if(tag==1)
        printf("|depth:%d|L child|%d|\n", depth, t->data);
    else
        printf("|depth:%d|R child|%d|\n", depth, t->data);
    depth = InOrderPrintElem(t->rchild, ++depth, 0);
    return --depth;
}

int
PostOrderPrintElem(tree *t, int depth, int tag) // tag = 1 means from lchild
{
    if(t==NULL)
        return --depth;
    depth = PostOrderPrintElem(t->lchild, ++depth, 1);
    depth = PostOrderPrintElem(t->rchild, ++depth, 0);
    if(tag==1)
        printf("|depth:%d|L child|%d|\n", depth, t->data);
    else
        printf("|depth:%d|R child|%d|\n", depth, t->data);
    return --depth;
}

