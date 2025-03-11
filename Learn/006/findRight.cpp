#include<iostream>

using namespace std;


//有序数组，找到<=x的最大位置的索引,如果不存在，则返回-1
//应该从算法的实现去思考，去验证其正确性。而不是全局的，脱离实现的
int findRight(int arr[],int n,int x){
	if(arr==NULL || n==0){
		return -1;
	}
	
	int ans=-1,l=0,r=n-1;
	
	while(l<=r){
//		int m=(l+r)/2;
		int m=l+(r-l)/2;  //防止溢出
		if(arr[m]<=x){
			ans=m;
			l=m+1;
		}
		else{
			r=m-1;
		}
	}
	
	return ans;
}


int main(){
	int arr[]={1,3,4,5,6,7,7,8,9,11,11,21};
	cout<<findRight(arr,12,7)<<endl;
	cout<<findRight(arr,12,6)<<endl;
	cout<<findRight(arr,12,13)<<endl;
	cout<<findRight(arr,12,0)<<endl;
	return 0;
}
