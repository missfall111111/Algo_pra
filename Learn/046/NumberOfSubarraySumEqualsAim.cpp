#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
	public:

		//在数组中，累加和为k的子数组的个数

		//对于数组中的每一个数组，得到他当前的前缀和 sum
		//在map中查找以前有几个前缀和为sum-k的位置  答案+=他
		int subarraySum(vector<int>& nums, int k) {

			int sum = 0;
			int ans = 0;
			//前缀和 出现的次数
			unordered_map<int, int>map;
			map[0] = 1;  //最开始为0的就有一次
			for (unsigned int i = 0; i < nums.size(); i++) {
				sum += nums[i];

				if (map.count(sum - k)) {
					ans += map[sum - k];
				}

				map[sum] += 1;
			}
			return ans;
		}
};
