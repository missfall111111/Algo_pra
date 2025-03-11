#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
	int merge(vector<int>&nums,int l,int m,int r){
		int res=0;
		for(int i=l,j=m+1,sum=0;i<=m;i++){
			while(j<=r && nums[i]>2LL*nums[j]){
				sum++;
				j++;
			}
			res+=sum;
		}
		
		int a=l,b=m+1,i=0;
		int help[r-l+1];
		while(a<=m && b<=r){
			help[i++]=nums[a]<=nums[b]?nums[a++]:nums[b++];
		}
		
		while(a<=m){
			help[i++]=nums[a++];
		}
		
		while(b<=r){
			help[i++]=nums[b++];
		}
		
		for(int i=0;i<=r-l;i++){
			nums[i+l]=help[i];
		}
		return res;
	}
	int counts(vector<int>&nums,int l,int r){
		if(l==r){
			return 0;
		}
		int m=(l+r)/2;
		return counts(nums,l,m)+counts(nums,m+1,r)+merge(nums,l,m,r);
	}
	int reversePairs(vector<int>& nums) {
		if(nums.size()==0){
			return 0;
		}
		return counts(nums,0,nums.size()-1);
	}
};
