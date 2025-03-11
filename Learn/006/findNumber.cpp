#include<iostream>

using namespace std;

//一个长度为n的，从小到大有顺序的数组，判断其内部是否含有某一个数字x
bool exist(int arr[],int n,int x){
	if(arr==NULL || n==0){
		return false;
	}
	
	int l=0,r=n-1,m;
	while(l<=r){
		m=(l+r)/2;
		if(arr[m]==x){
			return true;
		}
		else if(arr[m]>x){
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	return false;
}
int main(){
	int arr1[]={1,3,5,7,9};
	
	bool res1=exist(arr1,5,2);
	bool res2=exist(arr1,5,3);
	if(res1){
		cout<<"存在2"<<endl;
	}
	else{
		cout<<"不存在2"<<endl;
	}
	
	if(res2){
		cout<<"存在3"<<endl;
	}
	else{
		cout<<"不存在3"<<endl;
	}
}
