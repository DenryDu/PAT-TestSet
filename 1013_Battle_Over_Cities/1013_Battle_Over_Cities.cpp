#include <bits/stdc++.h>
using namespace std;
bool ways[1001][1001]={false};
int numCity, numWays, numCheck;
int counter=0;
void dfs(int index, bool* vis){
   vis[index]=true; 
   for(int i=1;i<=numCity;i++){
      if(ways[index][i]==true&&vis[i]==false)
         dfs(i,vis);
   }
}

void check(int c){
   int count=-1;
   bool visited[1001]={false};
   visited[c]=true;
   for(int i=1; i<=numCity;i++){
      if(!visited[i]){
         dfs(i, visited);
         count++;
      }
   }
   cout<<count;
}
int main(){
   //cin>>numCity>>numWays>>numCheck;
   scanf("%d %d %d", &numCity, &numWays, &numCheck);
   for(int i=0;i<numWays;i++){
      int c1,c2;
      //cin>>c1>>c2;
      scanf("%d %d", &c1, &c2); 
      ways[c1][c2]=ways[c2][c1]=true;
   }
   for(int j =0;j<numCheck;j++){
      int c;
      //cin>>c;
      scanf("%d", &c);
      check(c);
      if(j<numCheck-1)  cout<<endl;
   }
   return 0;
}
