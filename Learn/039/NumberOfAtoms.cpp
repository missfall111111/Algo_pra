#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
	public:
		int where;
		map<string, int>f(int i, string&s) {

			string ele = "";
			int cur = 0;
			map<string, int>res;
			map<string, int>tmp;
			while (i < s.size() && s[i] != ')') {
				if (s[i] >= '0' && s[i] <= '9') {
					cur = cur * 10 + s[i] - '0';
				} else if (s[i] >= 'A' && s[i] <= 'Z') { //大写字母一个元素的开头！
					if (ele != "") {
						//这是上一个元素的结尾，同样是这一个元素的开头
						res[ele] += (cur == 0 ? 1 : cur);
						cur = 0;
						ele = "";
					}
					if (!tmp.empty()) {  //或者是上一个表达式的开头
						for (int i = 0; i < (cur == 0 ? 1 : cur); i++) {
							for (auto& ele : tmp) {
								res[ele.first] += ele.second;
							}
						}
						cur = 0;
						tmp.clear();
					}
					ele += s[i];
				} else if (s[i] == '(') {
					if (ele != "") {
						//左括号是上一个元素的结尾
						res[ele] += (cur == 0 ? 1 : cur);
						cur = 0;
						ele = "";
					}
					if (!tmp.empty()) {  //或者是上一个表达式的开头
						for (int i = 0; i < (cur == 0 ? 1 : cur); i++) {
							for (auto& ele : tmp) {
								res[ele.first] += ele.second;
							}
						}
						cur = 0;
						tmp.clear();
					}
					tmp = f(i + 1, s);
					i = where;
				} else { //小写字母，接在大写字母后边
					ele += s[i];
				}
				i++;
			}

			if (tmp.empty()) {
				res[ele] += (cur == 0 ? 1 : cur);  //以一个化学式结尾
			} else { //以一个括号表达式结尾
				for (int i = 0; i < (cur == 0 ? 1 : cur); i++) {
					for (auto& ele : tmp) {
						res[ele.first] += ele.second;
					}
				}
				cur = 0;
				tmp.clear();
			}

			where = i;
			//括号里面同样是化学式
			return res;
		}
		string countOfAtoms(string formula) {
			where = 0;
			map<string, int>a = f(0, formula);
			string res;
			for (auto & e : a) {
				res += e.first;
				if (e.second == 1) {
					continue;
				}
				res += to_string(e.second);
			}
			return res;
		}
};

int main() {
	string a = "((N42)24(OB40Li30CHe3O48LiNN26)33(C12Li48N30H13HBe31)21(BHN30Li26BCBe47N40)15(H5)16)14";
	Solution s;
	cout << s.countOfAtoms(a);
	return 0;
}
