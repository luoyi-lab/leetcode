/* 合并两个有序链表 题目描述
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]

示例 2：
输入：l1 = [], l2 = []
输出：[]

示例 3：
输入：l1 = [], l2 = [0]
输出：[0]

思路：有两摞按从小到大顺序排好的扑克牌 你要把两摞合成一摞 怎么做：
1.左右观察 哪张牌小
2.把小的拿出来单独放 漏出下面的牌
3.重复上述两步
4.直到有一摞牌被拿完 剩下一摞的牌直接盖上去（因为是按从小到大的顺序排的 剩下的一摞肯定是要更大或者起码相等的）

关键神器：虚拟头节点：Dummy Node
如果你直接比较，然后往“空盒子”里塞第一个牌，你要写一堆特判代码（判断盒子是不是空的），很麻烦
我们提前在盒子里放一个“假牌（dummy）”。所有比较出来的牌，全塞在这个假牌后面。最后返回的时候，把假牌扔掉
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

void printList(ListNode* head) 
{
    while (head != nullptr) 
    {
        cout << head->val << " -> ";
        head = head->next; // 移动到下一个节点
    }
    cout << "nullptr" << endl; // 走到尽头了，打印 nullptr
}

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        // 1. 创建一个虚拟头节点
        ListNode* dummy = new ListNode(-1); //在堆区开辟一块内存 创建一个ListNode对象 值为-1 并且把这个对象的内存地址赋给dummy
        ListNode* curr = dummy; //curr是负责干活的指针 永远指着新链表的尾巴

        // 2.当两个链表都不为空时，开始比较大小
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                curr->next = list1; // 把较小的L1挂到新链表的尾巴上
                list1 = list1->next; // L1往前走
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next; // 每判断一次 就让curr更新一次 确保在最后
        }
        // 3.循环结束之后，有一个链表已经空了，另一个还有剩下的 直接把剩下的部分 挂在curr后面
        if(list1 != nullptr)
        {
            curr->next = list1;
        }
        else
        {
            curr->next = list2;
        }
        // 返回真正的头节点（就是一开始创建的dummy的下一个）
        ListNode* result = dummy->next;
        delete dummy;
        return result; //这里的 result 是交出具体的变量名，不需要再写类型了
    }
};

int main()
{
    // 1.构造链表L1：1->2->2->4
    ListNode* L1 = new ListNode(1);
    L1->next = new ListNode(2);
    L1->next->next = new ListNode(2);
    L1->next->next->next = new ListNode(4);

    // 2.构造链表L2：1->3->4
    ListNode* L2 = new ListNode(1);
    L2->next = new ListNode(3);
    L2->next->next = new ListNode(4);

    // 3.打印一下看看原链表
    cout << "链表1：";
    printList(L1);

    cout << "链表2：";
    printList(L2);

    Solution s;
    ListNode* mergedHead = s.mergeTwoLists(L1, L2);

    // 4.打印合并后的
    cout << "合并后：";
    printList(mergedHead);

    return 0;
}