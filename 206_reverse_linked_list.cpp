/* 反转链表 题目描述
给你单链表的头节点 head，请你反转链表，并返回反转后的链表

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]
*/

// 迭代法
// prev 记录当前操作节点的前一个节点
// curr 记录当前正在操作的节点
// next_temp curr的备胎 记录的是原本指向的下一个节点（指针）

/* 以链表1->2->3->nullptr 为例
初始状态：
prev = nullptr
curr = 节点1
第一轮循环（处理节点1）：
1.next_temp = curr->next（备胎指针指向节点2）
2.curr->next = prev（让节点1的箭头指向nullptr，此时1和2的链子断了，但是备胎已经存了2）
3.prev = curr  （让prev指向节点1）
4.curr = next_temp （让curr指向节点2） 
现在节点1处理完了 变成 1-> nullptr prev在1，curr在2

第二轮循环（处理节点2）：
1.next_temp = curr->next （备胎=节点3）
2.curr->next = prev （节点2的箭头指向节点1）
3.prev = curr （让prev指向节点2）
4.curr = next_temp （让curr指向节点3）

第三轮循环（处理节点3）（完全同上）

此时状态：3->2->1->nullptr prev在3 curr在nullptr

因为curr = nullptr, 故退出while循环
此时，prev指着原本最后一个节点（现在的第一个节点3）
所以return prev，交出反转后的新节点头
*/

#include<iostream>
using namespace std;

// 定义链表结构体
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr)
    {

    }
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr; // 前任指针 初始为空
        ListNode* curr = head; // 现任指针，从原 头节点开始

        while (curr != nullptr)
        {
            ListNode* next_temp = curr->next; // 1.存备胎：先把当前节点的下一个节点存起来
            curr->next = prev; // 2.改箭头：把当前节点的next指向prev，完成调头
            prev = curr; // 3.前任前移 把curr变为prev
            curr = next_temp; // 4.现任前移 原来的curr已经是prev了 原来的备胎next_temp现在是现任了
        }
        // 循环结束时，curr变成了nullptr，而prev指向原链表的最后一个节点 也就是新链表的头节点
        return prev;
    }
};

// 辅助函数 打印链表
void printList(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val << "->";
        head = head->next; // 指针后移
    }
    cout << " nullptr" <<endl; // 最后再加上一个指向nullptr
}

int main()
{
    // 手工构造链表: 1 -> 2 -> 3 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    // cout << "反转前：" << printList(head) <<endl; 典型的错误代码 因为printList没有返回值 不能塞入到cout里面
    cout << "返回前：" ;
    printList(head);

    Solution s;
    ListNode* newhead = s.reverseList(head); //让s去反转以 head 开头的链表，并且把反转后的新头节点存到 newHead 指针里

    cout << "反转后：" ;
    printList(newhead);

    return 0;
}