/* 二叉树的右视图 完整题目：
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值

示例 1：
输入：root = [1,2,3,null,5,null,4]

      1         <-- 第1层最右边是 1
     / \
    2   3       <-- 第2层最右边是 3
     \   \
      5   4     <-- 第3层最右边是 4

输出：[1,3,4]

示例 2：
输入：root = [1,null,3]
输出：[1,3]

示例 3：
输入：root = []
输出：[]

这题就是让你找出二叉树里，每一层最右边的那个节点

⚠️ 注意「一路向右」是错的：
        1
       / \
      2   3
     /
    4
   一直往右走得 1,3；但第 2 层只有 4 一个节点，它也是右视图的一部分，答案是 [1,3,4]。
   「右视图」= 每层最右，不是「一路向右」。
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

// ==========================================
// 版本一 BFS：数 size 分层，每层取最后一个
// ==========================================
class SolutionBFS
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            const int size = static_cast<int>(q.size());
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (i == size - 1) ans.push_back(node->val);   // 这一层最后一个 = 最右边
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};

// ==========================================
// 版本二 DFS：先右后左，第一次到达某深度的节点就是该层最右
//
// ⚠️ 踩过的坑（和 98 那道一模一样）：
//    一开始把 ans 写成了类的【成员变量】。成员变量不会在两次调用之间清空 ——
//    第二次调用一棵更小的树时，返回的还是上一棵树的答案。
//       树A [1,2,3,null,5,null,4] -> [1,3,4]  ✓
//       树B [1,2]                 -> [1,3,4]  ✗（应该 [1,2]）
//    更阴险的是：拿【同一棵树】连判两次，第二次居然是"对"的
//    （因为 depth == ans.size() 永远不成立，什么都没加，返回的正好是上次的正确答案）。
//    → 想抓这类 bug，必须换【不同的输入】重测。
//    现在改成局部变量 + 引用传递：状态只活在一次调用里。
// ==========================================
class SolutionDFS {
public:
    void dfs(TreeNode* node, int depth, vector<int>& ans)
    {
        if (node == nullptr) return;

        // 第一次来到这一层 -> 就是这一层最右的（因为我们是先右后左走的）
        if (depth == static_cast<int>(ans.size()))
            ans.push_back(node->val);

        dfs(node->right, depth + 1, ans);
        dfs(node->left,  depth + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;          // ← 每次调用都是全新的，不会串味
        dfs(root, 0, ans);
        return ans;
    }
};


// ==========================================
// 测试
// ==========================================
static void destroy(TreeNode* n)
{
    if (!n) return;
    destroy(n->left);
    destroy(n->right);
    delete n;
}

static void printVec(const char* tag, const vector<int>& v)
{
    cout << tag << " [";
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << (i + 1 == v.size() ? "" : ", ");
    cout << "]" << endl;
}

int main() {
    SolutionBFS sBFS;
    SolutionDFS sDFS;

    /* 示例 1：[1,2,3,null,5,null,4]
            1
           / \
          2   3
           \   \
            5   4                                            */
    TreeNode* root1 = new TreeNode(1);
    root1->left  = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right  = new TreeNode(5);
    root1->right->right = new TreeNode(4);
    printVec("示例1 BFS:", sBFS.rightSideView(root1));   // 期望 [1, 3, 4]
    printVec("示例1 DFS:", sDFS.rightSideView(root1));   // 期望 [1, 3, 4]

    /* 一路向右的陷阱：答案是 [1,3,4]，不是 [1,3]
            1
           / \
          2   3
         /
        4                                                    */
    TreeNode* trap = new TreeNode(1);
    trap->left  = new TreeNode(2);
    trap->right = new TreeNode(3);
    trap->left->left = new TreeNode(4);
    printVec("陷阱树 BFS:", sBFS.rightSideView(trap));   // 期望 [1, 3, 4]
    printVec("陷阱树 DFS:", sDFS.rightSideView(trap));   // 期望 [1, 3, 4]

    // 空树
    printVec("空树 BFS:", sBFS.rightSideView(nullptr));  // 期望 []
    printVec("空树 DFS:", sDFS.rightSideView(nullptr));  // 期望 []

    // ---------- ★ 同一个对象连判两次，且第二次换一棵【不同】的树 ----------
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2); a->right = new TreeNode(3);
    a->left->right  = new TreeNode(5);
    a->right->right = new TreeNode(4);

    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2);

    SolutionDFS one;                                   // ← 同一个对象
    const vector<int> ra = one.rightSideView(a);       // 期望 [1,3,4]
    const vector<int> rb = one.rightSideView(b);       // 期望 [1,2]
    printVec("连判两次 第1棵(期望[1,3,4]):", ra);
    printVec("连判两次 第2棵(期望[1,2])  :", rb);
    if (rb != vector<int>{1, 2}) {
        cout << "  ^^^ 这里挂了，说明 ans 又被写回成成员变量了" << endl;
    }

    destroy(root1);
    destroy(trap);
    destroy(a);
    destroy(b);

    return 0;
}
