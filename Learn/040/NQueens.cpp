#include <algorithm>
using namespace std;
//class Solution {
//	public:
//		bool check(int path[], int i, int j) {
//			for (int a = 0; a < i; a++) {
//				if (path[a] == j || abs(i - a) == abs(j - path[a])) {
//					return false;
//				}
//			}
//			return true;
//		}
//		int f(int path[], int i, int n) {
//			if (i == n) {
//				return 1;
//			}
//			int ans = 0;
//			for (int j = 0; j < n; j++) {
//				if (check(path, i, j)) {
//					path[i] = j;
//					ans += f(path, i + 1, n);
//				}
//			}
//
//			return ans;
//		}
//		int totalNQueens(int n) {
//			int a[n];
//			return f(a, 0, n);
//		}
//};


//位运算版本
class Solution {
	public:
		int f(int limit, int col, int left, int right) {
			if (col == limit) {
				return 1;
			}

			int ban = col | left | right;
			int candidate = limit & (~ban);
			int place = 0;
			int ans = 0;
			while (candidate != 0) {
				place = candidate & (-candidate);
				candidate ^= place;
				ans += f(limit, col | place, (left | place) >> 1, (right | place) << 1);
			}
			return ans;

		}
		int totalNQueens(int n) {
			int limit = (1 << n) - 1;
			int col = 0;
			int left = 0;
			int right = 0;
			return f(limit, col, left, right);
		}
};
