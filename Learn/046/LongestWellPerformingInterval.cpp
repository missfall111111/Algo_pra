#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	public:

		//返回表现时间良好的时间段的最长的长度
		//这个子数组劳累的天数严格大于不劳累的天数
		//劳累前缀和 劳累+1 不劳累-1   当他>0时，当前就是一个表现良好的时间段的最大值
		//当他小于等于0时，需要寻找劳累前缀和-1出现的最早位置
		//对于每一个数字，他有当前的劳累前缀和
		int longestWPI(vector<int>& hours) {

			unsigned int ans = 0;
			int sum = 0;

			//负数劳累前缀和 出现的最早的位置
			unordered_map<int, int>map;
			map[0] = -1;
			for (unsigned int i = 0; i < hours.size(); i++) {
				sum += hours[i] > 8 ? 1 : -1;

				if (sum > 0) {
					ans = i + 1;
					continue;
				}
				//sum<=0
				if (map.count(sum - 1)) {
					ans = max(ans, i - map[sum - 1]);
				}

				if (!map.count(sum)) {
					map[sum] = i;
				}
			}
			return ans;
		}
};
