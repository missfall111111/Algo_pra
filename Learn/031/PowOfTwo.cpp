/**
 * 提取最右侧的1
 * 0001 1000   x
 * 1110 1000   -x
 */
class Solution {
public:
	bool isPowerOfTwo(int n) {
		
		return n>0 && n==(n&-n);
	}
};
