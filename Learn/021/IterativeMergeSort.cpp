#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=100000;
int arr[MAXN];
int help[MAXN];

void merge(int l,int r,int m){
	int a=l;
	int b=m+1;
	int i=l;
	
	while(a<=m && b<=r){
		help[i++]=arr[a]<=arr[b]?arr[a++]:arr[b++];
	}
	
	while(a<=m){
		help[i++]=arr[a++];
	}
	while(b<=r){
		help[i++]=arr[b++];
	}
	
	for(int i=l;i<=r;i++){
		arr[i]=help[i];
	}
}


void iterativeMergeSort(int n){
	for(int step=1;step<n;step<<=1){
		for(int l=0;l<n-1;l+=2*step){
			int mid=l+step-1;
			int r=min(l+2*step-1,n-1);
			
			if(mid>=n) break;
			
			merge(l,r,mid);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	iterativeMergeSort(n);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
