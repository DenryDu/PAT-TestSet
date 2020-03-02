#include <bits/stdc++.h>
#define M 0x3f3f3f3f
using namespace std;
typedef struct{
	string id;
	int score[4];
	int rank[4]={-1};
}stuInfo;
vector<stuInfo> info;
bool cmpC(stuInfo a, stuInfo b){	return (a.score[1]>b.score[1]);}
bool cmpM(stuInfo a, stuInfo b){	return (a.score[2]>b.score[2]);}
bool cmpE(stuInfo a, stuInfo b){	return (a.score[3]>b.score[3]);}
bool cmpA(stuInfo a, stuInfo b){	return (a.score[0]>b.score[0]);}
typedef struct ifIdMatch{
	string m_id;
	ifIdMatch(string id):m_id(id){}
	bool operator()(const stuInfo& si){
		return (si.id.compare(m_id)==0);
	}
}ifIdMatch;
void Rank(stuInfo si){
	int min=M;
	char map[4]={'A','C','M','E'};
	int flag=-1;
	for(int i=0;i<4;i++){
		if(min>si.rank[i]){
			min=si.rank[i];
			flag=i;
		}
	}
	cout<<min<<" "<<map[flag];
} 
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		stuInfo si;
		cin>>si.id>>si.score[1]>>si.score[2]>>si.score[3];
		si.score[0]=si.score[1]+si.score[2]+si.score[3];
		info.push_back(si);
	}
	sort(info.begin(),info.end(),cmpC);
	for(int i=0;i<n;i++)		if(i>0&&info[i-1].score[1]==info[i].score[1]) info[i].rank[1]=info[i-1].rank[1];else info[i].rank[1]=i+1;
	sort(info.begin(),info.end(),cmpM);
	for(int i=0;i<n;i++)		if(i>0&&info[i-1].score[2]==info[i].score[2]) info[i].rank[2]=info[i-1].rank[2];else info[i].rank[2]=i+1;
	sort(info.begin(),info.end(),cmpE);
	for(int i=0;i<n;i++)		if(i>0&&info[i-1].score[3]==info[i].score[3]) info[i].rank[3]=info[i-1].rank[3];else info[i].rank[3]=i+1;
	sort(info.begin(),info.end(),cmpA);
	for(int i=0;i<n;i++)		if(i>0&&info[i-1].score[0]==info[i].score[0]) info[i].rank[0]=info[i-1].rank[0];else info[i].rank[0]=i+1;
	
	vector<string> idVec;
	for(int i=0;i<m;i++){
		string id;
		cin>>id;
		idVec.push_back(id);
	}
	for(int i=0;i<m;i++){
		std::vector<stuInfo>::iterator it = find_if(info.begin(),info.end(),ifIdMatch(idVec[i]));
		if(it!=info.end())
			Rank(*it);
		else cout<<"N/A";
		if(i<m-1)	cout<<endl;
	}
	return 0;
}
//	vector<string*> idVec;
//	for(int i=0;i<m;i++){
//		string id[7];
//		cin>>id;
//		idVec.push_back(id);
//	}
