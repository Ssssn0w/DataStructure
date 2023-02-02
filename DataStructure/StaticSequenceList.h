//
//  StaticSequenceList.h
//  DataStructure
//  静态顺序表
//  Created by Noth Amor on 2023/1/31.
//

#ifndef StaticSequenceList_h
#define StaticSequenceList_h

// 静态顺序表
typedef struct {
    int data[10];
    int size;
    int length;
}SqList;

// 初始化静态顺序表
bool InitList(SqList &L) {
    L.length = 10;
    for (int i = 0; i < 10; i++) {
        L.data[i] = 0;
    }
    L.size = 0;
    return true;
}

// 求表长
int ListSize(SqList L) {
    return L.size;
}

// 顺序表判空
bool Empty(SqList L) {
    return L.size == 0;
}

// 销毁顺序表
bool DestroyList(SqList &L) {
    for (int i = 0; i < L.length; i++) {
        L.data[i] = 0;
    }
    L.length = 0;
    L.size = 0;
    
    return true;
}

// 循环输出顺序表
void PrintList(SqList L) {
    for (int i = 0; i < L.size; i++) {
        std::cout << L.data[i];
    }
    std::cout << std::endl;
}

// 按值查找
int LocateElem(SqList L, int element) {
    if (L.size == 0) {
        return -1;
    }
    
    int result = -1;
    
    for (int i = 0; i < 10; i++) {
        if (L.data[i] == element) {
            result = i;
        }
    }
    
    return result;
}

// 按位查找
int GetElem(SqList L, int i) {
    if (L.size == 0) {
        return -1;
    }
    
    if (i >= L.size) {
        return -1;
    }
    
    return L.data[i];
}

// 插入操作
bool ListInsert(SqList &L, int element) {
    if (L.size + 1 > L.length) {
        return false;
    }
    
    L.data[L.size++] = element;
    return true;
}

// 删除操作
bool ListDelete(SqList &L, int i) {
    if (i > L.size || i < 1) {
        return false;
    }
    
    for (int j = i; j < L.size; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.size--;
    
    return true;
}

// 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值，空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行
int DeleteMinimumElementInSequenceList(SqList &L, int &element) {
    if (L.size == 0) {
        std::cout << "The sequence list is empty, quiting..." << std::endl;
        return -1;
    }

    element = L.data[0];
    int index = -1;
    
    // 找出最小值和最小值的下标
    for (int i = 0; i < L.size; i++) {
        if (L.data[i] < element) {
            element = L.data[i];
            index = i;
        }
    }
    
    // 删除元素
    for (int temp = index + 1; temp < L.size; temp++) {
        L.data[temp - 1] = L.data[temp];
    }
    
    L.data[L.size - 1] = L.data[L.size - 2];
    L.size--;
    
    // 书上的方案居然是直接给值然后长度--, bug是如果最小值是最后一位就删不掉，而且直接长度--，最后一个元素直接丢了
    // L.data[index] = L.data[L.size - 1];
    
    return element;
}

// 设计一个高效算法，将顺序表L的所有元素逆置，要求算法空间复杂度为O(1)
void ReverseSequenceListElement(SqList &L) {
    int temp = 0;
    for (int i = 0; i < L.size / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.size - i - 1];
        L.data[L.size - i - 1] = temp;
    }
}

// 对长度为n的顺序表L，编写一个时间复杂度为O(n), 空间复杂度为O(1)的算法，该算法删除线性表中所有值为x的数据元素
void DeleteSpecifiedElementInSequenceList(SqList &L, int x) {
    int k = 0;
    for (int i = 0; i < L.size; i++) {
        if (L.data[i] != x) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.size = k;
}

// 从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行
void DeleteElementBetweenSAndT(SqList &L, int s, int t) {
    if (L.size == 0 || s >= t) {
        std::cout << "顺序表为空或参数不合理" << std::endl;
    }
    
    int k = 0;
    for (int i = 0; i < L.size; i++) {
        if (!(L.data[i] > s && L.data[i] < t)) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.size = k;
}

// 从顺序表中删除其值在给定值s与t之间（包含s和t，要求s<t）的所有元素，若s或t不合理或顺序表为空，则显示出错信息并退出运行
void DeleteElementBetweenSAndTWithItself(SqList &L, int s, int t) {
    if (L.size == 0 || s >= t) {
        std::cout << "顺序表为空或参数不合理" << std::endl;
    }
    
    int k = 0;
    for (int i = 0; i < L.size; i++) {
        if (!(L.data[i] >= s && L.data[i] <= t)) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.size = k;
}

// 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
void DropDuplicateElementInSequenceList(SqList &L) {
    if (L.size == 0) {
        std::cout << "顺序表未初始化" << std::endl;
    }

    int k = 0;
    for (int i = 0; i < L.size; i++) {
        if (L.data[i] != L.data[i + 1]) {
            L.data[k] = L.data[i];
            k++;
        }
    }
    
    L.size = k;
}

// 将两个有序顺序表合并成一个新的有序顺序表，并由函数返回结果顺序表
SqList MergeTwoOrderlySequenceList(SqList L1, SqList L2) {
    if (L1.size == 0 || L2.size == 0) {
        std::cout << "顺序表未初始化" << std::endl;
    }
    
    SqList result;
    
    int i = 0, j = 0, k = 0;
    while (i < L1.size && j < L2.size) {
        if (L1.data[i] <= L2.data[j]) {
            result.data[k++] = L1.data[i++];
        } else {
            result.data[k++] = L2.data[j++];
        }
    }
    
    while (i < L1.size) {
        result.data[k++] = L1.data[i++];
    }
    while (j < L2.size) {
        result.data[k++] = L2.data[j++];
    }
    result.size = k;
    return result;
}

// 

// 静态顺序表测试
void StaticSequenceListTest() {
    SqList L;
    
    bool initStatus = InitList(L);
    ListInsert(L, 5);
    ListInsert(L, 4);
    ListInsert(L, 3);
    ListInsert(L, 3);
    ListInsert(L, 2);
    ListInsert(L, 1);
    //int getElemTest = GetElem(L, 0);
    //int LocateElemTest = LocateElem(L, 5);
    //int listSize = ListSize(L);
    //bool deleteStatus = ListDelete(L, 2);
    //int element = 0;
    
    std::cout << "init status: " << initStatus << std::endl;
    //std::cout << "list size: " << listSize << std::endl;
    //std::cout << "get element test, should be 5: " << getElemTest << std::endl;
    //std::cout << "locate elem test, should be 0: " << LocateElemTest << std::endl;
    //std::cout << "delete status: " << deleteStatus << std::endl;
    //std::cout << "empty status: " << Empty(L) << std::endl;
    //std::cout << DeleteMinimumElementInSequenceList(L, element) << std::endl;
    
    SqList L1;
    SqList L2;
    
    L1.data[0] = 1;
    L1.data[1] = 3;
    L1.data[2] = 5;
    L1.data[3] = 7;
    L1.size = 4;
    
    L2.data[0] = 2;
    L2.data[1] = 4;
    L2.data[2] = 6;
    L2.data[3] = 8;
    L2.size = 4;
    
    for (int i = 0; i < L1.size; i++) {
        std::cout << L1.data[i];
    }
    std::cout << std::endl;
    
    for (int i = 0; i < L2.size; i++) {
        std::cout << L2.data[i];
    }
    std::cout << std::endl;

    //PrintList(L);
    //ReverseSequenceListElement(L);
    //DeleteSpecifiedElementInSequenceList(L, 4);
    //DeleteElementBetweenSAndT(L, 2, 4);
    //DeleteElementBetweenSAndTWithItself(L, 2, 4);
    //DropDuplicateElementInSequenceList(L);
    SqList result = MergeTwoOrderlySequenceList(L1, L2);
    PrintList(result);
    
    DestroyList(L);
}

#endif /* StaticSequenceList_h */
