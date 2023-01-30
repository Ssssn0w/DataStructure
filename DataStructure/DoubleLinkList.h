//
//  DoubleLinkList.h
//  DataStructure
//  双链表
//  Created by Noth Amor on 2023/1/30.
//

#include <stdlib.h>

#ifndef DoubleLinkList_h
#define DoubleLinkList_h

typedef struct DNode {
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 初始化双链表
bool InitDLinkList(DLinkList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) {
        return false;
    }
    
    L->prior = NULL;
    L->next = NULL;
    
    return true;
}

// 判断双链表是否为空
bool LinkListEmpty(DLinkList L) {
    return L->next == NULL;
}

// 删除p节点的后继节点
bool DeleteNextNode(DNode *p) {
    if (p == NULL) {
        return false;
    }
    
    DNode *q = p->next;
    
    if (q == NULL) {
        return false;
    }
    
    p->next = q->next;
    if (p->next != NULL) {
        q->next->prior = p;
    }
    
    free(q);
    
    return true;
}

// 销毁双链表
void DestroyDLinkList(DLinkList &L) {
    while (L->next != NULL) {
        DeleteNextNode(L);
    }
    free(L);
    L = NULL;
}

// 在p节点之后插入s节点
bool InsertNextNode(DNode *p, DNode *s) {
    if (p == NULL || s == NULL) {
        return false;
    }
    
    s->next = p->next;
    if (p->next != NULL) {
        p->next->prior = s;
    }
    
    s->prior = p;
    p->next = s;
    
    return true;
}

#endif /* DoubleLinkList_h */
