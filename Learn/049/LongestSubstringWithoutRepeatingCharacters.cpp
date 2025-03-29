#include <string>
#include <iostream>
using namespace std;

//s中无重复字母的最长最子串

//随着r增大，遇到重复字母的可能越大，串也越长
class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			//对于每一个字符，以其结尾的无重复字母的最子串，找最长
			//s 由英文字母、数字、符号和空格组成

			int cnt[256] = {};
			fill(cnt, cnt + 256, -1);
			unsigned int maxLen = 0;
			/**
			 * 出现重复的情况，一定是这个新添加进来的字母的重复，以前都没重复
			 * 需要一个cnt数组来记录每一种字符出现的位置，从未出现过即为-1
			 * 重复了，l就是更新到重复的字符曾经的位置+1
			 *
			  上面的逻辑是错误的！
			  对模型思考得不够全面！
			 * [l,r]是子串的范围
			 */
			for (unsigned int l = 0, r = 0; r < s.size(); r++) {
				//重复
//				if (cnt[(int)s[r]] != -1) {
//					l = cnt[(int)s[r]] + 1;
//				}  //Wrong
				l = max((int)l, cnt[(int)s[r]] + 1); //Correct
				cnt[(int)s[r]] = r;
				maxLen = max(maxLen, r - l + 1);

//				cout << l << " " << r << "\n";

			}

			return maxLen;
		}
};


int main() {
	Solution s = Solution();
	string a = "abba";
	cout << s.lengthOfLongestSubstring(a);
}
