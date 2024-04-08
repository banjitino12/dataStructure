#include <iostream>
using namespace std;
#define MaxSize 20
typedef struct {
    int data[MaxSize];
    int top; //规定top指向栈顶元素
}sqStack;
void InitStack(sqStack &S){
    for(int i = 0; i < MaxSize; i++){
        S.data[i] = 0;
    }
    S.top = -1;
}
bool Push(sqStack &S, int x){
    if(S.top + 1 == MaxSize) return false;
    S.data[++S.top] = x;
    return true;
}
bool Pop(sqStack &S, int &x){
    if(S.top == -1) return false;
    x = S.data[S.top--];
    return true;
}
void ClearStack(sqStack &S){
    InitStack(S);
}
bool GetTop(sqStack S, int &x){
    if(S.top == -1) return false;
    x = S.data[S.top];
    return true;
}
bool StackEmpty(sqStack S){
    if(S.top == -1) return true;
    return false;
}
int StackLength(sqStack S){
    return S.top + 1;
}
int main(){
    sqStack stack;
    InitStack(stack);
    cout << StackEmpty(stack) << endl;
    int i = 0;
    while(Push(stack, i + 1)){
        i++;
        int tmp = 0;
        if(GetTop(stack, tmp)) cout << "Now the top of the stack is " << tmp << endl;
    }
    cout << "The Length of the sqStack is " <<StackLength(stack) << endl;
    cout << StackEmpty(stack) << endl;

    int tmp1 = 0;
    while(Pop(stack, tmp1)){
        cout << "Successfully pop "<< tmp1 << endl;
    }
    cout << StackEmpty(stack) << endl;

}