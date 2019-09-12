class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		vector<int> nums;
		for (size_t i = 0; i < lists.size(); i++)
		{
			ListNode* cur = lists[i];
			while (cur)
			{
				nums.push_back(cur->val);
				cur = cur->next;
			}
		}
		sort(nums.begin(), nums.end());
		ListNode node(0);
		ListNode*cur = &node;
		for (size_t i = 0; i < nums.size(); i++)
		{
			cur->next = new ListNode(nums[i]);
			cur = cur->next;
		}
		return node.next;
	}
};
// 参考
// 时间太长
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* p, *p1, *p2;
		while (lists.size()>1)
		{
			p1 = lists.back();
			lists.pop_back();
			p2 = lists.back();
			lists.pop_back();
			p = mergeTwoLists(p1, p2);
			lists.insert(lists.begin(), p);
		}
		return lists.size() == 1 ? lists[0] : NULL;
	}
private:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		static ListNode dummy(0);
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
// 使用优先队列
struct cmp
{
	bool operator()(const pair<int, ListNode*> a, const pair<int, ListNode*> b) const { return a.first > b.first; } // 这是升序，小顶堆
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, cmp> pq;
		for (size_t i = 0; i < lists.size(); i++)
		{
			ListNode* node = lists[i];
			if (!node) continue;
			pq.push({ node->val, node });
		}
		ListNode dummy(0);
		ListNode* prev = &dummy;
		while (pq.size())
		{
			auto item = pq.top();
			pq.pop();
			prev->next = item.second;
			prev = prev->next;
			if (item.second->next) {
				pq.push({ item.second->next->val, item.second->next });
			}
		}
		return dummy.next;
	}
};