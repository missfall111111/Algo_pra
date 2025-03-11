#include <algorithm>
using namespace std;

class Solution {
	public:
		int gcd(int a, int b) {
			if (b == 0) {
				return a;
			}
			return gcd(b, a % b);
		}

		int lcm(int a, int b) {
			return a / gcd(a, b) * b;
		}
		int nthMagicalNumber(int n, int a, int b) {
			int l = 0;
			int r = min(a, b) * n;
			int m;
			int x = lcm(a, b);
			while (l <= r) {
				m = (l + r) / 2;
				if ((m / a + m / b - m / x) >= n ) {
					r = m - 1;
				} else  {
					l = m + 1;
				}
			}
			return m % (1000000000);
		}
};
