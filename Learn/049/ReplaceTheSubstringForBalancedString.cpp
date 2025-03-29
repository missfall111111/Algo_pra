#include <string>
#include <vector>
#include <limits>
using namespace std;

//找到最小替换字串的长度

class Solution {
	public:
		int balancedString(string s) {
			int n = s.size();
			int cnt[4] = {0};
			vector<int>a(n);
			//QWER
			for (int i = 0; i < n; i++) {
				if (s[i] == 'Q') {
					a[i] = 0;
				} else if (s[i] == 'W') {
					a[i] = 1;

				} else if (s[i] == 'E') {
					a[i] = 2;
				} else {
					a[i] = 3;
				}
				cnt[a[i]]++;
			}

			int debt = 0;

			//需要包含的就是个数的负数，不需要的就是0
			for (int i = 0; i < 4; i++) {
				if (cnt[i] > n / 4) {
					cnt[i] = n / 4 - cnt[i]; //某一个字母多的,刚好的 变负数
					debt -= cnt[i];
				} else {  //少的
					cnt[i] = 0;
				}
			}

			if (debt == 0) {
				return 0;
			}
			int ans = numeric_limits<int>::max();
			//以r结尾，凑到至少包含那些多的字符的最小子串
			for (int l = 0, r = 0; r < n; r++) {
				if (cnt[a[r]] < 0) {
					debt--;
				}
				cnt[a[r]]++;

				if (debt == 0) {
					while (cnt[a[l]] > 0) {
						cnt[a[l]]--;
						l++;
					}

					ans = min(ans, r - l + 1);
				}
			}
			return ans;
		}
};
