#include <bits/stdc++.h>
using namespace std;
typedef struct timeInfo{

	string id;
	char* inTime=(char*)malloc(8*sizeof(char));
	char* outTime=(char*)malloc(8*sizeof(char));
}timeInfo;
void InitTimeInfo(timeInfo &tI, string a, char* b, char* c){
	tI.id=a;
	strcpy(tI.inTime,b);
	strcpy(tI.outTime,c);
}
bool cmpInTime(timeInfo a, timeInfo b){
	return (strcmp(a.inTime,b.inTime)<0);
}
bool cmpOutTime(timeInfo a, timeInfo b){
	return (strcmp(a.inTime,b.inTime)>0);
}
int main(){
	int num;
	cin>>num;
	vector<timeInfo> timeVec;
	for(int i=0;i<num;i++){
		string id;
		char inTime[8];
		char outTime[8];
		cin>>id>>inTime>>outTime;
		timeInfo tI;
		InitTimeInfo(tI, id, inTime, outTime);
		timeVec.push_back(tI); 
	}
	sort(timeVec.begin(),timeVec.end(),cmpInTime);
	cout<<timeVec[0].id;
	cout<<" "; 
	sort(timeVec.begin(),timeVec.end(),cmpOutTime);
	cout<<timeVec[0].id;
	return 0;
}
