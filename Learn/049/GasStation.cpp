#include <vector>

using namespace std;

class Solution {
	public:
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			int n = gas.size();

			for (int l = 0, r = 0, sum; l < n; l = r + 1, r = l) {
				sum = 0;
				// l-r-1
				while (sum + (gas[r % n] - cost[r % n]) >= 0) {
					if (r - l + 1 == n) {
						return l;
					}
					sum += (gas[r % n] - cost[r % n]);
					r++;
				}
			}
			return -1;
		}
};
