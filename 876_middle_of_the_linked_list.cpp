/* 链表的中间结点 题目描述：
给你单链表的头结点 head，请你找出并返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。

示例 1：
输入：head = [1,2,3,4,5]
输出：[3,4,5]
解释：链表只有一个中间结点，值为 3 。

示例 2：
输入：head = [1,2,3,4,5,6]
输出：[4,5,6]
解释：该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。

约束：
节点数 1 ~ 100 → 不会是空链表
要求返回的是节点本身，不是值

思路： 还是快慢指针 这道题比判断是否有环更加简单一些
兔子（快指针）每次跑2步  乌龟（慢指针）每次跑1步
当兔子跑到终点，乌龟刚好跑到跑道的一半

如果是奇数个节点（如 [1, 2, 3, 4, 5]）：兔子跑到 5（终点），乌龟刚好在 3（中间）。
如果是偶数个节点（如 [1, 2, 3, 4, 5, 6]）：兔子跑出界了（nullptr），乌龟刚好在 4（中间偏右的那个）
*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr){}
};

class Solution
{
public:
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)  // 这样可以控制奇数个时 fast在最后一个节点就不动了 偶数fast会在倒数第二个 再走2步到nullptr
        {
            slow = slow->next;   // 走一步
            fast = fast->next->next;  // 走两步
        }

        //兔子到底了，直接返回乌龟介电
        return slow;
    }
};

// 辅助打印函数
void printListFrom(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout <<endl;
}

int main()
{
    Solution s;

    // 测试用例1：奇数个
    ListNode* n1 = new ListNode(1);
    n1->next = new ListNode(2);
    n1->next->next = new ListNode(3);
    n1->next->next->next = new ListNode(4);
    n1->next->next->next->next = new ListNode(5);
    cout << "奇数结果：" ;
    printListFrom(s.middleNode(n1));

    // 测试用例2：偶数个
    ListNode* m1 = new ListNode(1);
    m1->next = new ListNode(2);
    m1->next->next = new ListNode(3);
    m1->next->next->next = new ListNode(4);
    m1->next->next->next->next = new ListNode(5);
    m1->next->next->next->next->next = new ListNode(6);

    cout << "偶数结果：" ;
    printListFrom(s.middleNode(m1));

    return 0;
}