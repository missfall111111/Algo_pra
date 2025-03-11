#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
	public:

		int where;
		//数字比符号多一个，符号只有加减
		int cal(vector<int>&num, vector<char>&sign) {
			int l = sign.size();
			for (int i = 0; i < l; i++) {
				int o1 = num[i];
				int o2 = num[i + 1];
				num[i + 1] = sign[i] == '+' ? o1 + o2 : o1 - o2;
			}
			return *(num.end() - 1);
		}

		//符号的前面必定有数字,在放完数字后使用,且数字至少2个
		void adjust(vector<int>&num, vector<char>&sign) {
			if (sign.empty()) {
				return;
			}
			if (*(sign.end() - 1) == '*') {
				int o1 = *(num.end() - 1);
				num.pop_back();
				int o2 = *(num.end() - 1);
				num.pop_back();
				sign.pop_back();
				num.push_back(o1 * o2);
			} else if (*(sign.end() - 1) == '/') {
				int o1 = *(num.end() - 1);
				num.pop_back();
				int o2 = *(num.end() - 1);
				num.pop_back();
				sign.pop_back();
				num.push_back(o2 / o1);
			}
		}

		//数字 符号 小括号/数字
		//小括号 符号
		//数字遇到符号加
		int f(int i, string &s) {
			vector<int>num;
			vector<char>sign;
			int cur = 0;
			while (i < s.size() && s[i] != ')') {
				if (s[i] >= '0' && s[i] <= '9') { //数字
					cur = cur * 10 + (s[i] - '0');
				} else if (s[i] == '(') { //小括号  此时cur必定为0
					int a = f(i + 1, s);
//					cout << "Push了" << a << "\n";
//					num.push_back(a); //后面的括号返回后，更新i
					cur = a;
					i = where;    //此时where的位置是右括号
//					adjust(num, sign);

				} else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ) { //符号

					num.push_back(cur);
					cout << "Push了" << cur << "\n";
					cur = 0;
					adjust(num, sign);

					sign.push_back(s[i]);
					cout << "Push了" << s[i] << "\n";
				}
				i++;
			}
			cout << "Push了" << cur << "\n";
			num.push_back(cur);
			adjust(num, sign);
			where = i;
			return cal(num, sign);
		}

		int calculate(string &s) {
			// Write your code here
			where = 0;
			return f(0, s);
		}
};

int main() {
	Solution s;
	string a = "(3-(5-(8)-(2+(9-(0-(8-(2))))-(4))-(4)))";
	cout << s.calculate(a);
	return 0;
}
