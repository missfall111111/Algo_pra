#include<iostream>

using namespace std;

const int MAXN=100000;
int arr[MAXN];
int help[MAXN];
int n;

long merge(int l,int m,int r){
	long ans=0;
	for(int i=l,j=m+1,sum=0;j<=r;j++){
		while(i<=m && arr[i]<=arr[j]){
			sum+=arr[i++];
		}
		ans+=sum;
	}
	int a=l,b=m+1,i=l;
	while(a<=m &&b<=r){
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
	return ans;
}
long smallSum(int l,int r){
	if(l==r){
		return 0;
	}
	int m=(l+r)/2;
	
	return smallSum(l,m)+smallSum(m+1,r)+merge(l,m,r);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<smallSum(0,n-1);	
	return 0;
}
