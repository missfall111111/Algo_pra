#include <string>


using namespace std;
class Solution {
	public:
		int longestSubstring(string s, int k) {
			int ans = 0;
			int cnt[26] = {};
			for (unsigned int t = 1; t <= 26; t++) {
				fill(cnt, cnt + 26, 0); //字母出现的次数
				//字母种类是1...26，得到的最长的至少每种重复k次的子数组长度
				for (unsigned int l = 0, r = 0, tCur = 0,  fufill = 0; r < s.size(); r++) {
					cnt[s[r] - 'a']++;
					if (cnt[s[r] - 'a'] == 1) { //新出现
						tCur++;  //当前种类++
					}


					if (cnt[s[r] - 'a'] == k) { //次数满足要求
						fufill++;
					}

					while (tCur > t) {
						cnt[s[l] - 'a']--;
						if (cnt[s[l] - 'a'] == k - 1) {
							fufill--;
						}
						if (cnt[s[l] - 'a'] == 0) {
							tCur--;
						}
						l++;
					}

					if (fufill == t) {
						ans = max(ans, int(r - l + 1));
					}
				}
			}
			return ans;
		}
};
