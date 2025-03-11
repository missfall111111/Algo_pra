#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
	public:
		/**
		 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
		 *
		 *
		 * @param s string字符串
		 * @return string字符串vector
		 */

		void f(int i, string &path, string &s, unordered_set<string> &ans) {
			if (i == s.size()) {
				string a = path;
				ans.insert(a);
				return;
			}
			f(i + 1, path, s, ans); //不加
			path += s[i];
			f(i + 1, path, s, ans);
			path.pop_back();
		}
		vector<string> generatePermutation(string s) {
			// write code here
			string path = "";
			unordered_set <string>ans;
			f(0, path, s, ans);
			vector<string>a;
			for (string i : ans) {
				a.push_back(i);
			}
			return a;
		}
};
