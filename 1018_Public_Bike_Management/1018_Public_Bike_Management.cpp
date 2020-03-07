#include <bits/stdc++.h>
#define Max 0x3f3f3f3f
// const int Max = 999999999999;
using namespace std;
int capMax, stNum, roadNum, sP, minIn=Max, minOut=Max;
int st[510]={0}, road[510][510], dis[510];
bool IsOut[510]={false};
vector<int> temppath, path, pre[510];/////////////////////////////////////////////////////init pre station condition
void dfs(int v){
    temppath.push_back(v);
    if(v==0){
        int tempIn = 0, tempOut = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {///////////////////////////////////////
            int id = temppath[i];
            if(st[id] > 0) {
                tempIn += st[id];
            } else {
                if(tempIn > abs(st[id])) {
                    tempIn += st[id];
                } else {
                    tempOut += abs(tempIn+st[id]);
                    tempIn = 0;
                }
            }
        }
        // int cnt=0;//////////////////////////////////////////////////////calculate the in and out
        // for(int i=temppath.size()-1;i>=0;i--){
        //     int tempI=temppath[i];
        //     cnt+=st[tempI];
        // }
        // int tempIn=0, tempOut=0;
        // if(cnt>0){
        //     tempIn=cnt;
        // }
        // else if(cnt<0){
        //     tempOut-=cnt;
        // }
        if(tempOut<minOut){
            minIn=tempIn;
            minOut=tempOut;
            path=temppath;
        }
        else if(tempOut==minOut&&tempIn<minIn){
            minIn=tempIn;
            path=temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i=0;i<pre[v].size();i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}
int main(){
    memset(dis,Max,sizeof(dis));
    memset(road,Max,sizeof(road));
    cin>>capMax>>stNum>>sP>>roadNum;
    for(int i=1;i<=stNum;i++){//////////////////////////////////////////////init station current num
        cin>>st[i];
        st[i]=st[i]-(capMax/2);
    }
    for(int i=0;i<roadNum;i++){/////////////////////////////////////////////init road
        int j_1,j_2,t;
        cin>>j_1>>j_2>>t;
        road[j_1][j_2]=road[j_2][j_1]=t;
    }
    dis[0]=0;
    for(int i=0;i<stNum+1;i++){/////////////////////////////////////////////implement djistra
        int picked=-1,mindis=Max;
        for(int j=0;j<=stNum;j++){/////////////////////////////////pick out the one with shortest path
            if(dis[j]<mindis && IsOut[j]==false){
                picked=j;
                mindis=dis[j];
            }
        }
        if(picked==-1)   break;
        ///////////////////////////////////////////////////////////then refreash the dis left
        IsOut[picked]=true;
        for(int j=0;j<=stNum;j++){
            if(IsOut[j]==false&&road[picked][j]!=Max){
                if(dis[picked]+road[picked][j]<dis[j]){///////refresh the st
                    dis[j]=dis[picked]+road[picked][j];
                    pre[j].clear();
                    pre[j].push_back(picked);               
                }
                else if(dis[picked]+road[picked][j]==dis[j])//refresh the st
                    pre[j].push_back(picked);
            }
        }
    }
    dfs(sP);
    cout<<minOut<<" 0";
    for(int i=path.size()-2;i>=0;i--)
        cout<<"->"<<path[i];
    cout<<" "<<minIn;
    return 0;
}
