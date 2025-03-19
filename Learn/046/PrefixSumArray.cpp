#include <vector>

using namespace std;


class NumArray {
	public:
		vector<int>arr;
		vector<int>prefixSum;
		NumArray(vector<int>& nums) {
			arr = nums;
			prefixSum.push_back(arr[0]);
			for (unsigned int i = 1; i < arr.size(); i++) {
				prefixSum.push_back(prefixSum[i - 1] + nums[i]);
			}
		}

		int sumRange(int left, int right) {
			if (left == 0) {
				return prefixSum[right];
			}
			return prefixSum[right] - prefixSum[left - 1];
		}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
