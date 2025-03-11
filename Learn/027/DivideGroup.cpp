#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class Solution {
public:
	int minGroups(vector<vector<int>>& intervals) {
		sort(intervals.begin(),intervals.end(),[](auto& a,auto& b){return a[0]<b[0];});
		size_t ans=0;
		priority_queue<int,vector<int>,greater<int>> heap;
		for(const auto &arr : intervals){
			while(!heap.empty() && arr[0]>heap.top()){
				heap.pop();
			}
			heap.push(arr[1]);
			ans=max(ans,heap.size());
		}
		return ans;
	}
};
