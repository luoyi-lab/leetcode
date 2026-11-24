/* 验证二叉搜索树 完整题目：
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树BST。

有效 二叉搜索树定义如下：

节点的左子树只包含 严格小于 当前节点的数。
节点的右子树只包含 严格大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

        10       <-- 根节点
       /  \
      5    15    <-- 节点
     / \
    2   7

对于根节点 10 来说
它的左孩子，仅仅指 5 这一个节点
它的左子树，指的是以 5 为根的那一大块（包含了 5、2、7 这三个节点）。这块结构本身也是一棵完整的树

示例 1：
输入：root = [2,1,3]
输出：true

示例 2：
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4
*/

/* 方法一 中序遍历法 二叉搜索树的中序遍历（左-根-右）结果，一定是一个严格递增的序列
思路：用一个变量记录"上一个节点"的值。每次遍历到当前节点时，只要发现当前节点的值 <= 上一个节点的值，直接判死刑，返回 false

⚠️ 踩过的坑：一开始把 pre 写成了类的【成员变量】。
   成员变量不会在两次调用之间清空 —— 第一棵树遍历完，pre 停在它的最右节点；
   第二次调用时，新树的第一个节点跟这个"旧尾巴"比较，合法树也会被判成 false。
   LeetCode 每个用例都 new 一个 Solution，所以看不出来；自己连着判两次立刻暴露。
   现在改成【本次调用的局部变量】，用引用往上传 —— 状态只活在一次调用里。
*/
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution
{
public:
    // prev 是引用：每次递归往上带"上一个访问过的节点"
    bool dfs(TreeNode* node, TreeNode*& prev)
    {
        if(node == nullptr) return true;   // 空树是合法的

        // 1.递归判断左子树
        if(!dfs(node->left, prev)) return false;

        // 2.判断当前节点与上一个节点的关系（必须【严格】大于）
        if(prev != nullptr && node->val <= prev->val) return false;
        prev = node;   // 把当前节点存为"上一个"，供后续使用

        // 3.递归判断右子树
        return dfs(node->right, prev);
    }

    bool isValidBST(TreeNode* root)
    {
        TreeNode* prev = nullptr;   // ← 每次调用都是全新的，不会串味
        return dfs(root, prev);
    }
};


/*方法二 上下界 没有只比较"当前节点和左右孩子"，而是用递归给每个子树维护一个允许取值的开区间  (lower, upper)
表示当前子树中所有节点值都必须满足：lower < node->val < upper
*/
class Solution2 {
public:
    bool check(TreeNode* node, long long lower, long long upper)
    {
        if (node == nullptr) return true;

        // 如果当前节点的值越界了，说明不是BST
        if (node->val <= lower || node->val >= upper) return false;

        // 往左走：上限变成了当前节点的值
        // 往右走：下限变成了当前节点的值
        return check(node->left, lower, node->val) &&
               check(node->right, node->val, upper);
    }

    bool isValidBST(TreeNode* root)
    {
        // 初始范围是负无穷到正无穷
        // ⚠️ 必须用 long long：测试用例里可能有 int 的最小值 -2147483648，
        //    如果用 INT_MIN 当下界，node->val == INT_MIN 时 "<= lower" 会误判。
        // ⚠️ 用标准的 LLONG_MIN / LLONG_MAX（定义在 <climits>），
        //    不要用 LONG_LONG_MIN —— 那是 glibc 的私有扩展，换编译器可能没有。
        return check(root, LLONG_MIN, LLONG_MAX);
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

int main() {
    Solution  sol;    // 方法一：中序遍历
    Solution2 sol2;   // 方法二：上下界

    // ---------- 示例 1: [2, 1, 3] ----------
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << "示例1  中序版: " << boolalpha << sol.isValidBST(root1)
         << "   上下界版: " << sol2.isValidBST(root1) << "   (期望 true)" << endl;

    // ---------- 示例 2: [5, 1, 4, null, null, 3, 6] ----------
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << "示例2  中序版: " << sol.isValidBST(root2)
         << "   上下界版: " << sol2.isValidBST(root2) << "   (期望 false)" << endl;

    // ---------- 陷阱树：只比较父子会判错的那种 ----------
    /*        5
            /   \
           4     6
                / \
               3   7
       5>4 ✓  6>5 ✓  3<6 ✓ —— 但 3 在 5 的右子树里，3<5，所以整棵不是 BST   */
    // （画 ASCII 树要用 /* */ 块，不能用 // —— 行尾的反斜杠会被当成续行，报 -Wcomment）
    TreeNode* trap = new TreeNode(5);
    trap->left = new TreeNode(4);
    trap->right = new TreeNode(6);
    trap->right->left = new TreeNode(3);
    trap->right->right = new TreeNode(7);
    cout << "陷阱树 中序版: " << sol.isValidBST(trap)
         << "   上下界版: " << sol2.isValidBST(trap) << "   (期望 false)" << endl;

    // ---------- INT 边界：long long 哨兵在这里起作用 ----------
    TreeNode* onlyMin = new TreeNode(INT_MIN);
    cout << "INT_MIN 中序版: " << sol.isValidBST(onlyMin)
         << "   上下界版: " << sol2.isValidBST(onlyMin) << "   (期望 true)" << endl;

    // ---------- 同一个对象连判两次：pre 不清空就会在这里挂 ----------
    TreeNode* a = new TreeNode(2);
    a->left = new TreeNode(1);
    a->right = new TreeNode(3);

    TreeNode* b = new TreeNode(2);
    b->left = new TreeNode(1);
    b->right = new TreeNode(3);

    const bool first  = sol.isValidBST(a);
    const bool second = sol.isValidBST(b);   // ← 和 a 完全一样的合法树
    cout << "连判两次 中序版: " << first << " / " << second
         << "   (期望 true / true)" << endl;
    if (!first || !second) {
        cout << "  ^^^ 这里挂了，说明 prev 又被写回成成员变量了" << endl;
    }

    destroy(root1);
    destroy(root2);
    destroy(trap);
    destroy(onlyMin);
    destroy(a);
    destroy(b);

    return 0;
}