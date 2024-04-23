#include <iostream>
using namespace std;
#define MaxSize 20
typedef struct {
    int data[MaxSize];
    int rear;//定义尾指针指向队列的尾部元素的下一个位置
    int front;//定义头指针指向队列的头元素
    int tag;//标记位 入队为1 出队为0
    int length;
}sqQueue;
void InitQueue(sqQueue &Q){
    for(int i = 0; i < MaxSize; i++){
        Q.data[i] = 0;
    }
    Q.length = 0;
    Q.tag = 0;
    Q.front = Q.rear = 0;
}
int QueueLength(sqQueue Q){
    cout << "The length of the queue is " << Q.rear - Q.front << endl;
    return Q.rear - Q.front;
}
bool QueueEmpty(sqQueue &Q){
    if((Q.rear == Q.front && Q.tag == 0) || Q.length == 0) {
        cout << "The Queue is Empty" << endl;
        return true;
    }
    cout << "The Queue is not Empty" << endl;
    return false;
}
bool EnQueue(sqQueue &Q, int x){
    if((Q.rear == Q.front && Q.tag == 1) || Q.length == MaxSize){
        cout << "The Queue is full" << endl;
        return false;
    }
    Q.length++;
    Q.tag = 1;
    Q.data[Q.rear] = x;
    //Q.rear++
    Q.rear = (Q.rear + 1) % MaxSize;//循环队列
    return true;
}
bool deQueue(sqQueue &Q, int &x){
    if((Q.rear == Q.front && Q.tag == 0) || Q.length == 0){
        cout << "The Queue is Empty" << endl;
        return false;
    }
    Q.length--;
    Q.tag = 0;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
bool GetHead(sqQueue Q, int &x){
    if((Q.rear == Q.front && Q.tag == 0) || Q.length == 0){
        cout << "The Queue is Empty" << endl;
        return false;
    }
    x = Q.data[Q.front];
    return true;
}
int main(){
    sqQueue queue;
    InitQueue(queue);
    int i = 0;
    QueueEmpty(queue);
    while(EnQueue(queue, i + 1)){
        i++;
    }
    QueueEmpty(queue);
    QueueLength(queue);
    int tmp1 = 0;
    while(deQueue(queue ,tmp1)){
        int tmp = 0;
        if(GetHead(queue, tmp)) cout << tmp << " ";
    }

    QueueEmpty(queue);


}
