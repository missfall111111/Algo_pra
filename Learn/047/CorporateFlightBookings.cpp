#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
			vector<int>ans;

			//n个位置 多两个是为了避免边界情况
			for (int i = 0; i < n; i++) {
				ans.push_back(0);
			}

			//0 1 ...n n+1
			ans.push_back(0);
			ans.push_back(0);

			for (const auto &arr : bookings) {
				ans[arr[0]] += arr[2];
				ans[arr[1] + 1] -= arr[2];
			}
			vector<int>tmp;
			tmp.push_back(ans[1]);
			for (int i = 2; i <= n; i++) {
				ans[i] = ans[i] +  ans[i - 1];
				tmp.push_back(ans[i]);
			}

			return tmp;
		}
};
