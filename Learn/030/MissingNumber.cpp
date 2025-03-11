#include<vector>

using namespace std;


class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n=nums.size();
		int eor1=0,eor2=0;
		for(int i=0;i<=n;i++){
			eor1^=i;
		}
		for(const auto &i:nums){
			eor2^=i;
		}
		return eor1^eor2;
	}
};
