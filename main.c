#include "llist.h"
#include <stdio.h>

void main()
{
    LkList *L = LkInitList(10);
    printf("---List---\n");
    LkPrintList(L);
    printf("---get---\n");
    ElemType *k = LkGetElem(L, 11);
    if(*k)
        printf("k = %d\n", *k);
    printf("---insert---\n");
    ElemType insertE = 100001;
    LkInsertElem(L, 11, &insertE);
    LkPrintList(L);
    printf("---pop---\n");
    ElemType *kk = LkPopElem(L, 10);
    if(kk)
        printf("kk = %d\n", *kk);
    LkPrintList(L);

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
