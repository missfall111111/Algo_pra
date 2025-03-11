#include <string>
#include <iostream>
using namespace std;


class Solution {
	public:
		/**
		 * @brief 返回l到r范围上的超级回文数字的个数
		 * 思路：从1开始制造（奇数，偶数）回文数字num,判断num^2是否在范围里
		 * 如果小于，不加，继续
		 * 如果在范围里，加
		 * 如果奇数开始大于 退出
		 *
		 * @param l
		 * @param r
		 *
		 * @return
		 */
		unsigned long getOddHuiWen(unsigned long a) {
			unsigned long ans = a;
			a /= 10;
			while (a != 0) {
				ans = ans * 10 + (a % 10);
				a /= 10;
			}
			return ans;
		}

		unsigned long getEvenHuiWen(unsigned long a) {
			unsigned long ans = a;
			while (a != 0) {
				ans = ans * 10 + (a % 10);
				a /= 10;
			}
			return ans;
		}

		bool isHuiWen(unsigned long a) {
			unsigned long offset = 1;
			while (a / offset >= 10) {
				offset *= 10;
			}

			while (a != 0) {
				if (a % 10 != a / offset) {
					return false;
				}
				a = a % offset;
				a /= 10;
				offset /= 100;
			}
			return true;
		}
		int f(unsigned long l, unsigned long r) {
			unsigned long i = 1;
			int ans = 0;
			while (1) {
				unsigned long x = getEvenHuiWen(i);
				unsigned long y = getOddHuiWen(i);
				if (x * x < l) {
					i++;
					continue;
				} else if (x * x >= l && x * x <= r) {
					if (isHuiWen(x * x)) {
						ans++;
					}
				}

				if (y * y < l) {
					i++;
					continue;
				} else if (y * y >= l && y * y <= r) {
					if (isHuiWen(y * y)) {
						ans++;
					}
				} else {
					break;
				}
				i++;
			}
			return ans;
		}
		int superpalindromesInRange(string left, string right) {
			unsigned long l = stol(left);
			unsigned long r = stol(right);

			return f(l, r);
		}
};


int main() {
	Solution s;
	string l = "4";
	string r = "1000";
	cout << s.superpalindromesInRange(l, r);
	cout << sizeof(unsigned long);
	cout << sizeof(unsigned long);
	return 0;
}
