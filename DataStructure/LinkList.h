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

// 求单链表表长
int LinkListLength(LinkList L) {
    if (L->next == NULL) {
        return 0;
    }
    
    int count = 0;
    LNode *t = L->next;
    while (t != NULL) {
        count++;
        t = t->next;
    }
    
    return count;
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

// 按值查找节点
LNode * LinkListSearchByValue(LinkList L, int x) {
    LNode *t = L->next;
    
    if (LinkListEmpty(L)) {
        std::cout << "单链表空" << std::endl;
        return t;
    }

    while (t != NULL) {
        if (t->data == x) {
            return t;
        }
        t = t->next;
    }
    
    std::cout << "单链表中未找到满足要求的值" << std::endl;
    return t;
}

// 按序号查找节点
LNode * LinkListSearchByIndex(LinkList L, int i) {
    LNode *t = L->next;
    
    if (LinkListEmpty(L)) {
        std::cout << "单链表空" << std::endl;
        return t;
    }
    
    int j = 1;
    while (j < i && t != NULL) {
        t = t->next;
        j++;
    }
    
    return t;
}

// 按值删除节点
void DeleteLNodeByValue(LinkList &L, int x) {
    if (LinkListEmpty(L)) {
        std::cout << "单链表空" << std::endl;
        return;
    }
    
    LNode *t = L->next;
    while (t != NULL) {
        if (t->next->data == x) {
            t->next = t->next->next;
            return;
        }
        t = t->next;
    }
}

// 按序号删除节点
void DeleteLNodeByIndex(LinkList &L, int i) {
    if (LinkListEmpty(L)) {
        std::cout << "单链表空" << std::endl;
        return;
    }
    
    int j = 1;
    LNode *t = L->next;
    while (t != NULL) {
        if (j + 1 == i) {
            t->next = t->next->next;
            return;
        }
        j++;
        t = t->next;
    }
    
    return;
}

// 设计一个递归算法，删除不带头节点的单链表L中所有值为x的节点

// 在带头节点的单链表，删除所有值为x的节点，并释放其空间，假设值为x的节点不唯一，试编写算法以实现上述操作
void DeleteAndFreeLNodeByValue(LinkList &L, int x) {
    if (LinkListEmpty(L)) {
        std::cout << "单链表为空" << std::endl;
        return;
    }
    
    LNode *p = L->next, *pre = L, *q;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = pre->next;
            p = p->next;
        }
    }
}

// 设L为带头节点的单链表，编写算法实现从尾到头反向输出每个节点的值
void ReversePrintLinkList(LinkList L) {
    if (L->next != NULL) {
        ReversePrintLinkList(L->next);
    }
    if (L != NULL) {
        std::cout << L->data;
    }
}

// 试编写在带头节点的单链表L中删除一个最小值节点的高效算法（假设最小值节点是唯一的）
void DropMinimumLNodeInLinkList(LinkList &L) {
    if (LinkListEmpty(L)) {
        std::cout << "单链表为空" << std::endl;
        return;
    }
    
//    int minimum = L->next->data;
//    LNode *p = L->next, *pre = L, *q;
//    while (p != NULL) {
//        if (p->data < minimum) {
//            minimum = p->data;
//        }
//        p = p->next;
//    }
//
//    p = L->next;
//    while (p != NULL) {
//        if (p->data == minimum) {
//            q = p;
//            p = p->next;
//            pre->next = p;
//            free(q);
//        } else {
//            pre = pre->next;
//            p = p->next;
//        }
//    }

    
    LNode *p = L->next, *pre = L, *minNode = p, *minPre = pre;
    while (p != NULL) {
        if (p->data < minNode->data) {
            minNode = p;
            minPre = pre;
        }
        pre = pre->next;
        p = p->next;
    }
    
    minPre->next = minNode->next;
    free(minNode);
}

// ******(还没太整明白) 试编写算法将带头节点的单链表就地逆置，所谓"就地"是指辅助空间复杂度为O(1)
void ReverseLinkList(LinkList &L) {
    LNode *p = L->next, *r;
    L->next = NULL;
    while (p != NULL) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
}

// 有一个带头节点的单链表L，设计一个算法使其元素递增有序
void SortLinkList(LinkList &L) {
    int linkListSize = 0;
    LNode *t = L->next;
    while (t != NULL) {
        linkListSize++;
        t = t->next;
    }
    
    int temp = 0;
    LNode *p = L->next, *pre = L;
    for (int i = 0; i < linkListSize; i++) {
        pre = L;
        p = L->next;
        for (int j = 0; j < linkListSize - i; j++) {
            if (pre->data > p->data) {
                temp = pre->data;
                pre->data = p->data;
                p->data = temp;
            }
            p = p->next;
            pre = pre->next;
        }
    }
}

// 设在一个带表头节点的单链表中所有元素节点的数据值无序，试编写一个函数，删除表中所有介于给定的两个值之间的元素的元素（若存在）
void DropValueBetweenSAndTInLinkList(LinkList &L, int s, int t) {
    LNode *p = L->next, *pre = L;
    while (p != NULL) {
        if (p->data > s && p->data < t) {
            pre->next = p->next;
        }
        
        p = p->next;
        pre = pre->next;
    }
}

// 给定两个单链表，编写算法找出两个链表的公共节点
void FindCommonNodeInTwoLinkList(LinkList L1, LinkList L2) {
    LNode *p = L1->next, *t = L2->next;
    while (p != NULL) {
        t = L2->next;
        while (t != NULL) {
            if (p->data == t->data) {
                std::cout << p->data << " ";
            }
            t = t->next;
        }
        p = p->next;
    }
    std::cout << std::endl;
}

// 给定一个带表头节点的单链表，设head为头指针，节点结构为(data,next), data为整型元素，next为指针，试写出算法：按递增次序输出单链表中各节点的数据元素，并释放节点所占的存储空间(要求：不允许使用数组作为辅助空间)
void IncrementalPrintLinkListElement(LinkList L) {
    while (L->next != NULL) {
        LNode *p = L->next, *pre = L, *u;
        while (p->next != NULL) {
            if (p->next->data < pre->next->data) {
                pre = p;
            }
            p = p->next;
        }
        
        std::cout << pre->next->data << " ";
        u = pre->next;
        pre->next = u->next;
        free(u);
    }
    std::cout << std::endl;
    free(L);
}

void LinkListTest() {
    LinkList L;
    LinkList L2;
    InitLinkList(L);
    InitLinkList(L2);
    
    LinkListInsert(L, 7);
    LinkListInsert(L, 5);
    LinkListInsert(L, 3);
    LinkListInsert(L, 1);
    
    LinkListInsert(L2, 1);
    LinkListInsert(L2, 3);
    
    //int length = LinkListLength(L);
    //LinkListSearchByValue(L, 3);
    //LNode *t = LinkListSearchByIndex(L, 2);
    
    //DeleteLNodeByIndex(L, 4);
    //DeleteAndFreeLNodeByValue(L, 3);
    //ReversePrintLinkList(L);
    //DropMinimumLNodeInLinkList(L);
    //ReverseLinkList(L);
    //SortLinkList(L);
    //DropValueBetweenSAndTInLinkList(L, 1, 5);
    //FindCommonNodeInTwoLinkList(L, L2);
    IncrementalPrintLinkListElement(L);

    //std::cout << t->data << std::endl;
    //std::cout << length << std::endl;
    PrintLinkList(L);
    
    //std::cout << "link list status(should be 1): " << initStatus << std::endl;
}

#endif /* LinkList_h */
