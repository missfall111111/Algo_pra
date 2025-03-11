class Solution {
public:
	int rangeBitwiseAnd(int left, int right) {
		while(left<right){
			right-=right&-right;
		}
		
		return right;
	}
};


/**13-15
 * 1110
 * 
 */
