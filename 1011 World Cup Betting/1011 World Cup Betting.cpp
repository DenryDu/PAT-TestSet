#include <bits/stdc++.h>
using namespace std;
int main(){
	double value[3]={-100};
	int flag[3];
	char map[3]={'W','T','L'};
	
	for(int i=0;i<3;i++){
		double temp;
		for(int j=0;j<3;j++){
			cin>>temp;
			if(value[i]<temp){
				value[i]=temp;
				flag[i]=j;
			}
		}
	}
	double profit=(value[0]*value[1]*value[2]*0.65-1)*2;
	for(int i=0;i<3;i++){
		cout<<map[flag[i]]<<" ";
	}
	printf("%.2f", profit);
	return 0;
} 
