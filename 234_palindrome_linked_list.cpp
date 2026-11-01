/* 回文链表 题目描述：
给你一个单链表的头节点 head，请你判断该链表是否为回文链表。如果是，返回 true；否则，返回 false

示例 1：
输入：head = [1,2,2,1]
输出：true

示例 2：
输入：head = [1,2]
输出：false

解题思路：
1.寻找中点，使用快慢指针，fast每次走两步 slow每次走一步 fast到终点 slow刚好到中点
2.反转后半部分：从中点slow的下一个节点开始，反转后半部分链表
3.对比前后两部分：将原链表的前半部分和反转后的后半部分比较 如果全部相等，则是回文链表 否则就不是
4.恢复链表 比较完之后可以将后半部分链表再反转回去

*/
#include <iostream>
#include <vector>

using namespace std;

// 1.链表节点定义
struct ListNode
{
    int val;
    ListNode* next;
    // 三段构造函数重载
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next):val(x), next(next){}
};

// 2.解题类
class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return true;
        }

        // 快慢指针找到前半部分尾节点
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* firstHalfEnd = slow;
        ListNode* secondHalfStart = slow->next;
        // 反转后半部分链表
        ListNode* prev = nullptr;   // 当前节点的前一个节点
        ListNode* curr = secondHalfStart;   // 表示当前正在处理的节点
        while(curr != nullptr)
        {
            ListNode* nextTemp = curr->next;   // 保存后路
            curr->next = prev;   // 反转 箭头指向prev
            prev = curr;   // 前节点更新
            curr = nextTemp;   // 当前节点更新
        }

        // 判断是否为回文
        ListNode* p1 = head;   //前半段的头节点
        ListNode* p2 = prev;   // 后半段链表反转的后的头节点
        bool result = true;   // 先默认为回文
        while(p2 != nullptr)
        {
            if(p1->val != p2->val)
            {
                result = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // 恢复链表
        curr = prev;   // 准备把刚才反转的后半段再反转回来。curr 指向反转后后半段的头
        prev = nullptr;
        while(curr != nullptr)
        {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        firstHalfEnd->next = prev;   // 极其关键：firstHalfEnd 是前半段的最后一个节点。把前半段的尾巴，重新接回已经恢复正常的后半段。

        return result;
    }
};

// 辅助函数 根据数组创建链表
ListNode* createList(const vector<int>& arr)   // 传入一个常引用数组，省内存
{
    if(arr.empty()) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for(size_t i = 1; i < arr.size(); i++)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// 辅助函数 打印链表
void printList(ListNode* head) {
    cout << "[";
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << ", ";
        head = head->next;
    }
    cout << "]" << endl;
}

// 辅助函数：释放链表内存（好习惯）
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// 测试
int main() {
    Solution sol;

    // --- 测试用例 1 ---
    vector<int> nums1 = {1, 2, 2, 1};
    ListNode* head1 = createList(nums1);
    cout << "测试用例 1: ";
    printList(head1);
    cout << "输出: " << (sol.isPalindrome(head1) ? "true" : "false") << endl;
    cout << "恢复后的链表: ";
    printList(head1); // 验证代码中恢复链表的逻辑
    freeList(head1);
    
    cout << "------------------------" << endl;

    // --- 测试用例 2 ---
    vector<int> nums2 = {1, 2};
    ListNode* head2 = createList(nums2);
    cout << "测试用例 2: ";
    printList(head2);
    cout << "输出: " << (sol.isPalindrome(head2) ? "true" : "false") << endl;
    freeList(head2);

    cout << "------------------------" << endl;

    // --- 测试用例 3 ---
    vector<int> nums3 = {1};
    ListNode* head3 = createList(nums3);
    cout << "测试用例 3: ";
    printList(head3);
    cout << "输出: " << (sol.isPalindrome(head3) ? "true" : "false") << endl;
    freeList(head3);

    return 0;
}