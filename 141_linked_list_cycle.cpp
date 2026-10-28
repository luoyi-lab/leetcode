/* 环形链表 题目描述
给你一个链表的头节点 head，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的某个位置（索引从 0 开始）。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况
如果链表中存在环，则返回 true；否则，返回 false。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

约束：
节点数 0 ~ 10^4 → head 可能为空
进阶：能不能用 O(1) 内存？ ← 这条排除了"存访问过的节点"的写法，逼你用快慢指针

关于内存的这个问题
O(1):不准建新的数组！不准用 map 或 set！不准用 new 申请堆内存！你只能利用现有的指针和变量，把这个问题解决掉  栈区 
O(n):new int[n], vector.push_back, unordered_set等等                                                 堆区

只要题目说 O(1) 空间，就是不准我建哈希表，也不准我建数组，那我就只能拿几个指针在原来的链表/数组上跳舞
*/

/*快慢指针 龟兔赛跑算法
想象你在一个环形操场（有环链表）上，让两个人同时起跑：

慢指针（乌龟）：每次走 1 步（slow = slow->next）。

快指针（兔子）：每次走 2 步（fast = fast->next->next）。

情况 A：如果没有环（是一条直线）
兔子跑得飞快，它一定会先到达终点（nullptr）。这时候循环结束，说明没有环，返回 false。

情况 B：如果有环（是操场）
兔子会先冲进操场里疯狂绕圈，乌龟后进操场。因为兔子速度比乌龟快，只要时间足够，兔子一定会在操场的某个位置，从后面追上并超过乌龟（两人相遇）。
只要 slow == fast，就说明有环，返回 true。

*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr)
    {

    }
};

class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        // 边界情况：空链表 或只有一个节点且无环
        if(head == nullptr || head->next == nullptr)
        {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // 只要fast和fast->next 都不是空， 就继续跑
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;  // 乌龟走一步
            fast = fast->next->next;  // 兔子走两步

            //如果相遇了 说明有环
            if(slow == fast)
            {
                return true;
            }
        }
        // 如果兔子跑到终点了 说明没有环
        return false;
    }
};

int main()
{
    // 人为构造一个有环的链表：
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // 认为创造一个环

    Solution s;
    cout << "是否有环：" << boolalpha<< s.hasCycle(n1) <<endl;  // 加个 boolalpha 把布尔值转换为true/false

    return 0;
}