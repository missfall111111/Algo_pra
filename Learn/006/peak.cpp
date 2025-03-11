#include<iostream>
#include<vector>

//[警告] control reaches end of non-void function [-Wreturn-type]

//编译器会警告甚至有的编译器会报错。但是在题目的条件下，是没问题的。
using namespace std;
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int l=0,r=nums.size();
		if (nums.size() == 1) return 0;  // 添加单个元素的情况
		if(nums[0]>nums[1]){
			return 0;
		}
		if(nums[r-1]>nums[r-2]){
			return r-2;
		}
		
		while(l<=r){
			int m=l+(r-l)/2;
			if(nums[m]>nums[m-1] && nums[m]>nums[m+1]){
				return m;
			}
			else if(nums[m]<nums[m-1]){
				r=m-1;
			}
			else{
				l=m+1;
			}
		}
		
		return -1;  //按照题目，上面是一定会返回值的
	}
};


int main(){
	Solution s;
	vector<int>nums1={1,2,3,1};
	vector<int>nums2={1,2,1,3,5,6,4};
	cout<<s.findPeakElement(nums1)<<endl;
	cout<<s.findPeakElement(nums2)<<endl;
	return 0;
}
