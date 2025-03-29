#include <vector>
#include <limits>
using namespace std;

//nums全是正数，找到累加和>=target的最短子数组的长度
class Solution {
	public:
		int minSubArrayLen(int target, vector<int>& nums) {

			//整体思路：以第i位结尾的数字要>=target的子数组，然后取其中最短的
			//现在不好解释这个滑动窗口的技巧的缘故，以后再总结吧

			int minLen = numeric_limits<int>::max();
			//l r初始为0，
			for (int i = 0, l = 0, r = 0, sum = 0; i < (int)nums.size(); i++) {
				//找到对于每一个数结尾的最短子数组长度
				//r=i 你会发现i与r同步
				sum += nums[r];
				if (sum < target) {
					r++;
					continue;
				}

				//此时 sum>=target
				//尝试移动l
				while (sum - nums[l] >= target) {
					sum -= nums[l];
					l++;
				}
				// [l,r]

				minLen = min(minLen, r - l + 1);
				r++;
			}
			return minLen == numeric_limits<int>::max() ? 0 : minLen;
		}
};
