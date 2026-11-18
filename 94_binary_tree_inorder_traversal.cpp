/* 二叉树的中序遍历 完整题目：
给定一个二叉树的根节点 root，返回它的中序遍历
中序遍历（左 -> 根 -> 右） 前序能弹出就记录，中序不行 —— 因为一个节点必须先走完左子树才能记录自己

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]
*/
#include <iostream>  // C++的输入输出工具
#include <vector>  // 动态数组工具
#include <stack>  // 栈工具
using namespace std;  // 把标准库的“公共前缀（std::）”免了

// 1.定义二叉树节点结构体
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    //  val(x)：把传进来的 5 塞给 val
};

// 版本一 递归法
class SolutionRecursive
{
public:
    void dfs(TreeNode* node, vector<int>& ans)
    {
        if(node == nullptr) return; // 防呆：遇到空节点返回

        dfs(node->left, ans);  // 左 先去左边一路向下  没有->left了 就代表左边处理完了
        ans.push_back(node->val); // 根 左边转完了 再把自己记录下来
        dfs(node->right, ans);  // 右：最后去右边一路向下
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

// 版本二 迭代法  一路向左压到底
class SolutionIterative
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<TreeNode*> stk;  // 准备一个“等候室（栈）”。里面存的是还没到记录时机的节点地址
        TreeNode* cur = root;  // 派一个探路小人叫 cur，让他站在最一开始的根节点

        // 只要指针还没走到尽头，或者栈里还有没处理完的节点，就继续
        while(cur != nullptr || !stk.empty())
        {
            // 1. 一路向左，压栈
            while(cur != nullptr)
            {
                stk.push(cur);   // 把当前节点存起来（以后要回溯）
                cur = cur->left; // 游标疯狂向左下角钻
            }
            // 2. 左边到底了，弹栈并记录
            cur = stk.top();         // 看看等候室最上面的那个倒霉蛋是谁。此时它就是最左边的节点  栈顶元素的值（地址）复制给了 cur。此时，栈里的元素并没有少  而且此步骤也让cur慢慢往上移动
            // 上述步骤也让cur慢慢往上移动
            stk.pop();               // 弹出
            ans.push_back(cur->val); // 这个时候才能真正记录它！
            
            // 3. 转向右子树
            cur = cur->right;
        }

        return ans;
    }
};

// 测试主函数
int main() {
    // 构造图里的示例 1： root = [1, null, 2, 3]
    //       1
    //        \
    //         2
    //        /
    //       3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // 测试递归版
    SolutionRecursive sol1;
    vector<int> res1 = sol1.inorderTraversal(root);
    cout << "递归版输出: [";
    for (int i = 0; i < res1.size(); i++) {
        cout << res1[i] << (i == res1.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    // 测试迭代版
    SolutionIterative sol2;
    vector<int> res2 = sol2.inorderTraversal(root);
    cout << "迭代版输出: [";
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i] << (i == res2.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}
