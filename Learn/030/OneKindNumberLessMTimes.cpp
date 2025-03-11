#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int find(vector<int>&nums,int t){
		int cnt[32];
		fill(cnt,cnt+32,0);
		for(const auto &num:nums){
			for(int i=0;i<32;i++){
				cnt[i]+=(num>>i)&1;
			}
		}
		
		int ans=0;
		for(int i=0;i<32;i++){
			if(cnt[i]%t!=0){
				ans|=(1<<i);
			}
		}
		return ans;
	}
	int singleNumber(vector<int>& nums) {
		return find(nums,3);
	}
	
	
};
