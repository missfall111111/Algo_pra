#include <vector>

using namespace std;
class Solution {
	public:
		void f(vector<int>&path, vector<vector<int>>&ans, int i) {
			if(i==path.size()-1){
				vector<int>a=path;
				ans.push_back(a);
				return;
			}
			
			f(path,ans,i+1); //自己开头，不交换
			for(int j=i+1;j<path.size();j++){
				swap(path[i],path[j]);
				f(path,ans,i+1);
				swap(path[i],path[j]);
			}
		}
		vector<vector<int>> permute(vector<int>& nums) {
			vector<int> a=nums;
			vector<vector<int>>ans;
			f(a,ans,0);
			return ans;
		}
};
