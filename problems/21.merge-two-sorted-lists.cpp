class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode node(0);
		ListNode* cur1 = l1, *cur2 = l2, *pre=&node, *tmp;
		while (cur1 || cur2)
		{
			if (cur1 && (!cur2 || cur1->val < cur2->val)) {
				pre->next = cur1;
				cur1 = cur1->next;
				pre = pre->next;
			}
			else {
				pre->next = cur2;
				cur2 = cur2->next;
				pre = pre->next;
			}
		}
		return node.next;
	}
};
// 参考方法
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode dummy(0);
		dummy.next = p1;
		ListNode* prev = &dummy;
		while (p1 && p2)
		{
			if (p1->val < p2->val) {
				prev = p1;
				p1 = p1->next;
			}
			else {
				prev->next = p2;
				p2 = p2->next;
				prev = prev->next;
				prev->next = p1;
			}
		}
		if (p2) {
			prev->next = p2;
		}
		return dummy.next;
	}
};