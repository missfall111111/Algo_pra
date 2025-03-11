#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<array>
using namespace std;

const int MAXN=10000;
array<int,2> arr[MAXN];
int n;

int MaxCover(){
	size_t ans=0;
	sort(arr,arr+n,[](auto a,auto b){
		return a[0]<b[0];
	});
	
//	for(int i=0;i<n;i++){
//		cout<<arr[i][0]<<" "<<arr[i][1]<<"\n";
//	}
//	
	priority_queue<int,vector<int>,greater<int>> heap;
	for(int i=0;i<n;i++){
		while(!heap.empty() && arr[i][0]>=heap.top()){
			heap.pop();
		}
		heap.push(arr[i][1]);
		ans=max(ans,heap.size());
	}
	
	return ans;
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i][0]>>arr[i][1];
	}
	
	cout<<MaxCover();
	
	return 0;
}
