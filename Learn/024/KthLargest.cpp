#include<iostream>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<algorithm>
using namespace std;

class Solution {
private:
	int first,last;
public:
	void partition(int l,int r,vector<int>&nums){
		int x=nums[l+rand()%(r-l+1)];
		first=l;last=r;
		int i=l;
		while(i<=last){
			if(nums[i]<x){
				swap(nums[i++],nums[first++]);
			}
			else if(nums[i]>x){
				swap(nums[i],nums[last--]);
			}
			else{
				i++;
			}
		}
	}
	int findKthLargest(vector<int>& nums, int k) {
		int l=0,r=nums.size()-1;
		int pos=nums.size()-k;
		srand(time(nullptr));
		while(l<=r){
			partition(l,r,nums);
			if(pos<first){
				r=first-1;
			}
			else if(pos>last){
				l=last+1;
			}
			else{
				return nums[pos];
			}
		}
		return 0;//否则编译不通过
	}
};
