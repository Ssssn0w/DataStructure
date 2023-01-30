//
//  CycleLinkList.h
//  DataStructure
//  循环单链表
//  Created by Noth Amor on 2023/1/30.
//

#include <stdlib.h>

#ifndef CycleLinkList_h
#define CycleLinkList_h

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

// 初始化循环单链表
bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) {
        return false;
    }
    
    L->next = L;
    
    return true;
}

// 判断循环单链表是否为空
bool Empty(LinkList L) {
    return L->next == L;
}

// 判断节点p是否为循环单链表的表尾节点
bool IsTail(LinkList L, LNode *p) {
    return p->next == L;
}

#endif /* CycleLinkList_h */
