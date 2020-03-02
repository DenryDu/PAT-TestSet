#include <bits/stdc++.h>
using namespace std;
#define verysmall -0x3f3f3f3f
vector<int> maxTemp(10000);
vector<int> stop(10000);
vector<int> Seq;
int len=0;
int main(){
	cin>>len;
	for(int i=0;i<len;i++){
		int intermdia;
		cin>>intermdia;
		Seq.push_back(intermdia);
	} 
	
	for(int i=0;i<len;i++){
		int Sum=0;
		maxTemp[i]=verysmall;
		for(int j=i;j<len;j++){
			Sum+=Seq[j];
			if(Sum>maxTemp[i]){
				maxTemp[i]=Sum;
				stop[i]=j;
			}
		}
	}
	int temp=verysmall;
	int index;
	for(int i=0;i<len;i++){
		if(temp<maxTemp[i]){
			temp=maxTemp[i];
			index=i;
		}
	}
	if(temp<0)
		cout<<"0 "<<Seq[0]<<" "<<Seq[len-1];
	else
		cout<<temp<<" "<<Seq[index]<<" "<<Seq[stop[index]];
} 
