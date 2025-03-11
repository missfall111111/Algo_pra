#include<iostream>

using namespace std;


void swap(int& a,int& b){
	a=a^b;
	b=a^b;
	a=a^b;
}
int main(){
	int arr1[]={3,2};
	swap(arr1[0],arr1[1]);
	cout<<arr1[0]<<" "<<arr1[1]<<" \n";  //交换2个不同的数字，正常
	
	int arr2[]={3,3};
	swap(arr2[0],arr2[1]);
	cout<<arr2[0]<<" "<<arr2[1]<<" \n";  //交换两个相同的数字，正常
	
	swap(arr2[0],arr2[0]);
	cout<<arr2[0]<<" "<<arr2[1]<<" \n";  //交换自己，错误
	return 0;
}
