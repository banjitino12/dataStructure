#include "cstdio"
#define MaxSize 100
typedef struct{
    int data[MaxSize];
    int length;
}SeqList; //静态申明顺序表
typedef enum {
    ERROR = 0,
    SUCCESS = 1,
} Status;

void initList(SeqList *L){
    for(int i = 0; i < MaxSize; i++){
        L->data[i] = 0;
    }
    L->length = 0;
}
Status GetElem(SeqList *L, int i, int *e){
    if(i > L->length) return ERROR;
    (*e) = L->data[i - 1];
    return SUCCESS;
}//时间复杂度O(1)
int LocateElem(SeqList *L, int e){
    for(int i = 0; i < L->length; i++){
        if(L->data[i] == e) return i + 1;
    }
    return 0;
}//时间复杂度O(n)
//在第i个元素处插入一个元素e
Status InsertElem(SeqList *L, int i, int e){
    if(i <= 0 || i > L->length + 1) return ERROR;
    if(L->length + 1 > MaxSize) return ERROR;
    for(int j = L->length - 1; j >= i - 1; j--){
        L->data[j + 1] = L->data[j]; //将第i个元素即以后的元素后移
    }
    L->data[i - 1] = e;
    L->length++;
    return SUCCESS;
}//时间复杂度O(n)
Status DeleteElem(SeqList *L, int i){
    if(i <= 0 || i > L->length) return ERROR;
    for(int j = i - 1; j < L->length; j++){
        L->data[j] = L->data[j + 1]; //将第i + 1个元素即以后的元素前移
    }
    L->length--;
    return SUCCESS;
}
void printList(SeqList *L){
    printf("Length of List: %d\n", L->length);
    printf("Elements in the List: ");
    for(int i = 0; i < L->length; i++){
        printf("%d ", L->data[i]);
    }
    printf("\n");
}
int main(){
    SeqList L;
    initList(&L);
    for(int i = 0; i < 9; i++){
        InsertElem(&L, i + 1, i + 1);
    }
    printList(&L);
    int e;
    GetElem(&L, 7, &e);
    printf("GetElem: %d\n", e);
    printf("LocateElem : %d\n", LocateElem(&L, 4));
    DeleteElem(&L, 9);
    printList(&L);



}