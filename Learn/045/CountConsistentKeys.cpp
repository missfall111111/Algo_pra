#include <vector>
#include <iostream>
using namespace std;


const int MAXN = 2000001;
int nodePath[MAXN][12];
int pass[MAXN];
int cnt = 1;
class Solution {
	public:
		/**
		 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
		 *
		 *
		 * @param b int整型vector<vector<>>
		 * @param a int整型vector<vector<>>
		 * @return int整型vector
		 */
		vector<vector<int>> adjust(vector<vector<int>>&a) {
			vector<vector<int>>ans = a;
			for (auto &ele : ans) {
				for (unsigned int i = 0; i < ele.size() - 1; i++) {
					ele[i] = ele[i + 1] - ele[i];
				}
				ele.pop_back();
//correct
//				for (const auto &a : ele) {
//					cout << a << " ";
//				}
//				cout << "\n";
			}
			return ans;
		}

		int getOffset(int a) {
			int offset = 1;
			while (a / offset >= 10) {
				offset *= 10;
			}
			return offset;
		}

		void AddToTrie(vector<vector<int>>&a) {
			for (const auto &arr : a) {
				int cur = 1;
				//加入一条数组
				for (const auto &ele : arr) {
					int tmp = ele;
					int offset = getOffset(tmp);
					if (tmp < 0) {
						if (nodePath[cur][10] == 0) {
							nodePath[cur][10] = ++cnt;
						}
						cur = nodePath[cur][10];
						tmp = -tmp;
					}
					//加入一个数字，以#结尾
					while (tmp != 0) {
						//获取首位
						int top = tmp / offset;
						if (nodePath[cur][top] == 0) {
							nodePath[cur][top] = ++cnt;
						}
						cur = nodePath[cur][top];
						tmp = tmp % offset;
						offset /= 10;
					}
					//加#号
					if (nodePath[cur][11] == 0) {
						nodePath[cur][11] = ++cnt;
					}
					cur = nodePath[cur][11];
					pass[cur]++; //结尾的#号标记有几个是这样的前缀的
				}
			}
		}
		//查看较短的b数组，是多少个a数组的前缀
		vector<int> cal(vector<vector<int>>&b) {
			vector<int>res;
			for (const auto &arr : b) {
				int cur = 1;
				int f = 1;
				//对于每一个b的数组，他是多少个a的前缀
				//需要把这个数组走完
				for (const auto &ele : arr) {
					int tmp = ele;
					int offset = getOffset(tmp);
					if (tmp < 0) {
						if (nodePath[cur][10] == 0) {
							f = 0;
							break;
						}
						cur = nodePath[cur][10];
						tmp = -tmp;
					}
					//检查一个数字，以#结尾
					while (tmp != 0) {
						//获取首位
						int top = tmp / offset;
						if (nodePath[cur][top] == 0) {
							f = 0;
							break;
						}
						cur = nodePath[cur][top];
						tmp = tmp % offset;
						offset /= 10;
					}
					//加#号
					if (nodePath[cur][11] == 0) {
						f = 0;
						break;
					}
					cur = nodePath[cur][11];
				}
				//最后cur停留在#号路径的结尾
				if (f) {
					res.push_back(pass[cur]);
				} else {
					res.push_back(0);
				}
			}
			return res;
		}
		vector<int> countConsistentKeys(vector<vector<int> >& b, vector<vector<int> >& a) {
			// write code here
			//先变成需要的结构
			vector<vector<int>>b1 = adjust(b);
			vector<vector<int>>a1 = adjust(a);

			//把a1加入前缀树里去
			AddToTrie(a1);
			return cal(b1);
		}
};
