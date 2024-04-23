#include <iostream>
#include <stack>
#include <vector>

using namespace std;
#define MaxSize 100
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
class Solution{
public:
    //判断括号是够合法
    static bool checkValid(string s){
        stack<char> stack;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                stack.push(c);
            }else{
                if(stack.empty()){
                    return false;
                }
                char x = stack.top();
                if(c == ')'){
                    if(x == '('){
                        stack.pop();
                    }else{
                        return false;
                    }
                }else if(c == ']'){
                    if(x == '['){
                        stack.pop();
                    }else{
                        return false;
                    }
                }else if(c == '}'){
                    if(x == '{'){
                        stack.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }

    static void testStack(){
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
    int calculate(string expression) {
        stack<int> values;
        stack<char> ops;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == ' ') continue; //跳过空格
            else if (isdigit(expression[i])) {
                int value = 0;
                // 可能不是一位数
                while (i < expression.length() && isdigit(expression[i])) {
                    value = value * 10 + (expression[i] - '0');
                    i++;
                }
                values.push(value);
                i--;
            } else if (expression[i] == '(') {
                ops.push(expression[i]);
            } else if (expression[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    int right = values.top(); values.pop();
                    int left = values.top(); values.pop();
                    char op = ops.top(); ops.pop();
                    values.push(applyOp(left, right, op));
                }
                ops.pop();
            } else {
                // Current character is an operator.
                processOperators(values, ops, expression[i]);
                ops.push(expression[i]);
            }
        }
        while (!ops.empty()) {
            int right = values.top(); values.pop();
            int left = values.top(); values.pop();
            char op = ops.top(); ops.pop();
            values.push(applyOp(left, right, op));
        }

        return values.top();
    }
    void processOperators(stack<int>& values, stack<char>& ops, char currentOp) {
        while (!ops.empty() && precedence(ops.top()) >= precedence(currentOp)) {
            // 栈顶元素是右操作数
            int right = values.top();
            values.pop();
            int left = values.top();
            values.pop();
            char op = ops.top();
            ops.pop();
            values.push(applyOp(left, right, op));
        }
    }
    int applyOp(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b; // Add check for b == 0 if needed
        }
        return 0;
    }
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

};
int main(){
   string expression = "100 + 100";
   Solution s;
   cout << s.calculate(expression)<< endl;
}












