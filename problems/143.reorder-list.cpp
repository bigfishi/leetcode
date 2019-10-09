// 中等 思路是有的，但是做了20分钟，需要多练习
class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head) return;
		ListNode* fast = head, *slow = head;
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* next = slow->next;
		slow->next = NULL;
		reverseLink(next);
		ListNode* cur1 = head, *cur2 = next;
		while (cur1 && cur2)
		{
			ListNode* tmp = cur1->next;
			ListNode* tmp2 = cur2->next;
			cur1->next = cur2;
			cur2->next = tmp;
			cur1 = tmp;
			cur2 = tmp2;
		}
	}
	void reverseLink(ListNode*& head) {
		if (!head || !head->next) return;
		ListNode dummy(0);
		ListNode*pre = &dummy, *next, *cur = head, *t;
		while (cur)
		{
			next = pre->next;
			pre->next = cur;
			cur = cur->next;
			pre->next->next = next;
		}
		head = dummy.next;
	}
};