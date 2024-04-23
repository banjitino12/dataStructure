#include <iostream>
using namespace std;
#define MaxSize 100
typedef struct{
    int data[MaxSize];
    int top0;//规定top指针指向栈顶元素
    int top1;
}shStack;
void InitStack(shStack &S){
    for(int i = 0; i < MaxSize; i++){
        S.data[i] = 0;
    }
    S.top0 = -1;
    S.top1 = 100;
}
bool PushStack0(shStack &S, int x){
    if(S.top0 + 1 == S.top1) {
        cout << "The Sharing Stack is full" << endl;
        return false;
    }
    S.data[++S.top0] = x;
    return true;
}
bool PushStack1(shStack &S, int x){
    if(S.top1 - 1 == S.top0) {
        cout << "The Sharing Stack is full" << endl;
        return false;
    }
    S.data[--S.top1] = x;
    return true;
}
bool PopStack0(shStack &S, int &x){
    if(S.top0 == -1){
        cout << "Stack0 is empty" << endl;
        return false;
    }
    x = S.data[S.top0--];
    return true;
}
bool PopStack1(shStack &S, int &x){
    if(S.top1 == MaxSize){
        cout << "Stack1 is empty" << endl;
        return false;
    }
    x = S.data[S.top0++];
    return true;
}
void ClearStack(shStack &S){
    InitStack(S);
}
bool GetTop0(shStack S, int &x){
    if(S.top0 == -1) return false;
    x = S.data[S.top0];
    return true;
}
bool GetTop1(shStack S, int &x){
    if(S.top1 == MaxSize) return false;
    x = S.data[S.top1];
    return true;
}
bool StackEmpty(shStack S){
    if(S.top0 == -1 && S.top1 == MaxSize) return true;
    return false;
}
int StackLength(shStack S){
    return S.top0 + 1 + MaxSize - S.top1;
}
int main(){

}