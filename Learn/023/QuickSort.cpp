/**
 * 使用荷兰国旗的partition
 */


#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<algorithm>
using namespace std;

const int MAXN=100000;
int n;
int arr[MAXN];
int a,b;


void particion(int l,int r,int x){
	a=l,b=r;
	int i=l;
	while(i<=b){
		if(arr[i]<x){
			swap(arr[a],arr[i]);
			i++;a++;
		}
		else if (arr[i]==x){
			i++;
		}
		else{
			swap(arr[i],arr[b]);
			b--;
		}
	}	
}
void QuickSort(int l,int r){
	if(l>=r)
	{
		return;
	}
	
	int x=l+rand()%(r-l+1); // %x  则生成0-x-1的数字
	particion(l,r,arr[x]);
	int first=a,last=b;
	QuickSort(l,first-1);
	QuickSort(last+1,r);
	
}
int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	srand(time(nullptr));
	QuickSort(0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
