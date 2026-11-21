/* 翻转二叉树 完整题目：
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点

示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

示例 2：
输入：root = [2,1,3]
输出：[2,3,1]

示例 3：
输入：root = []
输出：[]

核心逻辑极其简单：把树里每一个节点的左孩子和右孩子互换一下

对于每一个节点，我们只需要干三件事：
1.把它的左孩子和右孩子交换
2.让左子树自己内部去翻转
3.让右子树自己内部去翻转

*/
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

// 版本一 递归法 
class SolutionRecursive
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(root == nullptr) return nullptr;

        // 交换左右孩子
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // 递归翻转
        invertTree(root->left); // 让左子树自己内部去翻转
        invertTree(root->right); // 让右子树自己内部去翻转

        return root;
    }
};

// 版本二 迭代法
class SolutionIterative
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(root == nullptr) return nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();  // 看一眼队伍最前面（队头）站着谁
            q.pop();  // 看完让它离开队列

            // 交换左右
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;

            // 孩子入队
            if(node->left) q.push(node->left);  // 如果这个节点有左孩子，把他排到队伍尾巴
            if(node->right) q.push(node->right);  // 如果这个节点有右孩子，把他排到队伍尾巴
            // 这样等当前这一层的人处理完，下一层的人就已经排好队在等了
        }
        return root;
    }
};

// 辅助打印函数（层序打印）
void printTree(TreeNode* root)
{
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

// ==========================================
// 测试主函数（双版本对比）
// ==========================================
int main() {
    // ==========================================
    // 测试一：递归版
    // ==========================================
    // 构造示例 1： [4, 2, 7, 1, 3, 6, 9]
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(9);

    cout << "【递归版】" << endl;
    cout << "翻转前: ";
    printTree(root1); 

    SolutionRecursive sol1;
    TreeNode* invertedRoot1 = sol1.invertTree(root1);
    
    cout << "翻转后: ";
    printTree(invertedRoot1); 
    cout << "-------------------" << endl;


    // ==========================================
    // 测试二：迭代版
    // ==========================================
    // ⚠️ 必须重新建一棵树！因为上面那棵树已经被递归版修改了，直接传进去会变回原样。
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(7);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    root2->right->left = new TreeNode(6);
    root2->right->right = new TreeNode(9);

    cout << "【迭代版】" << endl;
    cout << "翻转前: ";
    printTree(root2); 

    SolutionIterative sol2;
    TreeNode* invertedRoot2 = sol2.invertTree(root2);
    
    cout << "翻转后: ";
    printTree(invertedRoot2); 

    return 0;
}