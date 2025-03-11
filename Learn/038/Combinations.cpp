#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:

		void f(int i, int path[], int s, vector<vector<int>>&ans, vector<int>&nums) {
			if (i == nums.size()) {
				vector<int>a ;
				for (int i = 0; i < s; i++) {
					a.push_back(path[i]);
				}
				ans.push_back(a);
				return;
			}
			int j = i + 1;
			while (j<nums.size() && nums[j] == nums[i]) {
				j++;
			}
			f(j, path, s, ans, nums); //0个
			for (; i < j; i++) {
				path[s++] = nums[i];
				f(j, path, s, ans, nums);
			}
		}
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<vector<int>>ans;
			int path[nums.size()];
			f(0, path, 0, ans, nums);
			return ans;
		}
};
