#include <iostream>
using namespace std;

int main() {
    std::string s;
    cin >> s;
}
int isBinary(string s, int i, int j){
    if(i == j) return 1;
    if(isBinary(s, i + 1, j) || isBinary(s, i, j - 1)){
        return j - i;
    }
}