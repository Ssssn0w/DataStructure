#include <iostream>
#include <stdlib.h>
#include "StaticSequenceList.h"

using namespace std;

// 静态链表
typedef struct {
    int data;
    int next;
} SLinkList[10];

int main() {
    StaticSequenceListTest();
    
    return 0;
}
