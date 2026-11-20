/*  二叉树的最大深度 完整题目:
给定一个二叉树root，返回其最大深度
二叉树的最大深度是指从根节点到最远叶子节点的最长路径上的节点数
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

// 版本一 递归法
class SolutionRecursive
{
public:
    int maxDepth(TreeNode* root)
    {
        if(!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;  //向左右索要高度 谁高选谁 最后再加上自己这一层
    }
};

// 版本二 迭代法 层序遍历
class SolutionIterative
{
public:
    int maxDepth(TreeNode* root)
    {
        if(!root) return 0;
        queue<TreeNode*> q;  // 创建一个队列 q  queue 的特点是“先进先出”（FIFO）
        q.push(root);  // 把第一层的根节点（包工头）放进队伍里
        int depth = 0;

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};

/* 例子：
树形：

text
      3         <-- 第 1 层
     / \
    9  20       <-- 第 2 层
       / \
      15  7     <-- 第 3 层
初始状态：q = [3]，depth = 0。

第一轮外层循环：

q.size() 是 1。

内层循环执行 1 次：拿出 3。把 9 和 20 塞进队伍。

此时 q = [9, 20]。

内层结束，depth 变成 1。

第二轮外层循环：

q.size() 是 2。

内层循环执行 2 次：

拿出 9（没儿子）。
拿出 20（把 15 和 7 塞进队伍）。

此时 q = [15, 7]。

内层结束，depth 变成 2。

第三轮外层循环：

q.size() 是 2。

内层循环执行 2 次：

拿出 15（没儿子）。

拿出 7（没儿子）。

此时 q = []。

内层结束，depth 变成 3。

循环结束：队伍空了，返回 depth = 3
*/
int main()
{
    // 构造示例1：[3, 9, 20, null, null, 15, 7]
    //       3
    //      / \
    //     9  20
    //        / \
    //       15  7 
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    SolutionRecursive sol1;
    cout << "递归版最大深度: " << sol1.maxDepth(root) << endl; // 3

    SolutionIterative sol2;
    cout << "迭代版最大深度: " << sol2.maxDepth(root) << endl; // 3

    return 0;
}