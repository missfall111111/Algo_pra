#include <string>
using namespace std;
class Solution {
	public:
		int where;
		string f(int i, string &s) {

			int cur = 0;
			string res;
			while (i < s.size() && s[i] != ']') {
				if (s[i] >= '0' && s[i] <= '9') { //数字，末尾必然是一个括号
					cur = cur * 10 + s[i] - '0';
				} else if (s[i] == '[') { //括号表达式
					string a = f(i + 1, s);
					i = where;
					for (int i = 0; i < cur; i++) {
						res += a;
					}
					cur = 0;
				} else {  //字母
					res += s[i];
				}
				i++;
			}
			where = i;
			return res;
		}
		string decodeString(string s) {
			where = 0;
			return f(0, s);
		}
};
