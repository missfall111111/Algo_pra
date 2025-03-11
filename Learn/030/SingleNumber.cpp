#include<vector>


using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int eor=0;
		for(const auto &i:nums){
			eor^=i;
		}
		
		return eor;
	}
};
