#include <string>
#include <limits>
using namespace std;


class Solution {
	public:
		//返回s中包含t中所有字符的最小子串
		string minWindow(string s, string t) {
			int debt = 0;
			int cnt[256] = {};
			for (const auto &ele : t) {
				cnt[(int)ele] -= 1;
				debt -= 1;
			}
			string ans = "";
			unsigned int len = numeric_limits<int>::max();
			//对于每一个以r结尾的位置，计算其可能包含t中所有字符的最小子串，取最小
			for (unsigned int r = 0, l = 0; r < s.size(); r++) {
				if (cnt[(int)s[r]] < 0) { //需要的
					debt++;
				}
				cnt[(int)s[r]]++;

				if (debt == 0) {
					while (cnt[(int)s[l]] > 0) {
						cnt[(int)s[l]] --;
						l++;
					}

					if (len > r - l + 1) {
						len = r - l + 1;
						ans = s.substr(l, r - l + 1);
					}
				}
			}
			return ans;
		}
};
