#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int seriousProblems = 0;
    int normalProblems = 0;
    vector<string> children;
};

void sumProblems(unordered_map<string, Node>& tree, const string& node_id, int& totalSerious, int& totalNormal) {
    // 累加当前节点的问题数量
    totalSerious += tree[node_id].seriousProblems;
    totalNormal += tree[node_id].normalProblems;

    // 遍历所有子节点，递归累加问题数量
    for (const string& child : tree[node_id].children) {
        sumProblems(tree, child, totalSerious, totalNormal);
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    unordered_map<string, Node> tree;
    string root_id;

    for (int i = 0; i < N; ++i) {
        string Ai, Bi;
        int Ci, Di;
        cin >> Ai >> Bi >> Ci >> Di;

        if (Bi == "*") {
            root_id = Ai;
        } else {
            tree[Bi].children.push_back(Ai);
        }

        if (Ci == 0) {
            tree[Ai].seriousProblems += Di;
        } else {
            tree[Ai].normalProblems += Di;
        }
    }

    int riskCount = 0;

    // 遍历所有云服务节点
    for (auto& [node_id, node] : tree) {
        int totalSerious = 0;
        int totalNormal = 0;

        // 为当前节点计算所有累计问题
        sumProblems(tree, node_id, totalSerious, totalNormal);

        // 计算DI值
        int DI = 5 * totalSerious + 2 * totalNormal;

        // 判断是否为风险云服务
        if (DI > M) {
            riskCount++;
        }
    }

    cout << riskCount << endl;

    return 0;
}
