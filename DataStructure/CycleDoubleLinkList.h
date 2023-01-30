//
//  CycleDoubleLinkList.h
//  DataStructure
//  循环双链表
//  Created by Noth Amor on 2023/1/30.
//

#include <stdlib.h>

#ifndef CycleDoubleLinkList_h
#define CycleDoubleLinkList_h

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

// 初始化空的循环双链表
bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) {
        return false;
    }
    
    L->prior = L;
    L->next = L;
    
    return true;
}

// 判断循环双链表是否为空
bool Empty(DLinkList L) {
    return L->next == L;
}

// 循环双链表在p节点之后插入s节点
bool InsertNextDNode(DNode *p, DNode *s) {
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 删除p的后继节点q
bool DeleteDNode(DNode *p) {
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}

#endif /* CycleDoubleLinkList_h */
