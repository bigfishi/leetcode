// 中等 ordered map，C++中的map会自动按照升序排列
// 错了一次，审错题了，题目说是每组手牌大小为W，且是由W张牌组成，我理解成手牌大小有个硬性条件W*W
class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int W) {
		if (W==0 || hand.size()%W!=0) return false;
		map<int, int> m;
		for (auto i : hand)
			m[i]++;
		int i = 0, count = 0, pre = 0;;
		while (i<hand.size())
		{

			for (auto item : m) {
				if (!item.second) continue;
				if (count == 0) {
					pre = item.first;
					count++;
					m[item.first]--;
				}
				else {
					if (item.first - pre == 1) {
						pre = item.first;
						count++;
						m[item.first]--;
					}
					else {
						return false;
					}
				}
				if (count == W) break;
			}
			if (count == W) {
				i+= W;
				count = 0;
			} 
			else {
				return false;
			}
		}
		return true;
	}
};