/* 二叉树的后序遍历 完整题目：
给你一棵二叉树的根节点 root ，返回它节点值的 后序 遍历
左右根

示例 1：
输入：root = [1,null,2,3]
输出：[3,2,1]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[2,1]

示例 5：
输入：root = [1,null,2]
输出：[2,1]
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // 为了使用 reverse 函数
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 版本一 递归法：
class SolutionRecursive
{
public:
    void dfs(TreeNode* node, vector<int>& ans)
    {
        if(node == nullptr) return;
        dfs(node->left, ans);
        dfs(node->right, ans);
        ans.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

// 版本二 迭代法 反转大法
class SolutionIterative
{
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        if(!root) return ans; // 如果树是空的，直接交空篮子

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);

            // 先左后右
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }

        reverse(ans.begin(), ans.end());  // 刚才得到的是【根右左】，把它反转一下，瞬间变成完美的【左右根】
        return ans;
    }
};

int main()
{
    // 构造示例 1
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    SolutionRecursive sol1;
    vector<int> res1 = sol1.postorderTraversal(root);
    cout << "递归版: [";
    for (int i = 0; i < res1.size(); i++) cout << res1[i] << (i == res1.size()-1 ? "" : ", ");
    cout << "]" << endl;

    SolutionIterative sol2;
    vector<int> res2 = sol2.postorderTraversal(root);
    cout << "迭代版: [";
    for (int i = 0; i < res2.size(); i++) cout << res2[i] << (i == res2.size()-1 ? "" : ", ");
    cout << "]" << endl;

    return 0;
}   