#include <bits/stdc++.h>
using namespace std;
int num, h[10001], cnt=0;
bool visited[10001]={false};
vector<int> roots;
vector<int> e[10001];
void dfs(int v){
    visited[v]=true;
    for(int i=0;i<e[v].size();i++){
        if(!visited[e[v][i]]){
            dfs(e[v][i]);
        }
    }
}
bool cmp(int a, int b){
    return a<b;
}
void find_h(int v, int h, int& deep){
    visited[v]=true;
    if(deep<h){
        deep=h;
    }
    for(int i=0;i<e[v].size();i++){
        if(!visited[e[v][i]]){
            find_h(e[v][i], h+1, deep);
        }
    }
}
int main(){
    memset(h,0,sizeof(h));
    cin>>num;
    for(int i=0;i<num-1;i++){
        int j, k;
        cin>>j>>k;
        e[j].push_back(k);
        e[k].push_back(j);
    }
    ////////////////////////////////////////////////////////////////check tree
    for(int i=1;i<=num;i++){
        if(visited[i]==false){
            cnt++;
            dfs(i);
        }
    }
    if(cnt!=1){
        cout<<"Error: "<<cnt<<" components";
        return 0;
    }
    for(int i=1;i<=num;i++){
        memset(visited, false,sizeof(visited));
        find_h(i, 0, h[i]);
    }
    int tempH=-1;
    for(int i=1;i<=num;i++){
        if(h[i]>tempH){
            roots.clear();
            roots.push_back(i);
            tempH=h[i];
        }else if(h[i]==tempH){
            roots.push_back(i);
        }
    }
    sort(roots.begin(), roots.end(), cmp);
    for(int i=0;i<roots.size();i++){
        cout<<roots[i]<<endl;
    }
    return 0;
}

