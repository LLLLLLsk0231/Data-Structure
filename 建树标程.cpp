#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int n;
    if (!(cin >> n) || n == 0) return 0;

    vector<TreeNode*> nodes(n + 1, nullptr);
    // 增加一个数组，记录某个节点是否有父节点，用来找根节点
    vector<bool> has_parent(n + 1, false); 
    
    // 1. 提前把所有 n 个节点 new 出来
    for (int i = 1; i <= n; ++i) {
        nodes[i] = new TreeNode(0);
    }

    // 2. 处理可能乱序的输入
    for (int i = 1; i <= n; ++i) {
        int id, left_idx, right_idx;
        // 假设这里输入的第一个数字既是节点的值，也是它的唯一编号 id
        cin >> id >> left_idx >> right_idx;
        
        // 直接使用 id 去索引数组，完美解决乱序问题！
        nodes[id]->val = id; 
        
        if (left_idx != 0) {
            nodes[id]->left = nodes[left_idx];
            has_parent[left_idx] = true; // 标记左孩子已经有爸爸了
        }
        if (right_idx != 0) {
            nodes[id]->right = nodes[right_idx];
            has_parent[right_idx] = true; // 标记右孩子已经有爸爸了
        }
    }

    // 3. 寻找真正的根节点（没有父节点的那个节点）
    TreeNode* root = nullptr;
    for (int i = 1; i <= n; ++i) {
        if (!has_parent[i]) {
            root = nodes[i];
            break; // 找到了就退出循环
        }
    }

    // 4. 执行前序遍历并输出
    preorderTraversal(root);
    cout << endl;

    // 释放内存
    for (int i = 1; i <= n; ++i) {
        delete nodes[i];
    }

    return 0;
}