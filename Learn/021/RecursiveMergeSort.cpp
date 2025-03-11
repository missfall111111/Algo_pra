#include<iostream>

using namespace std;

const int MAXN=100000;
int arr[MAXN];
int help[MAXN];

void merge(int l,int m,int r)
{
	int i=l;
	int a=l;
	int b=m+1;
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
void mergeSort(int l,int r){
	if(l==r){
		return;
	}
	int m=(l+r)/2;
	mergeSort(l,m);
	mergeSort(m+1,r);
	merge(l,m,r);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	mergeSort(0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	
	return 0;
}
