// 中等 翻转链表，然后+1，然后翻转。需要注意的是+1可能会有多余进位，需要延长链表。7分钟，还不错
class Solution {
	void reverseLink(ListNode*& head) {
		ListNode dummy(0);
		ListNode* pre = &dummy, *cur = head, *next;
		while (cur)
		{
			next = pre->next;
			pre->next = cur;
			cur = cur->next;
			pre->next->next = next;
		}
		head = pre->next;
	}
public:
	ListNode* plusOne(ListNode* head) {
		if (!head) return head;
		reverseLink(head);
		int w = 0;
		ListNode* cur = head, *pre = NULL;
		while (cur)
		{
			int t = w + cur->val;
			if (cur == head) {
				t++;
			}
			w = t / 10;
			t = t % 10;
			cur->val = t;
			if (!w) break;
			pre = cur;
			cur = cur->next;
		}
		if (w) {
			pre->next = new ListNode(w);
		}
		reverseLink(head);
		return head;
	}
};