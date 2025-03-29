#include <vector>

using namespace std;

class Solution {
	public:
		// 含有k种不同数字的子数组的个数
		//随着l-r范围的增大，数字的种类总是有单调上升的趋势，但不是种类是某一个固定值的单调上升的趋势
		int cnt[20000 + 10];
		int subarraysWithKLessEqual(vector<int>& nums, int k) {
			fill(cnt + 1, cnt + 20000 + 10, 0);
			int ans = 0;
			for (unsigned int l = 0, r = 0, type = 0; r < nums.size(); r++) {
				cnt[nums[r]]++;
				if (cnt[nums[r]] == 1) {
					type++;
				}

				while ((int)type > k) {
					cnt[nums[l]]--;
					if (cnt[nums[l]] == 0) {
						type--;
					}
					l++;
				}

				ans += r - l + 1;
			}
			return ans;
		}
		int subarraysWithKDistinct(vector<int>& nums, int k) {
			return subarraysWithKLessEqual(nums, k) - subarraysWithKLessEqual(nums, k - 1);
		}
};
