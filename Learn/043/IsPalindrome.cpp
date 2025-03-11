class Solution {
	public:
		bool isPalindrome(int x) {
			if (x < 0) {
				return false;
			}
			int offset = 1;
			while (x / offset >= 10) {
				offset *= 10;
			}
			while (x != 0) {
				if (x / offset != x % 10) {
					return false;
				}
				x = x % offset;
				x /= 10;
				offset /= 100;
			}

			return true;
		}
};
