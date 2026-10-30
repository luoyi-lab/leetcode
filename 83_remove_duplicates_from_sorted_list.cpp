/* 删除排序链表中的重复元素 题目描述：
给定一个已排序的链表的头 head，删除所有重复的元素，使每个元素只出现一次。返回已排序的链表。

示例 1：
输入：head = [1,1,2]
输出：[1,2]

示例 2：
输入：head = [1,1,2,3,3]
输出：[1,2,3]

约束：
节点数 0 ~ 300 → head 可能为空，要判空
题目保证链表已经升序排列 ← 这是关键：重复元素一定相邻

思路：
这是一个非常简单的单指针问题 顺藤摸瓜：
1.你手里拿着一个瓜curr 眼瞅下一个curr->next
2.如果下一个和你手上的一样 不要下一个 继续向前看 人不要动
3.重复2 直到看到不一样的瓜 再到这个不一样的瓜面前去拿它

*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        //边界情况 空链表直接返回
        if(head == nullptr)
        {
            return nullptr;
        }

        // 取出curr指针 从头节点开始查
        ListNode* curr = head;
        
        while(curr != nullptr && curr->next != nullptr)  // 只要当前节点和下一个节点不为空 就要查
        {
            if(curr->val == curr->next->val)
            {
                //发现重复了
                ListNode* temp = curr->next;  // 先存下这个准备要删除的节点
                curr->next = curr->next->next;  // 改变指针 跳过重复点
                delete temp;  // 把跳过的节点在内存里销毁
            }
            else
            {
                // 没有重复，直接让curr向前走
                curr = curr->next;
            }
        }
        return head;
    }
};

// 辅助测试打印函数
void printList(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "nullptr" <<endl;
}

int main()
{
    Solution s;

    // 测试用例：1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    cout << "原链表" ;
    printList(head);

    ListNode* result = s.deleteDuplicates(head);

    cout << "去重后" ;
    printList(result);

    return 0;
}