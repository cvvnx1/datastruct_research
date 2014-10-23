//#include "llist.h"
//#include "stack.h"
#include "lib.h"
#include "btree.h"
#include <stdio.h>

void main()
{
    tree *T = RootInit();
    elem i;
    for(i=0;i<20;i++)
        InsertElem(T, NumberRandom(-50, 50));
    printf("---PreOrderPrintElem---\n");
    PreOrderPrintElem(T, 1, 1);
    printf("---InOrderPrintElem---\n");
    InOrderPrintElem(T, 1, 1);
    printf("---PostOrderPrintElem---\n");
    PostOrderPrintElem(T, 1, 1);

/* --- LkStack example
    LkStack *S = LkInit();
    SElemType e;
    for(e=10;e<15;e++)
        LkPush(S, &e);
    printf("---Stack---\n");
    LkPrintElem(S);
*/

/* --- SqdStack example
    SqdStack *S = SqdInit();
    SElemType e;
    for(e=1000;e<1005;e++)
        SqdPush(S, 1, &e);
    for(e=1000;e<1008;e++)
        SqdPush(S, 2, &e);
    printf("---Stack---\n");
    SqdPrintElem(S);
    printf("---pop---\n");
    SElemType f;
    for(e=0;e<100;e++)
    {
        f = SqdPop(S, 1);
        if(f==-1)
        {
            break;
        } else {
            printf("f for top1:%d\n", f);
        }
    }
    for(e=0;e<100;e++)
    {
        f = SqdPop(S, 2);
        if(f==-1)
        {
            break;
        } else {
            printf("f for top2:%d\n", f);
        }
    }
    SqdPrintElem(S);
*/

/* --- SqStack example
    SqStack *S = SqInit();
    printf("stack full?%d\n", SqIsFull(S));
    SElemType e;
    for(e=0;e<100;e++)
        SqPush(S, &e);
    printf("---Stack---\n");
    SqPrintElem(S);
    printf("stack full?%d\n", SqIsFull(S));
    printf("---pop---\n");
    e = SqPop(S);
    if(e!=-1)
        printf("e:%d\n", e);
    SqPrintElem(S);
*/

/* --- LkList example
    LkList *L = LkInitList(10);
    printf("---List---\n");
    LkPrintList(L);
    printf("---get---\n");
    ElemType *k = LkGetElem(L, 1);
    if(*k)
        printf("k = %d\n", *k);
    printf("---insert---\n");
    ElemType insertE = 100001;
    LkInsertElem(L, 1, &insertE);
    LkPrintList(L);
    printf("---pop---\n");
    ElemType *kk = LkPopElem(L, 1);
    if(kk)
        printf("kk = %d\n", *kk);
    LkPrintList(L);
*/

/* ---  SqList example
    SqList *L = SqInitList(10);
    printf("---List---\n");
    SqPrintList(L);
    printf("---get---\n");
    ElemType *k = SqGetElem(L, 5);
    if(k)
        printf("k = %d\n", *k);
    printf("---insert---\n");
    ElemType insertE = 100001;
    SqInsertElem(L, 3, &insertE);
    SqPrintList(L);
    printf("---pop---\n");
    ElemType *kk = SqPopElem(L, 7);
    if(kk)
        printf("kk = %d\n", *kk);
    SqPrintList(L);
*/
}
