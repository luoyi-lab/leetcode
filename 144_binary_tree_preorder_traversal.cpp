/* 二叉树的前序遍历 完整题目：
给你二叉树的根节点 root，返回它节点值的前序遍历

前序遍历：根 -> 左 -> 右
示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]
根节点 1 的左孩子是空 整个树长这样
    1
     \
      2
     /
    3

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]
*/
#include <iostream>
#include <vector>
#include <stack>  // 引入栈。有了它，你在“迭代法”里才能用 push 和 pop

using namespace std;

// 1.定义二叉树节点结构体
struct TreeNode
{
    int val;  // 存这个节点的数据
    TreeNode* left;  // 左指针
    TreeNode* right;  // 右指针 
    // 构造函数 当你new TreeNode(5) 创建节点时 自动执行
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    // val(x) 把传进来的数字 x 塞给 val  同时把左右指针初始化为空，防止野指针导致程序崩溃
};

// 版本一 递归法
class SolutionRecursive
{
public:
    // 辅助函数：
    void dfs(TreeNode* node, vector<int>& ans)  // 传入一个节点和数组
    {
        if(node == nullptr) return;  // 防呆 遇到空就返回

        ans.push_back(node->val);  // 根 先把当前这个节点的值，装进篮子（ans）里
        dfs(node->left, ans);  // 左 递归处理左子树       顺着左指针，去左边走一趟 
        dfs(node->right, ans);  // 右 递归处理右子树      顺着右指针，去右边走一趟
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;  // 准备一个空篮子
        dfs(root, ans);  // 让 dfs 这个工人，从头开始把树走一遍，顺便把值装进 ans
        return ans;
    }
};

// 版本二 迭代法
class SolutionIterative
{
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;  // 准备空蓝子
        if(root == nullptr) return ans;  // 如果根节点是空的 直接返回空蓝子
        stack<TreeNode*> st;  // 创建一个数据结构“栈”（后进先出的箱子）  意思是：造一个专门用来装 TreeNode 指针的箱子
        st.push(root);  // push是塞进去  pop是顶出来 这里是把根节点(1)先放进箱子

        // 只要箱子里还有东西 就一直循环
        while(!st.empty())
        {
            TreeNode* node = st.top();  // 把箱子最顶上的节点记为node
            st.pop();  // 把箱子最顶上的节点拿出来扔掉
            ans.push_back(node->val);  // 既然已经拿出来了 就把它的值装进篮子里
            // 灵魂操作：为什么先压右边，再压左边？
            // 因为“栈”是后进先出。如果你先压左再压右，那右就会在最上面，出来的时候就是右先出
            // 前序遍历要求：根 -> 左 -> 右。所以为了让左先出，左必须最后压进去（在栈顶）
            if(node->right) st.push(node->right);  // 如果右儿子存在，把右儿子压进箱子
            if(node->left) st.push(node->left);  // 如果左儿子存在，把左儿子压进箱子
        }
        return ans;
    }
};
/* 例子：
      1
     / \
    2   3
   / \
  4   5
前序遍历的要求是：根 -> 左 -> 右。并且是深度优先
所以这道题正确的输出结果应该是：[1, 2, 4, 5, 3]

第一轮循环：
TreeNode* node = st.top(); // 拿到 1
st.pop();                  // 把 1 拿出来
ans.push_back(node->val);  // 篮子装入 1
if (node->right) st.push(node->right); // 压入右孩子 3
if (node->left)  st.push(node->left);  // 压入左孩子 2
第二轮循环：
TreeNode* node = st.top(); // 拿到 2
st.pop();                  // 把 2 拿出来
ans.push_back(node->val);  // 篮子装入 2
if (node->right) st.push(node->right); // 压入右孩子 5
if (node->left)  st.push(node->left);  // 压入左孩子 4
第三轮循环：
TreeNode* node = st.top(); // 拿到 4
st.pop();                  // 把 4 拿出来
ans.push_back(node->val);  // 篮子装入 4
// 4 没有左右孩子，所以没有 push 操作
第四轮循环：
TreeNode* node = st.top(); // 拿到 5
st.pop();                  // 把 5 拿出来
ans.push_back(node->val);  // 篮子装入 5
第五轮循环：
TreeNode* node = st.top(); // 拿到 3
st.pop();                  // 把 3 拿出来
ans.push_back(node->val);  // 篮子装入 3
箱子空了 循环结束 
*/

int main()
{
    // 1.手工造树 root = [1, nullptr, 2, 3]
    TreeNode* root = new TreeNode(1);  // 先在堆区new一个值为1的根节点
    root->right = new TreeNode(2);  // 1的右边new一个2
    root->right->left = new TreeNode(3);  // 2的左边new一个3

    // 2.测试递归版本
    SolutionRecursive Sol1;  // 实例化一个递归型解法的对象 叫sol1
    vector<int> res1 = Sol1.preorderTraversal(root);  // 把树丢给它 拿到结果res1
    cout << "递归版本输出：[";

    // 遍历打印结果数组
    for(int i = 0; i < res1.size(); i++)
    {
        // 打印当前数字。如果它不是最后一个数字，后面就加个逗号；如果是最后一个，就不加
        cout << res1[i] << (i == res1.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;    

    // 3. 测试迭代版（逻辑和上面一模一样，只是换了个类）
    SolutionIterative sol2;                      
    vector<int> res2 = sol2.preorderTraversal(root); 
    cout << "迭代版本输出: [";
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i] << (i == res2.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;    
}