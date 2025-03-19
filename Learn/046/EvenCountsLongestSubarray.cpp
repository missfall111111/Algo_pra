#include <string>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		//返回一个最长的字串 字串内a e i o u 5个元音字母都出现偶数次

		//偶数状态的前缀和

		//map记录各种奇数状态出现最早的位置 及其索引
		//偶数状态只有一个00000
		//                uoiea

		//从第一个字符开始 更新状态，有一个当前的状态
		//如果是00000，ans=i+1
		//如果不是，找最早出现的相同位置j,

		bool isYuanYin(const char& c) {
			return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
		}

		//保证是元音
		int pos(const char& c) {
			if (c == 'a') {
				return 0;
			} else if (c == 'e') {
				return 1;
			} else if (c == 'i') {
				return 2;
			} else if (c == 'o') {
				return 3;
			} else if (c == 'u') {
				return 4;
			}
		}
		int findTheLongestSubstring(string s) {
			unsigned int ans = 0;

			//状态使用char存储
			char status = 0;
			//map记录各种奇数状态出现最早的位置 及其索引
			unordered_map<char, int>map;
			for (unsigned int i = 0; i < s.size(); i++) {
				//更新状态
				if (isYuanYin(s[i])) {
					status = status ^ (1 << (pos(s[i])));
				}

				if (status == 0) {
					ans = i + 1;
					continue;
				}

				if (map.count(status)) {
					ans = max(ans, i - map[status]);
				} else {
					map[status] = i;
				}
			}

			return ans;
		}
};
