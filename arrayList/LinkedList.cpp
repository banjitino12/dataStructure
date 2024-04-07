#include <iostream>
using namespace std;
typedef enum {
    ERROR = 0,
    SUCCESS = 1
} Status;
typedef struct LNode{
    int data;
    LNode *next;
}LNode, *LinkedList;

Status InitList(LinkedList &L){
    L = (LNode*) malloc(sizeof(LNode)); //创造空的头结点：造作统一（无需判断链表是否为空）
    if(L == nullptr) return ERROR;
    L->next = nullptr;
    return SUCCESS;
}
LNode *LocateElem(LinkedList L, int e){
    LNode *p = L->next;
    while(p != nullptr && p->data != e){
        p = p->next;
    }
    return  p;
}//获取值为e的结点地址,时间复杂度O(n)
int getElem(LinkedList L, int i){
    LNode *p = L->next;
    int index = 1;
    while(p != nullptr && index < i){
        index++;
        p=p->next;
    }
    if(p == nullptr || index > i) return ERROR;
    return p->data;
}//获得链表第i个元素，时间复杂度O(n)
Status InsertElem(LinkedList &L, int i, int e){
    LNode *p = L;
    int index = 0;//初始化为0 插入第一个的时候的前一个为0
    while(p != nullptr && index < i - 1){
        index++;
        p = p->next;
    }//找到第i-1个结点
    if(p == nullptr || i <= 0) return ERROR;//i 超出链表长度+1 或者 i <= 0
    LNode *s = (LNode*) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return SUCCESS;
}//在链表第i个位置插入元素， 时间复杂度O(n)
LNode *getNode(LinkedList L, int i){
    LNode *p = L->next;
    int index = 1;
    while(p != nullptr && index < i){
        index++;
        p=p->next;
    }
    if(p == nullptr || index > i) return nullptr;
    return p;
}
Status InsertNextNode(LNode *p, int e){
    if(p == nullptr) return ERROR;
    LNode *s =(LNode*) malloc(sizeof(LNode));
    if(s == nullptr) return ERROR;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return SUCCESS;
}//后插法，在给定结点的后面插入一个元素 时间复杂度O(1)
Status InsertPriorNode(LNode *p, int e){
    if(p == nullptr) return ERROR;
    LNode *s = (LNode*) malloc(sizeof(LNode));
    if(s == nullptr) return ERROR;
    s->data = p->data;
    s->next = p->next;
    p->next = s;
    p->data = e;//由于单链表没有前指针，所以找前继非常困难，所以可以先把元素插入到结点后面，再交互两者的数据
    return SUCCESS;
}
Status deleteElem(LinkedList &L, int i){
    LNode *p = L;
    int index = 0;
    while(p != nullptr && index < i - 1){
        index++;
        p = p->next;
    }
    if(p == nullptr || index > i - 1) return ERROR;
    LNode *q = p->next;
    p->next = p->next->next;
    delete(q);
    return SUCCESS;
}
void printList(LinkedList L){
    LNode *p = L->next;
    cout << "The LinkedList is : ";
    while(p != nullptr){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main(){
    LinkedList linkedList = new LNode();
    InitList(linkedList);
    for(int i = 0; i < 20; i++){
        InsertElem(linkedList, i + 1, i + 1);
    }
    printList(linkedList);
    cout << "The seventh element is " << getElem(linkedList, 7) << endl;
    cout << "The '7' is at the " << LocateElem(linkedList, 7)->data << "th of the whole linked list" << endl;
    cout << "Now delete the '7'" << endl;
    deleteElem(linkedList, 7);
    printList(linkedList);
    cout << "Now add '7' before '8'" << endl;
    InsertPriorNode(LocateElem(linkedList, 8), 7);
    printList(linkedList);
    cout << "Now delete the '7'" << endl;
    deleteElem(linkedList, 7);
    cout << "Now add '7' after '6'" << endl;
    InsertNextNode(LocateElem(linkedList, 6), 7);
    printList(linkedList);



}