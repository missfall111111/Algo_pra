#include<iostream>

using namespace std;


//有序数组：返回>=x的最小的位置的索引，如果不存在，则返回-1
//也是二分的思想,只是向更精确的方向靠近时，做的动作不一样
int findLeft(int arr[],int n,int x){
	if(arr==NULL || n==0){
		return -1;
	}
	
	int ans=-1,l=0,r=n-1;
	
	while(l<=r){
		int m=(l+r)/2;
		if(arr[m]>=x){
			ans=m;
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	return ans;
}
int main(){
	int arr[]={2,4,5,6,6,9,10,10,18};
	cout<<findLeft(arr,9,6)<<endl;
	cout<<findLeft(arr,9,7)<<endl;
	cout<<findLeft(arr,9,10)<<endl;
	cout<<findLeft(arr,9,19)<<endl;
	
	return 0;
}
