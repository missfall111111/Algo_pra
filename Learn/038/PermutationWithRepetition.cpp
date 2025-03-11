#include <vector>
#include<unordered_set>
using namespace std;

class Solution {
	public:
	void f(int i, vector<int>&path,vector<vector<int>>&ans){
		if(i==path.size()-1){
			vector<int>a=path;
			ans.push_back(a);
			return;
		}
		
		f(i+1,path,ans);  //自己做头，不交换
		unordered_set<int> s;
		s.insert(path[i]);
		for(int j=i+1;j<path.size();j++){
			if(s.count(path[j])){
				continue;
			}
			s.insert(path[j]);
			swap(path[i],path[j]);
			f(i+1,path,ans);
			swap(path[i],path[j]);
		}
	}
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			vector<int>path=nums;
			vector<vector<int>>ans;
			f(0,path,ans);
			return ans;
		}
};
