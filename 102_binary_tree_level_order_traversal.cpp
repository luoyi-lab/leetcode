/* 二叉树的层序遍历 完整题目：
给你二叉树的根节点 root，返回其节点值的 层序遍历。（即逐层地，从左到右访问所有节点）。

和前/中/后序不一样：那三个是「一路往下钻到底」（深度优先），
这个是一层一层横扫过去（广度优先），所以要用【队列】，不能用栈。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]

        3
       / \
      9   20
         /  \
        15   7

示例 2：
输入：root = [1]
输出：[[1]]

示例 3：
输入：root = []
输出：[]

提示：
树中节点数目在范围 [0, 2000] 内
-1000 <= Node.val <= 1000
*/
#include <iostream>
#include <vector>
#include <queue>   // 队列工具。层序遍历的主角，先进先出
using namespace std;

// 1.定义二叉树节点结构体
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 版本一 递归法（DFS + 深度标记）
// 和 144/94/145 的区别就一个：dfs 要多带一个 depth 参数，
// 告诉每个节点「你该住进第几个桶」，这样就算深度优先地走，也能按层归档。
class SolutionRecursive
{
public:
    void dfs(TreeNode* node, int depth, vector<vector<int>>& ans)
    {
        if (node == nullptr) return;  // 防呆：遇到空节点返回

        // 什么时候开新桶？当 depth == ans.size() 时，
        // 说明第 depth 层还是第一次来，桶还没建，赶紧补一个。
        // （depth 从 0 开始数，ans[0] 就是第 0 层）
        if (depth == (int)ans.size())
        {
            ans.push_back(vector<int>());
        }

        ans[depth].push_back(node->val);  // 根：把自己装进「第 depth 层」的桶里

        dfs(node->left, depth + 1, ans);   // 左：孩子都在下一层，depth+1
        dfs(node->right, depth + 1, ans);  // 右

        // 注意：这里「记录自己」写在递归之前，但先后其实无所谓 ——
        // 因为桶是按层分的，同一层的兄弟谁先记谁后记都在同一个桶里，
        // 真正的「从左到右」是由「先左后右」的递归顺序保证的。
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;  // 外层 vector 装「一层」，内层装「这一层的值」
        dfs(root, 0, ans);        // 根节点在第 0 层
        return ans;
    }
};

// 版本二 迭代法（BFS + 队列）
// 队列是先进先出：第 d 层的节点一定比第 d+1 层的先进队列，
// 所以按「出一层、进一层」的节奏走，顺序天然是对的。
class SolutionIterative
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;  // 空树直接交空篮子（示例 3）

        queue<TreeNode*> q;  // 创建队列：先进先出的「传送带」
        q.push(root);        // 根节点先上传送带

        // 只要传送带上还有人，就继续
        while (!q.empty())
        {
            // 灵魂操作：进 for 之前，先数清这一层有多少人。
            // 此刻队列里装着的【恰好全是这一层】的节点，
            // 而 for 里面压进去的都是下一层的，所以必须提前把人数存下来。
            // （如果直接 while(!q.empty()) 一个个弹，层就塌成一维了）
            int size = q.size();
            vector<int> level;  // 给这一层准备一个桶

            for (int i = 0; i < size; i++)  // 只弹 size 次，不多不少
            {
                TreeNode* node = q.front();  // 看传送带最前面是谁
                q.pop();                     // 把他送下传送带

                level.push_back(node->val);        // 记录到本层的桶里
                if (node->left) q.push(node->left);   // 左儿子排到队尾（下一层）
                if (node->right) q.push(node->right); // 右儿子排到队尾（下一层）
                // 先左后右，所以下一层出队时也是从左到右
            }

            ans.push_back(level);  // 这一层收工，整个桶塞进答案
        }

        return ans;
    }
};

/* 手动走一遍示例 1：
        3
       / \
      9   20
         /  \
        15   7

第一轮 while：
  进循环时 q = [3]，size = 1
  弹 3，level = [3]，压入 9、20 → q = [9, 20]
  ans = [[3]]

第二轮 while：
  进循环时 q = [9, 20]，size = 2
  弹 9， level = [9]，9 没有孩子，不压
  弹 20，level = [9, 20]，压入 15、7 → q = [15, 7]
  ans = [[3], [9, 20]]

第三轮 while：
  进循环时 q = [15, 7]，size = 2
  弹 15，level = [15]
  弹 7， level = [15, 7] → q 空了
  ans = [[3], [9, 20], [15, 7]]

队列空，退出 → [[3], [9, 20], [15, 7]] ✓
*/

// 打印 [[3],[9,20],[15,7]] 这种二维结果
void printAns(const vector<vector<int>>& ans)
{
    cout << "[";
    // 注意用 size_t 而不是 int —— int i 和 size() 比大小会报 -Wsign-compare
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << (j == ans[i].size() - 1 ? "" : ", ");
        }
        cout << "]" << (i == ans.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main()
{
    // 1. 手工造树 root = [3, 9, 20, null, null, 15, 7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    // 9 的左右孩子都是 null，不用 new —— nullptr 就代表空

    // 2. 测试递归版本
    SolutionRecursive sol1;
    cout << "递归版输出: ";
    printAns(sol1.levelOrder(root));

    // 3. 测试迭代版本
    SolutionIterative sol2;
    cout << "迭代版输出: ";
    printAns(sol2.levelOrder(root));

    // 4. 顺便测示例 2（单节点）和示例 3（空树）
    TreeNode* single = new TreeNode(1);
    cout << "单节点递归版: ";
    printAns(sol1.levelOrder(single));
    cout << "单节点迭代版: ";
    printAns(sol2.levelOrder(single));

    cout << "空树递归版: ";
    printAns(sol1.levelOrder(nullptr));  // 输出 []
    cout << "空树迭代版: ";
    printAns(sol2.levelOrder(nullptr));  // 输出 []

    return 0;
}