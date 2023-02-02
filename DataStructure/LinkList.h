//
//  LinkList.h
//  DataStructure
//  单链表
//  Created by Noth Amor on 2023/2/2.
//

#ifndef LinkList_h
#define LinkList_h

#include <iostream>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;

// 单链表初始化
bool InitLinkList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    if (L == NULL) {
        return false;
    }
    
    L->next = NULL;
    return true;
}

// 单链表判空
bool LinkListEmpty(LinkList L) {
    return L->next == NULL;
}

// 销毁单链表
void DestroyLinkList(LinkList &L) {
    free(L);
}

// 遍历输出单链表
void PrintLinkList(LinkList L) {
    if (L->next == NULL) {
        std::cout << "当前链表内无数据" << std::endl;
        return;
    }
    
    LNode *t = L->next;
    while (t != NULL) {
        std::cout << t->data;
        t = t->next;
    }
    std::cout << std::endl;
}

// 单链表尾插法
void LinkListInsert(LinkList &L, int x) {
    // 如果L只有头节点，没有后继节点
    if (L->next == NULL) {
        LNode *s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        L->next = s;
        return;
    }
    
    // L有后继节点
    LNode *t = L->next;
    while (t != NULL) {
        if (t->next == NULL) {
            LNode *s = (LNode *) malloc(sizeof(LNode));
            s->data = x;
            s->next = NULL;
            t->next = s;
            return;
        }
        
        t = t->next;
    }
}

void LinkListTest() {
    LinkList L;
    InitLinkList(L);
    
    LinkListInsert(L, 1);
    LinkListInsert(L, 3);
    LinkListInsert(L, 5);
    LinkListInsert(L, 7);
    
    //DestroyLinkList(L);
    
    PrintLinkList(L);
    
    //std::cout << "link list status(should be 1): " << initStatus << std::endl;
}

#endif /* LinkList_h */
