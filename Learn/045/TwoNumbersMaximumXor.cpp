#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


const int MAXN = 6 * 1000000;
int nodePath[MAXN][2];
int cnt = 1;
class Solution {
	public:
		void build(vector<int>&nums, int high) {
			for (const auto &ele : nums) {
				int cur = 1;
				for (int i = high; i >= 0; i--) {
					int bit = ((ele & (1 << i)) == 0 ? 0 : 1); //第ID位是0/1
					if (nodePath[cur][bit] == 0) {
						nodePath[cur][bit] = ++cnt;
					}
					cur = nodePath[cur][bit];
				}
			}
		}
		void clear() {
			cnt = 1;
			for (int i = 0; i < MAXN; i++) {
				for (int j = 0; j < 2; j++) {
					nodePath[i][j] = 0;
				}
			}
		}
		int MaximumXOR(vector<int>nums, int high) {
			int biggest = 0;
			//对于每一个数字，找到其能异或到达的最大值
			for (const auto& ele : nums) {
				int tmp = ele;
				int cur = 1;
				for (int i = high; i >= 0; i--) {
					int bit = ((tmp & (1 << i)) == 0 ? 0 : 1); //第ID位是0/1
					int want = (bit == 0 ? 1 : 0);
					if (nodePath[cur][want] == 0) {  //想要的那一位不在，那么这一位最后就是0了
						tmp = (tmp & (~(1 << i)));
						cur = nodePath[cur][bit];
					} else { //这一位最后是1
						tmp = (tmp | (1 << i));
						cur = nodePath[cur][want];
					}
				}
				biggest = max(biggest, tmp);
			}
			return biggest;
		}
		int findMaximumXOR(vector<int>& nums) {
			int big = 0;
			for (const auto &ele : nums) {
				big = max(ele, big);
			}
			cout << big << '\n';

			//找到最大数字的最高位
			int high;
			for (high = 30; high >= 0; high--) {
				if ((big & (1 << high)) != 0) {
					break;
				}
			}
			cout << high << '\n';
			//把数组的每一个数字按位建立前缀树
			build(nums, high);

			//对于数组里的每一个数字，找到其最大的异或和
			int ans = MaximumXOR(nums, high);
			clear();
			return ans;
		}
};


int main() {
	Solution s;
	vector<int>nums = {4, 2};
	cout << s.findMaximumXOR(nums);
	return 0;
}
