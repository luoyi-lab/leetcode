/* 对称二叉树 完整题目：
给你一个二叉树的根节点 root ，检查它是否轴对称

示例 1：
输入：root = [1,2,2,3,4,4,3]
        1
       / \
      2   2
     / \ / \
    3  4 4  3
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
        1
       / \
      2   2
       \   \
        3   3
输出：false
*/
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class SolutionRecursive 
{
// 💡 打包一个叫“递归解法”的工具箱。
public:
    // 辅助函数：专门用来对比两棵树是不是镜像
    bool check(TreeNode* left, TreeNode* right) 
    {
        // 💡 这里的 left 和 right 不是指左右孩子，而是指【左子树的根】和【右子树的根】
        
        if (!left && !right) return true;
        // 💡 防呆1：如果左树和右树同时都空了，说明这一对是完美的对称（都到底了），返回 true。
        
        if (!left || !right || left->val != right->val) return false;
        // 💡 防呆2：如果只有一个空了（一个有一个没有），或者两个的值不一样，那绝对不对称，直接判死刑。

        // 💡 核心魔法：互相照镜子！
        // 左边节点的【左】孩子，必须和右边节点的【右】孩子去对比。
        // 左边节点的【右】孩子，必须和右边节点的【左】孩子去对比。
        // 用 && 连接，说明这两个条件必须同时满足。
        return check(left->left, right->right) && check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true; 
        // 💡 如果传进来就是一棵空树，那它也是对称的。
        
        return check(root->left, root->right);
        // 💡 把根节点的左边和右边，丢给 check 函数去互相折磨。
    }
};

class SolutionIterative 
{
// 💡 打包一个叫“迭代解法”的工具箱。
public:
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;
        // 💡 空树直接返回 true。

        queue<TreeNode*> q;
        // 💡 准备一个排队用的队列。
        
        q.push(root->left);
        q.push(root->right);
        // 💡 把根节点的左边和右边，成双成对地塞进队列里。

        while (!q.empty()) {
        // 💡 只要队伍里还有人，就继续比。
            
            TreeNode* l = q.front(); q.pop();
            // 💡 拿出队伍里的第 1 个人，记为 l（代表左边的节点）。
            
            TreeNode* r = q.front(); q.pop();
            // 💡 拿出队伍里的第 2 个人，记为 r（代表右边的节点）。

            if (!l && !r) continue;
            // 💡 如果拿出来的这一对都是空的（都到底了），没问题，跳过本轮，去拿下一对。
            
            if (!l || !r || l->val != r->val) return false;
            // 💡 如果只有一个空，或者两个值不等，直接爆炸（返回 false）。

            // ⚠️ 灵魂入队顺序：必须是对称的！
            // 因为接下来要成对成对地拿出来对比，所以入队也要成对。
            q.push(l->left);   q.push(r->right);
            // 💡 把 l 的左边和 r 的右边，塞进队伍（这俩等会儿要比）。
            q.push(l->right);  q.push(r->left);
            // 💡 把 l 的右边和 r 的左边，塞进队伍（这俩等会儿要比）。
        }
        return true;
        // 💡 队伍清空，全比完了，没发现不对称，返回 true。
    }
};

int main() 
{
    // 示例 1：对称树 [1, 2, 2, 3, 4, 4, 3]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    // 示例 2：不对称树 [1, 2, 2, null, 3, null, 3]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);

    SolutionRecursive sol1;
    SolutionIterative sol2;

    cout << "示例1 (递归版): " << boolalpha << sol1.isSymmetric(root1) << endl; // true
    cout << "示例1 (迭代版): " << boolalpha << sol2.isSymmetric(root1) << endl; // true
    cout << "示例2 (递归版): " << boolalpha << sol1.isSymmetric(root2) << endl; // false
    cout << "示例2 (迭代版): " << boolalpha << sol2.isSymmetric(root2) << endl; // false

    return 0;
}