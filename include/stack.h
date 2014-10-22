#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAXSIZE 100

/*
    Seq stack
*/
typedef int SElemType;

typedef struct SqStack
{
    SElemType data[MAXSIZE];
    int top;
    int size;
} SqStack;

SqStack *
SqInit()
{
    SqStack *s = malloc(sizeof(SqStack));
    s->top = -1;
    s->size = MAXSIZE-1;

    return s;
}

int
SqIsFull(SqStack *S)
{
    if(!S || S->top==S->size)
        return TRUE;
    else
        return FALSE;
}

int
SqPush(SqStack *S, SElemType *e)
{
    if(!S || !e || S->top>MAXSIZE-2)
        return FALSE;

    S->data[++S->top] = *e;
    return TRUE;
}

SElemType
SqPop(SqStack *S)
{
    if(!S || S->top<0)
        return -1;

    SElemType e = S->data[S->top];
    S->top--;
    return e;
}

void
SqPrintElem(SqStack *S)
{
    if(!S)
        return;

    int j;
    for(j=S->top;j>-1;j--)
    {
        printf("%d -> | %d |\n", j, S->data[j]);
    }
}

/*
    Seq double stack
*/
typedef struct SqdStack
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
    int size;
} SqdStack;

SqdStack *
SqdInit()
{
    SqdStack *s = malloc(sizeof(SqdStack));
    s->size = MAXSIZE - 1;
    s->top1 = -1;
    s->top2 = s->size + 1;
}

int
SqdIsFull(SqdStack *s)
{
    if(!s)
        return TRUE;

    if((s->top1+1)==s->top2)
        return TRUE;
    else
        return FALSE;
}

int
SqdPush(SqdStack *s, int StackNumber, SElemType *e)
{
    if(!s || SqdIsFull(s))
        return FALSE;

    if(StackNumber==1)
    {
        s->top1++;
        s->data[s->top1] = *e;
        return TRUE;
    }

    if(StackNumber==2)
    {
        s->top2--;
        s->data[s->top2] = *e;
        return TRUE;
    }

    return FALSE;
}

SElemType
SqdPop(SqdStack *s, int StackNumber)
{
    if(!s)
        return -1;

    if(StackNumber==1 && s->top1>-1)
        return s->data[s->top1--];

    if(StackNumber==2 && (s->top2)<(s->size+1))
        return s->data[s->top2++];

    return -1;
}

void
SqdPrintElem(SqdStack *s)
{
    if(!s)
        return;

    int j;
    printf("top1 -\n");
    for(j=s->top1;j>0;j--)
        printf("%d -> | %d |\n", j, s->data[j]);

    printf("top2 -\n");
    for (j=s->top2;j<s->size+1;j++)
        printf("%d -> | %d |\n", j, s->data[j]);
}

