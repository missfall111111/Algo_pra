#include <iostream>

using namespace std;

class GcdAndLcm {
	public:
		//a和b的最大公因数 greatest common divisor
		int gcd(int a, int b) {
			if (b == 0) {
				return a;
			}
			return gcd(b, a % b);
		}

		//a和b的最小公倍数 least common multiple
		int lcm(int a, int b) {
			return a / gcd(a, b) * b;
		}
};
int main() {
	GcdAndLcm a = GcdAndLcm();
	cout << a.gcd(3, 8) << "\n";
	cout << a.lcm(3, 8) << "\n";
	return 0;
}
