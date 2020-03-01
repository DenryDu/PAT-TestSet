#include <bits/stdc++.h>
using namespace std;
int main(){
	int reqNum;
	int current=0;
	int next;
	int totalTime=0;
	cin>>reqNum;
	for(int i=0;i<reqNum;i++){
		cin>>next;
		totalTime+=5;
		if(next>current){
			totalTime+=(6*(next-current));
		}else if(next<current){
			totalTime+=(4*(current-next));
		}
		current=next;
	}
	cout<<totalTime;
	return 0;
} 
