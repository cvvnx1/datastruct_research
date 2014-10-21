#include <stdio.h>
#include <stdlib.h>

/*
  line list func
*/
#define MAXSIZE 100

typedef int Status;

typedef int ElemType;

typedef struct _SqList
{
    ElemType data[MAXSIZE];
    int length;
} SqList;

ElemType *
SqGetElem(SqList *L, int i)
{
    if(L->length==0 || i<1 || i>L->length)
        return NULL;

    return &L->data[i-1];
}


void
SqInsertElem(SqList *L, int i, ElemType *e)
{
    if(!L || i<1 || L->length>MAXSIZE-1 || i>L->length)
        return;

    int j;
    for(j=L->length-1;j>=i-1;j--)
    {
        L->data[j+1] = L->data[j];
    }

    L->data[i-1] = *e;
    L->length++;
}

ElemType *
SqPopElem(SqList *L, int i)
{
    if(!L || L->length<1 || i<1 || i>L->length)
        return NULL;

    int j;
    for(j=i-1;j<L->length-1;j++)
    {
        L->data[j] = L->data[j+1];
    }
    L->length--;
}

SqList *
SqInitList(int i)
{
    if(i<1 || i>MAXSIZE)
        return NULL;

    SqList *L = malloc(sizeof(SqList));
    int j;
    for(j=0;j<i;j++){
        L->data[j] = j;
    }
    L->length = i;
    return L;
}

void
SqPrintList(SqList *L)
{
    if(L)
    {
        int j;
        for(j=0;j<L->length;j++)
        {
            printf("| %d ", L->data[j]);
        }
        printf("|\n");
    }
}

/*
  link list func
*/
typedef struct LkNode
{
    struct LkNode *next;
    ElemType data;
} LkNode;

typedef struct LkNode LkList; // begin link
/*
LkNode *_LkLocateElemFront(LkList *L, int i);
ElemType *LkGetElem(LkList *L, int i);
void LkInsertElem(LkList *L, int i, ElemType *e);
ElemType *LkPopElem(LkList *L, int i);
SqList *LkInitList(int i);
void LkPrintList(LkList *L);
*/
// do not check in internal func
LkNode *
_LkLocateElemFront(LkList *L, int i)
{
    int j = 1;
    LkNode *op = L->next;
    while(op->next && j++ < i-1)
    {
        op = op->next;
    }
    return op;
}

ElemType *
LkGetElem(LkList *L, int i)
{
    if(!L || i<1)
        return NULL;

    LkNode *op = _LkLocateElemFront(L, i);
    return &(op->next)->data;
}

void
LkInsertElem(LkList *L, int i, ElemType *e)
{
    if(!L || i<1 || !e)
        return;

    LkNode *op = _LkLocateElemFront(L, i);
    if(!op->next)
        return;
    LkNode *q = malloc(sizeof(LkNode));
    q->next = op->next;
    q->data = *e;
    op->next = q;
}

ElemType *
LkPopElem(LkList *L, int i)
{
    if(!L || i<1)
        return NULL;

    LkNode *op = _LkLocateElemFront(L, i);
    if(!op->next)
        return NULL;
    ElemType *element = &(op->next)->data;
    op->next = (op->next)->next;
    return element;
}

LkList *
LkInitList(int i)
{
    if(i<1)
        return NULL;

    int j;
    LkList *L = malloc(sizeof(LkList));
    L->next = NULL;
    L->data = 0;
    for(j=i;j>-1;j--)
    {
        LkNode *op = malloc(sizeof(LkNode));
        op->next = (LkNode *)L;
        op->data = j;
        L = (LkList *) op;
    }
    return L;
}

void
LkPrintList(LkList *L)
{
    if(!L)
        return;

    int j = 1;
    LkNode *op = L->next;
    while(op->next)
    {
        printf("Node %d | self:%p | next:%p | value:%d\n", j++, op, op->next, op->data);
        op = op->next;
    }
}

